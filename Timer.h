#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <cstdint>

class Timer {
public:
	Timer();
	void start();
	void stop();
	void reset();
	template <typename T> int64_t read();
	typedef std::chrono::nanoseconds nanoseconds;
	typedef std::chrono::microseconds microseconds;
	typedef std::chrono::milliseconds milliseconds;
	typedef std::chrono::seconds seconds;
	typedef std::chrono::minutes minutes;
	typedef std::chrono::hours hours;
private:
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::duration time_duration;
	enum State { stopped, running } state; // indicate if the Timer is running
};


Timer::Timer()
{
	reset();
}


void Timer::start()
{
	// start a stopped Timer
	if (state == stopped)
	{
		state = running;
		begin = std::chrono::steady_clock::now();
	}
}


void Timer::stop()
{
	// stop a running Timer
	if (state == running)
	{
		time_duration += std::chrono::steady_clock::now() - begin;
		state = stopped;
	}
}

void Timer::reset()
{
	// do same thing in both states
	time_duration = std::chrono::steady_clock::duration::zero();
	state = stopped;
}

template <typename T>
int64_t Timer::read()
{
	if (state == running)
	{
		std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
		time_duration = time_duration + (now - begin);
		begin = now;
		return (std::chrono::duration_cast<T>(time_duration)).count();
	}
	else
	{
		return (std::chrono::duration_cast<T>(time_duration)).count();
	}
}

#endif