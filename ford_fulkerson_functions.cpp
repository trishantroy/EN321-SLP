// Copyright srcmake 2018.
// C++ Example Ford Fulkerson Algorithm

/* Ford Fulkerson Algorithm:
    // 0. Initialize an adjacency matrix to represent our graph.
    // 1. Create the residual graph. (Same as the original graph.)
    // 2. Create an default parent vector for BFS to store the augmenting path. 
    // 3. Keep calling BFS to check for an augmenting path (from the source to the sink...
        // 4. Find the max flow through the path we found.
        // 5. Update the residual capacities of the edges and reverse edges. 
        // 6. Add this path's flow to our total max flow so far.
*/

// The example graph: https://www.srcmake.com/uploads/5/3/9/0/5390645/maxflow_1_orig.jpg

#include <iostream>
#include <vector>
#include <queue>

#include "ford_fulkerson_functions.h"

//////////////////////////////////////////////////////////////////////////////////////////////
// A special BFS version that returns true if there's a path from source to sink.
bool BFS(std::vector<std::vector<int> > &resAdjMatrix, int &source, int &sink, std::vector<int> &parent)
    {
    // Create an array for all nodes we visited. Initialized to false.
    int n = resAdjMatrix.size();
    bool visited[n] = { false };
        
    // Create a queue to check each node.
    std::queue<int> q;
    
    // Push our source into the queue and mark it as visited. It has no parent.
    q.push(source);
    visited[source] = true;
    parent[source] = -1;
        
    // Keep visiting vertices.
    while(q.empty() == false)
        {
        int u = q.front();
        q.pop();
        
        // Check all of u's friends.
        for(int i = 0; i < n; i++)
            {
            int v = i;
            int capacity = resAdjMatrix[u][v];
            
            // We find a neighbor that hasn't been visited, and the capacity is bigger than 0.
            if(visited[v] == false && capacity > 0)
                {
                // Push the neighbor onto the queue, mark it's parent, and mark it as visited.
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                }
            }
        }
        
    // If the sink got visited, then we found a path to it. 
    if(visited[sink] == true) 
        { return true; }
        
    return false;
    }
//////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// Use the Ford Fulkerson algorithm. Return the max flow.
double ford_fulkerson_functions::FordFulkerson(std::vector< std::vector<int> > &adjMatrix, int source, int sink){
    std::cout << "Source, Sink: " << source << ", " << sink << std::endl;
    double maxflow = 0;
    
    // 1. Create the residual graph. (Same as the original graph.)
    std::vector< std::vector<int> > resAdjMatrix;
    int n = adjMatrix.size();
    for(int i = 0; i < n; i++)
        {
        std::vector<int> row;
        resAdjMatrix.push_back(row);
        for(int j = 0; j < adjMatrix[i].size(); j++)
            {
            resAdjMatrix[i].push_back(adjMatrix[i][j]);
            }
        }
    // for(int i = 0; i < resAdjMatrix.size(); i++){
    //     for(int j = 0; j < resAdjMatrix[i].size(); j++){
    //         std::cout << "resAdjMatrix: " << i << ", " << j << ", " << resAdjMatrix[i][j] << std::endl;
    //     }
    // }
    
    // 2. Create an empty parent array for BFS to store the augmenting path. 
    std::vector<int> parent;
    for(int i = 0; i < n; i++)
        {
        parent.push_back(-1);
        }
    
    // 3. Keep calling BFS to check for an augmenting path (from the source to the sink...
    while(BFS(resAdjMatrix, source, sink, parent) == true){
        std::cout << "Inside BFS" << std::endl;
        // 4. Find the max flow through the path we just found.
        int pathflow = 10000007;
        
        // Go through the path we just found. Iterate through the path.
        int v = sink;
        while(v != source){
            int u = parent[v]; // The parent.
            
            // Update the pathflow to this capacity if it's smaller
            int capacity = resAdjMatrix[u][v];
            // if(capacity < pathflow){
            //     std::cout << "debug1: " << pathflow << ", " << capacity << ", " << u << ", " << v << std::endl;
            // }
            pathflow = std::min(pathflow, capacity);
            
            // Setup for the next edge in the path.
            v = u;
        }
        
        // 5. Update the residual capacities of the edges and reverse edges. 
        v = sink;
        while(v != source){
            int u = parent[v]; // The parent.
            
            // Update the capacities.
            
            resAdjMatrix[u][v] -= pathflow;
            resAdjMatrix[v][u] += pathflow;
            
            // Setup for the next edge in the path.
            v = u;
        }
        
        // 6. Add this path's flow to our total max flow so far.
        std::cout << "Path flow: " << pathflow << std::endl;
        maxflow += pathflow;
        }
    
    return maxflow;
    }
//////////////////////////////////////////////////////////////////////////////////////////////