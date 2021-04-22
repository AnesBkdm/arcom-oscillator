#include<linux/init.h>
#include<linux/module.h>

#include <asm/io.h>
#include <asm/irq.h>
#include <rtai.h>
#include <rtai_sched.h>
#include <rtai_fifos.h>

MODULE_LICENSE("GPL");

#define BASE (0x300)            	// Base address DAC
#define CHAN0_LOW (BASE)        	// Channel 0 LSB
#define CHAN0_HIGH (BASE+1)     	// Channel 0 MSB
#define CHAN1_LOW (BASE+2)      	// Channel 1 LSB
#define CHAN1_HIGH (BASE+3)     	// Channel 1 MSB
#define SYNC_CONTROL (BASE+4)   	// Sync control enable
#define OUTPUT_CONTROLE (BASE+5) 	// Output/channel enable


u8 dac_lsb;
u8 dac_msb;

/////////////////////////////
//        DAC init         //
/////////////////////////////

void dac_init(void) 			
{
 	outb(0x00,CHAN0_LOW);      		
 	outb(0x00,CHAN0_HIGH);     		
 	outb(0x00,CHAN1_LOW);      		
 	outb(0x00,CHAN1_HIGH);     		
 	outb(0x80,OUTPUT_CONTROLE);		// Output enable
}

/////////////////////////////
//         DAC out         //
/////////////////////////////

void dac_output(int channel, u16 value) 
{
 	if(channel == 0) {
	  	dac_lsb = 0x00FF & value;      	// Fetching LSB
	  	dac_msb = value >> 8;         	// Fetching MSB
	  	outb(dac_lsb,CHAN0_LOW);       	// Loading LSB in register
	  	outb(dac_msb,CHAN0_HIGH);     	// Loading MSB in register
 	}

 	else {
	  	dac_lsb = 0x00FF & value;      	// Fetching LSB
	  	dac_msb = value >> 8;         	// Fetching MSB
	  	outb(dac_msb,CHAN1_HIGH);     	// Loading MSB in register
	  	outb(dac_lsb,CHAN1_LOW);       	// Loading LSB in register
	  
 	}
}

EXPORT_SYMBOL(dac_init);
EXPORT_SYMBOL(dac_output);