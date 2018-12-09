#ifndef _GENRELIST_H
#define _GENRELIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "SimpleType.h"
#include "SingleLinkedList.h"
#include "MusicType.h"

class GenreList
{
public:
	/**
	*	default constructor.
	*/
	GenreList()
	{
		genre = "";
	}

	~GenreList()
	{}

	void SetGenre(string m_genre)	//music List의 genre를 받음.
	{
		genre = m_genre;
	}

	string GetGenre()
	{
		return genre;
	}

	SingleLinkedList<SimpleType>* GetGenreList()
	{
		return &mg_List;
	}

	/**
	*	@brief	display genre information on screen.
	*/
	void DisplayAll()
	{
		//cout << "Genre Number : " << g_Number << endl;
		cout << "Genre : " << genre << endl;
	}

	/**
	*	@brief	add a music information into this genre.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInGenre(SimpleType indata);

	/**
	*	@brief	Display all music information in this genre.
	*	@param[in]	list	music list.
	*/
	void DisplayMusicDetailInGenre(SingleLinkedList<MusicType> *list);

	/**
	*	@brief  연산자 오버로딩
	*	@pre	none.
	*	@post	none.
	*	@return	연산자에 맞는 1,0 값
	*/
	bool operator== (const GenreList &T)const
	{
		if (this->genre == T.genre)return 1;
		return 0;
	}
	bool operator> (const GenreList &T)
	{
		if (this->genre > T.genre)return 1;
		return 0;
	}
	bool operator< (const GenreList &T)
	{
		if (this->genre < T.genre)return 1;
		return 0;
	}

	bool operator!=(const GenreList &T)
	{
		if (this->genre != T.genre)return 1;
		return 0;
	}

private:
	string genre;
	SingleLinkedList<SimpleType> mg_List;

};
#endif //_GENRELIST_H