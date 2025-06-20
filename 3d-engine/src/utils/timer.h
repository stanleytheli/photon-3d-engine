#pragma once

#include <Windows.h>

namespace photon {
	class Timer {
	private:
		LARGE_INTEGER m_start;
		double m_period;
	public:
		Timer() {
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_period = 1.0 / frequency.QuadPart;
			QueryPerformanceCounter(&m_start);
		}

		// Reset timer.
		void reset() {
			QueryPerformanceCounter(&m_start);
		}

		// Get time from last reset or init, in seconds.
		float elapsed() const {
			LARGE_INTEGER now;
			QueryPerformanceCounter(&now);
			unsigned __int64 cycles = now.QuadPart - m_start.QuadPart;
			return (float)(cycles * m_period);
		}
	};
}