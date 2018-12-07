#include"Customer.h"

void Customer::SetCustomer(string id, string password, string name, int amount)
{
	_amount = amount;
	_id = id;
	_password = password;
	_name = name;
	return;
}

void Customer::Modifyuserinfo(const User& newinfo, int num)
{
	switch (num)
	{
	case 1:
		break;
	case 2:
		_password = ((Customer&)newinfo).Getpassword();
		break;
	case 3:
		_name = ((Customer&)newinfo).Getname();
	}
}