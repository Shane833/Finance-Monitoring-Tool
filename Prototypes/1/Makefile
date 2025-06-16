CPPFLAGS=-Wall -g -Isrc/headers
LIBS=
CC=g++

SRC=$(wildcard src/**/*.cpp src/*.cpp)
OBJ=$(patsubst %.cpp,%.o, $(SRC))

TARGET=main

all: $(TARGET)
s
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

clean: 
	del /q $(TARGET).exe
	del /q src\*.o
	

