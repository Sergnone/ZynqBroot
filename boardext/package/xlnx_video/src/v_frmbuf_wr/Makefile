V_FRMBUF_WR_SRC=$(wildcard $(CURDIR)/v_frmbuf_wr/*.c)
V_FRMBUF_WR_OBJECTS=$(V_FRMBUF_WR_SRC:.c=.o)
v_frmbuf_wr: $(V_FRMBUF_WR_OBJECTS)
	@echo "Compilation of V_FRMBUFWR files complete."

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@

#clean:
#	rm -f *.o
