.PHONY: compile wget

compile:
	gcc -o out src/*.c -I src/ -Wall -Wextra

wget:
	gcc -o wget wget.c