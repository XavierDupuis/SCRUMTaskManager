CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=-lm

SRCDIR=src
LINUXDIR=linux
BUILDDIR=build
EXEC=program.out

SOURCES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

all: $(EXEC) $(SOURCES)
	
$(EXEC): $(OBJECTS)
	$(CC) -o $(BUILDDIR)/$@ $(LINUXDIR)/$^ $(LDFLAGS)

%.o: %.cpp %.h
	$(CC) -o $(LINUXDIR)/$@ -c $(SRCDIR)/$< $(CFLAGS)

run:
	./$(BUILDDIR)/$(EXEC)

clean:
	rm -rf $(OBJECTS)