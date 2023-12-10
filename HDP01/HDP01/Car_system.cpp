
#include"Car.h"
#include"Display.h"
#include"General.h"
#include "Car_system.h"

using namespace std;

//Car_system** car_list = new Car_system * [1000];
Car_system* car_list[1000];
Car_system* gCar = new Car_system;
int gNum_of_car = 0;

Car_system::Car_system() {
	display = new Display;
	sound = new Sound;
	general = new General;
	is_first_time = true;
}
Car_system::~Car_system() {
	cout << "destruction!" << endl;
}
bool Car_system::get_is_first_time() {
	return is_first_time;
}
void Car_system::set_is_first_time(bool data) {
	is_first_time = data;
}



void Car_system::setDisplay(Display* data) {
	display = data;
}
Display* Car_system::getDisplay() {
	return display;
}
void Car_system::setSound(Sound* data) {
	sound = data;
}
Sound* Car_system::getSound() {
	return sound;
}
void Car_system::setGeneral(General* data) {
	general = data;
}
General* Car_system::getGeneral() {
	return general;
}



/* ####################### MENU SCREEN ######################## */
void Car_system::Main_Screen() {
	string inputkey;
	do {
		system("cls");
		cout << "--- SELECT INPUT ---" << endl;
		cout << "1. INPUT SETTING INFORMATION" << endl;
		cout << "2. PRINT SETTING INFORMATION" << endl;
		cout << "3. EXIT" << endl;
		cout << "Your selection: ";
		getline(cin, inputkey);
	} while (!check_validation(inputkey, VALIDATE_INPUT_SCREEN));
	int key = stoi(inputkey);

	switch (key) {
	case 1:
		Input_Screen();
		break;
	case 2:
		Print_Screen();
		break;
	case 3:
		cout << endl;
		cout << "GOOD BYE !!!" << endl;
		exit(0);
		return;
	default:
		cout << "Invalid choice, please enter again" << endl;
		system("pause");
		Main_Screen();
		break;
	}
}

/* ######################## INPUT SCREEN ####################### */
void Car_system::Input_Screen() {
	string inputkey;
	do {
		system("cls");
		cout << "--- SELECT INPUT ---" << endl;
		cout << "1. DISPLAY SETTING" << endl;
		cout << "2. SOUND SETTING" << endl;
		cout << "3. GENERAL SETTING" << endl;
		cout << "4. RETURN" << endl;
		cout << "Your selection: ";
		getline(cin, inputkey);
	} while (!check_validation(inputkey, VALIDATE_INPUT_SCREEN));
	int key = stoi(inputkey);

	switch (key) {
	case 1:
		Input_Screen_Display();
		break;
	case 2:
		Input_Screen_Sound();
		break;
	case 3:
		Input_Screen_General();
		break;
	case 4:
		Return_screen();
		break;
	default:
		cout << "Invalid choice, please enter again" << endl;
		system("pause");
		gCar = new Car_system; is_first_time = true;
		Input_Screen();
		break;
	}
}
void Car_system::Input_Screen_Display() {
	string inputkey;
	do {
		system("cls");
		cout << "----- Input Display Setting ------" << endl;
		if (is_first_time) cout << "Car Index: " << gNum_of_car + 1 << endl;
		else cout << "Car Index: " << gNum_of_car << endl;
		// kiểm tra đã nhập thông tin cơ bản: tên, key, email, odo, remind service chưa
		if (is_first_time) {
			gCar->basic_info();
			is_first_time = false;
		}

		checkUserKey(gCar); //Kiểm tra phần tử đã tồn tại trong mảng chưa
		gCar->getDisplay()->input_Info();

		cout << "Will you input for car " << gNum_of_car + 1 << " (y/n): ";
		getline(cin, inputkey);
		while (!check_validation(inputkey, VALIDATE_INPUT_YES_NO))
		{
			system("cls");
			cout << "----- Input Display Setting ------" << endl;
			cout << "Car Index: " << gNum_of_car + 1 << endl;
			cout << "Owner: " << gCar->getName() << endl;
			cout << "Private ID: " << gCar->getKey() << endl;
			cout << "Email: " << gCar->getEmail() << endl;
			cout << "Odo number: " << gCar->getODO() << endl;
			cout << "Remind service number (km): " << gCar->getServiceRemind() << endl;
			cout << "Light level: " << gCar->getDisplay()->getLightLevel() << endl;
			cout << "Screen light level: " << gCar->getDisplay()->getScreenLightLevel() << endl;
			cout << "Taplo light level: " << gCar->getDisplay()->getTaploLightLevel() << endl;
			cout << "Will you input for car " << gNum_of_car + 1 << " (y/n): "<<endl;
			cout << "Please enter y or n: ";
			getline(cin, inputkey);
		}
		if (inputkey == "y" || inputkey == "Y") {
			//++gNum_of_car;
			gCar = new Car_system;
			is_first_time = true;
		}
		else {
			Input_Screen();
		}
	} while (inputkey == "y" || inputkey == "Y"); //Nếu người dùng chọn yes thì tiếp tục nhập phần tử cho mảng Display
	//sort_list();
	Input_Screen();
}

