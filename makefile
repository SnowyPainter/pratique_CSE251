CC = gcc
TARGET = r.out
SRC = sig.c

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

clean:
	rm -f *.o