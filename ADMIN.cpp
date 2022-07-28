#include"CLASSES.h"
#include"LIBRARIES.h"


void Admin::change_name()
{
	string new_name;
	cout << "Enter new name" << endl;
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
	string  sec_pass, name_check;
	count_of_accs(users_file, number);
	cout << "Enter security password:\t";
	cin >> sec_pass;
	if (sec_pass != PASS) finish_programm();
	cout << "Enter name of user by letter:\t";
	cin >> name_check;
	for (int i = 0; i < number; i++)
	{
		string user_name;
		for (int j = 0; j < name_check.length(); j++) //generate string with loop
		{
			user_name[j] = users[i].get_name()[j];
		}
		if (_stricmp(user_name.c_str(), name_check.c_str())==0) //Function for compare string
		{
			int choice;
			cout << users[i].get_name() << endl;
			cout << "Is this right word?" << endl;
			cout << "1-Yes, 2-No" << endl;
			cin >> choice;
			if (choice == 1)
			{
				auto iter_del = (users.begin() + i);
				users.erase(iter_del);
				return;
			}
		}
		system("cls");
	}
}