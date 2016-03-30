binaries = maps
CC = g++
CFLAGS = -Wall

.PHONY : all
all : $(binaries)

maps : maps.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY : clean
clean :
	rm -f $(binaries)
