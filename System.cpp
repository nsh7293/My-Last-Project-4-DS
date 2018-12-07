#include"Application.h"

using namespace std;

System::System()
{
	this->_loginedUser = NULL;
	LoadDB();
}

System::~System()
{
	SaveDB();
}


void System::Run()
{	
	PrintMenu();
	
}


void System::LoadDB()
{
	fstream fs;
	int userType, amount;
	string id, pw, name;
	User* newuser;
	fs.open("User db\\user.txt");
	while (fs >> userType >> id >> pw >> name >> amount)
	{
		newuser = new Customer; // Dynamic allocation
		newuser->SetUserType(userType);
		((Customer*)newuser)->SetCustomer(id, pw, name, amount);
		_users.Add(newuser);
	}
	fs.close();
}


void System::SaveDB()
{
	fstream fs;
	DoublyIterator<User*>itor(_users);
	fs.open("User db\\user.txt", ios::out); // User Database
	while (!itor.IsNull())
	{
		fs << (*itor)->GetUserType() << '\t'
			<< (*itor)->Getid() << '\t'
			<< (*itor)->Getpassword() << '\t'
			<< (*itor)->Getname() << '\t'
			<< (*itor)->Getamount();

		if (!(++itor).IsNull())
			fs << endl;
	}
	fs.close();
}



void System::PrintMenu()
{
	while (1)
	{
		cls;
		cout << "(∩^ω^)⊃ - ** 이. 것. 은 조금 더 업그레이드 된 RhyThme.. 접속해주셔서 감사해요!"<< endl;
		cout << bar << endl;
		cout << "1. Login" << endl;
		cout << "2. Register User" << endl;
		cout << "3. Modify User Info" << endl;
		cout << "4. End" << endl;
		cout << bar << endl;
		cout << ">>";

		int selection;
		while (!GetCommand(selection, 1, 4))
		{
			error("잘못된 선택입니다. 다시 시도해주세요.");
			pause;
		}

		switch (selection)
		{
		case 1:
			Login(); //login
			break;
		case 2:
			RegisterUser(); //register
			break;
		case 3:
			Modifyuserinfo();
			break;
		case 4:
			return; //exit
			break;
		}
	}
}
	
void System::PrintCommandMenu()
{
	while (1)
	{
		//cls;
		cout << "\t				 ♬ Command Menu ♬ " << endl;
		cout << bar << endl;
		Printuserinfo();
		cout << bar << endl;
		cout << "\t				   1 : Add Music" << endl;
		cout << "\t				   2 : Delete Music" << endl;
		cout << "\t               ／⌒ヽ		   3 : Replace Music" << endl;
		cout << "\t              / ^ω^ヽ		   4 : Search Music by Title" << endl;
		cout << "\t          ＿ノ ヽ　ノ ＼＿          5 : Search Music by Artist" << endl;
		cout << "\t	`/　`/ ⌒Ｙ⌒ Ｙ　ヽ        6 : Search Music by Album" << endl;
		cout << "\t            ((三ヽ人　 /　　|       7 : Search Music by Genre" << endl;
		cout << "\t	|　ﾉ⌒＼ ￣￣ヽ　 ノ	   8 : Display all Music" << endl;
		cout << "\t	 ヽ＿＿＿＞､＿＿_／ 	   9 : Get it from file" << endl;
		cout << "\t	    ｜(王 ﾉ〈		  10 : Put it to file" << endl;
		cout << "\t	    / ー―彡 ヽ		  11 : Display Recent Music" << endl;
		cout << "\t	  / ヽ_／　     |          12 : Display Music By Album " << endl;
		cout << "\t	｜　　 /     ノ           13 : Display Music By Artist" << endl;
		cout << "\t				  14 : Display Music By Genre" << endl;
		cout << "\t				  15 : Retrieve By Name And Genre " << endl;
		cout << "\t				  16 : Retrieve By Genre And Lyrics " << endl;
		cout << "\t				  17 : Recommend " << endl;
		cout << "\t				  18 : Display Best Played Music " << endl;
		cout << "\t				   0 : Quit " << endl;
		//cout << "\t				16 : Recommend 4 User" << endl;
		//cout << "\				        0 : Quit" << endl;
		cout << bar << endl;

		cout << "사용하실 메뉴의 번호를 입력하세요 >> " << endl;
		int choice;
		GetCommand(choice);
		switch (choice)
		{
		case 1:
			AddItem();
			break;
		case 2:
			Delete();
			break;
		case 3:
			ReplaceMusic();
			break;
		case 4:
			SearchByTitle();
			break;
		case 5:
			SearchByArtist();
			break;
		case 6:
			SearchByAlbum();
			break;
		case 7:
			SearchByGenre();
			break;
		case 8:
			DisplayAll();
			break;
		case 9:
			ReadDataFromFile();
			break;
		case 10:
			WriteDataToFile();
			break;
		case 11:
			DisplayNewMusic();
			break;
		case 12:
			DisplayMusicByAlbum();
			break;
		case 13:
			DisplayMusicByArtist();
			break;
		case 14:
			DisplayMusicByGenre();
			break;
		case 15:
			RetrieveByNameNGenre();
			break;
		case 16:
			RetreiveInfoByGenreNLyrics();
			break;
		case 17:
			Recommend();
			break;
		case 18:
			DSBestPlayedMusic();
			break;
		case 0:
			return;
			break;
		}
	}
}



