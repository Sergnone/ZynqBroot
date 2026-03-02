V_MIX_SRC=$(wildcard $(CURDIR)/drivers/v_mix/*.c)
V_MIX_OBJECTS=$(V_MIX_SRC:.c=.o)
v_mix: $(V_MIX_OBJECTS)
	@echo "Compilation of V_MIX files complete."

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@

#clean:
#	rm -f *.o
