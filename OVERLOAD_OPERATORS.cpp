#include"CLASSES.h"
#include"LIBRARIES.h"

//User's overload operators

istream& operator>>(istream& stream, User& ob)
{
	stream >> ob.name_of_user >> ob.pass_of_user;
	return stream;
}
ostream& operator<<(ostream& stream, User ob)
{
	stream << "Name:\t" << ob.name_of_user << endl;
	stream << "Pass:\t" << ob.pass_of_user << endl;
	return stream;
}
ifstream& operator>>(ifstream& stream, User& ob)
{
	stream >> ob.name_of_user >> ob.pass_of_user;
	return stream;
}
ofstream& operator<<(ofstream& stream, User ob)
{
	stream << ob.name_of_user << endl << ob.pass_of_user << endl;
	return stream;
}

bool operator ==(User& ob1, User& ob2)
{
	if (ob1.name_of_user == ob2.name_of_user && ob1.pass_of_user == ob2.pass_of_user) return 1;
	return 0;
}

//Admin's overload operators

istream& operator>>(istream& stream, Admin& ob)
{
	stream >> ob.name_of_admin >> ob.pass_of_admin;
	return stream;
}
ifstream& operator >> (ifstream& stream, Admin& ob)
{
	stream >> ob.name_of_admin >> ob.pass_of_admin;
	return stream;
}
ofstream& operator<<(ofstream& stream, Admin ob)
{
	stream << ob.name_of_admin << endl << ob.pass_of_admin << endl;
	return stream;
}

bool operator==(Admin& ob1, Admin& ob2)
{
	if (ob1.name_of_admin == ob2.name_of_admin && ob1.pass_of_admin == ob2.pass_of_admin) return 1;
	return 0;
}