void Car_system::Input_Screen_Sound() {
	string inputkey;
	do {
		system("cls");
		cout << "----- Input Sound Setting ------" << endl;
		if(is_first_time) cout << "Car Index: " << gNum_of_car + 1 << endl;
		else cout << "Car Index: " << gNum_of_car << endl;
		// kiểm tra đã nhập thông tin cơ bản: tên, key, email, odo, remind service chưa
		if (is_first_time) {
			gCar->basic_info();
			is_first_time = false;
		}
		checkUserKey(gCar); //Kiểm tra phần tử đã tồn tại trong mảng chưa

		gCar->getSound()->input_Info();
		cout << "Will you input for car " << gNum_of_car + 1 << " (y/n): ";
		getline(cin, inputkey);
		while (!check_validation(inputkey, VALIDATE_INPUT_YES_NO))
		{
			system("cls");
			cout << "----- Input Sound Setting ------" << endl;
			cout << "Car Index: " << gNum_of_car + 1 << endl;
			cout << "Owner: " << gCar->getName() << endl;
			cout << "Private ID: " << gCar->getKey() << endl;
			cout << "Email: " << gCar->getEmail() << endl;
			cout << "Odo number: " << gCar->getODO() << endl;
			cout << "Remind service number (km): " << gCar->getServiceRemind() << endl;
			cout << "Media volume: " << gCar->getSound()->getMediaVolume() << endl;
			cout << "Call volume: " << gCar->getSound()->getCallVolume() << endl;
			cout << "Navigation volume: " << gCar->getSound()->getNavigationVolume() << endl;
			cout << "Notification volume: " << gCar->getSound()->getNotificationVolume() << endl;
			cout << "Will you input for car " << gNum_of_car + 1 << " (y/n)" << endl;
			cout << "Please enter y or n: ";
			getline(cin, inputkey);
		}
		if (inputkey == "y" || inputkey == "Y") {
			//++gNum_of_car;
			gCar = new Car_system;
			is_first_time = true;
		}
		else {
			Input_Screen();
		}

	} while (inputkey == "y" || inputkey == "Y");
	//sort_list();
	Input_Screen();
}
void Car_system::Input_Screen_General() {
	string inputkey;
	do {
		system("cls");
		cout << "----- Input General Setting ------" << endl;
		if (is_first_time) cout << "Car Index: " << gNum_of_car + 1 << endl;
		else cout << "Car Index: " << gNum_of_car << endl;

		// kiểm tra đã nhập thông tin cơ bản: tên, key, email, odo, remind service chưa
		if (is_first_time) {
			gCar->basic_info();
			is_first_time = false;
		}
		checkUserKey(gCar); //Kiểm tra phần tử đã tồn tại trong mảng chưa

		string input_time, choice;
		/*
		do {
			do {
				system("cls");
				cout << "--- SELECT TIMEZONE DATA ---" << endl;
				cout << "Would you like to sort the list in order Alphabet(1) or Utc/index (2)?" << endl;
				cout << "Your choice: ";
				getline(cin, choice);
			} while (!check_validation(choice, VALIDATE_CHOICE_1_2));
			if(choice == "1") {
				print_in_oder_alphabet("timezones.txt", 19, num_of_line_timeZoneList);
			}
			else {
				for (int i = 0; i < num_of_line_timeZoneList; i++) {
					cout << timeZoneList[i] << endl;
				}
			}
			cout << "YOUR SELECTION: ";
			getline(cin, input_time);
		} while (!check_validation(input_time, VALIDATE_TIMEZONE));
		*/
		do {
			system("cls");
			cout << "--- SELECT TIMEZONE DATA ---" << endl;
			cout << "Would you like to sort the list in order Alphabet(1) or Utc/index (2)?" << endl;
			cout << "Your choice: ";
			getline(cin, choice);
		} while (!check_validation(choice, VALIDATE_CHOICE_1_2));
		
		do {
			if (choice == "1") {
				print_in_oder_alphabet("timezones.txt", 16, num_of_line_timeZoneList);
			}
			else {
				for (int i = 0; i < num_of_line_timeZoneList; i++) {
					cout << timeZoneList[i] << endl;
				}
			}
			cout << "YOUR SELECTION: ";
			getline(cin, input_time);
		} while (!check_validation(input_time, VALIDATE_TIMEZONE));

		string input_language;
		//SETTING LANGUAGE
		string Choice;
		do {
			system("cls");
			cout << "--- SELECT LANGUAGE DATA ---" << endl;
			cout << "Would you like to sort the list in order Alphabet(1) or Utc/index (2)?" << endl;
			cout << "Your choice: ";
			getline(cin, Choice);
		} while (!check_validation(Choice, VALIDATE_CHOICE_1_2));
		do {
			if (Choice == "1") {
				print_in_oder_alphabet("languages.txt", 4, num_of_line_languageList);
			}
			else {
				for (int i = 0; i < num_of_line_languageList; i++) {
					cout << languageList[i] << endl;
				}
			}
			cout << "YOUR SELECTION: ";
			getline(cin, input_language);
		} while (!check_validation(input_language, VALIDATE_LANGUGE));

		gCar->getGeneral()->set_timeZone(timeZoneList[stoi(input_time) - 1]);
		gCar->getGeneral()->set_language(languageList[stoi(input_language) - 1]);
		cout << "Will you input for car " << gNum_of_car + 1 << " (y/n): ";
		getline(cin, inputkey);
		while (!check_validation(inputkey, VALIDATE_INPUT_YES_NO)) {
			system("cls");
			cout << "----- Input General Setting ------" << endl;
			cout << "Car Index: " << gNum_of_car + 1 << endl;
			cout << "Owner: " << gCar->getName() << endl;
			cout << "Private ID: " << gCar->getKey() << endl;
			cout << "Email: " << gCar->getEmail() << endl;
			cout << "Odo number: " << gCar->getODO() << endl;
			cout << "Remind service number (km): " << gCar->getServiceRemind() << endl;
			cout << "Timezone: " << gCar->getGeneral()->get_timeZone() << endl;
			cout << "Language: " << gCar->getGeneral()->get_language() << endl;
			cout << "Will you input for car " << gNum_of_car + 1 << " (y/n): " << endl;;
			cout << "Please enter y or n: ";
			getline(cin, inputkey);
			//cin.clear();
		}
		if (inputkey == "y" || inputkey == "Y") {
			gCar = new Car_system;
			is_first_time = true;
		}
		else {
			Input_Screen();
		}
	} while (inputkey == "y" || inputkey == "Y");
	Input_Screen();
}
void Car_system::Return_screen() {
	string inputkey;
	if (gNum_of_car) {
		do {
			system("cls");
			cout << " Do you want to save data to list? yes(y) or no(n)" << endl;
			cout << "Your choice: ";
			getline(cin, inputkey);

			if (inputkey == "y" || inputkey == "Y") {
				car_list[gNum_of_car - 1] = gCar;
				gCar = new Car_system;
				is_first_time = true;
				cout << "data is saved!" << endl;
			}
			else {
				gCar = new Car_system;
				is_first_time = true;
				cout << "not saved! back to menu" << endl;
			}
		} while (!check_validation(inputkey, VALIDATE_INPUT_YES_NO));
		system("pause");
	}
	Main_Screen();
}
/* ####################### PRINT SCREEN ######################## */
void Car_system::Print_Screen() {
	string inputkey;
	do {
		system("cls");
		cout << "--- SELECT INPUT ---" << endl;
		cout << "1. PRINT DISPLAY SETTING INFORMATION" << endl;
		cout << "2. PRINT SOUND SETTING INFORMATION" << endl;
		cout << "3. PRINT GENERAL SETTING INFORMATION" << endl;
		cout << "4. PRINT ALL SETTING INFORMATION" << endl;
		cout << "5. RETURN" << endl;
		cout << "Your selection: ";
		getline(cin, inputkey);
		cin.clear();
	} while (!check_validation(inputkey, VALIDATE_INPUT_SCREEN));
	int key = stoi(inputkey);

	switch (key) {
	case 1:
		Print_Screen_Display();
		break;
	case 2:
		Print_Screen_Sound();
		break;
	case 3:
		Print_Screen_General();
		break;
	case 4:
		Print_Screen_All();
		break;
	case 5:
		Main_Screen();
		break;
	default:
		cout << "Invalid choice, please enter again" << endl;
		system("pause");
		Print_Screen();
		break;
	}
}
void Car_system::printCommonInfo() {
	cout << setw(25) << left << getName() << setw(20) << getEmail() << setw(20) 
		<< getKey() << setw(15) << getODO() << setw(25) << getServiceRemind();
}
void Car_system::Print_Screen_Display() {
	system("cls");
	cout << "--- Display setting ---" << endl;
	cout << setw(25) << left << "Name" << setw(20) << "Email" << setw(20) << "ID" << setw(15) << "ODO" 
		 << setw(25) << "Remind service" << setw(20) << "Light level" << setw(25) << "Screen light level" 
		 << setw(25) << "Taplo light level" << endl;
	for (int i = 0; i < gNum_of_car; i++) {
		cout << setw(25) << left << car_list[i]->getName() << setw(20) << car_list[i]->getEmail() << setw(20) 
			<< car_list[i]->getKey() << setw(15) << car_list[i]->getODO()
			<< setw(25) << car_list[i]->getServiceRemind() << setw(20) << car_list[i]->getDisplay()->getLightLevel() 
			<< setw(25) << car_list[i]->getDisplay()->getScreenLightLevel()
			<< setw(25) << car_list[i]->getDisplay()->getTaploLightLevel() << endl;
	}
	system("pause");
	Print_Screen();
}

