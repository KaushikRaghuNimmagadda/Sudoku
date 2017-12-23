CXX = g++
CXXFLAGS = -g -std=c++11
EXEC = solver

LIBS = -I/usr/local/boost_1_66_0

all: $(EXEC)

clean:
	rm -f $(EXEC) fake

fake: main.cpp solver.cpp solver.hpp board.cpp board.hpp generator.cpp generator.hpp
	$(CXX) $(CXXFLAGS) main.cpp generator.cpp solver.cpp board.cpp $(LIBS) -o fake

.PHONY: all clean

solver: main.o solver.o
	$(CXX)

main.o: main.cpp solver.hpp solver.cpp
	$(CXX)
