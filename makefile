.PHONY: compile debug wget

IFLAGS := -I src/ -I include/
LFLAGS := -L lib/ -lcjson -rpath lib
WFLAGS := -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable
EXEC := out

GCC_CMD := gcc src/*.c -o $(EXEC) $(IFLAGS) $(LFLAGS) $(WFLAGS)

compile:
	$(GCC_CMD)

debug:
	$(GCC_CMD) -fsanitize=address -v

wget:
	gcc -o wget wget.c