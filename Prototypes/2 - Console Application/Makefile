CPPFLAGS=-Wall -g -Isrc
LIBS=
CC=g++
SANITIZE = -fsanitize=address

SRC=$(wildcard src/*.cpp)
OBJ=$(patsubst %.cpp,%.o, $(SRC))

TARGET=FinanceMonitor

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

cleanw: 
	del /q $(TARGET).exe
	del /q src\*.o

cleanl:
	rm -f $(TARGET)
	rm -f src/*.o
	

