// 将该文件下的所有 *.cpp文件，编译为源文件的文件名
CXX = g++
CXXFLAGS = -Wall -std=c++20

all: $(patsubst %.cpp,%,$(wildcard *.cpp))

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
