#include "../incl/dijkstra.hpp"
#define NDEBUG
#ifndef NDEBUG 
#define DEBUG_MSG(str) do { std::cout << str << "\n"; } while (false)
#else
#define DEBUG_MSG(str) do {} while(false)
#endif

#include <iostream>
#include <algorithm>

AdjacencyMatrix::AdjacencyMatrix(int vertices): vertices{vertices}{
		DEBUG_MSG("Creating Matrix");
		for (int i = 0; i<vertices; i++){
			vector.push_back(std::vector<std::optional<int>>(vertices));
		}
		vector.resize(vertices);
}
std::optional<int>& AdjacencyMatrix::operator()(int row_i, int col_i){
		DEBUG_MSG("Accessing Matrix");
		return vector[row_i][col_i];
}
std::vector<std::optional<int>>& AdjacencyMatrix::operator()(int row_i){
		DEBUG_MSG("Accessing Matrix Col");
		return vector[row_i];
}
int AdjacencyMatrix::size(){
		return vertices;
}

std::string print_adjacency(AdjacencyMatrix matrix){
	std::string print_string;
	for(int row_i = 0; row_i < matrix.size(); row_i++){
		DEBUG_MSG("In print_adjacency.");

		for (int col_i = 0; col_i < matrix.size(); col_i ++){
			std::optional<int> opt_value = matrix(row_i,col_i);
			std::string string_val;
			if (!opt_value.has_value()){ string_val = "*";}
			else { string_val = std::to_string(*opt_value);}
			print_string += string_val + " ";
		}
		print_string += "\n";
	}
	std::cout << print_string;
	return print_string;
}

std::optional<std::tuple<int,std::vector<int>>> dijkstra(
		AdjacencyMatrix    adjacencies, 
		int                start, 
		int                dest) {
	// Check params are legal
	DEBUG_MSG("Checking that parameters are legal.");
	const int element_count = adjacencies.size();

	auto is_valid = [element_count](int i){ return (i>=0 && i<element_count) ;};
	if (!is_valid(start) || !is_valid(dest)) { 
		throw std::out_of_range("Start or Destination not within range");
	}

	if (start == dest){ throw std::invalid_argument("Start and end must be different");}

	std::vector<Vertex> graph(adjacencies.size());
	std::optional<int>  next_i;

	Vertex* cur_v = &graph[start];
	cur_v->distance = 0;

	DEBUG_MSG("Caching indeces.");
	//Cache indeces in Verteces
	for(int i = 0; i < graph.size(); i++){ graph[i].index = i; }


	DEBUG_MSG("Initiating main loop.");
	while (cur_v->index != dest){

		DEBUG_MSG((std::string("At the Vertex on: ") + std::to_string(cur_v->index)));
		cur_v->visited = true;
		auto distances  = adjacencies(cur_v->index);				//std::array


		DEBUG_MSG("Updating distances.");
		//Update distances from this vertex
		for (auto dist_it = distances.begin(); dist_it != distances.end(); ++dist_it){
			Vertex* other_v = &graph[std::distance(distances.begin(),dist_it)];
			DEBUG_MSG("Checking if visited.");
			if (other_v->visited) { continue;}		

			DEBUG_MSG("Checking if Adjacent.");
			if (!dist_it->has_value())   { continue;} 

			DEBUG_MSG("calculating new distance.");
			int new_dist = cur_v->distance + dist_it->value();
			DEBUG_MSG((std::string("New distance is: ") + std::to_string(new_dist)));

			DEBUG_MSG("Checking if smaller.");
			if (new_dist < other_v->distance || other_v->distance == -1){
				DEBUG_MSG("Found smaller distance.");
				other_v->distance = new_dist;
				other_v->parent = &(*cur_v);
			}
		}

		DEBUG_MSG("Finding closest.");
		//Find next closest
		Vertex* next_v = nullptr;
		for (auto& v: graph){
			if (v.visited || v.distance == -1 || cur_v->index == v.index) {continue;}
			if (next_v == nullptr) {
				DEBUG_MSG(std::string("Initializing as: ") + std::to_string(v.index));
				next_v = &v;
				continue;
			}
			if(v.distance < next_v->distance){
				DEBUG_MSG(std::string("closest is: ") + std::to_string(v.index));
				next_v = &v;
				continue;
			}
		}
		if (next_v == nullptr) {return std::nullopt;} // if there is no path
		cur_v = &(*next_v);
	}

	// Construct return value
	int path_length = 0;
	std::vector<int> path_indeces;
	Vertex* arrow = &(*cur_v);
	while (arrow != nullptr){
		path_length += arrow->distance;
		path_indeces.push_back(arrow->index);
		arrow = arrow->parent;
	}
	std::reverse(path_indeces.begin(), path_indeces.end());
	auto return_value = std::tuple<int,std::vector<int>>(path_length,path_indeces);

	return return_value;
}

