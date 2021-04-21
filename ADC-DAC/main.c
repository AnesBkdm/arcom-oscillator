#include<linux/init.h>
#include<linux/module.h>

#include <asm/io.h>
#include <asm/irq.h>
#include <rtai.h>
#include <rtai_sched.h>
#include <rtai_fifos.h>

#include "3712.h"
#include "3718.h"

MODULE_LICENSE("GPL");

#define STACK_SIZE 2000
#define TICK_PERIOD 1000000         // 1 ms
#define PERIODE_CONTROL 20000000    // 20 ms
#define PRIORITE 1

static RT_TASK tache_dac;

void dac(long arg);
static int task_init(void);
static void task_exit(void);

/////////////////////////////
//        Main fn          //
/////////////////////////////

void main_fn(long arg)  
{
  u16 dac_value = 0;
  u16 dac_value2 = 0;

  while(1)
  {  
    if(idle_adc() == 1){
      dac_value = adc_readADC(0);     // Reading converted value (ADC)
      dac_output(0,dac_value);        // Outputing value to DAC
    }

    rt_task_wait_period();            

    if(idle_adc() == 1){
    	dac_value2 = adc_readADC(1);   // Reading converted value (ADC)
    	dac_output(1,dac_value2);      // Outputing value to DAC
    }

    rt_task_wait_period();
  }

}

/////////////////////////////
//        RTAI init        //
/////////////////////////////

static int task_init(void)
{
  int ierr;
  RTIME now;

  dac_init();     
  adc_init();     

  adc_set_range(0,0); //-5-5
  adc_set_range(1,4); // 0-10

  adc_scan_chan(0x10);

  rt_set_oneshot_mode();      // Oneshot mode

  ierr = rt_task_init(&tache_dac,main_fn,0,STACK_SIZE,PRIORITE,1,0);

  start_rt_timer(nano2count(TICK_PERIOD));
  now = rt_get_time();

  rt_task_make_periodic(&tache_dac,now,nano2count(PERIODE_CONTROL));

  return 0;
}

/////////////////////////////
//        RTAI exit        //
/////////////////////////////

static void task_exit(void)
{
  stop_rt_timer();
  rt_task_delete(&tache_dac);
}

  module_init(task_init);
  module_exit(task_exit);
