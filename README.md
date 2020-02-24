##Files
<ul>
    <li>Makefile</li>
    <li>find_vulnerability_index.cpp</li>
</ul>

##Library Files
<ul>
    <li>vulnerability_analysis_functions</li>
    <li>ford_fulkerson_functions</li>
</ul>

###Makefile
This file compiles the source files and creates an executable.
`make all` 

###find_vulnerability_index.cpp
Main file.

###vulnerability_analysis_functions
Classes:
<ul>
    <li>bus_system<br>
        class for representing the bus system<br>
        number_of_buses: denotes the number of buses in the system<br>
        adjacency_matrix: denotes the connectivity of the system in matrix form<br>
        Y_bus_matrix: denotes the admittance matrix of the matrix<br>
        calculate_vulnerability_indices(): function to calculate the vulnerability index of each edge        
    </li>
    <li>directed_edge<br>
        class to represent a directed edge<br>
        start: index of the start vertex
        end: index of the end vertex
        capacity: max capacity of the edge
    </li>
    <li>directed_graph
        Class to represent a directed graph<br>
        vertices: vector of indices of nodes<br>
        edges: vector of 'directed_edge's<br>
        no_of_vertices: number of vertices in the graph<br>
        no_of_edges: number of edges in the graph<br>
        generate_vertices(): this function generate the 'vertices' vector (of length <i>no_of_vertices</i>)<br>
        find_maximum_flow(int s, int e): finds maximum flow between source (s) and end (e)
    </li>
</ul>