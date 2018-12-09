#pragma once
#include<Windows.h>
#include"User.h"
#include<string>
using namespace std;

class Customer :

	public User // Inheritence user.
{
public:

	Customer() {};

	~Customer() {};

	void SetCustomer(string id, string password, string name, int amount);

	void Modifyuserinfo(const User& newinfo, int num);

	bool operator==(Customer customer) { return  _id == customer.Getid(); };

	bool operator<(Customer customer) { return _id < customer.Getid(); };

	bool operator>(Customer customer) { return _id > customer.Getid(); };

};