void Car_system::Print_Screen_Sound() {
	system("cls");
	cout << "--- Sound setting ---" << endl;
	cout << setw(25) << left << "Name" << setw(20) << "Email" << setw(20) << "ID" << setw(15) << "ODO" 
		<< setw(25) << "Remind service" << setw(20) << "Media" << setw(20) << "Call" << setw(25) 
		<< "Navigation" << setw(25) << "Notification" << endl;
	for (int i = 0; i < gNum_of_car; i++) {
		cout << setw(25) << left << car_list[i]->getName() << setw(20) << car_list[i]->getEmail() << setw(20)
			<< car_list[i]->getKey() << setw(15) << car_list[i]->getODO()
			<< setw(25) << car_list[i]->getServiceRemind() << setw(20) << car_list[i]->getSound()->getMediaVolume()
			<< setw(20) << car_list[i]->getSound()->getCallVolume()
			<< setw(25) << car_list[i]->getSound()->getNavigationVolume() 
			<< setw(25) << car_list[i]->getSound()->getNotificationVolume()
			<< endl;
	}
	system("pause");
	Print_Screen();
}

void Car_system::Print_Screen_General() {
	system("cls");
	cout << "--- General setting ---" << endl;
	cout << setw(25) << left << "Name" << setw(20) << "Email" << setw(20) 
		<< "ID" << setw(15) << "ODO" << setw(25) << "Remind service" << setw(48) 
		<< "Timezone" << setw(30) << left << "Language" << endl;

	for (int i = 0; i < gNum_of_car; i++) {
		cout << setw(25) << left << car_list[i]->getName() << setw(20) << car_list[i]->getEmail() << setw(20)
			<< car_list[i]->getKey() << setw(15) << car_list[i]->getODO()
			<< setw(25) << car_list[i]->getServiceRemind() 
			<< setw(48) << car_list[i]->getGeneral()->get_timeZone() 
			<< setw(30) << car_list[i]->getGeneral()->get_language()
			<< endl;
	}
	system("pause");
	Print_Screen();
}

