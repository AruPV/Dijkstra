#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <string>
#include <optional>
#include <tuple>
#include <vector>

// Made this a class to make interfacing with the array easier
class AdjacencyMatrix { 
	public:
		int vertices;
		std::vector<std::vector<std::optional<int>>> vector;
		AdjacencyMatrix(int vertices);
		std::optional<int>& operator()(int row_i, int col_i);
		std::vector<std::optional<int>>& operator()(int row_i);
		int size();
};

std::string print_adjacency(AdjacencyMatrix matrix);
	/*************************************************************************
	 * @brief prints an adjacency matrix in easy-to-read format
	 * @param adjacency a 2D list of edge weights for a graph
	 *************************************************************************/

struct Vertex{
	/*************************************************************************
	 * @brief Ties the information relating to a vertex together
	 *************************************************************************/
	int	    distance  = -1;
	bool    visited   = false;
	Vertex* parent    = nullptr;
	int     index     = -1;
};

std::optional<std::tuple<int,std::vector<int>>> dijkstra(
		AdjacencyMatrix    adjacencies, 
		int                start, 
		int                dest);
	/*************************************************************************
	 * @brief Dijkstra's algorithm on a graph represented by AdjacencyMatrix
	 * @param adjacency 2D adjacency matrix representin graph
	 * @param start origin index
	 * @param dest destination index
	 * @throw std::out_of_range if dest or start are not valid indeces
	 * @return shortest path
	 *************************************************************************/

#endif
