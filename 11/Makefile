objects = rectangle.o main.o

CC = g++
CFLAGS = -Wall

main : rectangle.o main.o
	$(CC) $(CFLAGS) -o $@ rectangle.o main.o

rectangle.o : rectangle.cpp rectangle.h
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY : clean
clean :
	rm -f $(objects) main
