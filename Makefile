CXX = g++
CXXFLAGS = -Wall -g
EXEC = solver

all: $(EXEC)

clean:
	rm -f $(EXEC)

.PHONY: all clean

solver: main.o solver.o
	$(CXX)

main.o: main.cpp solver.hpp solver.cpp
	$(CXX)
