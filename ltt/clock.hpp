#pragma once

#include "ltt.hpp"

namespace ltt
{
	template <typename _t_t>
	clock<_t_t>::clock()
	{}

	template <>
	clock<ns>::clock()
	{
		diff = ns(0);
	}

	template <>
	clock<us>::clock()
	{
		diff = us(0);
	}
	template <>
	clock<ms>::clock()
	{
		diff = ms(0);
	}

	template <>
	clock<s>::clock()
	{
		diff = s(0);
	}

	template <>
	clock<m>::clock()
	{
		diff = m(0);
	}
	template <>
	clock<h>::clock()
	{
		diff = h(0);
	}

	template <typename _t_t>
	void clock<_t_t>::start()
	{
		diff += std::chrono::duration_cast<_t_t>(end - begin);
		begin = std::chrono::system_clock::now();
	}

	template <typename _t_t>
	_t_t clock<_t_t>::pause()
	{
		return std::chrono::duration_cast<_t_t>(end = chrono::system_clock::now());
	}

	template <typename _t_t>
	_t_t clock<_t_t>::stop()
	{
		end = std::chrono::system_clock::now();
		diff += std::chrono::duration_cast<_t_t>(end - begin);
		return diff;
	}

	template <typename _t_t>
	u64_t clock<_t_t>::result()
	{
		return diff.count();
	}

	template <typename _t_t>
	void clock<_t_t>::reset()
	{
		begin = 0;
		end = 0;
		diff = 0;
	}

	template <typename _t_t>
	_t_t clock<_t_t>::now()
	{
		return std::chrono::duration_cast<_t_t>(std::chrono::system_clock::now());
	}
}