void System::Modifyuserinfo()
{
	cls;
	cout << bar << endl;
	cout << "1. ID : " << _loginedUser->Getid() << endl;
	cout << "2. PW : ******** " << endl;
	cout << "3. Name : " << _loginedUser->Getname() << endl;
	cout << bar << endl;
	cout << "Choose the item." << endl;
	cout << ">>";
	int slt = 0;
	if ((_loginedUser->GetUserType() == 0 && !GetCommand(slt, 1, 3)) || _loginedUser->GetUserType() == 1 && !GetCommand(slt, 1, 3))
	{
		error("Wrong input.");
		pause;
		return;
	}
	string pw;
	string id;
	string name;
	switch (slt)
	{
	case 1:
		cout << " New ID : ";
		GetCommand(id);
		_loginedUser->Setid(id);
		success(" ID has been changed. ");
		pause;
		return;
		break;
	case 2:
		cout << " New PW : ";
		GetCommand(pw);
		_loginedUser->Setpassword(pw);
		success(" PW has been changed.");
		pause;
		return;
		break;
	case 3:
		cout << " New Name : ";
		GetCommand(name);
		_loginedUser->Setname(name);
		success(" Name has been changed.");
		pause;
		return;
		break;

	}
}
//
//
//void System::Customermenu()
//{
//	while (1)
//	{
//		cls;
//		cout << bar << endl;
//		Printuserinfo();
//		cout << bar << endl;
//		cout << "1. Modify" << endl;
//		cout << "2. Logout" << endl;
//		cout << bar << endl;
//		cout << ">>";
//		int selection2 = 0;
//		GetCommand(selection2);
//		switch (selection2)
//		{
//		case 1:
//			Modifyuserinfo();
//			break;
//		case 2:
//			Logout();
//			return;
//			break;
//		}
//	}
//}


bool System::Login()
{
	cls;
	string id, pw;
	cout << "ID : ";
	GetCommand(id);
	cout << "PW : ";
	GetCommand(pw);

	DoublyIterator<User*>itor(_users);
	while (!itor.IsNull())
	{
		if ((*itor)->Getid() == id && (*itor)->Getpassword() == pw)
		{
			_loginedUser = *itor;
			success(" Login success! ");
			pause;
			if ((*itor)->GetUserType() == 0)
				PrintCommandMenu();
			return true;

		}
		++itor;

	}
	error(" Login failed! Check id and pw again. ");
	cout << bar << endl;
	pause;
	return false;
}


void System::Logout()
{
	_loginedUser = nullptr;
}

