_NETLINK_SRC=$(wildcard $(CURDIR)/_netlink/*.c)
_NETLINK_OBJECTS=$(_NETLINK_SRC:.c=.o)
_netlink: $(_NETLINK_OBJECTS)
	@echo "Compilation of _NETLINK files complete."

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@

#clean:
#	rm -f *.o
