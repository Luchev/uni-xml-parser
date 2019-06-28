CC = g++
CFLAGS = -std=c++17 -g -Wall -Wextra -Wpedantic -Werror
INC = -I . -I lib
C = $(CC) $(CFLAGS) $(INC)

VERBOSE_OUTPUT = 0

SRCB = build/src
TESTB = build/test

TEST_MAIN_CPP = test/test-main.cpp
TEST_MAIN = build/test/test-main.o

SRC_MAIN_CPP = src/main.cpp

TEST_CPP = $(shell find test/ -name *.cpp)
SRC_CPP = $(shell find src/ -name *.cpp)

OBJ_TESTS = $(patsubst %.cpp,%.o, $(SRC_TESTS))
OBJ_RELEASE = $(patsubst %.cpp,%.o, $(SRC_RELEASE))

.PHONY: all init clean run test-all clearscr

build/src/%.o: src/%.cpp src/%.h
	@echo Compiling $<
	@$(C) -o $@ -c $<

build/test/%.o: test/%.cpp
	@echo Compiling $<
	@$(C) -o $@ -c $<

all:
#@echo Compiling all files
	@$(C) src/*.cpp -o bin/foo
#@echo Running program
	@bin/foo

init:
	@mkdir -p test
	@mkdir -p src
	@mkdir -p doc
	@mkdir -p lib
	@mkdir -p data
	@mkdir -p include
	@mkdir -p bin
	@mkdir -p build
	@mkdir -p build/src
	@mkdir -p build/test
	@mkdir -p logs

clean:
	@echo Cleaning project...
	@rm -rf bin/* 2>/dev/null
	@rm -rf build/src/*.o 2>/dev/null
	@find build/test/ -name *.o 2>/dev/null | grep -v $(TEST_MAIN) | xargs rm -rf

clean-all:
	@rm -rf build/src/*.o
	@rm -rf build/test/*.o
	@rm -rf bin/*

unit: $(TEST_MAIN) unit-XmlTag unit-XmlElement

unit-XmlElement: $(TEST_MAIN)\
		build/test/unit-XmlElement.o\
		build/src/XmlElement.o\
		build/src/XmlAttribute.o\
		build/src/XmlTag.o\
		build/src/CharacterSet.o\
		build/src/StringExtension.o
	@echo Linking $@
	@$(C) -o bin/$@ $^
	@echo Running $@
	@bin/$@

unit-XmlTag: $(TEST_MAIN)\
		build/test/unit-XmlTag.o\
		build/src/XmlTag.o\
		build/src/CharacterSet.o\
		build/src/StringExtension.o\
		build/src/XmlAttribute.o\
		build/src/XmlConfig.o
	@echo Linking $@
	@$(C) -o bin/$@ $^
	@echo Running $@
	@bin/$@

unit-XmlAttribute: $(TEST_MAIN)\
		build/test/unit-XmlAttribute.o\
		build/src/XmlAttribute.o\
		build/src/CharacterSet.o\
		build/src/XmlConfig.o
	@echo Linking $@
	@$(C) -o bin/$@ $^
	@echo Running $@
	@bin/$@

unit-XmlElementEmpty: $(TEST_MAIN)\
		build/test/unit-XmlElementEmpty.o\
		build/src/XmlElement.o\
		build/src/XmlElementEmpty.o\
		build/src/XmlAttribute.o\
		build/src/XmlConfig.o\
		build/src/CharacterSet.o
	@echo Linking $@
	@$(C) -o bin/$@ $^
	@echo Running $@
	@bin/$@

unit-XmlElementSpecial: $(TEST_MAIN)\
		build/test/unit-XmlElementSpecial.o\
		build/src/XmlElement.o\
		build/src/XmlElementEmpty.o\
		build/src/XmlElementSpecial.o\
		build/src/XmlAttribute.o\
		build/src/XmlConfig.o\
		build/src/CharacterSet.o
	@echo Linking $@
	@$(C) -o bin/$@ $^
	@echo Running $@
	@bin/$@

unit-XmlElementContent: $(TEST_MAIN)\
		build/test/unit-XmlElementContent.o\
		build/src/XmlElement.o\
		build/src/XmlElementContent.o\
		build/src/XmlAttribute.o\
		build/src/XmlConfig.o\
		build/src/CharacterSet.o
	@echo Linking $@
	@$(C) -o bin/$@ $^
	@echo Running $@
	@bin/$@

unit-XmlElementDefault: $(TEST_MAIN)\
		build/test/unit-XmlElementDefault.o\
		build/src/XmlElement.o\
		build/src/XmlElementEmpty.o\
		build/src/XmlElementContent.o\
		build/src/XmlElementDefault.o\
		build/src/XmlAttribute.o\
		build/src/XmlConfig.o\
		build/src/CharacterSet.o
	@echo Linking $@
	@$(C) -o bin/$@ $^
	@echo Running $@
	@bin/$@

run: clearscrean all
	@bin/foo

clearscrean:
	@clear