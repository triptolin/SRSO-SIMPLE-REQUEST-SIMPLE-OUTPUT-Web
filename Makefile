exec = srso.exe
sources = $(wildcard src/*.c)

objects = $(patsubst src/%.c,build/%.o,$(sources))
flags = -g


all: build $(exec)

build:
	-if not exist build mkdir build


$(exec): $(objects)
	gcc $(objects) $(flags) -o build/$(exec)


VPATH = src

build/%.o: %.c | build
	gcc -c $(flags) $< -o $@

clean:
	-del /Q build\*.exe
	-del /Q build\*.o
	-rmdir /Q build