V_COMMON_SRC=$(wildcard $(CURDIR)/v_common/*.c)
V_COMMON_OBJECTS=$(V_COMMON_SRC:.c=.o)
v_common: $(V_COMMON_OBJECTS)
	@echo "Compilation of V_COMMON files complete."

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@

#clean:
#	rm -f *.o
