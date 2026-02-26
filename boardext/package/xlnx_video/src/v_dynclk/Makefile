V_DYNCLK_SRC=$(wildcard $(CURDIR)/v_dynclk/*.c)
V_DYNCLK_OBJECTS=$(V_DYNCLK_SRC:.c=.o)
v_dynclk: $(V_DYNCLK_OBJECTS)
	@echo "Compilation of V_DYNCLK files complete."

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@

#clean:
#	rm -f *.o
