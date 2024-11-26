TARGET = out
OBJ_FILES = src/main.o src/network.o src/weather.o src/display.o

INCLUDE_DIRS = $(shell find include/ -type d)
INCLUDE_FILES = $(shell find include/ -type f -name "*")
LIB_FILES = $(shell find lib/ -type f -name "*")

IFLAGS = -I src/ -I include/
LFLAGS = -L lib/ -lcjson -ltransientextension -ltransientfoundation -rpath lib
WFLAGS = -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-command-line-argument
FLAGS = $(IFLAGS) $(LFLAGS) $(WFLAGS)

$(TARGET): $(OBJ_FILES) $(INCLUDE_DIRS) $(INCLUDE_FILES) $(LIB_FILES)
	gcc -o $(TARGET) $(OBJ_FILES) $(LFLAGS)

$(OBJ_FILES): %.o: %.c
	gcc -c $^ -o $@ $(IFLAGS) $(WFLAGS)

clean:
	rm -rf src/*.o
	rm -rf .DS_Store
	rm -rf include/.DS_Store