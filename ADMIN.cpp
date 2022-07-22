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
	string  sec_pass;
	char name_symb;
	count_of_accs(users_file, number);
	cout << "Enter security password:\t";
	cin >> sec_pass;
	cout << "Enter name of user by letter:\t";
	cin >> name_symb;
	if (sec_pass != PASS) finish_programm();
	for (int i = 0; i < number; i++)
	{
		if (tolower(name_symb) == users[i].get_name()[0] || toupper(name_symb) == users[i].get_name()[0])
		{
			int choice;
			cout << users[i].get_name() << endl;
			cout << "Is this right name?" << endl;
			cout << "1=Yes, 2-No" << endl;
			cin >> choice;
			if (choice == 1)
			{
				auto iter_del = (users.begin() + i);
				users.erase(iter_del);
				return;
			}
			if (choice == 2) continue;
		}
		system("cls");
	}
}