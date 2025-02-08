NASM:=nasm
NASMFLAGS:=-Wall -f elf64 -g -Wall
CC:=gcc
CFLAGS:=-std=c11 -m64 -no-pie -Wall -Wextra -pedantic -O0 -g -z noexecstack

SRCS:= lib.asm lib.c main.c

TARGET:=main
OBJS := $(addsuffix .o,$(basename $(SRCS)))

all: $(TARGET) run

%.o: %.asm 
	$(NASM) $(NASMFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	gcc $(CFLAGS) -o $@ $^

run:
	./$(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)