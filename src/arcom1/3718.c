#include<linux/init.h>
#include<linux/module.h>

#include <asm/io.h>
#include <asm/irq.h>
#include <rtai.h>
#include <rtai_sched.h>
#include <rtai_fifos.h>

MODULE_LICENSE("GPL");

#define BASE (0x320)            // Base address ADC
#define RD_LB (BASE)            // Reading the converted 4 LSB & channel #
#define WR_TRIGGER (BASE)       // Conversion trigger
#define RD_HB (BASE+1)          // Reading the converted 8 MSB
#define WR_RANGE (BASE+1)       // Output tension range select
#define WR_MUX_SCAN (BASE+2)    // Channel select
#define WR_DIO_LB (BASE+3)      // IO declaration LSB
#define WR_DIO_HB (BASE+11)     // IO declaration MSB
#define RD_STATUS (BASE+8)      // Reading status register
#define WR_CLR_INT (BASE+8)     // Clear interrup bit
#define WR_CONTROL (BASE+9)     // Control register init

int init_status = 0;

u8 EOC_bit;
u8 adc_lsb;
u8 adc_msb;
u16 rd_return;
u16 rd_return0; 
u16 rd_return1;


/////////////////////////////
//    ADC Initialization   //
/////////////////////////////

void adc_init(void)
{
    outb(0,WR_CONTROL);    
    outb(0x0F,WR_DIO_LB);  // Activating 4 LSB channels
    outb(0x00,WR_DIO_HB);  // Disable MSB channels
}

/////////////////////////////
//      Channel select     //
/////////////////////////////

void adc_scan_chan(u8 channel)
{
    outb(channel,WR_MUX_SCAN);     
}

/////////////////////////////
//       Range select      //
/////////////////////////////

void adc_set_range(int channel,int range)  
{
    outb(channel,WR_MUX_SCAN);              
    outb(range,WR_RANGE);           // Channel select, & then range select
}

/////////////////////////////
//       Idle check        //
/////////////////////////////

int idle_adc(void)
{
    EOC_bit = inb(RD_STATUS);

    if((EOC_bit >> 7) && 0x01){     // If not available, ADC returns 1
        return 0;
    } 

    else {
    return 1;
    }
}

/////////////////////////////
//         ADC read        //
/////////////////////////////

u16 adc_readADC(int channel)   
{
    outb(1,WR_TRIGGER);                             // Convertion start
    init_status = inb(RD_STATUS);                   // Status register read

    while((init_status&0x10) == 0x00){              // Conversion finish check
        init_status = inb(RD_STATUS);               // Reading til conversion finishes
    }

    outb(0,WR_CLR_INT);                             // Clearing interrupt (End of conversion)

    adc_lsb = inb(RD_LB);                            // Fetching LSB
    adc_msb = inb(RD_HB);                            // Fetching MSB

    if ((adc_lsb & 0x0F) == channel){
        rd_return = adc_msb;                         
        rd_return = (rd_return<<4) + (adc_lsb>>4);   // Assembling MSB & LSB
        
        if (channel == 0) {
            rd_return0 = rd_return;
        }

        else rd_return1 = rd_return;

        return rd_return;
    }

    else if (channel == 0){
        return rd_return0;
    }

    else 
        return rd_return1;
}

EXPORT_SYMBOL(adc_init);
EXPORT_SYMBOL(adc_scan_chan);
EXPORT_SYMBOL(adc_set_range);
EXPORT_SYMBOL(idle_adc);
EXPORT_SYMBOL(adc_readADC);