void System::RegisterUser()
{
	int usertype;
	string id, pw, name;
	User* newuser;
	cls;
	cout << bar << endl;
	cout << "1.Normal user" << endl;
	cout << ">>";
	if (!GetCommand(usertype))
	{
		error("Wrong input");
		pause;
		return;
	}
	usertype -= 1;
	cout << "ID : ";
	GetCommand(id);
	DoublyIterator<User*>itor(_users);
	for (; !itor.IsNull(); ++itor)
	{
		if ((*itor)->Getid() == id)
		{
			error(" Already existing id. Choose another id. ");
			pause;
			return;
		}
	}
	cout << "PW : ";
	GetCommand(pw);
	cout << "Name : ";
	GetCommand(name);
	newuser = new Customer;
	((Customer*)newuser)->SetCustomer(id, pw, name, 0);
	newuser->SetUserType(usertype);
	_users.Add(newuser);
	cout << bar << endl;
	success(" Welcome! You have been sign up. ");
	pause;
	return;

}

bool System::DeleteUser()
{
	return false;
}


void System::Printuserinfo()
{
	cout << "ID : " << _loginedUser->Getid() << endl;
	cout << "Name : " << _loginedUser->Getname() << endl;
}

bool System::GetCommand(int& buffer, int minRange, int maxRange)
{
	int temporarybuffer;
	if (!(cin >> temporarybuffer) || cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return false;
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	if (minRange > temporarybuffer || maxRange < temporarybuffer)
	{
		return false;
	}
	buffer = temporarybuffer;
	return true;
}

bool System::GetCommand(string& buffer)
{
	string temporarybuffer;
	if (!(cin >> temporarybuffer) || cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		return false;
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	buffer = temporarybuffer;
	return true;
}



//void System::Run()
//{
//	PrintMenu();
//	
//	while (1)
//	{
//		
//		m_Command = GetCommand();
//
//		switch (m_Command)
//		{
//		case 1:
//			AddItem();
//			break;
//		case 2:
//			Delete();
//			break;
//		case 3:
//			ReplaceMusic();
//			break;
//		case 4:
//			SearchByTitle();
//			break;
//		case 5:
//			SearchByArtist();
//			break;
//		case 6:
//			SearchByAlbum();
//			break;
//		case 7:
//			SearchByGenre();
//			break;
//		case 8:
//			DisplayAll();
//			break;
//		case 9:
//			ReadDataFromFile();
//			break;
//		case 10:
//			WriteDataToFile();
//			break;
//		case 11:
//			DisplayNewMusic();
//			break;
//		case 12:
//			DisplayMusicByAlbum();
//			break;
//		case 13:
//			DisplayMusicByArtist();
//			break;
//		case 14:
//			DisplayMusicByGenre();
//			break;
//		case 15:
//			RetrieveByNameNGenre();
//			break;
//		case 16:
//			Recommend();
//			break;
//		case 0:
//			return;
//			break;
//		}
//	}
//}
//
//int System::GetCommand()
//{
//	int cmd;
//	cout << endl << endl;
//	cout << "\t ♬ Command Menu ♬ " << endl;
//	cout << "\t   1 : Add Music" << endl;
//	cout << "\t   2 : Delete Music" << endl;
//	cout << "\t   3 : Replace Music" << endl;
//	cout << "\t   4 : Search Music by Title" << endl;
//	cout << "\t   5 : Search Music by Artist" << endl;
//	cout << "\t   6 : Search Music by Album" << endl;
//	cout << "\t   7 : Search Music by Genre" << endl;
//	cout << "\t   8 : Display all Music" << endl;
//	cout << "\t   9 : Get it from file" << endl;
//	cout << "\t  10 : Put it to file " << endl;
//	cout << "\t  11 : Display Recent Music" << endl;
//	cout << "\t  12 : Display Music By Genre" << endl;
//	cout << "\t  13 : Display Music By Artist" << endl;
//	cout << "\t  14 : Display Music By Album" << endl;
//	cout << "\t  15 : Retrieve By Name And Genre " << endl;
//	cout << "\t  16 : Recommend 4 User" << endl;
//	cout << "\t   0 : Quit" << endl;
//	cout << endl << "\t Choose a Number --> ";
//	cin >> cmd;
//	cout << endl;
//	
//	return cmd;
//}

int System::AddItem()
{
	MusicType item;
	SimpleType s_item;
	GenreList g_item;
	ArtistList a_item;
	AlbumList al_item;

	item.SetNumberFromKB();

	while (m_List.Get(item))
	{
		cout << "\t 곡 번호가 중복됩니다!" << endl;
		if (m_List.Get(item))
			item.SetNumberFromKB();
	}
	item.SetAlbumFromKB();
	item.SetArtistFromKB();
	item.SetGenreFromKB();
	item.SetLyricsFromKB();
	item.SetTitleFromKB();
	item.SetPlayedFromKB();

	s_item.SetNumber(item.GetNumber());
	s_item.SetTitle(item.GetTitle());

	g_item.SetGenre(item.GetGenre());
	a_item.SetArtist(item.GetArtist());
	al_item.SetAlbum(item.GetAlbum());

	m_List.Add(item);
	r_List.EnQueue(s_item);

	if (g_List.GetLength() == 0)
	{
		g_List.Add(g_item);
	}
	else
	{
		while (g_List.Get(g_item) == 0)
		{
			g_List.Add(g_item);
		}
	}

	if (a_List.GetLength() == 0)
	{
		a_List.Add(a_item);
	}
	else
	{
		while (a_List.Get(a_item) == 0)
		{
			a_List.Add(a_item);
		}
	}

	if (al_List.GetLength() == 0)
	{
		al_List.Add(al_item);
	}
	else
	{
		while (al_List.Get(al_item) == 0)
		{
			al_List.Add(al_item);
		}
	}

	NodeType<GenreList>*node = new NodeType<GenreList>;
	NodeType<GenreList>*pre;
	GenreList temp;

	node->data = g_item;
	node->next = NULL;

	g_List.ResetList();
	while (1)
	{
		pre = pData;
		pData = g_List.GetPoint(temp);

		if (temp.GetGenre() == item.GetGenre())
		{
			pData->data.GetGenreList()->Add(s_item);
			break;
		}
	}

	NodeType<ArtistList>*A_node = new NodeType<ArtistList>;
	NodeType<ArtistList>*A_pre;
	ArtistList A_temp;

	A_node->data = a_item;
	A_node->next = NULL;

	a_List.ResetList();
	while (1)
	{
		A_pre = pa_Data;
		pa_Data = a_List.GetPoint(A_temp);

		if (A_temp.GetArtist() == item.GetArtist())
		{
			pa_Data->data.GetArtistList()->Add(s_item);
			break;
		}
	}

	NodeType<AlbumList>*L_node = new NodeType<AlbumList>;
	NodeType<AlbumList>*L_pre;
	AlbumList L_temp;

	L_node->data = al_item;
	L_node->next = NULL;

	al_List.ResetList();
	while (1)
	{
		L_pre = pal_Data;
		pal_Data = al_List.GetPoint(L_temp);

		if (L_temp.GetAlbum() == item.GetAlbum())
		{
			pal_Data->data.GetAlbumList()->Add(s_item);
			break;
		}
	}

	//DisplayAll();

	return 1;
}

void System::DisplayAll()
{
	MusicType data;
	cout << "\n\t현재 리스트: " << endl;
	m_List.ResetList(); //리스트를 초기화시킨다.
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		data.DisplayRecordOnScreen();
	}
}

//찾을 Title을 사용자에게 입력받고 Get함수를 호출한다.
bool System::Search()
{
	cout << "\t찾을";
	MusicType data;	//Get함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetTitleFromKB();	//사용자에게서 Title을 입력받는다.
	if (m_List.Get(data))	//Title만 가진 data를 Get으로 보내 나머지 정보를 채운다.
	{
		cout << "\t찾았습니다." << endl;
		data.DisplayRecordOnScreen();
		return 1;	//찾으면 그 항목을 출력해주고 1을 리턴한다.
	}
	else
		cout << "\t찾지 못했습니다." << endl;
	return 0;	//찾지 못하면 찾지 못했다는 메시지를 출력하고 0을 리턴한다.
}


//찾을 Title를 사용자에게 입력받고 Delete함수를 호출한다.
void System::Delete()
{
	cout << "\t지울";
	MusicType data;	//Delete함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetNumberFromKB();	//사용자에게서 Number를 입력받는다.
	if (m_List.Delete(data))//Delete함수에 data를 넘겨준다.
	{
		cout << "\t삭제를 완료했습니다." << endl;	//삭제에 성공했으면 메시지를 출력한다.
	}
	else
		cout << "\t삭제하지 못했습니다. 일치하는 항목을 찾을 수 없습니다." << endl;	//삭제에 실패했으면 다른 메시지를 출력한다.
}


//찾을 Title를 사용자에게 입력받고 수정할 Title의 정보를 찾아 기존의 정보를 갱신한다.
void System::ReplaceMusic()
{
	cout << "\t변경을 원하는 항목의 ";
	MusicType data;	//마찬가지로 Replace함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
	data.SetNumberFromKB();	//사용자에게서 수정할 항목의 Number를 입력받는다.

	if (!m_List.Get(data))	//사용자가 입력한 항목이 List에 있는지 검색한다.
	{
		cout << "\t항목을 찾을 수 없습니다." << endl; //찾을 수 없을때 메시지를 출력한다.
		return;
	}

	else //찾을 수 있을때
	{
		data.SetArtistFromKB();	//사용자에게서 아티스트를 입력받는다.
		data.SetAlbumFromKB();	//사용자에게서 앨범을 입력받는다.
		data.SetGenreFromKB();	//사용자에게서 장르를 입력받는다.

		if (m_List.Replace(data))//Replace함수에 data를 넘겨준다.
		{
			cout << "\t수정을 완료했습니다." << endl;	//수정을 성공했을 때 메시지를 출력한다.
		}
		else
			cout << "\t수정을 실패했습니다." << endl;	//수정에 실패했을 때 다른 메시지를 출력한다.
	}

}


//사용자에게 찾고자하는 Title을 입력받고 넘겨준다.
void System::RetreiveRecordByMemberName()
{
	MusicType temp;
	cout << "\t찾으실";
	temp.SetTitleFromKB();	//SearchListByMemberName함수에 넘겨줄 temp의 name을 사용자로부터 입력받는다.
	cout << "\t찾으실";
	temp.SetGenreFromKB();
	SearchListByMemberName(temp); // 찾는 역할을 수행하는 SearchListByMemberName함수를 호출하고 temp값을 넘겨준다.
}
//사용자로부터 장르와 가사를 입력받고 이를 이용하여 검색을한다.
void System::RetreiveInfoByGenreNLyrics()
{
	MusicType info;
	cout << "\t찾으실";
	info.SetGenreFromKB();
	cout << "\t찾으실";
	info.SetLyricsFromKB();
	SearchListByMemberName(info);
}



//사용자가 찾고자하는 Title을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다.
void System::SearchListByMemberName(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
	m_List.ResetList();

	int length = m_List.GetLength();
	int count = 0;
	//m_List.GetPoint(temp);		//초기화시켜줘서 NULL이라 처음에 증가시켜줘야함_예전 랩보기
	for (int i = 0; i < length; i++)
	{
		m_List.GetPoint(temp);


		if (temp.GetGenre().find(inData.GetGenre()) != -1)
		{

			if (temp.GetTitle().find(inData.GetTitle()) != -1)
			{
				temp.DisplayRecordOnScreen(); //일치하는 문자열을 포함하는 temp의 내용을 출력한다.
				count++; //찾은 개수를 1만큼 늘려준다.
			}

		}

	}
	if (count == 0)
		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}




int System::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);

	// 파일 오픈에 성공하면 1, 그렇지 않으면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}



