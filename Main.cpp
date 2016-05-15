#include "Timer.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void Random_Vector(std::vector<int>& vec, size_t number)
{
	std::uniform_int_distribution<int> U(0, 100000);
	std::default_random_engine R;
	for (size_t i = 0; i != number; ++i)
	{
		vec.push_back(U(R));
	}
}

int main()
{
	Timer timer;
	std::vector<int> rand;
	Random_Vector(rand, 10000);

	timer.start();
	std::sort(rand.begin(), rand.end());
	timer.stop();

	std::cout << timer.read<Timer::milliseconds>() << std::endl;
	std::cout << timer.read<Timer::microseconds>() << std::endl;
	return 0;
}