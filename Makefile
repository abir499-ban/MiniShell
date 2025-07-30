# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Executable name
TARGET = minishell

# Source and object files
SRC = main.cpp parser.cpp
OBJ = $(SRC:.cpp=.o)

# Default build target
all: $(TARGET)

# Link object files to make the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean build artifacts
clean:
	rm -f $(OBJ) $(TARGET)
