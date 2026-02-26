# Top-level Makefile
TARGET ?= xlnx_video

ARCH ?= arm
CROSS_COMPILE=arm-linux-gnueabihf-

V_COMMON=v_common
V_VIDC=v_vidc
V_VTC=v_vtc
V_TPG=v_tpg
V_DYNCLK=v_dynclk
V_FRMBUF_RD=v_frmbuf_rd
V_FRMBUF_WR=v_frmbuf_wr
_NETLINK=_netlink
include $(CURDIR)/v_common/Makefile
include $(CURDIR)/v_vidc/Makefile
include $(CURDIR)/v_vtc/Makefile
include $(CURDIR)/v_tpg/Makefile
include $(CURDIR)/v_dynclk/Makefile
include $(CURDIR)/v_frmbuf_rd/Makefile
include $(CURDIR)/v_frmbuf_wr/Makefile
include $(CURDIR)/_netlink/Makefile

CFLAGS += -Wall -Wextra -g -Wno-implicit-fallthrough
CFLAGS += -I$(CURDIR) \
	-I$(CURDIR)/include \
	-I$(CURDIR)/v_common \
	-I$(CURDIR)/v_vidc  \
	-I$(CURDIR)/v_vtc \
	-I$(CURDIR)/v_tpg \
	-I$(CURDIR)/v_dynclk \
	-I$(CURDIR)/v_frmbuf_rd \
	-I$(CURDIR)/v_frmbuf_wr \
	-I$(CURDIR)/_netlink
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

O_SOURCES = $(shell find . -name "*.o")

O_OBJ = xlnx_video.o \
	_xl_vtc.o \
	_xl_tpg.o \
	v_vtc/xvtc_selftest.o \
	v_vtc/xvtc_g.o \
	v_vtc/xvtc_sinit.o \
	v_vtc/xvtc.o \
	v_vtc/xvtc_intr.o \
	v_tpg/xv_tpg_intr.o \
	v_tpg/xv_tpg.o \
	v_tpg/xv_tpg_g.o \
	v_tpg/xv_tpg_sinit.o \
	v_vidc/xvidc_parse_edid.o \
	v_vidc/xvidc_edid.o \
	v_vidc/xvidc_timings_table.o \
	v_vidc/xvidc_edid_ext.o \
	v_vidc/xvidc.o \
	v_dynclk/ddynclk_g.o \
	v_dynclk/ddynclk_selftest.o \
	v_dynclk/ddynclk_sinit.o \
	v_dynclk/ddynclk.o \
	v_frmbuf_rd/xv_frmbufrd_g.o \
	v_frmbuf_rd/xv_frmbufrd_l2_intr.o \
	v_frmbuf_rd/xv_frmbufrd_l2.o \
	v_frmbuf_rd/xv_frmbufrd_sinit.o \
	v_frmbuf_rd/xv_frmbufrd.o \
	v_frmbuf_wr/xv_frmbufwr_g.o \
	v_frmbuf_wr/xv_frmbufwr_l2_intr.o \
	v_frmbuf_wr/xv_frmbufwr_l2.o \
	v_frmbuf_wr/xv_frmbufwr_sinit.o \
	v_frmbuf_wr/xv_frmbufwr.o \
	v_common/xil_assert.o \
	v_common/xversion.o \
	v_common/xutil_memtest.o \
	v_common/xbasic_types.o	\
	_netlink/_netlink.o	\


.PHONY: clean all
all: $(V_COMMON) $(V_VIDC) $(V_VTC) $(V_TPG) \
		$(V_DYNCLK) $(V_DYNCLK) $(V_FRMBUF_RD) $(V_FRMBUF_WR) $(_NETLINK) \
		$(TARGET) finalize allobj

$(TARGET): $(V_COMMON) $(V_VIDC) $(V_VTC) $(V_TPG) $(V_DYNCLK) $(V_FRMBUF_RD) $(V_FRMBUF_WR) $(_NETLINK) $(OBJECTS)
	@echo "Compilation of XLNX_VIDEO files complete."

%.o: %.c
	@echo "-------------------------------------------------"
	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@


allobj: finalize
	@echo "============================Object files: $(O_OBJ)"
	$(CROSS_COMPILE)gcc $(CFLAGS) $(O_OBJ) -o $(TARGET)

finalize: $(TARGET)
	@echo "--------Application created!---------."
#	$(CROSS_COMPILE)gcc $(CFLAGS) $(OBJECTS) -o $(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)

#$(CROSS_COMPILE)gcc $(CFLAGS) $(OBJECTS) -o $(TARGET)
#$(CROSS_COMPILE)gcc $(CFLAGS) $^ -o $@