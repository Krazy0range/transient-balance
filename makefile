.PHONY: compile wget

IFLAGS := -I src/ -I include/
LFLAGS :=
WFLAGS := -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable
EXEC := out

GCC_CMD := gcc src/*.c -o $(EXEC) $(IFLAGS) $(LFLAGS) $(WFLAGS)

compile:
	$(GCC_CMD)

debug:
	$(GCC_CMD) -fsanitize=address

wget:
	gcc -o wget wget.c