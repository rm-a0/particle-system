CXX = g++
CXXFLAGS = -std=c++11 -Wall -I/usr/local/include -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRCDIR = src
INCDIR = inc

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

TARGET = particlesystem

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
