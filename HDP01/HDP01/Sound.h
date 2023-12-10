#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Car.h"
using namespace std;
class Sound :
	public Car
{
private:
	int media_volume_level;
	int call_volume_level;
	int navigation_volume_level;
	int notification_volume_level;
public:
	Sound();
	~Sound();
	int getMediaVolume();
	int getCallVolume();
	int getNavigationVolume();
	int getNotificationVolume();
	void setMediaVolume(int data);
	void setCallVolume(int data);
	void setNavigationVolume(int data);
	void setNotificationVolume(int data);
	//friend class Car_system;;
	void operator = (const Sound& x) {
		media_volume_level = x.media_volume_level;
		call_volume_level = x.call_volume_level;
		navigation_volume_level = x.navigation_volume_level;
		notification_volume_level = x.notification_volume_level;
	}
	void input_Info();
	void printCommoInfo();
};
#endif 
