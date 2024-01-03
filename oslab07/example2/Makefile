CC = gcc
CFLAGS = -Wall -Wextra -g

all:
	$(CC) $(CFLAGS) producer.c -lrt -o producer.exe 
	$(CC) $(CFLAGS) comsumer.c -lrt -o comsumer.exe

clean:
	rm -f program *.exe