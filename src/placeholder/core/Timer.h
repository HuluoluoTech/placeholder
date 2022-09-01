#pragma once

#include <chrono>

namespace Placeholder {

	class Timer
	{
	public:
		Timer()
		{
			Reset();
		}

		// extra qualification ‘Placeholder::Timer::’ on member Reset
		// This is not valid C++ but Visual Studio seems to accept it.
		// void Timer::Reset()
		// {
		// 	m_Start = std::chrono::high_resolution_clock::now();
		// }
		
		void Reset()
		{
			m_Start = std::chrono::high_resolution_clock::now();
		}

		float Elapsed()
		{
			return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.001f * 0.001f * 0.001f;
		}

		float ElapsedMillis()
		{
			return Elapsed() * 1000.0f;
		}

	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
	};

}
