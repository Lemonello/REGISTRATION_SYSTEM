#include"LIBRARIES.h"
#include"CLASSES.h"

//Function for help main menu func

void menu_help(int type)
{
	if (type == 1)
	{
		cout << "What are you want to do?" << endl;
		cout << "1.Change name" << endl << "2.Change password" << endl;
		cout << "3.Delete account" << endl;
	}
	if (type == 2)
	{
		cout << "What are you want to do?" << endl;
		cout << "1.Change name" << endl << "2.Change password" << endl;
		cout << "3.Delete user's account" << endl << "4.Show all users" << endl;
	}
}

void menu_main(vector<User>& users, vector<Admin>& admins)
{

	int choice;
	cout << "What type of account are you want to add or log in?" << endl;
	cout << "1.User\t" << "2.Admin(only log in)" << endl;
again:
	cout << "Enter your choice:\t" << endl;
	cin >> choice;
	switch (choice)
	{
	case USER:
	{
		menu_user(users);
		break;
	}
	case ADMIN:
	{
		menu_admin(admins, users);
		break;
	}
	default:
	{
		goto again;
	}
	}
}

void menu_user(vector<User>& users)
{
	int choice;
	cout << "What are you want to do?" << endl;
	cout << "1.Log in" << endl << "2.Add acc" << endl;
user_again:
	cout << "Enter your choice:\t" << endl;
	cin >> choice;
	read_file(users, users_file);
	switch (choice)
	{
	case LOG_IN:
	{
		int number = log_in_acc(users);
		if (number != 404)
		{
			menu_help(1);
			cin >> choice;
		user_switch:
			switch (choice)
			{
			case CHANGE_NAME:
			{
				users[number].change_name();
				out_file(users, users_file);
				break;
			}
			case CHANGE_PASS:
			{
				users[number].change_pass();
				out_file(users, users_file);
				break;
			}
			case DEL_ACC:
			{
				if (users[number].del_user())
				{
					auto iter_del = (users.begin() + number);
					users.erase(iter_del);
					out_file(users, users_file);
					break;
				}
				else cout << "Try again later" << endl;
				break;
			}
			default:
			{
				goto user_switch;
			}
			}
		}
		break;
	}
	case ADD_ACC:
	{
		add_acc(users);
		out_file(users, users_file);
		break;
	}
	default:
	{
		goto user_again;
	}
	}
}

void menu_admin(vector<Admin>& admins, vector<User>& users)
{
	int choice;
	read_file(admins, admins_file);
	int number = log_in_acc(admins);
	if (number != 404)
	{
		menu_help(2);
	admin_switch:
		cin >> choice;
		switch (choice)
		{
		case CHANGE_NAME:
		{
			admins[number].change_name();
			out_file(admins, admins_file);
			break;
		}
		case CHANGE_PASS:
		{
			admins[number].change_pass();
			out_file(admins, admins_file);
			break;
		}
		case SHOW_ALL:
		{
			read_file(users, users_file);
			admins[number].show_all_users(users);
			break;
		}
		case DEL_ACC:
		{
			read_file(users, users_file);
			admins[number].del_user(users);
			out_file(users, users_file);
			break;
		}
		default:
		{
			goto admin_switch;
		}
		}
	}
}