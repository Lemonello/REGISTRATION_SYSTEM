#include"CLASSES.h"
#include"LIBRARIES.h"

//USER

void add_acc(vector<User>& data)
{
	User ob_add;
	cin >> ob_add;
	while (!check_dubl_name(users_file, ob_add.name_of_user))
	{
		cout << "Your name is alreaddy taken" << endl;
		cin >> ob_add;
	}
	data.push_back(ob_add);
}