V_STDALN_SRC=$(wildcard $(CURDIR)/drivers/standalone/*.c)
V_STDALN_OBJECTS=$(V_STDALN_SRC:.c=.o)
v_stdaln: $(V_STDALN_OBJECTS)
	@echo "Compilation of V_STDALN files complete."

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@
