CC = gcc
TARGET = r.out
SRC = ipc_smp.c

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

clean:
	rm -f *.o