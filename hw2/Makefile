CC=g++
CFLAGS=-c
LDFLAGS=
OPTIMIZATIONS=-O3
SOURCES=main.cpp matmul.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=results

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
func.o: matmul.cpp
	$(CC) $(OPTIMIZATIONS) $(CFLAGS) $< -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o results