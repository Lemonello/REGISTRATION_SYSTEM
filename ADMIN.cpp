#include"CLASSES.h"
#include"LIBRARIES.h"

void Admin::change_name()
{
	string new_name;
	cin.ignore();
	getline(cin, new_name);
	while (!check_dubl_name(admins_file, new_name))
	{
		cin.ignore();
		getline(cin, new_name);
	}
	name_of_admin = new_name;
}
void Admin::change_pass()
{
	int attempts = 0;
	string password;
	while (attempts != 3)
	{
		cout << "Enter old password:" << endl;
		cin >> password;
		if (password == pass_of_admin)
		{
			cout << "Enter new password:" << endl;
			cin >> password;
			pass_of_admin = password;
			return;
		}
		attempts++;
	}
	return;
}
void Admin::show_all_users(vector<User>& users)
{
	for (const auto& i : users) cout << i;
}
void Admin::del_user(vector<User>& users)
{
	int number;
	string name_del, sec_pass;
	count_of_accs(users_file, number);
	cout << "Enter name of user:\t";
	cin >> name_del;
	cout << "Enter security password:\t";
	cin >> sec_pass;
	if (sec_pass != PASS) atexit(finish_programm);
	for (int i = 0; i < number; i++)
	{
		if (name_del == users[i].get_name())
		{
			auto iter_del = (users.begin() + i);
			users.erase(iter_del);
			return;
		}
	}
}