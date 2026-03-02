V_GPIOPS_SRC=$(wildcard $(CURDIR)/drivers/v_gpiops/*.c)
V_GPIOPS_OBJECTS=$(V_GPIOPS_SRC:.c=.o)
v_gpiops: $(V_GPIOPS_OBJECTS)
	@echo "Compilation of V_GPIOPS files complete."

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@

#clean:
#	rm -f *.o
