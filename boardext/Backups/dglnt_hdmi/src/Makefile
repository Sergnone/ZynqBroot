# Hardware specific drivers go first
obj-m += dglnt_hdmi.o

all:
	$(MAKE) -C $(KDIR) M=$(PWD)

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

