#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include<time.h>
#include "SingleLinkedList.h"
#include "CircularQueueType.h"
#include "GenreList.h"
#include "SimpleType.h"
#include "MusicType.h"
#include "ArtistList.h"
#include "AlbumList.h"
#include"DoublyIterator.h"
#include"DoublySortedLinkedList.h"
#include<Windows.h>
#include<iomanip>
#include<sstream>
#include<conio.h>
#include<WinUser.h>
#include"Customer.h"



#define pause system("pause")
#define cls system("cls")
#define bar "============================================================================"
#define error(a) cout << ">ERROR!<" << a << endl
#define success(a) cout << "<SUCCESS>" << a << endl


#define FILENAMESIZE 1024
#define cls system("cls");
using namespace std;
/**
*	application class for item management simply.
*/
class System
{
public:
	/**
	*	default constructor.
	*/
	System();
	
	/**
	*	destructor.
	*/
	~System();

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	bool GetCommand(int& buffer, int minRange = INT_MIN, int maxRange = INT_MAX);

	bool GetCommand(string& buffer);

	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAll();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
	*	@brief	����ڿ��� Title�� �Է¹޾� SortedList�� Get�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	�ҿ����� data�� ������ ��� ä������ �� ����� ��µȴ�.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	bool Search();

	/**
	*	@brief	����ڿ��� Title�� �Է¹޾� SortedList�� Delete�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	����ڰ� �Է��� Title�� ������ �ִ� MusicType�� m_List���� �������.
	*	@return	����.
	*/
	void Delete();

	/**
	*	@brief	����ڿ��� Title�� �Է¹޾� SortedList�� Replace�Լ��� �Ѱ��ִ� ������ �Ѵ�.
	*	@pre	����.
	*	@post	����ڰ� �Է��� Title�� ������ �ִ� MusicType�� �ٽ� �Է¹޾� �����Ѵ�.
	*	@return	����.
	*/
	void ReplaceMusic();

	/**
	*	@brief	��ü�� ���� ��, ���ڿ��� �Է¹޴´�.
	*	@pre	����.
	*	@post	SearchListByMemberName�Լ��� ���ڿ��� ������ ��ü�� �����Ѵ�.
	*	@return	����.
	*/
	void RetreiveRecordByMemberName();
	/**
	*	@brief	��ü�� ���� ��, ���ڿ��� �Է¹޴´�.
	*	@pre	����.
	*	@post	SearchListByMemberName�Լ��� ���ڿ��� ������ ��ü�� �����Ѵ�.
	*	@return	����.
	*/
	void RetreiveInfoByGenreNLyrics();
	/**
	*	@brief	inData�� �̸� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� �̸� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	�̸��� �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void SearchListByMemberName(MusicType &inData);
	
/**
*	@brief	����ڿ��� Title�� �Է¹޾� Title�� ã�� �����͸� ���
*	@pre	ã������ Title�� ��ġ�ϴ� �����Ͱ� �����ؾ� ��.
*	@post	����.
*	@return		ã������ ����� �й��� ��ġ�ϴ� �����͸� ȭ�鿡 ���� 1�� �����ϰ� �׷��� ������ 0�� ������.
*/
	int SearchByTitle();

	/**
	*	@brief	����ڿ��� ������ �Է¹޾� ������ ã�� �����͸� ���
	*	@pre	ã������ ������ ��ġ�ϴ� �����Ͱ� �����ؾ� ��.
	*	@post	����.
	*	@return		ã������ ������ ��ġ�ϴ� �����͸� ȭ�鿡 ���� 1�� �����ϰ� �׷��� ������ 0�� ������.
	*/
	int SearchByArtist();

	/**
	*	@brief	����ڿ��� �ٹ��� �Է¹޾� �ٹ��� ã�� �����͸� ���
	*	@pre	ã������ �ٹ��� ��ġ�ϴ� �����Ͱ� �����ؾ� ��.
	*	@post	����.
	*	@return		ã������ �ٹ��� ��ġ�ϴ� �����͸� ȭ�鿡 ���� 1�� �����ϰ� �׷��� ������ 0�� ������.
	*/
	int SearchByAlbum();

