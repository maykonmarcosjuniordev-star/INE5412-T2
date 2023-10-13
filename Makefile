# Variáveis do compilador
CC = g++
CFLAGS = -Wall -Wextra -Werror -O3

# Nome do executável
TARGET = simulador

# Lista de arquivos objeto
OBJS = main.o OPT.o FIFO.o LRU.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp OPT.hpp FIFO.hpp LRU.hpp
	$(CC) $(CFLAGS) -c $< -o $@

OPT.o: OPT.cpp OPT.hpp
	$(CC) $(CFLAGS) -c $< -o $@

FIFO.o: FIFO.cpp FIFO.hpp
	$(CC) $(CFLAGS) -c $< -o $@

LRU.o: LRU.cpp LRU.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
