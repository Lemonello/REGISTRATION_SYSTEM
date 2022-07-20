#include"LIBRARIES.h"
#include"CLASSES.h"

string users_file, admins_file, PASS = "1234";

int main()
{
	vector<User> users(SIZE);
	vector<Admin> admins(SIZE);
	get_files(users_file, admins_file);
	menu_main(users, admins);
}