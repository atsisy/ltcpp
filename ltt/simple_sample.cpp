#include "ltt.hpp"
#include <iostream>

int main()
{
	ltt::clock<ltt::ms> clock;
	clock.start();

	for (int i = 0; i < 100000000;++i)
	{
		i++;
	}

	clock.stop();

	std::cout << clock.result() << std::endl;

	return 0;
}