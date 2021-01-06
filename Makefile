#
# @file Makefile
# @author XAVIER DUPUIS / OLIVIER SAINT-CYR
# @e      xavier0978@hotmail.fr /  saintcyr.olivier1@gmail.com
# @brief 
# @version 0.1
# @date 2020-12-16
# 
# @copyright Copyright (c) 2020
#

CC=g++
CCFLAGS = -std=c++17
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=-lm

SRC_DIR=src
BIN_DIR=bin
BUILD_DIR=build
TEST_DIR=test
EXEC=program.out

SOURCES=$(sort $(shell find $(SRC_DIR) -name '*.cpp'))
OBJECTS=$(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

TEST_SOURCES=$(sort $(shell find $(TEST_DIR)/$(SRC_DIR) -name '*.cpp'))
TEST_OBJECTS=$(TEST_SOURCES:$(TEST_DIR)/$(SRC_DIR)/%.cpp=$(TEST_DIR)/$(BIN_DIR)/%.o)


all: $(BUILD_DIR)/$(EXEC) $(SOURCES) 

$(BUILD_DIR)/$(EXEC): $(OBJECTS)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $@ $^ $(LDFLAGS) $(CCFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BIN_DIR)
	$(CC) -o $@ -c $< $(CFLAGS) $(CCFLAGS)

run: all
	./$(BUILD_DIR)/$(EXEC)

test: $(TEST_DIR)/$(BUILD_DIR)/test.$(EXEC) $(TEST_SOURCES) $(filter-out bin/main.o,$(OBJECTS))
	./$(TEST_DIR)/$(BUILD_DIR)/test.$(EXEC)

$(TEST_DIR)/$(BUILD_DIR)/test.$(EXEC): $(TEST_OBJECTS) $(filter-out src/main.cpp,$(SOURCES))
	mkdir -p $(TEST_DIR)/$(BUILD_DIR)
	$(CC) -o $@ $^ $(LDFLAGS) $(CCFLAGS) -lcppunit

$(TEST_DIR)/$(BIN_DIR)/%.o: $(TEST_DIR)/$(SRC_DIR)/%.cpp
	mkdir -p $(TEST_DIR)/$(BIN_DIR)
	$(CC) -o $@ -c $< $(CFLAGS) $(CCFLAGS)

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)
	rm -rf $(TEST_DIR)/$(BIN_DIR)
	rm -rf $(TEST_DIR)/$(BUILD_DIR)

help:
	@echo Usage : make [tag]
	@echo "   "[no_tag]"  ": make all
	@echo "   "all"       ": make all
	@echo "   "run"       ": execute $(EXEC)
	@echo "   "clean"     ": remove /$(BIN_DIR) and /$(BUILD_DIR)directories
	@echo "   "help"      ": show help page
	@echo "   "printvars" ": print makefile variables
	
printvars:
	@echo VARIABLES
	@echo "   "CC" 	           ": $(CC)
	@echo "   "CCFLAGS"         ": $(CCFLAGS)
	@echo "   "CFLAGS"          ": $(CFLAGS)
	@echo "   "LDFLAGS"         ": $(LDFLAGS)
	@echo "   "SRC_DIR"         ": $(SRC_DIR)
	@echo "   "BIN_DIR"         ": $(BIN_DIR)
	@echo "   "BUILD_DIR"       ": $(BUILD_DIR)
	@echo "   "EXEC"            ": $(EXEC)
	@echo "   "OBJECTS"         ": $(OBJECTS)
	@echo "   "TEST_OBJECTS"    ": $(TEST_OBJECTS)
