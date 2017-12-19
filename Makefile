CXX = g++
CXXFLAGS = -Wall -g
EXEC = solver

LIBS = -I/usr/local/boost_1_66_0

all: $(EXEC)

clean:
	rm -f $(EXEC)

.PHONY: all clean

solver: main.o solver.o
	$(CXX)

main.o: main.cpp solver.hpp solver.cpp
	$(CXX)
