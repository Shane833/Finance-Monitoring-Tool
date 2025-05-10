CPPFLAGS=-Wall -g -Isrc/headers
LIBS=
CC=g++

SRC=$(wildcard src/**/*.cpp src/*.cpp)
OBJ=$(patsubst %.cpp,%.o, $(SRC))

TARGET=main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean: 
	del /q $(TARGET).exe
	del /q src\*.o
	

