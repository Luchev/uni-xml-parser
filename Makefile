CC = g++
CFLAGS = -std=c++17 -g -Wall -Wextra -Wpedantic -Werror
INC = -I . -I lib
C = $(CC) $(CFLAGS) $(INC)

BUILD_DIR_SRC = build/src/
BUILD_DIR_TEST = build/test/

RELEASE_DIR_SRC = bin/
RELEASE_DIR_TEST = bin/test/

TEST_MAIN_OBJ = build/test/test-main.o

.PHONY: all init clean run test-all clearscr

all:
	@$(C) src/*.cpp -o bin/foo
	@bin/foo

init:
	@mkdir -p test
	@mkdir -p src
	@mkdir -p doc
	@mkdir -p lib
	@mkdir -p data
	@mkdir -p include
	@mkdir -p bin
	@mkdir -p bin/test
	@mkdir -p build
	@mkdir -p build/src
	@mkdir -p build/test
	@mkdir -p logs

clean:
	@echo Cleaning project...
	@find bin/ -type f 2>/dev/null -exec rm -rf '{}' \;
	@rm -rf build/src/*.o 2>/dev/null
	@find build/test/ -name *.o 2>/dev/null | grep -v $(TEST_MAIN_OBJ) | xargs rm -rf

clean-all:
	@rm -rf build/src/*.o
	@rm -rf build/test/*.o
	@find bin/ -type f 2>/dev/null -exec rm -rf '{}' \;

build/src/%.o: src/%.cpp src/%.h
	@echo Compiling $<
	@$(C) -o $@ -c $<

build/test/%.o: test/%.cpp
	@echo Compiling $<
	@$(C) -o $@ -c $<

unit: $(TEST_MAIN_OBJ)\
		unit-XmlTag\
		unit-XmlAttribute\
		unit-XmlElementEmpty\
		unit-XmlElementSpecial\
		unit-XmlElementContent\
		unit-XmlElementDefault\
		unit-XmlBuilder

unit-XmlTag: $(TEST_MAIN_OBJ)\
		build/test/unit-XmlTag.o\
		build/src/XmlTag.o\
		build/src/XmlAttribute.o\
		build/src/CharacterSet.o\
		build/src/StringExtension.o\
		build/src/XmlConfig.o
	@echo Linking $@
	@$(C) -o bin/test/$@ $^
	@echo Running $@
	@bin/test/$@

unit-XmlAttribute: $(TEST_MAIN_OBJ)\
		build/test/unit-XmlAttribute.o\
		build/src/XmlAttribute.o\
		build/src/CharacterSet.o\
		build/src/StringExtension.o\
		build/src/XmlConfig.o
	@echo Linking $@
	@$(C) -o bin/test/$@ $^
	@echo Running $@
	@bin/test/$@

unit-XmlElementEmpty: $(TEST_MAIN_OBJ)\
		build/test/unit-XmlElementEmpty.o\
		build/src/XmlElement.o\
		build/src/XmlElementEmpty.o\
		build/src/XmlAttribute.o\
		build/src/XmlConfig.o\
		build/src/CharacterSet.o\
		build/src/StringExtension.o
	@echo Linking $@
	@$(C) -o bin/test/$@ $^
	@echo Running $@
	@bin/test/$@

unit-XmlElementSpecial: $(TEST_MAIN_OBJ)\
		build/test/unit-XmlElementSpecial.o\
		build/src/XmlElement.o\
		build/src/XmlElementEmpty.o\
		build/src/XmlElementSpecial.o\
		build/src/XmlAttribute.o\
		build/src/XmlConfig.o\
		build/src/CharacterSet.o\
		build/src/StringExtension.o
	@echo Linking $@
	@$(C) -o bin/test/$@ $^
	@echo Running $@
	@bin/test/$@

unit-XmlElementContent: $(TEST_MAIN_OBJ)\
		build/test/unit-XmlElementContent.o\
		build/src/XmlElement.o\
		build/src/XmlElementContent.o\
		build/src/XmlAttribute.o\
		build/src/XmlConfig.o\
		build/src/CharacterSet.o\
		build/src/StringExtension.o
	@echo Linking $@
	@$(C) -o bin/test/$@ $^
	@echo Running $@
	@bin/test/$@

unit-XmlElementDefault: $(TEST_MAIN_OBJ)\
		build/test/unit-XmlElementDefault.o\
		build/src/XmlElement.o\
		build/src/XmlElementEmpty.o\
		build/src/XmlElementContent.o\
		build/src/XmlElementDefault.o\
		build/src/XmlAttribute.o\
		build/src/XmlConfig.o\
		build/src/CharacterSet.o\
		build/src/StringExtension.o
	@echo Linking $@
	@$(C) -o bin/test/$@ $^
	@echo Running $@
	@bin/test/$@

unit-XmlBuilder: $(TEST_MAIN_OBJ)\
		build/test/unit-XmlBuilder.o\
		build/src/XmlBuilder.o\
		build/src/XmlElement.o\
		build/src/XmlElementEmpty.o\
		build/src/XmlElementContent.o\
		build/src/XmlElementDefault.o\
		build/src/XmlElementSpecial.o\
		build/src/XmlAttribute.o\
		build/src/XmlConfig.o\
		build/src/CharacterSet.o\
		build/src/StringExtension.o\
		build/src/XmlTag.o
	@echo Linking $@
	@$(C) -o bin/test/$@ $^
	@echo Running $@
	@bin/test/$@

run: clearscrean all
	@bin/foo

clearscrean:
	@clear
