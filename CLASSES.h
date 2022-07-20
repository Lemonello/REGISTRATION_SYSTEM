#include"LIBRARIES.h"
#ifndef CLASSES_H
#define CLASSES_H


const int SIZE = 5;

extern string admins_file, users_file, PASS;

class Admin;
class User;

//independ functions
void count_of_accs(string file, int& count);
bool check_dubl_name(string file, string name);
void get_files(string& file1, string& file2);
void finish_programm();

//menu functions
void menu_help(int type);
void menu_main(vector<User>& users, vector<Admin>& admins);
void menu_user(vector<User>& users);
void menu_admin(vector<Admin>& admins, vector<User>& users);

//enums for menu
enum LOG_OR_ADD { LOG_IN = 1, ADD_ACC = 2 };
enum USER_OR_ADMIN { USER = 1, ADMIN };
enum ACC { CHANGE_NAME = 1, CHANGE_PASS, DEL_ACC, SHOW_ALL };


class User
{
	string name_of_user, pass_of_user;
	int flag = 2; //1- acc is empty, 2-acc is already taken
public:
	template<typename T> friend void read_file(vector<T>& data, string name_of_file);
	template<typename T> friend void out_file(vector<T>& data, string name_of_file);
	template<typename T> friend int log_in_acc(vector<T>& data);
	friend void add_acc(vector<User>& data);
	friend istream& operator>>(istream& stream, User& ob);
	friend ifstream& operator >> (ifstream& stream, User& ob);
	friend ostream& operator<<(ostream& stream, User ob);
	friend ofstream& operator<<(ofstream& stream, User ob);
	friend bool operator ==(User& ob1, User& ob2);
	string get_name() { return name_of_user; }
	int del_user();
	void change_name();
	void change_pass();
};

//1-User, 2-Admin

class Admin
{
	string name_of_admin, pass_of_admin;
	int flag = 2;
public:
	template<typename T> friend void read_file(vector<T>& data, string name_of_file);
	template<typename T> friend void out_file(vector<T>& data, string name_of_file);
	template<typename T> friend int log_in_acc(vector<T>& data);
	friend ofstream& operator<<(ofstream& stream, Admin ob);
	friend istream& operator>>(istream& stream, Admin& ob);
	friend ifstream& operator >> (ifstream& stream, Admin& ob);
	friend bool operator ==(Admin& ob1, Admin& ob2);
	void change_pass();
	void change_name();
	void show_all_users(vector<User>& users);
	void del_user(vector<User>& users);
};

//template friend functions

template<typename T>
void read_file(vector<T>& data, string name_of_file)
{
	int count = 0;
	count_of_accs(name_of_file, count);
	if (count > data.size()) data.resize(count);
	ifstream fin(name_of_file);
	for (int i = 0; i < count; i++)
	{
		fin >> data[i];
	}
	fin.close();
}

template<typename T>
void out_file(vector<T>& data, string name_of_file)
{
	ofstream fout(name_of_file);
	for (const auto& i : data)
	{
		fout << i;
	}
	fout.close();
}

template<typename T>
int log_in_acc(vector<T>& data)
{
	T ob{}; size_t count = data.size();
	cin >> ob;
	for (int i = 0; i < count; i++)
	{
		if (ob == data[i])
		{
			cout << "You are sucscessfully entered to account!!!" << endl;
			return i;
		}
	}
	cout << "Try again!!!" << endl;
	atexit(finish_programm);
}
#endif


