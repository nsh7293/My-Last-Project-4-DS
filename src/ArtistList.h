#ifndef _ARTISTLIST_H
#define _ARTISTLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "SimpleType.h"
#include "SingleLinkedList.h"
#include "MusicType.h"

class ArtistList
{
public:
	/**
	*	default constructor.
	*/
	ArtistList()
	{
		artist = "";
	}

	~ArtistList()
	{}

	void SetArtist(string m_artist)	//music List의 genre를 받음.
	{
		artist = m_artist;
	}

	string GetArtist()
	{
		return artist;
	}

	SingleLinkedList<SimpleType>* GetArtistList()
	{
		return &ma_List;
	}

	/**
	*	@brief	display genre information on screen.
	*/
	void DisplayAll()
	{
		//cout << "Genre Number : " << g_Number << endl;
		cout << "Artist : " << artist << endl;
	}

	/**
	*	@brief	add a music information into this genre.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInArtist(SimpleType indata)
	{
		ma_List.Add(indata);
	}

	/**
	*	@brief	Display all music information in this genre.
	*	@param[in]	list	music list.
	*/
	void DisplayMusicDetailInArtist(SingleLinkedList<MusicType> *list) 
	{
		SimpleType data;
		MusicType m_item;

		cout << "\n\tCurrent list" << endl;

		// list의 모든 데이터를 화면에 출력
		ma_List.ResetList();
		list->ResetList();

		for (int i = 0; i < ma_List.GetLength(); i++)
		{
			ma_List.GetNextItem(data);
			list->GetNextItem(m_item);

			while (data.GetNumber() != m_item.GetNumber())
			{
				list->GetNextItem(m_item);
			}
			m_item.DisplayRecordOnScreen();
		}
	}

	/**
	*	@brief  연산자 오버로딩
	*	@pre	none.
	*	@post	none.
	*	@return	연산자에 맞는 1,0 값
	*/
	bool operator== (const ArtistList &T)const
	{
		if (this->artist == T.artist)return 1;
		return 0;
	}
	bool operator> (const ArtistList &T)
	{
		if (this->artist > T.artist)return 1;
		return 0;
	}
	bool operator< (const ArtistList &T)
	{
		if (this->artist < T.artist)return 1;
		return 0;
	}

	bool operator!=(const ArtistList &T)
	{
		if (this->artist != T.artist)return 1;
		return 0;
	}



private:
	string artist;
	SingleLinkedList<SimpleType> ma_List;

};
#endif //_ARTISTLIST_H
