CC = g++
CFLAGS = -std=c++17 -g -Wall -Wextra -Wpedantic -Werror
INC = -I lib -I .
C = $(CC) $(CFLAGS) $(INC)

TEST_MAIN_CPP = test/tests-main.cpp
TEST_MAIN_OBJ = build/test/tests-main.o

SRC_MAIN_CPP = src/main.cpp

TEST_CPP = $(shell find test/ -name *.cpp)
SRC_CPP = $(shell find src/ -name *.cpp)

OBJ_TESTS = $(patsubst %.cpp,%.o, $(SRC_TESTS))
OBJ_RELEASE = $(patsubst %.cpp,%.o, $(SRC_RELEASE))

.PHONY: all init clean run test-all clearscr

all:
	@echo Compiling all files
	@$(C) src/*.cpp -o bin/foo
	@echo Running program
	@bin/foo

init:
	@mkdir -p test
	@mkdir -p src
	@mkdir -p doc
	@mkdir -p lib
	@mkdir -p data
	@mkdir -p bin
	@mkdir -p build
	@mkdir -p build/src
	@mkdir -p build/test
	@mkdir -p logs

clean:
	@echo Cleaning project...
	@find build/test/ -name *.o | grep -v $(TEST_MAIN_OBJ) | xargs rm
	@rm -rf build/src/*.o

clean-all:
	@rm -rf build/src/*.o
	@rm -rf build/test/*.o
	@rm -rf bin/*

test-all: clearscrean $(TEST_MAIN_OBJ) test-XmlElement

test-XmlElement: $(TEST_MAIN_OBJ) build/src/CharacterSet.o build/src/XmlAttribute.o build/src/XmlElement.o
	@echo Compiling XmlElement tests
	@$(C) test/test-XmlElement.cpp $^ -o bin/test-XmlElement
	@echo Running XmlElement tests
	@bin/test-XmlElement

build/src/%.o: src/%.cpp src/%.h
	@echo Compiling $<
	@$(C) $< -c -o $@

build/test/%.o: test/%.cpp
	@echo Compiling $@
	$(C) $< -c -o $@

##test-utilities:
##@$(C) test/test-utilities.hpp -c -o build/test/test-utilities.o

run: clearscrean all
	@bin/foo

clearscrean:
	@clear