	/**
	*	@brief	����ڿ��� �帣�� �Է¹޾� �帣�� ã�� �����͸� ���
	*	@pre	ã������ �帣�� ��ġ�ϴ� �����Ͱ� �����ؾ� ��.
	*	@post	����.
	*	@return		ã������ �帣�� ��ġ�ϴ� �����͸� ȭ�鿡 ���� 1�� �����ϰ� �׷��� ������ 0�� ������.
	*/
	int SearchByGenre();

	/**
	*	@brief	�ֱٿ� �߰��� 30���� �ڼ��� ������ ȭ�鿡 ���
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayNewMusic();

	/**
	*	@brief	�帣���� ���� ȭ�����
	*	@pre	none.
	*	@post	none.
	*/
	int DisplayMusicByGenre();


	/**
	*	@brief	�ٹ����� ���� ȭ�����
	*	@pre	none.
	*	@post	none.
	*/
	int System::DisplayMusicByAlbum();


	/**
	*	@brief	�������� ���� ȭ�����
	*	@pre	none.
	*	@post	none.
	*/
	int System::DisplayMusicByArtist();

	


	/**
	*	@brief	Retrieve item in the list.
	*	@pre	none.
	*	@post	none.
	*	@return	1 if the target item is exist in the list, otherwise 0.
	*/
	int RetrieveByNameNGenre();
	/**
	*	@brief	Retrieve item in the list.
	*	@pre	none.
	*	@post	none.
	*	@return	1 if the target item is exist in the list, otherwise 0.
	*/
	int RetrieveByGenreNLyrics();
	////////////////
	/**
	*	@brief	����Ʈ �ȿ� ���� �ִ� ���� ��õ
	*	@pre	������ ����Ʈ �ȿ� ������ �־�� ��.
	*	@post	������ ���� ����.
	*	@return	1 if the target item is exist in the list, otherwise 0.
	*/
	void Recommend();


	/**
	*	@brief	��õ ���� ���� ����� ȭ�鿡 ���� Ű���忡�� �Է¹޴´�.
	*	@pre	none.
	*	@post	none.
	*	@return	����ڰ� ������ ����.
	*/
	int Recommend_Menu();

	/**
	*	@brief	m_List ������ �������� �ϳ��� ���� ȭ�鿡 ���´�.
	*	@pre	m_List ���� �� ������ ����Ǿ� �־�� ��. 
	*	@post	������ �ڼ��� �� ������ ȭ�鿡 ����.
	*/
	int InMusicList();

	//	int InGenreList();
	//	int InArtistList();
	//	int InAlbumList();

	void PrintCommandMenu();

	void DSBestPlayedMusic();



	private:
		ifstream m_InFile;		///< input file descriptor.
		ofstream m_OutFile;		///< output file descriptor.
		SingleLinkedList<MusicType> m_List;		///< item list.
		int m_Command;			///< current command number0
		int r_Commend;			///< ��õ���� ���� ��� �ѹ�()
		SingleLinkedList<SimpleType> s_List;		///< s_item list.
		SingleLinkedList<GenreList> g_List;
		SingleLinkedList<ArtistList> a_List;
		SingleLinkedList<AlbumList> al_List;
		SingleLinkedList<MusicType>BP;
		CircularQueueType<SimpleType> r_List;     ///< AddRecentlyMuusic list
		NodeType<GenreList> *pData=NULL; // mGenreList�� �ش� �帣�� �����ͷ� ����Ű�� ���� ����
		NodeType<ArtistList> *pa_Data = NULL; // mGenreList�� �ش� ������ �����ͷ� ����Ű�� ���� ����
		NodeType<AlbumList> *pal_Data = NULL; // mGenreList�� �ش� �ٹ��� �����ͷ� ����Ű�� ���� ����
		NodeType<MusicType> *pm_Data = NULL; // m_List�� �ش� �ٹ��� �����ͷ� ����Ű�� ���� ����
		int command; //command

		void LoadDB(); // Load DataBase

		void SaveDB(); // Save DataBase

		void PrintMenu(); // Show menu

		//void PrintCustomerMenu();

		bool Login(); //Login

		void Logout(); //Logout

		void RegisterUser(); //Register user

		bool DeleteUser(); //Delete user

		void Modifyuserinfo(); //Modify user info

		void Printuserinfo(); //Print user info

		void Customermenu();

		User*_loginedUser; //Current logined user

		DoublySortedLinkedList<User*> _users;

};
#endif	// _APPLICATION_H