int System::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);

	// 파일 오픈에 성공하면 1, 그렇지 않으면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}



int System::ReadDataFromFile()
{
	int index = 0;
	MusicType data;	// 읽기위한 변수를 임시로 설정한다.

	char filename[FILENAMESIZE];
	cout << "\n\t입력파일 이름을 설정하세요 : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisplayAll();

	return 1;
}


int System::WriteDataToFile()
{
	MusicType data;	// 쓰기위해서 임시로 변수를 설정한다.

	char filename[FILENAMESIZE];
	cout << "\n\t출력파일 이름을 설정하세요 : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화한다.
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();

	return 1;
}


// 입력된 정보로 리스트에서 제목을 찾아 정보출력
int System::SearchByTitle()
{
	MusicType item;
	string input;

	cout << "\t찾고자하는 음악 제목을 입력하세요 : ";
	cin >> input;
	cout << endl << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetList(); //리스트값을 리셋한다. 값은 -1이 된다.
	int length = m_List.GetLength();  //리스트의 길이를 length에 저장한다.
	m_List.GetNextItem(item);

	for (int i = 0; i < m_List.GetLength(); i++)
	{
		if (item.GetTitle() == input)
		{
			item.DisplayRecordOnScreen();
			break;
		}
		m_List.GetNextItem(item);
	}

	return 0;
}

