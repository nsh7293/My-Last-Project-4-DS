
#ifndef _MUSICTYPE_H
#define _MUSICTYPE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
*	item information class.
*/

enum RelationType {LESS, GREATER, EQUAL};

class MusicType
{
public:
	/**
	*	default constructor.
	*/
	MusicType()
	{	
		m_Number = 0;
		m_Title = "";
		m_sArtist = "";
		m_sAlbum = "";
		m_sGenre = "";
		m_sLyrics = "";
		
	}

	/**
	*	destructor.
	*/
	~MusicType()	{}

	/**
	*	@brief	곡번호 받기.
	*	@pre	number is set.
	*	@post	none.
	*	@return	number.
	*/
	int GetNumber()
	{
		return m_Number;
	}

	int GetPlayed()
	{
		return m_Played;
	}
	/**
	*	@brief	곡명 받기.
	*	@pre	Title is set.
	*	@post	none.
	*	@return	Title.
	*/
	string GetTitle()
	{
		return m_Title;
	}

	/**
	*	@brief	가수 받기.
	*	@pre	Artist is set.
	*	@post	none.
	*	@return	Artist.
	*/
	string GetArtist()
	{
		return m_sArtist;
	}

	/**
	*	@brief	앨범 받기.
	*	@pre	Album is set.
	*	@post	none.
	*	@return	Album.
	*/
	string GetAlbum()
	{
		return m_sAlbum;
	}

	/**
	*	@brief	장르 받기.
	*	@pre	Genre is set.
	*	@post	none.
	*	@return	Genre.
	*/
	string GetGenre()
	{
		return m_sGenre;
	}

	/**
	*	@brief	가사 받기.
	*	@pre	Lyrics is set.
	*	@post	none.
	*	@return	Lyrics.
	*/
	string GetLyrics()
	{
		return m_sLyrics;
	}

	/**
	*	@brief	Set Number.
	*	@pre	none.
	*	@post	Number is set.
	*	@param	inNumber	Title.
	*/
	void SetNumber(int inNumber)
	{
		m_Number = inNumber;
	}

	void SetPlayed(int playboy)
	{
		m_Played = 10000 - playboy;
	}
	/**
	*	@brief	Set Title.
	*	@pre	none.
	*	@post	Title is set.
	*	@param	inTitle	Title.
	*/
	void SetTitle(string inTitle)
	{
		m_Title = inTitle;
	}
	
	/**
	*	@brief	Set Artist.
	*	@pre	none.
	*	@post	Artist is set.
	*	@param	inArtist	Artist.
	*/
	void SetArtist(string inArtist)
	{
		m_sArtist = inArtist;
	}
	
	/**
	*	@brief	Set Album.
	*	@pre	none.
	*	@post	Album is set.
	*	@param	inAlbum		Album.
	*/
	void SetAlbum(string inAlbum)
	{
		m_sAlbum = inAlbum;
	}

	/**
	*	@brief	Set Genre.
	*	@pre	none.
	*	@post	Genre is set.
	*	@param	inGenre		Genre.
	*/
	void SetGenre(string inGenre)
	{
		m_sGenre = inGenre;
	}

	/**
	*	@brief	Set Lyrics. 단, 띄어쓰기까지 인식할 수 있어야 함.
	*	@pre	none.
	*	@post	Lyrics is set.
	*	@param	inLyrics	Lyrics.
	*/
	void SetLyrics(string inLyrics)
	{
		m_sLyrics = inLyrics;
	}

	
	/**
	*	@brief	Set Music.
	*	@pre	none.
	*	@post	Music record is set.
	*	@param	inNumber	Music Number.
	*	@param	inTitle	Music Title.
	*	@param	inArtist	Music Artist.
	*	@param	inAblum		Music Album.
	*	@param	inGenre		Music Genre.
	*	@param	inLyrics	Music Lyrics.


	*/
	void SetRecord(int inNumber,string inTitle, string inArtist, string inAlbum, string inGenre,string inLyrics, string key, int inplayboy)
	{
		SetNumber(inNumber);
		SetTitle(inTitle);
		SetArtist(inArtist);
		SetAlbum(inAlbum);
		SetGenre(inGenre);
		SetLyrics(inLyrics);
		SetPlayed(inplayboy);

	}

