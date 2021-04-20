obj-m	   := adc.o dac.o controle.o bus_can.o main_prog.o

PATH := /opt/x86_64/gcc/gcc-3.4.4/bin:$(PATH)
KIT = arcom12.esiee.fr
CURRENT = 2.6.16.14-arcom1
KDIR = /usr/lib/arcom/lib/modules/${CURRENT}/build
PWD = $(shell pwd)
EXTRA_CFLAGS += -I/usr/lib/arcom/realtime/include -Wall -ffast-math -mhard-float
default:
	@echo --------------------------------------
	@echo PWD = $(PWD)
	@echo CURRENT = $(CURRENT)
	@echo KDIR = $(KDIR)
	i386 -B --uname-2.6 make -C $(KDIR) M=$(PWD) modules

clean:
	-rm -f *.o squelette*.ko .*.cmd .*.flags *.mod.c *~
	-rm -r .tmp*
send:
	scp *.ko runarcom arcom@$(KIT):/home/arcom
	ssh arcom@$(KIT)
