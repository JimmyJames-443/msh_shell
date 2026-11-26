CXX := g++
TARGET := msh
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -Wconversion -Wshadow
CPPFLAGS :=
LDFLAGS :=

.PHONY: all clean debug test

all: $(TARGET)

$(TARGET): src/main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

debug:
	$(MAKE) clean
	$(MAKE) CXXFLAGS="$(CXXFLAGS) -g3 -O0 -fsanitize=address,undefined" LDFLAGS="-fsanitize=address,undefined"

test: $(TARGET)
	./tests/smoke.sh

clean:
	rm -f $(TARGET)