// 입력된 정보로 리스트에서 가수를 찾아 정보출력
int System::SearchByArtist()
{
	MusicType item;
	string input;

	cout << "\t찾고자하는 음악 제목을 입력하세요 : ";
	cin >> input;
	cout << endl << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetList();     //리스트값을 리셋한다. 값은 -1이 된다.
	int length = m_List.GetLength();   //리스트의 길이를 length에 저장한다.
	m_List.GetNextItem(item);

	for (int i = 0; i < m_List.GetLength(); i++)
	{
		if (item.GetTitle() == input)
		{
			item.DisplayRecordOnScreen();
			break;
		}
		m_List.GetNextItem(item);
	}

	return 0;
}
// 입력된 정보로 리스트에서 앨범을 찾아 정보출력
int System::SearchByAlbum()
{
	MusicType item;
	string input;

	cout << "\t찾고자하는 음악 제목을 입력하세요 : ";
	cin >> input;
	cout << endl << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetList();   //리스트값을 리셋한다. 값은 -1이 된다.
	int length = m_List.GetLength();  //리스트의 길이를 length에 저장한다.
	m_List.GetNextItem(item);

	for (int i = 0; i < m_List.GetLength(); i++)
	{
		if (item.GetTitle() == input)
		{
			item.DisplayRecordOnScreen();
			break;
		}
		m_List.GetNextItem(item);
	}

	return 0;
}

