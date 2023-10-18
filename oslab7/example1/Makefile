CC = gcc
CFLAGS = -Wall -Wextra -g

all:
	$(CC) $(CFLAGS) receiver.c -lrt -o receiver.exe 
	$(CC) $(CFLAGS) sender.c -lrt -o sender.exe

clean:
	rm -f program *.exe
