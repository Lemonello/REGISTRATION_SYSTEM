#include"CLASSES.h"
#include"LIBRARIES.h"

void count_of_accs(string file, int& count)
{
	int count_of_acc = 0;
	ifstream fin(file);
	while (true)
	{
		string s;
		getline(fin, s);
		if (!fin.eof()) count_of_acc++;
		else break;
	}
	fin.close();
	count_of_acc++;
	count = (count_of_acc / 2);
}

bool check_dubl_name(string file, string name)
{
	string file_name;
	ifstream fin(file);
	while (fin)
	{
		getline(fin, file_name);
		if (name == file_name) return 0;
	}
	return 1;
}

//Work with files

void get_files(string& users_file, string& admins_file)
{
	cout << "Enter names of two files for working:" << endl;
	cin >> users_file >> admins_file;
	ifstream fin1(users_file);
	ifstream fin2(admins_file);
	if (fin1.is_open() && fin2.is_open())
	{
		fin1.close();
		fin2.close();
		return;
	}
	atexit(finish_programm);
}

//Finishing programm at different situations

void finish_programm()
{
	cout << "Something went wrong" << endl;
}