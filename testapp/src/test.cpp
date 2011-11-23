#include <stdafx.h>
#include <testapp/test.h>

namespace oms
{

int some_func(int param)
{
	boost::shared_ptr<void> test_arg; // test argument to chech that precompiled headers are included
	return param + 1;
}

} // namespace oms
