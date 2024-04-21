#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>

bool is_power_of_two(int x);
/*****************************************************************************
 * @brief check if int passed is a power of two
 * @returns bool
 *****************************************************************************/

template<typename T>
std::string stringify(T t){
	/*************************************************************************
	 * @brief wrapper around std::to_string to handle more types
	 ************************************************************************/	return std::to_string(t);
}

template<>
inline std::string stringify<std::string>(std::string string){
	return string;
}

template<>
inline std::string stringify<char>(char c){
	return std::string(1,c);
}


#endif
