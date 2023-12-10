#include "Car.h"
using namespace std;
//######################################################CLASS CAR##################################################################

Car::Car() {
	string car_name = " ";
	string personal_key = " "; 	// Chuoi 8 ky tu so
	string email = " ";			// email format abc@xyz.com
	int odo = 0;
	int service_remind = 0;
}
Car::~Car() {
	cout << "destruction" << endl;
};

string Car::getName() {
	return this->car_name;
}

string Car::getKey() {
	return this->personal_key;
}
string Car::getEmail() {
	return email;
}
int Car::getODO() {
	return this->odo;
}

int Car::getServiceRemind() {
	return this->service_remind;
}


void Car::setName(string data) {
	car_name = data;
}
void Car::setEmail(string data) {
	email = data;
}
void Car::setKey(string data) {
	personal_key = data;
}
void Car::setOdo(int data) {
	odo = data;
}
void Car::setServiceRemind(int data) {
	service_remind = data;
}
void Car::basic_info() {
	string name, Email, key, oDo, sv;
	//cin.ignore();	//Xóa bộ nhớ đệm trước khi getline để bò qua ký tự '\n'

	/*				ENTER OWNER NAME			*/
	do {
		cout << "SETTING USER INFORMATION\n" << endl;
		cout << "Owner name: ";
		getline(cin, name);
	} while (!check_validation(name, VALIDATE_NAME));
	setName(name);


	/*				ENTER PRIVATE ID			*/
	do {
		system("cls");
		cout << "SETTING USER INFORMATION\n" << endl;
		cout << "Owner: " << car_name << endl;
		cout << "Private Key: ";
		getline(cin, key);
	} while (!check_validation(key, VALIDATE_KEY));	//Nếu ID nhập vào không hợp lệ thì nhập lại, các thông tin đã lưu
	setKey(key);

	/*				ENTER OWNER EMAIL			*/
	do {
		system("cls");
		cout << "SETTING USER INFORMATION\n" << endl;
		cout << "Owner: " << car_name << endl;
		cout << "Private Key: " << personal_key << endl;
		cout << "Email: ";
		getline(cin, Email);
	} while (!check_validation(Email, VALIDATE_EMAIL));
	setEmail(Email);

	/*				ENTER CAR ODO NUMBER			*/
	do {
		system("cls");
		cout << "SETTING USER INFORMATION\n" << endl;
		cout << "Owner: " << car_name << endl;
		cout << "Private ID: " << personal_key << endl;
		cout << "Email: " << email << endl;
		cout << "Odo number: ";
		getline(cin, oDo);
	} while (!check_validation(oDo, VALIDATE_INPUT_NUMBER));
	setOdo(stoi(oDo));

	/*				ENTER SERVICE REMIND NUMBER			  */
	do {
		system("cls");
		cout << "SETTING USER INFORMATION\n" << endl;
		cout << "Owner: " << car_name << endl;
		cout << "Private Key: " << personal_key << endl;
		cout << "Email: " << email << endl;
		cout << "Odo number: " << odo << endl;
		cout << "Remind service number (km): ";
		getline(cin, sv);
	} while (!check_validation(sv, VALIDATE_INPUT_NUMBER));
	setServiceRemind(stoi(sv));
	++gNum_of_car;
}
void Car::input_Info() {
	basic_info();
}
//void Car::basicInfo() {
//	input_Info();
//}

void Car::printCommoInfo() {
	cout << setw(25) << left << car_name << setw(20) << email << setw(20) << personal_key << setw(15) << odo << setw(25) << service_remind;
}

//#############################################  VALIDATE  #############################################################


bool check_validation(string user_input, const char* regEx) {
	regex Input(regEx);
	return regex_match(user_input, Input);
}

//#############################################  VALIDATE  #############################################################
/*
vector <string> download_file(const char* file_path) {
	ifstream filee;	vector <string> V_list;
	filee.open(file_path, ios::in);
	if (!filee.is_open()) {
		cout << "File loii!!" << endl;
		exit(0);
	}
	while (!filee.eof()) {
		string tmp;
		getline(filee, tmp);
		V_list.push_back(tmp);
	}
	filee.close();
	return  V_list;
}
*/

char** download_file(const char* file_path, int num_of_line) {
	ifstream filee; 
	filee.open(file_path, ios::in);
	if (!filee.is_open()) {
		cout << "File loii!!" << endl;
		exit(0);
	}

	char** V_list = new char* [num_of_line];
	int I = 0;
	while (!filee.eof()) {
		string tmp;
		getline(filee, tmp);
		const int Size = tmp.size();
		char* temp = new char[Size + 1];
		strcpy_s(temp, Size + 1, tmp.c_str());
		V_list[I]= temp;
		I++;
	}
	filee.close();
	return  V_list;
	delete[] V_list;
}
char** timeZoneList = download_file("timezones.txt", num_of_line_timeZoneList);
char** languageList = download_file("languages.txt", num_of_line_languageList);

void Swap(string& a, string& b) {
	string tmp = a;
	a = b;
	b = tmp;
}
void selection_sort(string arr[], int n) {
	for (int i = 0; i < n-1; i++) {
		int Index = i;
		for (int j = i; j < n - 1; j++) {
			if (arr[Index] > arr[j]) Index = j;
		}
		if(Index != i) Swap(arr[Index], arr[i]);
	}
}

