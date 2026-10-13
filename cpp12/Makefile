CXX			= g++
CXXFLAGS	= -Wall	-std=c++17	-MMD	-MP	-Iinclude
TARGET		= build/myprogram
SRCS		= src/main.cpp	src/add.cpp
OBJS		= $(SRCS:src/%.cpp=build/%.o)

$(TARGET):	$(OBJS)
	$(CXX)	$(OBJS)	-o	$(TARGET)

build/%.o:	src/%.cpp
	mkdir -p build
	$(CXX)	$(CXXFLAGS)	-c	$<	-o	$@

clean:
	rm -rf build

.PHONY: clean

-include $(OBJS:.o=.d)