
# Compile all .c files to .exe files
all: $(patsubst %.c, %.exe, $(wildcard *.c))

%.exe: %.c
	gcc $< -g -o $@

clean:
	rm -f *.exe

