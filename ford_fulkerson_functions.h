#pragma once

#include <vector>

namespace ford_fulkerson_functions{
	double FordFulkerson(std::vector<std::vector<int> > &adjMatrix, int source, int sink);
}