CC = gcc

INCLUDE = -O2 -ID:/MinGW64/include -ID:/MinGW64/x86_64-w64-mingw32/include

file = 7-23

path = D:/DATA/Code/PTA

all:
	$(CC) -o $(path)/$(file).exe $(INCLUDE) $(path)/$(file).c

clean:
	rm -f $(path)/$(file).exe