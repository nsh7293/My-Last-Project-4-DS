#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<conio.h>
#include<WinUser.h>
#include<cstdlib>
#include<ctime>
#include"Customer.h"
#include"DoublyIterator.h"
#include"DoublySortedLinkedList.h"



#define pause system("pause")
#define cls system("cls")
#define bar "============================================="
#define error(a) cout << "ERROR!" << a << endl
#define success(a) cout << "SUCCESS" << a << endl

using namespace std;

//class System
//{
//public:
//	System();
//	~System();
//	void Run();
//
//private:
//
//	void LoadDB(); // Load DataBase
//
//	void SaveDB(); // Save DataBase
//
//	void PrintMenu(); // Show menu
//
//	//void PrintCustomerMenu();
//
//	bool Login(); //Login
//
//	void Logout(); //Logout
//
//	void RegisterUser(); //Register user
//
//	bool DeleteUser(); //Delete user
//
//	void Modifyuserinfo(); //Modify user info
//
//	void Printuserinfo(); //Print user info
//
//	void Customermenu();
//
//	bool GetCommand(int& buffer, int minRange = INT_MIN, int maxRange = INT_MAX);
//
//	bool GetCommand(string& buffer);
//
//	User*_loginedUser; //Current logined user
//
//	DoublySortedLinkedList<User*> _users;
//
//
//
//};
