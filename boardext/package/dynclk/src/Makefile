# Hardware specific drivers go first
obj-m += dynclk_drv.o

all:
	$(MAKE) -C $(KDIR) M=$(PWD)

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

