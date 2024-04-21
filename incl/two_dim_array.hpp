#ifndef TWO_D_ARRAY_HPP
#define TWO_D_ARRAY_HPP

#include <array>
#include <string>
#include "utils.hpp"

template<typename T, int R, int C>
class TwoDArray{
	/*************************************************************************
	 * @brief wrapper of std::array class that makes 2D arrays easier
	 *************************************************************************/

	private:
		std::array<T,R*C> array;
		std::size_t rows;
		std::size_t cols;
	public:
		TwoDArray(): rows{R}, cols{C}{}
		bool is_empty(){ return array.size();}
		int get_size(){ return (rows*cols); }
		int get_rows(){ return rows; }
		int get_cols(){ return cols; }
		T& get_element(int row, int col){
			return array[(row*cols)+col];
		}
		std::string to_string(){
			/*****************************************************************
			 * @brief returns string representation of array
			 * Will be garbage if not initialized
			 *****************************************************************/

			std::string return_string;
			for (int i=0; i<get_size(); i++){
				if (i%4 == 0) { return_string += "\n";}
				std::string value_string;
				return_string += "[" + stringify(array[i])+ "\n";
			}

		}

};

#endif
