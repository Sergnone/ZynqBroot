V_SCUGIG_SRC=$(wildcard $(CURDIR)/drivers/scugic/*.c)
V_SCUGIG_OBJECTS=$(V_SCUGIG_SRC:.c=.o)
v_scugic: $(V_SCUGIG_OBJECTS)
	@echo "Compilation of V_SCUGIC files complete."

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
