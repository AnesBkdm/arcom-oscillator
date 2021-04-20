//////////ARCOM2//////////
#include<linux/init.h>
#include<linux/module.h>

#include <asm/io.h>
#include <asm/irq.h>
#include <rtai.h>
#include <rtai_sched.h>
#include <rtai_fifos.h>

#include "bus_can.h"
#include "controle.h"
#include "dac.h"
#include "adc.h"


MODULE_LICENSE("GPL");

#define STACK_SIZE 2000
#define TICK_PERIOD 1000000         // 1 ms
#define PERIODE_CONTROL 10000000    // 20 ms
#define PRIORITE 1

// RT task
static RT_TASK tache_cmd, tache_acq;
void recup_capteurs(u8* cpt_data);

RTIME time_count;
u8 data_p1[4];
u8 data_p2[4];
u16 commande;
u8  commande_calcul[2];
int position;
int theta;

///////////////////Pendule 1
void can_reception_commande(long arg)
{
    while(1)
    {
        reception(5,data_p1);
        theta = (data_p1[0] << 8) + data_p1[1];
        position = (data_p1[2] << 8) + data_p1[3];
        commande = calcul_commande(position,theta);
        commande_calcul[0] = ((commande & 0xFF00)>>8);
        commande_calcul[1] = commande & 0x00FF;
        //printk("\ncommande calculee : %d\n",(int)((commande_calcul[0] << 8) + commande_calcul[1]));
        emission(6,commande_calcul,2);
        rt_task_wait_period();
    }
}
///////////////////////Fin pendule 1

//////////////////////Pendule 2
void acq_capteurs(long arg)
{
    while(1)
    {
        recup_capteurs(data_p2);
        printk("\ncapteur acq p2 theta = %d et pos = %d\n",(int) ((data_p2[0])<<8+data_p2[1]),(int) ((data_p2[2])<<8+data_p2[3]));
        emission(7,data_p2,4);
        rt_task_wait_period();
    }
}

void recup_capteurs(u8* cpt_data)
{
        u16 dac_value,dac_value2;
	if(idle_adc() == 1)
	{
		//time_count = rt_get_time();
		dac_value = adc_readADC(0);  // lecture valeur convertie ADC angle
	}
	int i;
	for(i=0;i<100;i++);
	//printk("\ntemps for : %d\n",(int)count2nano(rt_get_time()-time_count));
	while(idle_adc() == 0);

	if(idle_adc() == 1)
	{
		dac_value2 = adc_readADC(1);  // lecture valeur convertie ADC position
	}
	
	cpt_data[0] = ((dac_value & 0xFF00)>>8);
	cpt_data[1] = dac_value & 0x00FF;
        cpt_data[2] = ((dac_value2 & 0xFF00)>>8);
	cpt_data[3] = dac_value2 & 0x00FF;
}
///////////////////////Fin pendule 2

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

    //
    rt_set_oneshot_mode();      // mode oneshot

    // Creation de la tache periodique
    // Pendule 1
    ierr = rt_task_init(&tache_cmd,can_reception_commande,0,STACK_SIZE,PRIORITE,1,0);
    // Pendule 2
    ierr = rt_task_init(&tache_acq,acq_capteurs,0,STACK_SIZE,PRIORITE+1,1,0);

    start_rt_timer(nano2count(TICK_PERIOD));
    now = rt_get_time();

    // lancement tache periodique
    rt_task_make_periodic(&tache_cmd,now,nano2count(PERIODE_CONTROL));
    rt_task_make_periodic(&tache_acq,now,nano2count(PERIODE_CONTROL+100));

    return 0;
}

static void task_exit(void)
{
    
    stop_rt_timer();
    rt_task_delete(&tache_cmd);
    rt_task_delete(&tache_acq);
    
}

module_init(task_init);
module_exit(task_exit);