void print_in_oder_alphabet(const char* file_path, const int index_of_line, const int num_of_line) // dùng map
{
	char** V_list = download_file(file_path, num_of_line);
	map<string, int> MAP;
	for (int i = 0; i < num_of_line; i++) {
		string line, new_line;
		line = V_list[i];// "1: (GMT-12:00) /  International Date Line West"
		if (i < 9) line = "0" + line;// "01: (GMT-12:00) /  International Date Line West"
		int Size = (line).size();
		for (int j = index_of_line; j < Size; j++) //index_of_line: vị trí bắt đầu lấy dữ liệu để xét thứ tự theo alphabet
		// ví dụ "1: (GMT-12:00) /  International Date Line West" thì lấy từ vị trí 19 trở đi: "International Date Line West"
		{
			new_line += line[j];//   "International Date Line West"
		}
		MAP[new_line] = i;// first: "International Date Line West"; second: 1 - thứ tự theo bảng ban đầu
	}
	for (auto x:MAP) {
		cout << V_list[x.second] << endl;
	}
}
/*

void print_in_oder_alphabet(const char* file_path, const int num_of_line) // không dùng map
{
	char** V_list = download_file(file_path, num_of_line);
	string* s_list = new string [num_of_line];
	for (int i = 0; i < num_of_line; i++) {
		string line, new_line;
		line = V_list[i];// "1: (GMT-12:00) /  International Date Line West"
		if (i < 9) line = "0" + line;// "01: (GMT-12:00) /  International Date Line West"
		int Size = (line).size();
		for (int j = 19; j < Size; j++) {
			new_line += line[j];//   "International Date Line West"
		}
		s_list[i] = new_line; //  "International Date Line West"
	}
	selection_sort(s_list, num_of_line);
	
	delete[]s_list;
}
*/



//vector <string> timeZoneList = download_file("timezones.txt");
//vector <string> languageList = download_file("languages.txt");
//vector <string> carList = download_file(STORAGE_PATH);

//fstream file_storage(STORAGE_PATH);
/*
USER_DATA get_user_data_from_file(string line) {
	//Common: TONG VAN LINH, abc@xyz.com, 11223344, 3000, 5000; Display: 1, 2, 3; Sound: 1, 2, 3, 4; General: GMT-10:00, English
	USER_DATA new_data;
	vector<string> data_line;
	string Buffer;
	for (int i = 0; i < line.size(); i++) {
		if ((line[i] != ',') && (line[i] != ';') && (line[i] != ':')) {
			Buffer += line[i];
		}
		else {
			if ((Buffer == " Display") || (Buffer == " Sound") || (Buffer == " General") || (Buffer == "Common")) {
				Buffer = "";
			}
			else {
				data_line.push_back(Buffer);
				Buffer = "";
			}
		}
	}

	int Size = 14; // data_line.size()
	//Ghép các phần của chỉ số múi giờ (bị tách khi xử lý chuỗi) là "GMT-10",":" và "00"
	data_line[Size - 2] = data_line[Size - 2] + ':' + data_line[Size - 1];
	data_line[Size - 1] = Buffer;// Ghi những giá trị sau dấu phẩy cuối cùng vào vector

	new_data.m_name = data_line[0];
	new_data.m_email = data_line[1];
	new_data.m_keyNumber = (data_line[2]);
	new_data.m_odo = stoi(data_line[3]);
	new_data.m_remindService = stoi(data_line[4]);
	new_data.m_light_level = stoi(data_line[5]);
	new_data.m_screen_light_level = stoi(data_line[6]);
	new_data.m_taplo_light_lv = stoi(data_line[7]);
	new_data.m_media = stoi(data_line[8]);
	new_data.m_call = stoi(data_line[9]);
	new_data.m_navi = stoi(data_line[10]);
	new_data.m_notification = stoi(data_line[11]);
	new_data.m_time = data_line[12];
	new_data.m_language = data_line[13];
	return new_data;
}*/
/*
void WritingDataToFile(USER_DATA new_car_upload) {
	//Common: TONG VAN LINH, abc@xyz.com, 11223344, 3000, 5000; Display: 1, 2, 3; Sound: 1, 2, 3, 4; General: GMT-10:00, English
	ofstream File;
	File.open(STORAGE_PATH, ios::app);
	if (!File.is_open())
	{
		cout << "\nError!" << endl;
		exit(0);
	}
	File << "Common: " << new_car_upload.m_name << ", " << new_car_upload.m_email << ", " << new_car_upload.m_keyNumber << ", " << new_car_upload.m_odo << ", " << new_car_upload.m_remindService << "; ";
	File << "Display: " << new_car_upload.m_light_level << ", " << new_car_upload.m_screen_light_level << ", " << new_car_upload.m_taplo_light_lv << ", ";
	File << "Sound: " << new_car_upload.m_call << ", " << new_car_upload.m_media << ", " << new_car_upload.m_navi << ", " << new_car_upload.m_notification << "; ";
	File << "General: " << new_car_upload.m_time << ", " << new_car_upload.m_language << endl;
	File.close();
}*/
/*
void delete_file(const char* fileName) {
	int result = remove(fileName);
	if (result != 0) {
		// print error message
		cerr << "File deletion failed";
	}
	else {
		cout << "File deleted successfully";
	}
}
*/

