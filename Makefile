#########
#
# The top level targets link in the two .o files for now.
#
TARGETS += rgb-test
TARGETS += helmet

LEDSCAPE_OBJS = ledscape.o pru.o util.o lib/cesanta/frozen.o lib/cesanta/mongoose.o
LEDSCAPE_LIB := libedscape.a  # Looks better as '-ledscape' than '-lledscape' :-)

all: $(LEDSCAPE_LIB) $(TARGETS) dmx_0.bin ws2801_0.bin ws2801_1.bin ws281x_0.bin ws281x_1.bin


ifeq ($(shell uname -m),armv7l)
# We are on the BeagleBone Black itself;
# do not cross compile.
export CROSS_COMPILE:=
else
# We are not on the BeagleBone and might be cross compiling.
# If the environment does not set CROSS_COMPILE, set our
# own.  Install a cross compiler with something like:
#
# sudo apt-get install gcc-arm-linux-gnueabi
#
export CROSS_COMPILE?=arm-linux-gnueabi-
endif

CFLAGS += \
	-W \
	-Wall \
	-D_BSD_SOURCE \
	-Wp,-MMD,$(dir $@).$(notdir $@).d \
	-Wp,-MT,$@ \
	-I. \
	-I/usr/bonelib/include \
	-O2 \
	-lm \
	-mtune=cortex-a8 \
	-march=armv7-a \
	-Wunused-parameter \
	-DNS_ENABLE_IPV6

LDFLAGS += \
	   -L. \
	   -L/usr/bonelib/lib \

LDLIBS += \
	  -lbone \
	  -lpthread \

COMPILE.cpp = $(CROSS_COMPILE)g++ $(CFLAGS) -std=c++11 -c -o $@ $<
COMPILE.o = $(CROSS_COMPILE)gcc -std=c99 $(CFLAGS) -c -o $@ $<
COMPILE.a = ar cr $@
COMPILE.link = $(CROSS_COMPILE)gcc $(LDFLAGS) -o $@ $^ $(LDLIBS)

#####
#
# The TI "app_loader" is the userspace library for talking to
# the PRU and mapping memory between it and the ARM.
#
APP_LOADER_DIR ?= ./am335x/app_loader
APP_LOADER_LIB := $(APP_LOADER_DIR)/lib/libprussdrv.a
CFLAGS += -I$(APP_LOADER_DIR)/include
LDLIBS += $(APP_LOADER_LIB) -lm

#####
#
# The TI PRU assembler looks like it has macros and includes,
# but it really doesn't.  So instead we use cpp to pre-process the
# file and then strip out all of the directives that it adds.
# PASM also doesn't handle multiple statements per line, so we
# insert hard newline characters for every ; in the file.
#
PASM_DIR ?= ./am335x/pasm
PASM := $(PASM_DIR)/pasm

%.bin: %.p $(PASM)
	$(CPP) - < $< | perl -p -e 's/^#.*//; s/;/\n/g; s/BYTE\((\d+)\)/t\1/g' > $<.i
	$(PASM) -V3 -b $<.i $(basename $@)
	$(RM) $<.i

%.o: %.c
	$(COMPILE.o)

%.o: %.cpp
	$(COMPILE.cpp)

$(foreach O,$(TARGETS),$(eval $O: $O.o $(LEDSCAPE_OBJS) $(APP_LOADER_LIB)))


$(LEDSCAPE_LIB): $(LEDSCAPE_OBJS)
	$(COMPILE.a) $(LEDSCAPE_OBJS)

rgb-test:
	$(COMPILE.link)

helmet:
	g++ -o $@ $< $(LDFLAGS) -ledscape $(LDLIBS)

SHOWTIMEOBJS = showtime.o helmet_draw.o smiley.o
showtime: $(SHOWTIMEOBJS) $(LEDSCAPE_LIB)
	g++ -o $@ $(LDFLAGS) $(SHOWTIMEOBJS) -ledscape $(LDLIBS)


.PHONY: clean

clean:
	rm -rf \
		*.o *.a \
		*.i \
		.*.swo .*.swp .*.o.d \
		*~ \
		$(INCDIR_APP_LOADER)/*~ \
		$(TARGETS) \
		*.bin \
		lib/cesanta/.*.o.d \
		lib/cesanta/*.i \
		lib/cesanta/*.o

###########
#
# The correct way to reserve the GPIO pins on the BBB is with the
# capemgr and a Device Tree file.  But it doesn't work.
#
SLOT_FILE=/sys/devices/bone_capemgr.8/slots
dts: LEDscape.dts
	@SLOT="`grep LEDSCAPE $(SLOT_FILE) | cut -d: -f1`"; \
	if [ ! -z "$$SLOT" ]; then \
		echo "Removing slot $$SLOT"; \
		echo -$$SLOT > $(SLOT_FILE); \
	fi
	dtc -O dtb -o /lib/firmware/BB-LEDSCAPE-00A0.dtbo -b 0 -@ LEDscape.dts
	echo BB-LEDSCAPE > $(SLOT_FILE)


###########
#
# PRU Libraries and PRU assembler are build from their own trees.
#
$(APP_LOADER_LIB):
	$(MAKE) -C $(APP_LOADER_DIR)/interface

$(PASM):
	$(MAKE) -C $(PASM_DIR)

# Include all of the generated dependency files
-include .*.o.d
