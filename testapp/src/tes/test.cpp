#include "stdafx.h"
#include <testapp/test.h>

namespace oms
{
int some_func_in_subdir(double param)
{
	std::cout << "function in subdirectort\n";
	return  static_cast<int>(param*2);
}

} // namespace oms
