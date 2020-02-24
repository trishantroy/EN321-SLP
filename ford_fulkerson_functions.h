#pragma once

#include <vector>

namespace ford_fulkerson_functions{
	class maxflow_resmatrix
	{
	public:
		double maxflow;
		std::vector<std::vector<double> > resmatrix;
	};
	maxflow_resmatrix FordFulkerson(std::vector<std::vector<double> > &adjMatrix, int source, int sink);
}