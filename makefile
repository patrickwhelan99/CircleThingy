CC=g++
LIBS=-lsfml-system -lsfml-window -lsfml-graphics

make:
	mkdir -p obj
	mkdir -p build

	$(CC) -o obj/main.o -c src/main.cpp $(LIBS)
	$(CC) -o build/circleThingy obj/main.o $(LIBS)

clean:
	rm -rf obj/ build/

