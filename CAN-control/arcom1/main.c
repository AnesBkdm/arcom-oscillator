#include<linux/init.h>
#include<linux/module.h>

#include <asm/io.h>
#include <asm/irq.h>
#include <rtai.h>
#include <rtai_sched.h>
#include <rtai_fifos.h>

#include "bus_can.h"
#include "3712.h"
#include "3718.h"

MODULE_LICENSE("GPL");

#define STACK_SIZE 2000
#define TICK_PERIOD 1000000         // 1 ms
#define PERIODE_CONTROL 10000000    // 10 ms
#define PRIORITE 1

static RT_TASK tache_acq, tache_emit, tache_recup;
void recup_capteurs(u8* cpt_data);

RTIME time_count;

u8 data[4];
u8 data_emit[4];
u8 data1[2];

void acq_capteurs(long arg)
{
    while(1){

        recup_capteurs(data);

        data_emit[0] = data[0];
        data_emit[1] = data[1];
        data_emit[2] = data[2];
        data_emit[3] = data[3];

        rt_task_wait_period();
    }
}

void emission_capteurs(long arg)  
{
    while(1){
        emission(8,data_emit,4);
        rt_task_wait_period();      // attente periode de la tache
    }
}

void recup_cmd(long arg)
{
    while(1){
        reception(7,data1);
        printk("\ncacommande recue = %d\n",(int) (data1[0]<<8) + data1[1]);
        dac_output(0,(data1[0]<<8) + data1[1]);
        rt_task_wait_period();
    } 
}

void recup_capteurs(u8* cpt_data)
{
    u16 dac_value;
    u16 dac_value2;
    int i;

	if(idle_adc() == 1){
		dac_value = adc_readADC(0);  // lecture valeur convertie ADC angle
	}
	
	for(i=0;i<100;i++);

	while(idle_adc() == 0);

	if(idle_adc() == 1){
		dac_value2 = adc_readADC(1);  // lecture valeur convertie ADC position
	}
	
	cpt_data[0] = ((dac_value & 0xFF00)>>8);
	cpt_data[1] = dac_value & 0x00FF;
    cpt_data[2] = ((dac_value2 & 0xFF00)>>8);
	cpt_data[3] = dac_value2 & 0x00FF;
	
}

static int task_init(void)      // fonction initialisation 
{
    int ierr;
    RTIME now;

    init_can();
    dac_init();     // initialisation module DAC
    adc_init();     // initialisation module ADC

    adc_set_range(0,0); //-10/10
    adc_set_range(1,8); // -5/5

    adc_scan_chan(0x10);

    rt_set_oneshot_mode();      // mode oneshot

    // Creation de la tache periodique
    ierr = rt_task_init(&tache_acq,acq_capteurs,0,STACK_SIZE,PRIORITE,1,0);
    ierr = rt_task_init(&tache_emit,emission_capteurs,0,STACK_SIZE,PRIORITE+1,1,0);
    ierr = rt_task_init(&tache_recup,recup_cmd,0,STACK_SIZE,PRIORITE+2,1,0);

    start_rt_timer(nano2count(TICK_PERIOD));
    now = rt_get_time();

    // lancement tache periodique
    rt_task_make_periodic(&tache_acq,now,nano2count(PERIODE_CONTROL));
    rt_task_make_periodic(&tache_emit,now,nano2count(PERIODE_CONTROL+50));
    rt_task_make_periodic(&tache_recup,now,nano2count(PERIODE_CONTROL+100));

    return 0;
}

static void task_exit(void)
{
    dac_output(0,2048);
    dac_off();
    stop_rt_timer();
    rt_task_delete(&tache_acq);
    rt_task_delete(&tache_emit);
    rt_task_delete(&tache_recup);
}

module_init(task_init);
module_exit(task_exit);
