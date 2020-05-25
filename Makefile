default: build ru

build:
	mkdir -p build
	g++ -std=c++11 -c src/main.cpp -o build/main.o
	g++ build/main.o -o build/slide_a_circle -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	./build/slide_a_circle

clean:
	rm -f build/*

.PHONY: build clean