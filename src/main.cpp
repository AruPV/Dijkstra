#include "../incl/dijkstra.hpp"
#include <iostream>

int main(){

	AdjacencyMatrix python_matrix{6};

	python_matrix(0,1) = python_matrix(1,0) = 7;
	python_matrix(0,3) = python_matrix(3,0) = 2;
	python_matrix(1,2) = python_matrix(2,1) = 2;
	python_matrix(1,4) = python_matrix(4,1) = 3;
	python_matrix(2,5) = python_matrix(5,2) = 4;
	python_matrix(3,4) = python_matrix(4,3) = 1;
	python_matrix(4,5) = python_matrix(5,4) = 1;

	print_adjacency(python_matrix);
	int start;
	int end;
	while (true){
		std::cout << "Enter a starting vertex: ";
		std::cin >> start;
		std::cout << "Enter a destination vertex: ";
		std::cin >> end;
		try{
			auto dijkstra_tuple = dijkstra(python_matrix, start, end);

			if (!dijkstra_tuple.has_value()){
				std::cout << "No path found!\n";
				continue;
			}

			std::string print_str;

			print_str += "The path from " 
				+ std::to_string(start)
				+ " to "
				+ std::to_string(end)
				+ " is length "
				+ std::to_string(std::get<int>(dijkstra_tuple.value()))
				+ "\n";

			std::cout << print_str;
		}
		catch (std::invalid_argument){
			std::cout << "Start and end must be in different locations!\n";
		}
		catch (std::out_of_range){
			std::cout << "Indexes out of bounds </3.\n";
		}
	}


}
