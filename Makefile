default: build
	./slide_a_circle

build:
	g++ -std=c++11 -c src/main.cpp
	g++ main.o -o slide_a_circle -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
