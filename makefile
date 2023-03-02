CC = gcc
TARGET = r.out
SRC = msg.c

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

clean:
	rm -f *.o