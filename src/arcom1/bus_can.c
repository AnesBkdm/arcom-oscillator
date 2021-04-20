#include<linux/init.h>
#include<linux/module.h>

#include <asm/io.h>
#include <asm/irq.h>
#include <rtai.h>
#include <rtai_sched.h>
#include <rtai_fifos.h>

MODULE_LICENSE("GPL");

#define base				0x180
#define CAN_CONTROL 		base
#define CAN_COMMAND 		(base+1)
#define CAN_STATUS 			(base+2)
#define CAN_INTERRUPT 		(base+3)
#define CAN_ACCEPTANCE_CODE	(base+4)
#define CAN_ACCEPTANCE_MASK	(base+5)
#define CAN_BUS_TIMING_0	(base+6)
#define CAN_BUS_TIMING_1	(base+7)
#define CAN_OUTPUT_CTRL		(base+8)
#define CAN_TEST			(base+9)
#define CAN_TX_IDENTIFIER	(base+10)
#define CAN_TX_RTB_BIT		(base+11)
#define CAN_TX_BUFFER		(base+12)
#define CAN_RX_IDENTIFIER	(base+20)
#define CAN_RX_RTB_BIT		(base+21)
#define CAN_RX_BUFFER		(base+22)

/////////////////////////////
//       CAN bus init      //
/////////////////////////////

void init_can(void) 
{
	outb(0x01,CAN_CONTROL);				// Reset
	outb(0x04,CAN_COMMAND);				// Freeing receive buffer
	outb(0xFF,CAN_ACCEPTANCE_CODE);		// Acceptance of all msg
	outb(0xFF,CAN_ACCEPTANCE_MASK);		// Acceptance of all msg
	outb(0x03,CAN_BUS_TIMING_0);		// Transfer speed
	outb(0x1C,CAN_BUS_TIMING_1);		// Transfer speed
	outb(0xFA,CAN_OUTPUT_CTRL);			// Init output to normal mode
	outb(0x00,CAN_CONTROL);				// No interrupt
}

/////////////////////////////
//   Receiving sequence    //
/////////////////////////////

void reception(int id,u8* rx_msg)
{	
	int rx_size;
	u16 rx_id;
	int j;
	
	if(inb(CAN_STATUS) && 0x01){												// If LSB = 1, a msg is waiting to be received

		rx_id = (inb(CAN_RX_IDENTIFIER) << 3) + (inb(CAN_RX_RTB_BIT) >> 5);		// Fetching the ID of the received message
		
		if((rx_id == id) || (id == 0)){											// Checking if it is the right msg
			rx_size = (inb(CAN_RX_RTB_BIT)) & 0x0F ;							// Fetching msg size	

			for(j=0; j < rx_size; j++){											
				rx_msg[j] = inb(CAN_RX_BUFFER+j);								// Fetching msg in u8 array
			}
			
			outb(0x04,CAN_COMMAND);												// Clearing buffer
		}
	}
}	

/////////////////////////////
//     Sending sequence    //
/////////////////////////////

void emission(u16 id,u8* data,u8 length)
{
	u8 id_p1 = id >> 3;
	u8 id_p2 = ((id & 0x0007) << 5) | length & 0x0F;

	int i;

	outb(id_p1,CAN_TX_IDENTIFIER);				// Writing ID on TX
	outb(id_p2,CAN_TX_RTB_BIT);					// Writing msg on TX
	
	if(inb(CAN_STATUS) && 0x04){				// Checking if send buffer is free	
		for(i=0 ; i<length ; i++){				
			outb(data[i], CAN_TX_BUFFER+i);		// Writing message from buffer
		}
		
		if(inb(CAN_STATUS) && 0x08){			// Checking if message have been received by controller
			outb(0x01,CAN_COMMAND);				// Sending to destination
		}
	}
}

EXPORT_SYMBOL(init_can);
EXPORT_SYMBOL(reception);
EXPORT_SYMBOL(emission);

