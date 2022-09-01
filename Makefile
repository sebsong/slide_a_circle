SEBGINE_DIR = ${HOME}/Workspace/sfml/sebgine
SEBGINE_INCLUDE_DIR = ${SEBGINE_DIR}/include
SEBGINE_LIB_DIR = ${SEBGINE_DIR}/lib
SEBGINE_LIBRARIES = -lsebgine-collision -lsebgine-entity -lsebgine-utils

SFML_LIBRARIES = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

SOURCE_FILES = src/*.cpp

CFLAGS = -Wall -W -std=c++17 -arch arm64

default: build run

build:
	mkdir -p build
	g++ ${CFLAGS} -I ${SEBGINE_INCLUDE_DIR} -L ${SEBGINE_LIB_DIR} -rpath ${SEBGINE_LIB_DIR} ${SOURCE_FILES} -o build/slide_a_circle ${SFML_LIBRARIES} ${SEBGINE_LIBRARIES}

run:
	./build/slide_a_circle

build_debug:
	mkdir -p build
	g++ ${CFLAGS} -g -I ${SEBGINE_INCLUDE_DIR} -L ${SEBGINE_LIB_DIR} -rpath ${SEBGINE_LIB_DIR} ${SOURCE_FILES} -o build/slide_a_circle ${SFML_LIBRARIES} ${SEBGINE_LIBRARIES}

debug: build_debug 
	lldb ./build/slide_a_circle

clean:
	rm -f build/*

.PHONY: build run debug clean