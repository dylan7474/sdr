.RECIPEPREFIX = >
CC = gcc
CFLAGS = -Wall -O2
LIBS = -lrtlsdr

TARGET = check_rtl
SRC = $(TARGET).c

all: $(TARGET)

$(TARGET): $(SRC)
>$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
>rm -f $(TARGET)

.PHONY: all clean
