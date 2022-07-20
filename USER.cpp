#include"CLASSES.h"
#include"LIBRARIES.h"

void User::change_name()
{
	string new_name;
	cout << "Enter new name of user" << endl;
	cin.ignore();
	getline(cin, new_name);
	while (!check_dubl_name(users_file, new_name))
	{
		cin.ignore();
		getline(cin, new_name);
	}
	name_of_user = new_name;
}
void User::change_pass()
{
	int attempts = 0;
	string password;
	while (attempts != 3)
	{
		cout << "Enter old password:" << endl;
		cin >> password;
		if (password == pass_of_user)
		{
			cout << "Enter new password:" << endl;
			cin >> password;
			pass_of_user = password;
			return;
		}
		attempts++;
	}
	return;
}
int User::del_user()
{
	int attempts = 0;
	string pass_check;
	while (attempts != 3)
	{
		cout << "Enter password of your account:" << endl;
		cin >> pass_check;
		if (pass_check == pass_of_user) return 1;
		attempts++;
	}
	return 0;
}