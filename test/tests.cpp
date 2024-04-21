#include <gtest/gtest.h>
#include "../incl/dijkstra.hpp"

class AdjacencyMatrixTest: public testing::Test{

	protected:
		AdjacencyMatrixTest(){
			four_matrix(1,0) = 2;
			four_matrix(0,3) = 1;
			four_matrix(2,0) = 8;
		}
		AdjacencyMatrix four_matrix{4};
		AdjacencyMatrix empty_matrix{4};

};

class DijkstraTest: public testing::Test{

	protected:
		DijkstraTest(){
			four_matrix(1,0) = four_matrix(0,1) = 2;
			four_matrix(0,3) = four_matrix(3,0) = 1;
			four_matrix(2,0) = four_matrix(0,2) = 8;
			//
	
		}
		AdjacencyMatrix four_matrix{4};
		AdjacencyMatrix empty_matrix{4};
		std::tuple<int,std::vector<int>> four_return{1,{0,3}};
};

TEST_F(AdjacencyMatrixTest, empty_matrix){
	EXPECT_EQ(print_adjacency(empty_matrix), "* * * * \n* * * * \n* * * * \n* * * * \n");
}

TEST_F(AdjacencyMatrixTest, four_four_matrix){
	EXPECT_EQ(print_adjacency(four_matrix), "* * * 1 \n2 * * * \n8 * * * \n* * * * \n");
}

TEST_F(DijkstraTest, illegal_dijkstra){
	EXPECT_THROW(dijkstra(four_matrix, -1, 3), std::out_of_range); 
	EXPECT_THROW(dijkstra(four_matrix, 0, -1), std::out_of_range); 
	EXPECT_THROW(dijkstra(four_matrix, 0, 0), std::invalid_argument); 
}

TEST_F(DijkstraTest, four_four_matrix){
	EXPECT_EQ(dijkstra(four_matrix,0,3), four_return);
}
