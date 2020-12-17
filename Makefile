CC=g++
CCFLAGS = -std=c++17
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=-lm

SRCDIR=src
LINUXDIR=linux
BUILDDIR=build
EXEC=program.out

SOURCES=$(wildcard */*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

all: $(EXEC) $(SOURCES)

$(EXEC): $(OBJECTS)
	mkdir -p $(BUILDDIR)
	$(CC) -o $@ $^ $(LDFLAGS) $(CCFLAGS)

%.o: %.cpp %.h
	mkdir -p $(LINUXDIR)
	$(CC) -o $@ -c $< $(CFLAGS) $(CCFLAGS)

# $(EXEC): $(OBJECTS)
# 	$(CC) -o $(BUILDDIR)/$@ $(LINUXDIR)/$^ $(LDFLAGS) $(CCFLAGS)

# %.o: %.cpp %.h
# 	$(CC) -o $(LINUXDIR)/$@ -c $(SRCDIR)/$< $(CFLAGS)

run:
	./$(BUILDDIR)/$(EXEC)

clean:
	rm -rf $(OBJECTS)
	rm -rf $(EXEC)
	rmdir $(BUILDDIR)
	rmdir $(LINUXDIR)
