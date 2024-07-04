CC = gcc
CFLAGS = -Wall
TARGET = writer
SRC = writer.c
OBJ = $(SRC:.c=.o)

# Check if CROSS_COMPILE is set, if so, override CC and AR
ifdef CROSS_COMPILE
	CC := $(CROSS_COMPILE)gcc
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all clean