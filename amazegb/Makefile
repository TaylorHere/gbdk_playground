CC	= lcc -Wa-l -Wl-m

CFLAGS	= -DGBDK_2_COMPAT

BINS	= main

all:	$(BINS).gb

%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o:	%.s
	$(CC) $(CFLAGS) -c -o $@ $<

%.s:	%.c
	$(CC) $(CFLAGS) -S -o $@ $<

%.gb:	%.o
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o *.lst *.map *.gb *.sav

# Link file, and write 0x80 at position 0x143 in header
$(BINS).gb: $(BINS).o
	$(CC) $(CFLAGS) -Wl-yp0x143=0x80 -o $(BINS).gb $(BINS).o
