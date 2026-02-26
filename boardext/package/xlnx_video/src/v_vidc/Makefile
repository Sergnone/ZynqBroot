V_VIDC_SRC=$(wildcard $(CURDIR)/v_vidc/*.c)
V_VIDC_OBJECTS=$(V_VIDC_SRC:.c=.o)
v_vidc: $(V_VIDC_OBJECTS)
	@echo "Compilation of V_VIDC files complete."

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@

#clean:
#	rm -f *.o
