#compiler for c++ code
CC:= g++

#directory for source code
TOPDIR:= ../..
INCLUDE:= ${TOPDIR}/include
SOURCE:= ${TOPDIR}/source

#flags
CFLAGS:= -I $(INCLUDE)

_DEPS:= fraccion.hpp
DEPS:= $(patsubst %,$(INCLUDE)/%,$(_DEPS))

_MAIN = main.cpp
_SRC:= fraccion.cpp
SRC:= $(patsubst %,$(SOURCE)/%,$(_SRC))
OBJ:= $(SRC:.cpp=.o) $(_MAIN:.cpp=.o)

ifeq ($(OS),Windows_NT)
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