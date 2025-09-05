CC=gcc
WCC=x86_64-w64-mingw32-gcc
WINE=wine
SRC=src/linux/main
WSRC=src/windows/main
DEPS=src/linux/include
WDEPS=src/windows/include
BUILD=build
SRS=$(SRC)/pilot.c $(SRC)/process.c
WSRS=$(WSRC)/pilot.c $(WSRC)/process.c

all: linux windows
linux: $(BUILD)/pilot
windows: $(BUILD)/pilot.exe
$(BUILD)/pilot: $(SRS) $(DEPS)/*.h $(BUILD)
	$(CC) -o $@ $(SRS) -g -I $(DEPS)
$(BUILD)/pilot.exe: $(WSRS) $(WDEPS)/*.h $(BUILD)
	$(WCC) -o $@ $(WSRS) -I $(WDEPS)
clean:
	rm -rf $(BUILD)
	rm -rf vgcore.*
	rm -rf *.exe
	rm -rf *.bin
$(BUILD):
	if ! [ -d $@ ]; then		\
		mkdir $@;		\
	fi
