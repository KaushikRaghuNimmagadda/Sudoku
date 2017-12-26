CXX = g++
CXXFLAGS = -g -std=c++11
EXECS = solver generator

LIBS = -I/usr/local/boost_1_66_0

SOLVER_DEPS = solver_main.cpp solver.cpp solver.hpp board.cpp board.hpp

GENERATOR_DEPS = generator_main.cpp generator.cpp generator.hpp solver.cpp solver.hpp board.cpp board.hpp SquareGenerator.hpp SnakeGenerator.cpp SnakeGenerator.hpp


all: $(EXECS)

clean:
	rm -f $(EXECS) fake

.PHONY: all clean

solver: $(SOLVER_DEPS)
	$(CXX) $(CXXFLAGS) $(SOLVER_DEPS) $(LIBS) -o $@

generator: $(GENERATOR_DEPS)
	$(CXX) $(CXXFLAGS) $(GENERATOR_DEPS) $(LIBS) -o $@
