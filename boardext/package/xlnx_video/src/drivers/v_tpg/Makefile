V_TPG_SRC=$(wildcard $(CURDIR)/drivers/v_tpg/*.c)
V_TPG_OBJECTS=$(V_TPG_SRC:.c=.o)
v_tpg: $(V_TPG_OBJECTS)
	@echo "Compilation of V_TPG files complete."

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@

