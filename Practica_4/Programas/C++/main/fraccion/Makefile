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
_TEST = test.cpp
_SRC:= fraccion.cpp
SRC:= $(patsubst %,$(SOURCE)/%,$(_SRC))
MAIN_OBJ:= $(SRC:.cpp=.o) $(_MAIN:.cpp=.o)
TEST_OBJ:= $(SRC:.cpp=.o) $(_TEST:.cpp=.o)

ifeq ($(OS),Windows_NT)
	TEST_EXE:= test.exe
	MAIN_EXE:= main.exe
else
	TEST_EXE:= test.out
	MAIN_EXE:= main.out
endif


%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(MAIN_EXE) $(TEST_EXE)

$(TEST_EXE): $(TEST_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(MAIN_EXE): $(MAIN_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f ./*.o ${SOURCE}/*.o
cross:
	x86_64-w64-mingw32-g++ -o main.exe $(SRC) $(_MAIN) $(CFLAGS)
