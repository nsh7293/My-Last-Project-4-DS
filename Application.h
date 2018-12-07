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
	*	@brief	사용자에게 Title을 입력받아 SortedList의 Get함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	불완전한 data의 정보가 모두 채워지고 그 결과가 출력된다.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	bool Search();

	/**
	*	@brief	사용자에게 Title을 입력받아 SortedList의 Delete함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 Title를 가지고 있는 MusicType이 m_List에서 사라진다.
	*	@return	없다.
	*/
	void Delete();

	/**
	*	@brief	사용자에게 Title를 입력받아 SortedList의 Replace함수에 넘겨주는 역할을 한다.
	*	@pre	없다.
	*	@post	사용자가 입력한 Title를 가지고 있는 MusicType을 다시 입력받아 갱신한다.
	*	@return	없다.
	*/
	void ReplaceMusic();

	/**
	*	@brief	객체를 생성 후, 문자열을 입력받는다.
	*	@pre	없다.
	*	@post	SearchListByMemberName함수에 문자열이 설정된 객체를 전달한다.
	*	@return	없다.
	*/
	void RetreiveRecordByMemberName();
	/**
	*	@brief	객체를 생성 후, 문자열을 입력받는다.
	*	@pre	없다.
	*	@post	SearchListByMemberName함수에 문자열이 설정된 객체를 전달한다.
	*	@return	없다.
	*/
	void RetreiveInfoByGenreNLyrics();
	/**
	*	@brief	inData의 이름 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 이름 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	이름이 설정되어있고 나머지는 비어있는 MusicType.
	*	@return	없다.
	*/
	void SearchListByMemberName(MusicType &inData);
	
/**
*	@brief	사용자에게 Title을 입력받아 Title을 찾아 데이터를 출력
*	@pre	찾으려는 Title에 일치하는 데이터가 존재해야 함.
*	@post	없음.
*	@return		찾으려는 사용자 학번에 일치하는 데이터를 화면에 띄우면 1을 리턴하고 그렇지 않으면 0을 리턴함.
*/
	int SearchByTitle();

	/**
	*	@brief	사용자에게 가수를 입력받아 가수를 찾아 데이터를 출력
	*	@pre	찾으려는 가수에 일치하는 데이터가 존재해야 함.
	*	@post	없음.
	*	@return		찾으려는 가수에 일치하는 데이터를 화면에 띄우면 1을 리턴하고 그렇지 않으면 0을 리턴함.
	*/
	int SearchByArtist();

	/**
	*	@brief	사용자에게 앨범을 입력받아 앨범을 찾아 데이터를 출력
	*	@pre	찾으려는 앨범에 일치하는 데이터가 존재해야 함.
	*	@post	없음.
	*	@return		찾으려는 앨범에 일치하는 데이터를 화면에 띄우면 1을 리턴하고 그렇지 않으면 0을 리턴함.
	*/
	int SearchByAlbum();

	/**
	*	@brief	사용자에게 장르를 입력받아 장르를 찾아 데이터를 출력
	*	@pre	찾으려는 장르에 일치하는 데이터가 존재해야 함.
	*	@post	없음.
	*	@return		찾으려는 장르에 일치하는 데이터를 화면에 띄우면 1을 리턴하고 그렇지 않으면 0을 리턴함.
	*/
	int SearchByGenre();

	/**
	*	@brief	최근에 추가된 30곡의 자세한 정보를 화면에 출력
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayNewMusic();

	/**
	*	@brief	장르별로 음악 화면출력
	*	@pre	none.
	*	@post	none.
	*/
	int DisplayMusicByGenre();


	/**
	*	@brief	앨범별로 음악 화면출력
	*	@pre	none.
	*	@post	none.
	*/
	int System::DisplayMusicByAlbum();


	/**
	*	@brief	가수별로 음악 화면출력
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
	*	@brief	리스트 안에 속해 있는 음원 추천
	*	@pre	선택한 리스트 안에 음원이 있어야 함.
	*	@post	랜덤한 곡이 나옴.
	*	@return	1 if the target item is exist in the list, otherwise 0.
	*/
	void Recommend();


	/**
	*	@brief	추천 받을 범위 목록을 화면에 띄우고 키보드에서 입력받는다.
	*	@pre	none.
	*	@post	none.
	*	@return	사용자가 선택한 범위.
	*/
	int Recommend_Menu();

	/**
	*	@brief	m_List 내에서 랜덤으로 하나의 곡이 화면에 나온다.
	*	@pre	m_List 내에 곡 정보가 저장되어 있어야 함. 
	*	@post	랜덤한 자세한 곡 정보가 화면에 나옴.
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
		int r_Commend;			///< 추천받을 범위 목록 넘버()
		SingleLinkedList<SimpleType> s_List;		///< s_item list.
		SingleLinkedList<GenreList> g_List;
		SingleLinkedList<ArtistList> a_List;
		SingleLinkedList<AlbumList> al_List;
		SingleLinkedList<MusicType>BP;
		CircularQueueType<SimpleType> r_List;     ///< AddRecentlyMuusic list
		NodeType<GenreList> *pData=NULL; // mGenreList의 해당 장르를 포인터로 가리키기 위한 더미
		NodeType<ArtistList> *pa_Data = NULL; // mGenreList의 해당 가수를 포인터로 가리키기 위한 더미
		NodeType<AlbumList> *pal_Data = NULL; // mGenreList의 해당 앨범을 포인터로 가리키기 위한 더미
		NodeType<MusicType> *pm_Data = NULL; // m_List의 해당 앨범을 포인터로 가리키기 위한 더미
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