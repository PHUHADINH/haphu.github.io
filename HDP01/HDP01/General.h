#pragma once
#ifndef _GENERAL_H_
#define _GENERAL_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<iomanip>
#include "Car.h"

using namespace std;
class General :
	public Car
{
private:
	string timeZone;
	string language;
public:
	General();
	~General();
	string get_language();
	string get_timeZone();
	void set_timeZone(string data);
	void set_language(string data);
	//friend class car_data;
	void operator = (const General& x) {
		timeZone = x.timeZone;
		language = x.language;
	}
	void input_Info();
	void printCommoInfo();
	//friend class Car_system;
};
#endif

