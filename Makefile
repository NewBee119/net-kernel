obj-m := hello.o
KDIR := /home/ker/Desktop/kernel/linux-2.6.36
PWD := $(shell pwd)
CROS := /home/ker/x-tools/mipsel-unknown-linux-uclibc/bin/mipsel-unknown-linux-uclibc-
all:
	$(MAKE) -C $(KDIR) ARCH=mips SUBDIRS=$(PWD) CROSS_COMPILE=$(CROS)
clean:
	rm *o
