V_FRMBUF_RD_SRC=$(wildcard $(CURDIR)/drivers/v_frmbuf_rd/*.c)
V_FRMBUF_RD_OBJECTS=$(V_FRMBUF_RD_SRC:.c=.o)
v_frmbuf_rd: $(V_FRMBUF_RD_OBJECTS)
	@echo "Compilation of V_FRMBUFRD files complete."

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@

#clean:
#	rm -f *.o
