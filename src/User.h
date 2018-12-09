#pragma once
#include<Windows.h>
#include<string>

using namespace std;

class User
{
public:

	User();

	~User();

	void SetUserType(int usertype)
	{
		_usertype = usertype;
	}


	int GetUserType()
	{
		return _usertype;
	}


	string Getid()
	{
		return _id;
	}


	string Getpassword()
	{
		return _password;
	}


	string Getname()
	{
		return _name;
	}

	int Getamount()
	{
		return _amount;
	}

	void Setid(string id)
	{
		_id = id;
	}


	void Setpassword(string pw)
	{
		_password = pw;
	}


	void Setname(string name)
	{
		_name = name;
	}

	void Setamount(int amount)
	{
		_amount = amount;
	}

	virtual void Modifyuserinfo(const User&, int num) = 0;

protected:
	int _usertype;
	string _id;
	string _password;
	string _name;
	int _amount;

};