// 입력된 정보로 리스트에서 장르를 찾아 정보출력
int System::SearchByGenre()
{
	MusicType item;
	string input;

	cout << "\t찾고자하는 음악 제목을 입력하세요 : ";
	cin >> input;
	cout << endl << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetList();      //리스트값을 리셋한다. 값은 -1이 된다.
	int length = m_List.GetLength();   //리스트의 길이를 length에 저장한다.
	m_List.GetNextItem(item);

	for (int i = 0; i < m_List.GetLength(); i++)
	{
		if (item.GetTitle() == input)
		{
			item.DisplayRecordOnScreen();
			break;
		}
		m_List.GetNextItem(item);
	}

	return 0;
}

//최근에 추가된 30곡의 자세한 정보를 화면에 출력
void System::DisplayNewMusic()
{
	cout << "\n\t최신 30곡: " << endl;

	MusicType item;
	SimpleType data;

	r_List.ResetQueue();	//r_CurPointer 초기화
	int length = r_List.GetTop(); // length에 리스트 길이 저장
	int curIndex = r_List.GetNextItem(data); // data에 첫번째 칸에 정보를 저장


	for (int i = length; i > 0; i--)
	{
		item.SetNumber(data.GetNumber());//SimpleType의 data에서 곡번호를 받아 MusicType의 item에 곡번호를 준다.
		m_List.Get(item);		//m_List에서 item에 저장된 곡번호에 맞는 정보를 찾는다.  
		item.DisplayRecordOnScreen();	//곡번호, 곡명, 가수, 장르, 가사를 화면에 출력함.
		curIndex = r_List.GetNextItem(data);	//r_CurPointer를 다음 index로 넘긴다.
	}
}


