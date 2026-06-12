# Makefile for Password Strength Checker

CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = password_checker

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)
