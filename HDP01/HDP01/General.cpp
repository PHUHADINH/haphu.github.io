#include "Car.h"
#include "General.h"

General::General() {
	timeZone = "16 / Vietnamese";
	language = "(GMT+07:00) /  Bangkok, Hanoi, Jakarta";
};

General::~General() {};

string General::get_language() {
	return language;
}

string General::get_timeZone() {
	return timeZone;
}

void General::set_timeZone(string data) {
	timeZone = data;
}

void General::set_language(string data) {
	language = data;
}
void General::input_Info() {

	//download_timezone();
	//download_language();

	//Time zone
	string TimeZonee;
	do {
		system("cls");
		cout << "SETTING GENERAL INFORMATION\n" << endl;
		cout << "Time zone: ";
		getline(cin, TimeZonee);
	} while (!check_validation(TimeZonee, VALIDATE_INPUT_NUMBER));
	int int_timeZone = stoi(TimeZonee) - 1;
	timeZone = timeZoneList[int_timeZone];
	cout << "Time Zone: " << timeZone << endl;
	//Language
	string Languagee;
	do {
		system("cls");
		cout << "SETTING GENERAL INFORMATION\n" << endl;
		cout << "Time zone: " << timeZone;
		cout << "Language: ";
		getline(cin, Languagee);
	} while (!check_validation(Languagee, VALIDATE_INPUT_NUMBER));
	int int_language = stoi(Languagee);
	language = languageList[int_language - 1];
	cout << "Language: " << language << endl;

	system("cls");
	cout << "SETTING GENERAL INFORMATION\n" << endl;
	cout << "Time zone: " << timeZone;
	cout << "Language: " << language;
	system("pause");
}
void General::printCommoInfo() {
	//if (is_first_time) Car::xuatThongTin();// nếu các thông tin cơ bản chưa xuất, in các thông tin này trước
	cout << left << setw(70) << get_timeZone() << setw(50) << get_language() << endl;
}