//장르별로 음악 화면출력
int System::DisplayMusicByGenre()
{
	GenreList data;
	GenreList dummy;//더미 설정

	cout << "\n\t현재 리스트: " << endl;

	// genre list의 모든 데이터를 화면에 출력
	g_List.ResetList();

	for (int i = 0; i < g_List.GetLength(); i++)
	{
		cout << i + 1 << endl;
		g_List.GetNextItem(data);
		data.DisplayAll();
	}

	// 특정 장르의 음악 정보만 보고 싶을 때
	string name;

	cout << "찾고자하는 장르를 입력하세요 : ";
	cin >> name;
	dummy.SetGenre(name);

	GenreList g_temp;
	NodeType<GenreList> *pData;

	g_List.ResetList();
	for (int i = 0; i < g_List.GetLength(); i++)
	{
		pData = g_List.GetPoint(g_temp);
		if (g_temp.GetGenre() == dummy.GetGenre())
		{
			pData->data.DisplayMusicDetailInGenre(&m_List); // 해당 장르 음악 출력
			return 1;
		}

	}

	cout << "저런..해당 장르에 곡이 존재하지 않네요.";
	return 1;

}

//가수별로 음악 화면출력
int System::DisplayMusicByArtist()
{
	ArtistList data;
	ArtistList dummy;

	cout << "\n\t현재 리스트: " << endl;

	// artist list의 모든 데이터를 화면에 출력
	a_List.ResetList();

	for (int i = 0; i < a_List.GetLength(); i++)
	{
		cout << i + 1 << endl;
		a_List.GetNextItem(data);
		data.DisplayAll();
	}

	// 특정 가수의 음악 정보만 보고 싶을 때
	string name;

	cout << "찾고자하는 가수를 입력하세요 : ";
	cin >> name;
	dummy.SetArtist(name);

	ArtistList a_temp;
	NodeType<ArtistList> *pa_Data;

	a_List.ResetList();
	for (int i = 0; i < a_List.GetLength(); i++)
	{
		pa_Data = a_List.GetPoint(a_temp);
		if (a_temp.GetArtist() == dummy.GetArtist())
		{
			pa_Data->data.DisplayMusicDetailInArtist(&m_List); // 해당 장르 음악 출력
			return 1;
		}

	}

	cout << "저런..해당 가수의 곡이 존재하지 않네요.";
	return 1;

}

//앨범별로 음악 화면출력
int System::DisplayMusicByAlbum()
{
	AlbumList data;
	AlbumList dummy;

	cout << "\n\tCurrent list" << endl;

	// album list의 모든 데이터를 화면에 출력
	al_List.ResetList();

	for (int i = 0; i < al_List.GetLength(); i++)
	{
		cout << i + 1 << endl;
		al_List.GetNextItem(data);
		data.DisplayAll();
	}

	// 특정 앨범의 음악 정보만 보고 싶을 때
	string name;

	cout << "찾고자하는 앨범을 입력하세요 : ";
	cin >> name;
	dummy.SetAlbum(name);

	AlbumList al_temp;
	NodeType<AlbumList> *pal_Data;

	al_List.ResetList();
	for (int i = 0; i < al_List.GetLength(); i++)
	{
		pal_Data = al_List.GetPoint(al_temp);
		if (al_temp.GetAlbum() == dummy.GetAlbum())
		{
			pal_Data->data.DisplayMusicDetailInAlbum(&m_List); // 해당 장르 음악 출력
			return 1;
		}

	}

	cout << "저런..해당 가수의 곡이 존재하지 않네요.";
	return 1;

}


