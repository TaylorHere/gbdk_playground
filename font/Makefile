AS	= /Users/taylor/sdk/gbz80-gb/2.1.5/bin/as
CC	= /Users/taylor/sdk/gbz80-gb/2.1.5/bin/lcc 
BIN = font.gb
OBJS = font.o

all: $(BIN)

%.s: %.ms
	maccer -o $@ $<

$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	rm -rf $(BIN) $(OBJS) *~