	/**
	*	@brief	Display Music Number on screen.
	*	@pre	Music Number is set.
	*	@post	Music Number is on screen.
	*/
	void DisplayNumberOnScreen()
	{
		cout << "\tNumber   : " << m_Number << endl;
	};

	void DisplayPlayedOnScreen()
	{
		cout << "\tPlayed	: " << 10000 - m_Played << endl;
	}
	/**
	*	@brief	Display Music Title on screen.
	*	@pre	Music Title is set.
	*	@post	Music Title is on screen.
	*/
	void DisplayTitleOnScreen() 
	{
		cout << "\tTitle   : " << m_Title << endl; 
	};

	/**
	*	@brief	Display Music Artist on screen.
	*	@pre	Music Artist is set.
	*	@post	Music Artist is on screen.
	*/
	void DisplayArtistOnScreen() 
	{
		cout << "\tArtist : " << m_sArtist << endl; 
	};

	/**
	*	@brief	Display Music Album on screen.
	*	@pre	Music Album is set.
	*	@post	Music Album is on screen.
	*/
	void DisplayAlbumOnScreen() 
	{
		cout << "\tAlbum : " << m_sAlbum << endl; 
	};

	/**
	*	@brief	Display Music Genre on screen.
	*	@pre	Music Genre is set.
	*	@post	Music Genre is on screen.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\tGenre : " << m_sGenre << endl;
	};

	/**
	*	@brief	Display Music Lyrics on screen.
	*	@pre	Music Lyrics is set.
	*	@post	Music Lyrics is on screen.
	*/
	void DisplayLyricsOnScreen()
	{
		cout << "\tLyrics : " << m_sLyrics << endl;
	};

	void DisplayAboutBest()
	{
		cout << "\tPlayed: " << 10000 - m_Number;
		cout << "\t\tName: " << m_Title << endl;
	}
	/**
	*	@brief	Display an Music record on screen.
	*	@pre	Music record is set.
	*	@post	Music record is on screen.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNumberOnScreen();
		DisplayTitleOnScreen();
		DisplayArtistOnScreen();
		DisplayAlbumOnScreen();
		DisplayGenreOnScreen();
		DisplayLyricsOnScreen();
		DisplayPlayedOnScreen();

	};

	/**
	*	@brief	Set Music Number from keyboard.
	*	@pre	none.
	*	@post	Music Number is set.
	*/
	void SetNumberFromKB();

	void SetPlayedFromKB();
	/**
	*	@brief	Set Music Title from keyboard.
	*	@pre	none.
	*	@post	Music Title is set.
	*/
	void SetTitleFromKB();

	/**
	*	@brief	Set Music Artist from keyboard.
	*	@pre	none.
	*	@post	Music Artist is set.
	*/
	void SetArtistFromKB();

	/**
	*	@brief	Set Music Album from keyboard.
	*	@pre	none.
	*	@post	Music Album is set.
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	Set Music Genre from keyboard.
	*	@pre	none.
	*	@post	Music Genre is set.
	*/
	void SetGenreFromKB();

	/**
	*	@brief	Set Music Lyrics from keyboard.
	*	@pre	none.
	*	@post	Music Lyrics is set.
	*/
	void SetLyricsFromKB();
	
	/**
	*	@brief	Set Music record from keyboard.
	*	@pre	none.
	*	@post	Music record is set.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	Music record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new Music record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);
	
	/**
	*	@brief  곡번호를 통한 비교로 연산자 오버로딩
	*	@pre	none.
	*	@post	none.
	*	@return	연산자에 맞는 1,0 값
	*/
	
	RelationType CompareById(const MusicType& data);

	bool operator== (MusicType item) const;
	
	bool operator> (MusicType item)const;


	bool operator< (const MusicType &T)
	{
		if (this->m_Number < T.m_Number)return 1;

		return 0;
	}

	bool operator!=(const MusicType &T)
	{
		if (this->m_Number != T.m_Number)return 1;
		return 0;
	}


protected:
	int m_Number;	// 곡번호, Primary Key
	string m_Title;		// 곡명
	string m_sArtist;	// 가수
	string m_sAlbum;   // 앨범
	string m_sGenre;   // 장르
	string m_sLyrics;  // 가사
	int m_Played;

};

#endif	// _MUSICTYPE_H
