int adc_init(void);
void adc_scan_chan(u8 channel);
void adc_set_range(int channel,int range);
u16 adc_readADC(int channel);
int idle_adc(void);
