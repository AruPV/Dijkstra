#include "../incl/utils.hpp"

bool is_power_of_two(int x){

	if (x == 1)                 { return true; }
	if (x == 0 || x%2 != 0)		{ return false; }

	return is_power_of_two(x/2);
}

