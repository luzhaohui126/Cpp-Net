﻿#pragma once

#include<chrono>
using namespace std::chrono;

class CellTime
{
public:
	//获取当前时间戳 (毫秒)
	static time_t getNowInMilliSec()
	{
		return duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
	}
	//获取当前时间戳 (微秒)
	static time_t getNowInMicroSec()
	{
		return duration_cast<microseconds>(high_resolution_clock::now().time_since_epoch()).count();
	}
	CellTime() {

	}
	~CellTime() {

	}
private:
};

class CellTimestamp
{
public:
	CellTimestamp() {
		//QueryPerformanceFrequency(&_frequency);
		//QueryPerformanceCounter(&_startCount);
		update();
	}
	~CellTimestamp() {
	}
	void    update()
	{
		//QueryPerformanceCounter(&_startCount);
		_begin = high_resolution_clock::now();
	}
	/**
	*   获取当前秒
	*/
	double getElapsedSecond()
	{
		return  getElapsedTimeInMicroSec() * 0.000001;
	}
	/**
	*   获取毫秒
	*/
	double getElapsedTimeInMilliSec()
	{
		return this->getElapsedTimeInMicroSec() * 0.001;
	}
	/**
	*   获取微妙
	*/
	long long getElapsedTimeInMicroSec()
	{
		/*
		LARGE_INTEGER endCount;
		QueryPerformanceCounter(&endCount);

		double  startTimeInMicroSec =   _startCount.QuadPart * (1000000.0 / _frequency.QuadPart);
		double  endTimeInMicroSec   =   endCount.QuadPart * (1000000.0 / _frequency.QuadPart);

		return  endTimeInMicroSec - startTimeInMicroSec;
		*/
		return duration_cast<microseconds>(high_resolution_clock::now() - _begin).count();
	}
protected:
	//LARGE_INTEGER   _frequency;
	//LARGE_INTEGER   _startCount;
	time_point<high_resolution_clock> _begin;
private:

};

