#compiler for c++ code
CC:= g++

#directory for source code
TOPDIR:= ../..
INCLUDE:= ${TOPDIR}/include
SOURCE:= ${TOPDIR}/source

#flags
CFLAGS:= -I $(INCLUDE) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

_DEPS:= triangulo.hh randomColor.h
DEPS:= $(patsubst %,$(INCLUDE)/%,$(_DEPS))

_MAIN = main.cpp
_SRC:= triangulo.cpp randomColor.c
SRC:= $(patsubst %,$(SOURCE)/%,$(_SRC))
OBJ:= $(SRC:.cpp=.o) $(_MAIN:.cpp=.o)

ifeq ($(OS),Windows_NT)
	CFLAGS=-I $(INCLUDE) -lraylib -lopengl32 -lgdi32 -lwinmm
	EXE:= triangulo.exe
else
	EXE:= triangulo.out
endif

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f ./*.o ${SOURCE}/*.o
