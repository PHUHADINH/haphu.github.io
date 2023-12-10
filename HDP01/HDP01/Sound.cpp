#include "Sound.h"
#include "Car.h"
#include "Sound.h"

Sound::Sound() {
	call_volume_level = 0;
	media_volume_level = 0;
	navigation_volume_level = 0;
	notification_volume_level = 0;
}

Sound::~Sound() {
	cout << "Sound function destruction" << endl;
}
int Sound::getMediaVolume() {
	return media_volume_level;
}
int Sound::getCallVolume() {
	return call_volume_level;
}
int Sound::getNavigationVolume() {
	return navigation_volume_level;
}
int Sound::getNotificationVolume() {
	return notification_volume_level;
}
void Sound::setMediaVolume(int data) {
	media_volume_level = data;
}
void Sound::setCallVolume(int data) {
	call_volume_level = data;
}
void Sound::setNavigationVolume(int data) {
	navigation_volume_level = data;
}
void Sound::setNotificationVolume(int data) {
	notification_volume_level = data;
}

void Sound::input_Info() {
	string media, call, navi, noti;

	//MEDIA VOLUME         
	do {
		system("cls");
		cout << "SETTING VOLUME INFORMATION\n" << endl;
		cout << "Media volume: ";
		getline(cin, media);
	} while (!check_validation(media, VALIDATE_INPUT_DISPLAY_SOUND));
	setMediaVolume(stoi(media));

	//CALL VOLUME        
	do {
		system("cls");
		cout << "SETTING VOLUME INFORMATION\n" << endl;
		cout << "Media volume: " << media << endl;
		cout << "Call volume: ";
		getline(cin, call);
	} while (!check_validation(call, VALIDATE_INPUT_DISPLAY_SOUND));
	setCallVolume(stoi(call));


	//NAVIGATION VOLUME         
	do {
		system("cls");
		cout << "SETTING VOLUME INFORMATION\n" << endl;
		cout << "Media volume: " << media << endl;
		cout << "Call volume: " << call << endl;
		cout << "Navigation volume: ";
		getline(cin, navi);
	} while (!check_validation(navi, VALIDATE_INPUT_DISPLAY_SOUND));
	setNavigationVolume(stoi(navi));

	//NOTIFICATION VOLUME       
	do {
		system("cls");
		cout << "SETTING VOLUME INFORMATION\n" << endl;
		cout << "Media volume: " << media << endl;
		cout << "Call volume: " << call << endl;
		cout << "Navigation volume: " << navi << endl;
		cout << "Notification volume: ";
		getline(cin, noti);
	} while (!check_validation(noti, VALIDATE_INPUT_DISPLAY_SOUND));
	setNotificationVolume(stoi(noti));
}

void Sound::printCommoInfo() {
	cout << setw(20) << getMediaVolume() << setw(20) << getCallVolume() << setw(25) << getNavigationVolume() << setw(25) << getNotificationVolume() << endl;
}