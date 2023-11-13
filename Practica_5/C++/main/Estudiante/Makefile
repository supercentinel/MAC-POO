#compiler for c++ code
CC:=g++

#directory for source code
TOPDIR:= ../..
INCLUDE:= ${TOPDIR}/include
SOURCE:= ${TOPDIR}/source

#flags
CFLAGS:= -I $(INCLUDE) #-lsqlite3

_DEPS:= Direccion.hpp Persona.hpp Materia.hpp
DEPS:= $(patsubst %,$(INCLUDE)/%,$(_DEPS))

_MAIN = main.cpp
_SRC:= Direccion.cpp Persona.cpp Materia.cpp
SRC:= $(patsubst %,$(SOURCE)/%,$(_SRC))
OBJ:= $(SRC:.cpp=.o) $(_MAIN:.cpp=.o)

ifeq ($(OS),Windows_NT)
	CFLAGS=-I $(INCLUDE)
	EXE:= main.exe
else
	EXE:= main.out
endif

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f ./*.o ${SOURCE}/*.o

cross:
	x86_64-w64-mingw32-g++ -o main.exe $(SRC) $(_MAIN) $(CFLAGS)
