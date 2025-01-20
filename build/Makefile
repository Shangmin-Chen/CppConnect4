# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -I ../include

# Source files
SRC = $(wildcard ../src/*.cpp)

# Output binary
TARGET = connect4

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean target
clean:
	rm -f $(TARGET)
