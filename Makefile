all:
	g++ find_vulnerability_index.cpp ford_fulkerson_functions.cpp vulnerability_analysis_functions.cpp -o vul

clean:
	rm -rf *o vul