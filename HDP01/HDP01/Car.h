#pragma once
#ifndef _CAR_H_
#define _CAR_H_
#include <iostream>
#include <string>
#include<iomanip>
#include <vector>
#include<map>
#include<regex>
#include<fstream>

using namespace std;
//######################################################CLASS CAR##################################################################
class Car
{
private:
	string car_name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;
public:
	Car();
	~Car();
	string getName();
	string getKey();
	string getEmail();
	int getODO();
	int getServiceRemind();
	void setName(string data);
	void setEmail(string data);
	void setKey(string data);
	void setOdo(int data);
	void setServiceRemind(int data);
	void operator == (const Car& x) {
		car_name = x.car_name;
		personal_key = x.personal_key;
		email = x.email;
		odo = x.odo;
		service_remind = x.service_remind;
	}
	void basic_info();
	virtual void input_Info();
	//virtual void basicInfo();
	virtual void printCommoInfo();
	//void search_car();
};
//#############################################  VALIDATION  #############################################################

const auto VALIDATE_NAME = "^\\D*$";
const auto VALIDATE_EMAIL = "^\\w+\\@\\w+\\.\\w+(\\.\\w+)*$";	//Định dạng email là: name@abc.xyz(.vn)
const auto VALIDATE_KEY = "^\\d{8}$";	//MSCN phải bao gồm 8 số
const auto VALIDATE_INPUT_NUMBER = "^[1-9]\\d+$";
const auto VALIDATE_INPUT_DISPLAY_SOUND = "^[1-5]$";
const auto VALIDATE_INPUT_SCREEN = "^[1-9][0-9]*$";	//input nhập vào phải là số (không có số 0 ở đầu E.g: 01 -> sai, 1 -> đúng)
const auto VALIDATE_INPUT_YES_NO = "^y$|^n$|^Y$|^N$";	//Các câu hỏi yes/no chỉ nhập vào y or n
const auto VALIDATE_TIMEZONE = "^[1-9]|[12][0-9]|3[0-2]$";
const auto VALIDATE_LANGUGE = "^[1-9]|[12][0-9]|3[0]$";
const auto VALIDATE_CHOICE_1_2 = "^[1-2]$";
bool check_validation(string user_input, const char* regEx);

//#############################################  FILE PROCESSING  #############################################################

//extern vector <string> timeZoneList;
//extern vector <string> languageList;
extern char** timeZoneList; 
const int num_of_line_timeZoneList = 32;
extern pair<int, string> TIMEZONE[num_of_line_timeZoneList];

extern char** languageList; 
const int num_of_line_languageList = 30;
extern pair<int, string> LANGUAGE[num_of_line_languageList];

void selection_sort(string arr, int n);
void print_in_oder_alphabet(const char* file_path, const int index_of_line, const int num_of_line);
//vector <string> download_file(const char* file_path);
char** download_file(const char* file_path, int num_of_line);

extern int gNum_of_car;// Tổng số xe khai báo trong listz
//#############################################  STRUCT DATA  #############################################################
typedef struct {

	string m_name;
	string m_email;
	string m_keyNumber;
	int m_odo;
	int	m_remindService;
	// display
	int m_light_level;
	int m_screen_light_level;
	int m_taplo_light_lv;
	//sound
	int m_call;
	int m_media;
	int m_navi;
	int m_notification;
	//general
	string m_time;
	string m_language;

} USER_DATA;

#endif