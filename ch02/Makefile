obj-m += hello-world.o
KDIR = /usr/src/linux-meta-5.4.0.88.92

all:
	make -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod.* *.sysvers *.order
