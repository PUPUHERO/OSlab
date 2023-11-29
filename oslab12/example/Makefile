# Specify the compiler
CC = gcc

# Specify the compiler flags
CFLAGS = -Wall -Wextra

# Specify the source files
SRCS = $(wildcard *.c)

# Specify the object files
OBJS = $(SRCS:.c=.o)

# Specify the target executable
TARGET = $(SRCS:.c=.exe)

# Default target
all: $(TARGET)

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link .o files to create the executable
%.exe: %.o
	$(CC) $(CFLAGS) $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

