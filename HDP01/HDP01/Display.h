#pragma once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<iomanip>
#include "Car.h"

using namespace std;
class Display :
	public Car
{
private:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
public:
	Display();
	~Display();
	int getLightLevel();
	int getScreenLightLevel();
	int getTaploLightLevel();
	void setLightLevel(int data);
	void setScreenLightLevel(int data);
	void setTaploLightLevel(int data);
	void operator = (const Display& x) {
		light_level = x.light_level;
		screen_light_level = x.screen_light_level;
		taplo_light_level = x.taplo_light_level;
	}
	friend class car_data;
	void input_Info();
	void printCommoInfo();
};
#endif

