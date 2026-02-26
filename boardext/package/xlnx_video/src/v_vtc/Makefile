V_VTC_SRC=$(wildcard $(CURDIR)/v_vtc/*.c)
V_VTC_OBJECTS=$(V_VTC_SRC:.c=.o)
v_vtc: $(V_VTC_OBJECTS)
	@echo "Compilation of V_VTC files complete."

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@

#clean:
#	rm -f *.o
