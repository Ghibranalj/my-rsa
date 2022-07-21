##
# My RSA
#
# @file
# @version 0.1


SRC = $(shell find . -type f -name '*.c')
OBJS  := $(SRC:%.c=%.o)
CFLAGS := -Wall -Wextra -std=c11
EXE:= my_rsa
CC:= gcc

all: $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) -o $(EXE)
.o:.c
	$(CC) -c $< -o $@

.PHONY: run clean
run: all
	 ./$(EXE)

clean:
	rm -v $(OBJS)

# end
