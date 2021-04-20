#ifndef BUS_CAN_H
#define BUS_CAN_H

void init_can(void);
void reception(int id,u8* rx_msg);
void emission(u16 id,u8* data,u8 length);


#endif