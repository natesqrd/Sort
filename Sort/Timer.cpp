#include <iostream>
#include "Timer.h"

using std::cout;
using std::endl;

Timer::Timer()
{
	if (!QueryPerformanceFrequency(&start))
		cout << "QueryPerformanceFrequency failed\n";
}
void Timer::startTimer()
{
	QueryPerformanceFrequency(&start);
}
void Timer::stopTimer()
{
	QueryPerformanceFrequency(&stop);
}
double Timer::getMicro()
{
	PCFreq = freq.QuadPart / 1000000.0;
	return double((stop.QuadPart - start.QuadPart)) / PCFreq;
}
double Timer::getMilli()
{
	PCFreq = freq.QuadPart / 1000.0;
	return double((stop.QuadPart - start.QuadPart)) / PCFreq;
}
double Timer::getSeconds()
{
	return double((stop.QuadPart - start.QuadPart)) / freq.QuadPart;
}