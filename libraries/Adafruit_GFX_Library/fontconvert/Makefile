all: fontconvert

CC     = gcc
CFLAGS += -I/mingw64/include/freetype2/
LIBS   = -L/mingw64/lib -lfreetype

fontconvert: fontconvert.c
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)
	strip $@

clean:
	rm -f fontconvert