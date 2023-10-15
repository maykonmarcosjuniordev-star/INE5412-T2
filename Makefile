# Variables for the compiler
CC = g++
CFLAGS = -Wall -Wextra -Werror -O3

# Name of the executable
TARGET = simulador

# List of object files
OBJS = main.o Simulator.o OPT.o FIFO.o LRU.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

main.o : main.cpp Simulator.hpp
	$(CC) $(CFLAGS) -c $< -o $@

Simulator.o: Simulator.cpp Simulator.hpp OPT.hpp FIFO.hpp LRU.hpp
	$(CC) $(CFLAGS) -c $< -o $@

OPT.o: OPT.cpp OPT.hpp
	$(CC) $(CFLAGS) -c $< -o $@

FIFO.o: FIFO.cpp FIFO.hpp
	$(CC) $(CFLAGS) -c $< -o $@

LRU.o: LRU.cpp LRU.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
