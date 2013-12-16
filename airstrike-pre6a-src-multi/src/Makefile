SH_LIB_PATH=../../Photon_libs

CFLAGS:= -g -O2 -Wall -Wno-unused $(OPTIONS)
# CFLAGS:=-g -O2 -Wall -Wno-unused -pthread $(OPTIONS)
#
# CFLAGS += $(shell sdl-config --cflags) -Isprite -I. -Isupport -I../enet/include -DINLINE=inline -lm -lfoo
CFLAGS += -I$(SH_LIB_PATH) -L$(SH_LIB_PATH)/Common-cpp -L$(SH_LIB_PATH)/Photon-cpp
CFLAGS += $(shell sdl-config --cflags) -Isprite -I. -Isupport -I../enet/include -DINLINE=inline -lm
# CFLAGS += -pthread -I../../Photon_libs
CFILES:= $(shell find . -name '*.c') 
# CFILES:= $(shell find . -type f \( -iname "*.c" ! -iname "airstrike.c" \)) 
OBJECTS_LIST:= $(CFILES:.c=.o)
OBJECTS:= $(CFILES:.c=.o) ./photon_arch1.o 
#./airstrike.o

airstrike: $(OBJECTS_LIST)
	# g++ $(CFLAGS) -pthread -lPhotonDebug32 -lCommonDebug32 -c airstrike.c -o airstrike.o
	g++ -o $@ $(CFLAGS) $(OBJECTS) `sdl-config --libs` -lSDL_image -lSDL_mixer -lm -lenet -pthread -lPhotonDebug32 -lCommonDebug32

airstrike-sound: $(OBJECTS)
	g++ -o $@ $(CFLAGS) $(OBJECTS) `sdl-config --libs` -lSDL_image -lSDL_mixer -lm -lenet -pthread -lPhotonDebug32 -lCommonDebug32

photon:
	g++ -I$(SH_LIB_PATH) -L$(SH_LIB_PATH)/Common-cpp -L$(SH_LIB_PATH)/Photon-cpp -pthread -lPhotonDebug32 -lCommonDebug32 -c -o photon_arch1.o photon_arch1.cpp

# Use the rule below when coding new sprite types
#sprites_autogen.h: sprite_types/*.c
#	../utils/genspritelist.sh $^

clean:
	rm -f `find . -name '*.[od]' -or -name '*~' -or -name '*.bb' -or -name '*.bbg'`

dryclean: 
	rm -f `find . -name '*.[^ch]' -type f` 

#Automatic dependency handling. This is not needed for a simple compile.

#include $(CFILES:.c=.d)
#
#%.d: %.c
#	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
#	sed 's,$(*F)\.o[ :]*,$(@:.d=.o) $@ : ,g' < $@.$$$$ > $@; \
#	rm -f $@.$$$$
