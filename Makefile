CXX := g++
SOLVE := solver
GEN := generator
EXECS := $(SOLVE) $(GEN)

MKDIR_P := mkdir -p

BUILD_DIR := build
BOARD_SRC := ./board_sources
SOLVER_SRC := ./solver_sources
GENERATOR_SRC := ./generator_sources
EXEC_SUFFIX := _main.cpp.o # format is rule_main.cpp i.e. generator_main.cpp

SOLVE_SRCS := $(shell find $(SOLVER_SRC) -name \*.cpp) # need to escape these wildcards or find produces no output
GEN_SRCS := $(shell find $(GENERATOR_SRC) -name \*.cpp)
BOARD_SRCS := $(shell find $(BOARD_SRC) -name \*.cpp)

SOLVE_OBJS := $(SOLVE_SRCS:%=$(BUILD_DIR)/%.o)
GEN_OBJS := $(GEN_SRCS:%=$(BUILD_DIR)/%.o)
BOARD_OBJS := $(BOARD_SRCS:%=$(BUILD_DIR)/%.o)

SOL_MAIN := $(SOLVE)$(EXEC_SUFFIX)
GEN_MAIN := $(GEN)$(EXEC_SUFFIX)

SOLVE_DEPS := $(SOLVE_OBJS:.o=.d)
GEN_DEPS := $(GEN_OBJS:.o=.d)
BOARD_DEPS := $(BOARD_OBJS:.o=.d)

LIBS := -I/usr/local/boost_1_66_0

INC_DIRS := $(shell find $(SOLVER_SRC) -type d)
INC_DIRS += $(shell find $(GENERATOR_SRC) -type d)
INC_DIRS += $(shell find $(BOARD_SRC) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CXXFLAGS := -g -std=c++11 $(INC_FLAGS) $(LIBS) -MMD -MP
all: $(addprefix $(BUILD_DIR)/, $(EXECS))

$(SOLVE): $(BUILD_DIR)/$(SOLVE)

$(GEN): $(BUILD_DIR)/$(GEN)

clean:
	rm -rf $(BUILD_DIR)

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean

$(BUILD_DIR)/$(SOLVE): $(SOLVE_OBJS) $(BOARD_OBJS)
	$(CXX) $(CXXFLAGS) $(SOLVE_OBJS) $(BOARD_OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/$(GEN): $(GEN_OBJS) $(SOLVE_OBJS) $(BOARD_OBJS)
	$(CXX) $(CXXFLAGS) $(GEN_OBJS) $(filter-out $(BUILD_DIR)/$(SOLVER_SRC)/$(SOL_MAIN), $(SOLVE_OBJS)) $(BOARD_OBJS) -o $@ $(LDFLAGS)
