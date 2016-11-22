CC = cc
CFLAGS = -W -Wall -g

SRC_PATH = src/
HEADER_PATH = header/
BIN_PATH = bin/

EXEC = main

all: $(EXEC)

$(EXEC): $(BIN_PATH)mmu.o
	$(CC) $(CFLAGS) -o $(EXEC) $(BIN_PATH)mmu.o

mmu.o : $(HEADER_PATH)mmu.h

$(BIN_PATH)%.o: $(SRC_PATH)%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LFLAGS)

clean:
	@rm -f $(BIN_PATH)*.o

mrproper: clean
	rm -rf $(EXEC)