//Song name과 Genre가 일치하는 음악을 찾아서 화면에 출력
int System::RetrieveByNameNGenre()
{
	MusicType item;
	RetreiveRecordByMemberName();
	return 1;

}

int System::RetrieveByGenreNLyrics()
{
	MusicType item;
	RetreiveInfoByGenreNLyrics();
	return 1;
}


//랜덤으로 사용자에게 음악을 추천해주는 함수
int System::Recommend_Menu()
{
	int recommend_num;
	cout << endl << endl;
	cout << "\t원하는 추천 범위를 고르세요" << endl;
	cout << "\t**********************************" << endl;
	cout << "\t   1 : 음원 전체에서 추천을 받겠습니다." << endl;	//m_List 내에서
	cout << "\t   0 : 아니야 그냥 되돌아겠어" << endl;
	cout << endl << "\t --> ";

	cin >> recommend_num;
	cout << endl;

	return recommend_num;
}

void System::Recommend()
{
	r_Commend = Recommend_Menu();

	switch (r_Commend)
	{
	case 1:	// 음원 전체
		InMusicList();
		break;
	case 0:	//되돌아가기
		return;
	default:
		cout << "\t잘못된 선택인걸...\n";
		break;
	}
}

//m_List 내에서 저장된 곡들 중 랜덤으로 한 곡을 골라서 추천해준다.
int System::InMusicList()
{
	MusicType item;
	m_List.ResetList();
	int length = m_List.GetLength();
	m_List.GetPoint(item);

	srand((unsigned int)time(NULL));	//srand: seed 생성 (랜덤으로 변수만들기 위해 사용한다.)		
	int num = (rand() % length) + 1;	//1~length까지 범위 (전체범위)
	for (int i = 0; i < num; i++)//랜덤변수에 위치한 데이터를 얻기 위한 포인터의 움직임.
	{
		m_List.GetPoint(item);
	}
	item.DisplayRecordOnScreen();//랜덤으로 선택한 위치에 있는 음원정보를 화면에 띄우기
	return 1;
}

void System::DSBestPlayedMusic()
{
	int no;
	BP.ResetList();
	MusicType data;

	cout << "\t=========================" << endl;
	cout << "\t    Best Played Music    " << endl;
	cout << "\t=========================" << endl;

	no = BP.GetLength();
	if (no > 10)
	{
		no = 10;
	}
	for (int i = 0; i < no; i++)
	{
		BP.GetNextItem(data);
		cout << "\t" << i + 1 << ". ";
		data.DisplayAboutBest();
		cout << endl;
	}
}
//void System::PrintUserInfo()
//{
//	cout << "ID: " << _loginedUser->Getid() << endl;
//	cout << "Name: " << _loginedUser->Getname() << endl;
//}

//bool System::GetCommand(int& buffer, int minRange , int maxRange)//범위 내에서 정수를 입력받는 함수
//{
//	int tmprBuffer;
//	if ((!cin >> tmprBuffer) || cin.fail())  // If wrong input,
//	{
//		cin.clear();//Reset
//		cin.ignore(INT_MAX, '\n'); // Make empty buffer
//		return false; 
//	}
//	cin.clear();
//	cin.ignore(INT_MAX, '\n');
//	if (minRange > tmprBuffer || maxRange < tmprBuffer)
//	{
//		return false;
//	}
//	buffer = tmprBuffer;
//	return true; // Return true(=success)
//
//}
//
//bool System::GetCommand(string& buffer) //문자열을 입력받는 함수
//{
//	string tmprBuffer;
//	if (!(cin >> tmprBuffer) || cin.fail()) // If wrong input
//	{
//		cin.clear();
//		cin.ignore(INT_MAX, '\n');
//		return false;
//	}
//	cin.clear();
//	cin.ignore(INT_MAX, '\n');
//	buffer = tmprBuffer;
//	return true;
//}
