void Car_system::Print_Screen_All() {
	int i = 0;
	system("cls");
	cout << "--- All setting ---" << endl;
	while (i < gNum_of_car) {
		cout << setw(25) << left << "Name" << setw(20) << "Email" << setw(20) << "ID" << setw(15) << "ODO" << setw(25) << "Remind service" << endl;
			
		car_list[i]->printCommonInfo();
		cout << endl;
		cout << endl;
		cout << left << setw(20) << "Display: " << setw(20) << "Light" << setw(25) << "Screen Light" << setw(25) << "Taplo Light" << endl;

		cout << setw(20) << "";
		car_list[i]->getDisplay()->printCommoInfo();

		cout << left << setw(20) << "Sound: " << setw(20) << "Media" << setw(20) << "Call" << setw(25) << "Navigation" << setw(25) << "Notification" << endl;

		cout << setw(20) << "";
		car_list[i]->getSound()->printCommoInfo();

		cout << left << setw(20) << "General: " << setw(40) << "Timezone" << setw(30) << " " << "Language" << endl;
		cout << setw(20) << " ";
		car_list[i]->getGeneral()->printCommoInfo();

		i++;
		cout << "------------------------------------------------------------------------------------------------------" << endl;
	}
	system("pause");
	Print_Screen();
}

