# Top-level Makefile
TARGET ?= aoncv

ARCH ?= arm


#CROSS_COMPILE=arm-linux-gnueabihf-

CROSS_COMPILE=/tools/xilinx/2025.2/gnu/aarch32/lin/gcc-arm-linux-gnueabi/bin/arm-linux-gnueabihf-

CXXFLAGS += -Wall -Wextra -g -Wno-implicit-fallthrough
CXXFLAGS += -I$(CURDIR)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))

O_SOURCES = $(shell find . -name "*.o")
O_OBJ = aoncv.o

BDIR = $(CURDIR)/../..

OCV_BUILD = /build/opencv4-4.12.0

OPENCV_INC += -I$(BDIR)$(OCV_BUILD)/modules/core/include
OPENCV_INC += -I$(BDIR)$(OCV_BUILD)/modules/highgui/include
OPENCV_INC += -I$(BDIR)$(OCV_BUILD)/modules/imgproc/include
OPENCV_INC += -I$(BDIR)$(OCV_BUILD)/modules/imgcodecs/include
OPENCV_INC += -I$(BDIR)$(OCV_BUILD)/modules/videoio/include
OPENCV_INC += -I$(BDIR)$(OCV_BUILD)/buildroot-build
OPENCV_LIB = -L$(BDIR)$(OCV_BUILD)/buildroot-build/lib

OPENCV_LIB += -L$(BDIR)/host/arm-buildroot-linux-gnueabihf/lib

#OPENCV_INC_0 =/opencv2
#OPENCV_INC += $(OPENCV_INC_0)

# Add include path to CXXFLAGS using -I
CXXFLAGS += $(OPENCV_INC)

# Add library path to LDFLAGS using -L and specify libraries using -l
LDFLAGS += $(OPENCV_LIB) -lopencv_core \
	-lopencv_highgui \
	-lopencv_imgproc \
	-lopencv_imgcodecs \
	-lopencv_videoio

$(info    TOPDIR--------------- is $(BDIR))


.PHONY: clean all
all: $(TARGET) finalize allobj

$(TARGET):  $(OBJECTS)
	@echo "Compilation of OpenCV files complete."

%.o: %.cpp
	@echo "-------------------------------------------------"
	$(CROSS_COMPILE)g++ --sysroot -fopenmp $(CXXFLAGS) -c $< -o $@ $(LDFLAGS) -lz


allobj: finalize
	@echo "============================Object files: $(O_OBJ)"
	$(CROSS_COMPILE)g++ $(CXXFLAGS) $(LDFLAGS)  $(O_OBJ) -o $(TARGET) 

finalize: $(TARGET)
	@echo "--------Application created!---------."

clean:
	rm -f $(TARGET) $(OBJECTS)
