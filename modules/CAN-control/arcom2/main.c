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


MODULE_LICENSE("GPL");

#define STACK_SIZE 2000
#define TICK_PERIOD 1000000         // 1 ms
#define PERIODE_CONTROL 10000000    // 20 ms
#define PRIORITE 1

// RT task
static RT_TASK tache_cmd, tache_send;

RTIME time_count;
u8 data[8];
u16 commande;
u8  commande_send[2];
u8  commande_calcul[2];
int position;
int theta;

/*
void main_fn(long arg)  // fonction principale
{
    while(1)
    {  
        reception(8,data);
        theta = data[0] + data[1];
        position = data[2] + data[3];
        //printk("\ncapteur recus theta = %d et pos = %d\n",(int) theta,(int) position);
        commande = calcul_commande(position,theta);

        commande_send[0] = ((commande & 0xFF00)>>8);
        commande_send[1] = commande & 0x00FF;
        //printk("\ncommande = %d\n",(int) commande_send[0] + commande_send[1]);
        emission(7,commande_send,2);
        rt_task_wait_period();      // attente periode de la tache
    }
}
*/
void can_reception_commande(long arg)
{
    while(1)
    {
        reception(8,data);
        theta = (data[0] << 8) + data[1];
        position = (data[2] << 8) + data[3];
        commande = calcul_commande(position,theta);
        commande_calcul[0] = ((commande & 0xFF00)>>8);
        commande_calcul[1] = commande & 0x00FF;
        commande_send[0] = commande_calcul[0];
        commande_send[1] = commande_calcul[1];
        rt_task_wait_period();
    }
}

void can_emission(long arg)
{
   while(1)
    {
        printk("\ncommande calculee : %d\n",(int)((commande_send[0] << 8) + commande_send[1]));
        emission(7,commande_send,2);
        rt_task_wait_period();
    }
}

static int task_init(void)      // fonction initialisation 
{
    int ierr;
    RTIME now;

	init_can();

    //
    rt_set_oneshot_mode();      // mode oneshot

    // Creation de la tache periodique
    ierr = rt_task_init(&tache_cmd,can_reception_commande,0,STACK_SIZE,PRIORITE,1,0);
    ierr = rt_task_init(&tache_send,can_emission,0,STACK_SIZE,PRIORITE+1,1,0);

    start_rt_timer(nano2count(TICK_PERIOD));
    now = rt_get_time();

    // lancement tache periodique
    rt_task_make_periodic(&tache_cmd,now,nano2count(PERIODE_CONTROL));
    rt_task_make_periodic(&tache_send,now,nano2count(PERIODE_CONTROL+10));

    return 0;
}

static void task_exit(void)
{
    
    stop_rt_timer();
    rt_task_delete(&tache_cmd);
    rt_task_delete(&tache_send);
    
}

module_init(task_init);
module_exit(task_exit);