/* ####################### DATA PROCESSING ######################## */
void Car_system::OverWrite(Car_system* x) {
	setName(x->getName());
	setKey(x->getKey());
	setEmail(x->getEmail());
	setOdo(x->getODO());
	setServiceRemind(x->getServiceRemind());
	setDisplay(x->getDisplay());
	setSound(x->getSound());
	setGeneral(x->getGeneral());
}
/*
pair<bool, int> Car_system::checkUserKey(){
	bool isExisted = false;
	string key_input = this->getKey();
	int new_pos = gNum_of_car - 1;
	pair<bool, int> Pair;
	for (int i = 0; i < new_pos; i++) // chú ý duyệt đến giá trị <new_pos
	{
		string key_from_car_list = (car_list[i])->getKey();
		long long Key_from_car_list = stoll(key_from_car_list);
		long long Key_input = stoll(key_input);
		if (Key_input == Key_from_car_list) {
			Pair.first = true;
			Pair.second =i;
			break;
		}
	}
	return Pair;
}*/
void checkUserKey(Car_system* data) {
	bool isExisted = false;
	string key_input = data->getKey();
	int new_pos = gNum_of_car - 1;
	int Index = -1;
	for (int i = 0; i < new_pos; i++) // chú ý duyệt đến giá trị <new_pos
	{
		string key_from_car_list = (car_list[i])->getKey();
		long long Key_from_car_list = stoll(key_from_car_list);
		long long Key_input = stoll(key_input);
		if (Key_input == Key_from_car_list) {
			isExisted = true;
			Index = i; cout << Index << endl;
			break;
		}
		else
		{
			Index = new_pos;
		}
	}
	if (isExisted) {
		cout << "This car already existed, data will be overwriten" << endl;
		for (int i = Index; i < new_pos-1; i++) {
			cout << i << endl;
			car_list[i]->OverWrite(car_list[i + 1]);
		}
		cout << "1" << endl;
		gCar = new Car_system;
		--gNum_of_car;
		system("pause");
	}
	else
	{
		cout << "This is a new car, data will be appended to your list" << endl;
		car_list[gNum_of_car - 1] = gCar;
	}
}
void Car_system::printCommoInfo() {
	cout << setw(25) << left << getName() << setw(20) << getEmail() << setw(20) << getKey() << setw(15) << getODO() << setw(25) << getServiceRemind();
}