# Top-level Makefile
TARGET ?= xlnx_video

ARCH ?= arm
CROSS_COMPILE=arm-linux-gnueabihf-

V_COMMON=v_common
V_DYNCLK=v_dynclk
V_VIDC=v_vidc
V_VTC=v_vtc
V_TPG=v_tpg
V_FRMBUF_RD=v_frmbuf_rd
V_FRMBUF_WR=v_frmbuf_wr
V_GPIOPS=v_gpiops
V_MIX=v_mix
V_STDALN=v_stdaln
V_SCUGIC=v_scugic
include $(CURDIR)/drivers/v_common/Makefile
include $(CURDIR)/drivers/v_dynclk/Makefile
include $(CURDIR)/drivers/v_vidc/Makefile
include $(CURDIR)/drivers/v_vtc/Makefile
include $(CURDIR)/drivers/v_gpiops/Makefile
include $(CURDIR)/drivers/v_tpg/Makefile
include $(CURDIR)/drivers/v_frmbuf_rd/Makefile
include $(CURDIR)/drivers/v_frmbuf_wr/Makefile
include $(CURDIR)/drivers/v_mix/Makefile
include $(CURDIR)/drivers/standalone/Makefile
include $(CURDIR)/drivers/scugic/Makefile

CFLAGS += -Wall -Wextra -g -Wno-implicit-fallthrough
CFLAGS += -I$(CURDIR) \
	-I$(CURDIR)/_commons \
	-I$(CURDIR)/include \
	-I$(CURDIR)/drivers/v_common \
	-I$(CURDIR)/drivers/v_dynclk \
	-I$(CURDIR)/drivers/v_vidc  \
	-I$(CURDIR)/drivers/v_vtc \
	-I$(CURDIR)/drivers/v_gpiops \
	-I$(CURDIR)/drivers/v_tpg \
	-I$(CURDIR)/drivers/v_frmbuf_rd \
	-I$(CURDIR)/drivers/v_frmbuf_wr \
	-I$(CURDIR)/drivers/v_mix \
	-I$(CURDIR)/drivers/standalone \
	-I$(CURDIR)/drivers/scugic

SOURCES = $(wildcard _commons/*.c)
SOURCES += $(wildcard *.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

O_SOURCES = $(shell find . -name "*.o")

O_OBJ = xlnx_video.o \
    _commons/_xl_dynclk.o \
	_commons/_xl_gpio.o \
	_commons/_xl_vtc.o \
	_commons/_xl_tpg.o \
	_commons/_xl_fb_rd.o \
	_commons/_xl_fb_wr.o \
	_commons/_xl_vmix.o \
	drivers/v_dynclk/ddynclk_g.o \
	drivers/v_dynclk/ddynclk_selftest.o \
	drivers/v_dynclk/ddynclk_sinit.o \
	drivers/v_dynclk/ddynclk.o \
	drivers/v_gpiops/xgpiops_g.o \
	drivers/v_gpiops/xgpiops_hw.o \
	drivers/v_gpiops/xgpiops_intr.o \
	drivers/v_gpiops/xgpiops_selftest.o \
	drivers/v_gpiops/xgpiops_sinit.o \
	drivers/v_gpiops/xgpiops.o \
	drivers/v_vtc/xvtc_selftest.o \
	drivers/v_vtc/xvtc_g.o \
	drivers/v_vtc/xvtc_sinit.o \
	drivers/v_vtc/xvtc.o \
	drivers/v_vtc/xvtc_intr.o \
	drivers/v_tpg/xv_tpg_intr.o \
	drivers/v_tpg/xv_tpg.o \
	drivers/v_tpg/xv_tpg_g.o \
	drivers/v_tpg/xv_tpg_sinit.o \
	drivers/v_vidc/xvidc_parse_edid.o \
	drivers/v_vidc/xvidc_edid.o \
	drivers/v_vidc/xvidc_timings_table.o \
	drivers/v_vidc/xvidc_edid_ext.o \
	drivers/v_vidc/xvidc.o \
	drivers/v_frmbuf_rd/xv_frmbufrd_g.o \
	drivers/v_frmbuf_rd/xv_frmbufrd_l2_intr.o \
	drivers/v_frmbuf_rd/xv_frmbufrd_l2.o \
	drivers/v_frmbuf_rd/xv_frmbufrd_sinit.o \
	drivers/v_frmbuf_rd/xv_frmbufrd.o \
	drivers/v_frmbuf_wr/xv_frmbufwr_g.o \
	drivers/v_frmbuf_wr/xv_frmbufwr_l2_intr.o \
	drivers/v_frmbuf_wr/xv_frmbufwr_l2.o \
	drivers/v_frmbuf_wr/xv_frmbufwr_sinit.o \
	drivers/v_frmbuf_wr/xv_frmbufwr.o \
	drivers/v_mix/xv_mix_g.o \
	drivers/v_mix/xv_mix_l2_intr.o \
	drivers/v_mix/xv_mix_l2.o \
	drivers/v_mix/xv_mix_sinit.o \
	drivers/v_mix/xv_mix.o \
	drivers/standalone/xinterrupt_wrap.o \
	drivers/standalone/xplatform_info.o \
	drivers/scugic/xscugic_g.o \
	drivers/scugic/xscugic_hw.o \
	drivers/scugic/xscugic_intr.o \
	drivers/scugic/xscugic_selftest.o \
	drivers/scugic/xscugic_sinit.o \
	drivers/scugic/xscugic.o \
	drivers/v_common/xil_assert.o \
	drivers/v_common/xversion.o \
	drivers/v_common/xutil_memtest.o \
	drivers/v_common/xbasic_types.o	\
	reg_proc_usr.o
	

.PHONY: clean all
all: $(V_COMMON) $(V_VIDC) $(V_VTC) $(V_TPG) \
		$(V_DYNCLK) $(V_DYNCLK) $(V_FRMBUF_RD) $(V_FRMBUF_WR) \
		$(V_GPIOPS) $(V_MIX) $(V_STDALN) $(V_SCUGIC) \
		$(TARGET) finalize allobj

$(TARGET): $(V_COMMON) $(V_VIDC) $(V_VTC) $(V_TPG) \
	$(V_DYNCLK) $(V_FRMBUF_RD) $(V_FRMBUF_WR) \
	$(V_GPIOPS) $(V_MIX) $(V_STDALN) $(V_SCUGIC) $(OBJECTS)
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