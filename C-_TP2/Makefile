CXX=g++
LD=g++

CXXFLAGS=-Wall -Werror -g -ansi -pedantic #-DMAP
LDFLAGS=-lm


EXEC=main
SRC=test.cpp Trajet.cpp TrajetSimple.cpp TrajetCompose.cpp
OBJECTS=$(SRC:.cpp=.o)

.PHONY: target clean realclean

target:$(EXEC)
valg : main
	valgrind --leak-check=yes ./main
%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)
	

$(EXEC): $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)
	./main
	
	
clean:
	rm -f *.o core
realclean: clean
	rm -f *~
