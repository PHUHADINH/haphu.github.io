
#include<iostream>
#include<fstream>
#include "Car.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"
#include "Car_system.h"

using namespace std;

int main() {
	Car_system* screen = new Car_system;
	screen->Main_Screen();
	delete screen;
	return 0;
}