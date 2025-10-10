# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -Ibuilt

# Executable name
TARGET = minishell

# Source files
SRC = main.cpp parser.cpp built/cd.cpp built/history.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default build target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile any .cpp to corresponding .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJ) $(TARGET)
