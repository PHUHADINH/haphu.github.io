#pragma once
#ifndef _CAR_SYSTEM_
#define _CAR_SYSTEM_
#include<iostream>
#include<string>
#include "Car.h"
#include"Display.h"
#include"General.h"
#include"Sound.h"

using namespace std;


class Car_system : public Car{
private:
	Display* display;
	Sound* sound;
	General* general;
	bool is_first_time;
public:
	Car_system();
	~Car_system();
	void setDisplay(Display* data);
	Display* getDisplay();
	void setSound(Sound* data);
	Sound* getSound();
	void setGeneral(General* data);
	General* getGeneral();
	bool get_is_first_time();
	void set_is_first_time(bool data);

	/* ####################### MENU SCREEN ######################## */
	void Main_Screen();

	void Input_Screen();
	void Input_Screen_Display();
	void Input_Screen_Sound();
	void Input_Screen_General();
	void Return_screen();

	void Print_Screen();
	void printCommonInfo();
	void Print_Screen_Display();
	void Print_Screen_Sound();
	void Print_Screen_General();
	void Print_Screen_All();
	/* ####################### DATA PROCESSING ######################## */
	//void operator = (const Car_system& x) {
	//	display = x.display;
	//	sound = x.sound;
	//	general = x.general;
	//}
	void OverWrite(Car_system* x);
	bool operator < (const Car_system& X) {
		return display->getName() < (X.display)->getName();
	}

	//pair<bool, int> checkUserKey();
	void printCommoInfo();
};
void checkUserKey(Car_system* data);

//extern Car_system** car_list;
#endif
