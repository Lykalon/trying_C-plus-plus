CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp book_actions.cpp Book.cpp books_library_actions.cpp CathalogBook.cpp find.cpp readers.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=library

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)