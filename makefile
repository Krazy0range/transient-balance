TARGET = out
OBJ_FILES = src/main.o src/network.o src/weather.o src/display.o

IFLAGS = -I src/
LFLAGS = -lcjson -ltransientextension -ltransientfoundation
WFLAGS = -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-command-line-argument
FLAGS = $(IFLAGS) $(LFLAGS) $(WFLAGS)

UNAME_S = $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	LFLAGS += -rpath lib
endif

$(TARGET): $(OBJ_FILES)
	gcc -o $(TARGET) $(OBJ_FILES) $(LFLAGS)

$(OBJ_FILES): %.o: %.c
	gcc -c $^ -o $@ $(IFLAGS) $(WFLAGS)

clean:
	rm -rf src/*.o
	rm -rf .DS_Store
	rm -rf include/.DS_Store
