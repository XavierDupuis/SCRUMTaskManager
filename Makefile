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


all: $(BUILD_DIR)/$(EXEC) $(SOURCES) 

$(BUILD_DIR)/$(EXEC): $(OBJECTS)
	mkdir -p $(BUILD_DIR)
	$(CC) -o $@ $^ $(LDFLAGS) $(CCFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp # $(SRC_DIR)/%.h
	mkdir -p $(BIN_DIR)
	$(CC) -o $@ -c $< $(CFLAGS) $(CCFLAGS)

run: all
	./$(BUILD_DIR)/$(EXEC)

test: all
	$(CC) -o $(BIN_DIR)/test.main.o -c $(TEST_DIR)/main.cpp $(CFLAGS) $(CCFLAGS)
	$(CC) -o $(BUILD_DIR)/test.$(EXEC) $(BIN_DIR)/test.main.o $(LDFLAGS) $(CCFLAGS)
	./$(BUILD_DIR)/test.$(EXEC)

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)
	
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
	@echo "   "CC" 	      ": $(CC)
	@echo "   "CCFLAGS"   ": $(CCFLAGS)
	@echo "   "CFLAGS"    ": $(CFLAGS)
	@echo "   "LDFLAGS"   ": $(LDFLAGS)
	@echo "   "SRC_DIR"   ": $(SRC_DIR)
	@echo "   "BIN_DIR"   ": $(BIN_DIR)
	@echo "   "BUILD_DIR" ": $(BUILD_DIR)
	@echo "   "EXEC"      ": $(EXEC)
	@echo "   "OBJECTS"   ": $(OBJECTS)
