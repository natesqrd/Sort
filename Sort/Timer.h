#pragma once
#include <iostream>
#include <chrono>
struct timer
{
	std::chrono::system_clock::time_point start, end;
	std::chrono::duration<float> duration;

	timer() { start = std::chrono::system_clock::now(); }

	~timer()
	{
		end = std::chrono::system_clock::now();
		duration = end - start;
		std::cout << "Function took " << duration.count() * 1000.0f << "ms to complete\n";
	}
};