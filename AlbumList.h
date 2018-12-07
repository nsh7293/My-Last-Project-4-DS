#ifndef _ALBUMLIST_H
#define _ALBUMLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "SimpleType.h"
#include "SingleLinkedList.h"
#include "MusicType.h"

class AlbumList
{
public:
	/**
	*	default constructor.
	*/
	AlbumList()
	{
		album = "";
	}

	~AlbumList()
	{}

	void SetAlbum(string m_album)	//music List�� genre�� ����.
	{
		album = m_album;
	}

	string GetAlbum()
	{
		return album;
	}

	SingleLinkedList<SimpleType>* GetAlbumList()
	{
		return &mal_List;
	}

	/**
	*	@brief	display genre information on screen.
	*/
	void DisplayAll()
	{
		//cout << "Genre Number : " << g_Number << endl;
		cout << "Album : " << album << endl;
	}

	/**
	*	@brief	add a music information into this genre.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInAlbum(SimpleType indata)
	{
		mal_List.Add(indata);
	}

	/**
	*	@brief	Display all music information in this genre.
	*	@param[in]	list	music list.
	*/
	void DisplayMusicDetailInAlbum(SingleLinkedList<MusicType> *list)
	{
		SimpleType data;
		MusicType m_item;

		cout << "\n\tCurrent list" << endl;

		// list�� ��� �����͸� ȭ�鿡 ���
		mal_List.ResetList();
		list->ResetList();

		for (int i = 0; i < mal_List.GetLength(); i++)
		{
			mal_List.GetNextItem(data);
			list->GetNextItem(m_item);

			while (data.GetNumber() != m_item.GetNumber())
			{
				list->GetNextItem(m_item);
			}
			m_item.DisplayRecordOnScreen();
		}
	}

	/**
	*	@brief  ������ �����ε�
	*	@pre	none.
	*	@post	none.
	*	@return	�����ڿ� �´� 1,0 ��
	*/
	bool operator== (const AlbumList &T)const
	{
		if (this->album == T.album)return 1;
		return 0;
	}
	bool operator> (const AlbumList &T)
	{
		if (this->album > T.album)return 1;
		return 0;
	}
	bool operator< (const AlbumList &T)
	{
		if (this->album < T.album)return 1;
		return 0;
	}

	bool operator!=(const AlbumList &T)
	{
		if (this->album != T.album)return 1;
		return 0;
	}



private:
	string album;
	SingleLinkedList<SimpleType> mal_List;

};
#endif //_ALBUMLIST_H

