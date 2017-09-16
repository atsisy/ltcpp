#ifndef _LTT_HPP_
#define _LTT_HPP_

#include "types.hpp"
#include <chrono>

namespace ltt 
{
	using ns = std::chrono::nanoseconds;
	using us = std::chrono::microseconds;
	using ms = std::chrono::milliseconds;
	using s = std::chrono::seconds;
	using m = std::chrono::minutes;
	using h = std::chrono::hours;
	using time = std::chrono::system_clock::time_point;

	template <typename _t_t>
	class clock {

	private:
		//測定開始時刻
		time begin;
		
		//測定終了時刻
		time end;
		
		//測定開始時刻と終了時刻の差
		_t_t diff;

	public:
		//コンストラクタ
		clock();

		void start();

		_t_t pause();

		_t_t stop();

		u64_t result();

		void reset();

		_t_t now();


	};

}

#include "clock.hpp"

#endif