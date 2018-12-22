CC=g++
CFLAGS=-Wall
MAINBIN=tarea3
MAINOBJ=main.o List.o Interprete.o


all: $(MAINBIN)

$(MAINBIN): $(MAINOBJ)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp List.hpp Interprete.hpp
	$(CC) $(CFLAGS) -c $<

List.o: List.cpp List.hpp
	$(CC) $(CFLAGS) -c $<

Interprete.o: Interprete.cpp Interprete.hpp
	$(CC) $(CFLAGS) -c $<