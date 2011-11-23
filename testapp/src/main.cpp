#include "stdafx.h"
#include <testapp/test.h>

int main(int argc, char** argv)
{
	std::cout << oms::some_func(100) << "\n";
	int value = oms::some_func_in_subdir(45.26);
	std::cout << "value: " << value << "\n";
	return 0;
}
