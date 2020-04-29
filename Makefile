CXX=clang++
CXXFLAGS=-g -std=c++11 -Wall -pedantic
BIN=prog

all:
	g++ find_vulnerability_index.cpp ford_fulkerson_functions.cpp vulnerability_analysis_functions.cpp -o vul
	g++ get_bus_system_data.cpp -o get_bus_system_data

clean:
	rm -rf *o vul
	rm -rf *o get_bus_system_data