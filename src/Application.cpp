//#include "Application.h"
//
//
//// Program driver.
//
//
//void Application::Run()
//{	while (1)
//	{	
//
//		m_Command = GetCommand();
//
//		switch (m_Command)
//		{
//		case 1:		// 음악 추가
//			AddItem();
//			break;
//		case 2:		//리스트에서 음악 삭제
//			Delete();
//			break;
//		case 3:		//리스트에 있는 음악 갱신
//			ReplaceMusic();	
//			break;
//		case 4:		//리스트에 있는 음악 검색(검색어가 곡명에 포함되면 출력)
//			SearchByTitle();
//			break;
//		case 5:		//리스트 있는 가수 검색(검색어가 가수명에 포함되면 출력)
//			SearchByArtist();
//			break;
//		case 6:		//리스트에 있는 앨범 검색(검색어가 앨범명에 포함되면 출력)
//			SearchByAlbum();
//			break;
//		case 7:			//리스트에 있는 장르검색(검색어가 장르명에 포함되면 출력)
//			SearchByGenre();
//			break;
//		case 8:		// 리스트에 있는 모든 음악 정보 출력
//			DisplayAll();
//			break;
//		case 9:		// txt 파일에서 음악 정보 읽어옴
//			ReadDataFromFile();
//			break;
//		case 10:		// txt 파일에 음악정보 씀
//			WriteDataToFile();
//			break;
//		case 11:		// 최근에 추가된 30곡의 자세한 정보를 화면에 출력
//			DisplayNewMusic();
//			break;
//		case 12:		// 장르별로 음악 화면출력
//			DisplayMusicByGenre();
//			break;
//		case 13:		// 장르별로 음악 화면출력
//			DisplayMusicByArtist();
//			break;
//		case 14:		// 장르별로 음악 화면출력
//			DisplayMusicByAlbum();
//			break;
//		case 15:		//Song name과 Genre가 일치하는 음악을 찾아서 화면에 출력
//			RetrieveByNameNGenre();
//			break;
//		case 16:		//Song name과 Genre가 일치하는 음악을 찾아서 화면에 출력
//			Recommend();
//			break;
//		case 0:
//			return;
//		default:
//			cout << "\tIllegal selection...\n";
//			break;
//		}
//	}
//}
//
//
//
//
//// Display command on screen and get a input from keyboard.
//int Application::GetCommand()
//{
//	int command;
//	cout << endl << endl;
//	cout << "\t---ID -- Command ----- " << endl;
//	cout << "\t   1 : Add Music" << endl;
//	cout << "\t   2 : Delete Music" << endl;
//	cout << "\t   3 : Replace Music" << endl;
//	cout << "\t   4 : Search Music by Title" << endl;
//	cout << "\t   5 : Search Music by Artist" << endl;
//	cout << "\t   6 : Search Music by Album" << endl;
//	cout << "\t   7 : Search Music by Genre" << endl;
//	cout << "\t   8 : Display all Music" << endl;
//	cout << "\t   9 : Get from file" << endl; 
//	cout << "\t  10 : Put to file " << endl; 
//	cout << "\t  11 : Display New Music" << endl;
//	cout << "\t  12 : Display Music By Genre" << endl;
//	cout << "\t  13 : Display Music By Artist" << endl;
//	cout << "\t  14 : Display Music By Album" << endl;
//	cout << "\t  15 : Retrieve By Name And Genre " << endl;
//	cout << "\t  16 : Recommend " << endl;
//	cout << "\t   0 : Quit" << endl; 
//
//	cout << endl << "\t Choose a Command--> ";
//	cin >> command;
//	cout << endl;
//
//	return command;
//}
//
//
//// Add new record into list.
//int Application::AddItem()
//{
//	MusicType item;
//	SimpleType s_item;
//	GenreList g_item;
//	ArtistList a_item;
//	AlbumList al_item;
//
//	item.SetNumberFromKB();
//
//	while (m_List.Get(item))
//	{
//		cout << "\t곡번호가 중복됩니다." << endl;
//		if (m_List.Get(item))
//			item.SetNumberFromKB();
//	}
//
//	item.SetTitleFromKB();
//	item.SetArtistFromKB();
//	item.SetAlbumFromKB();
//	item.SetGenreFromKB();
//	item.SetLyricsFromKB();
//
//	s_item.SetNumber(item.GetNumber());
//	s_item.SetTitle(item.GetTitle());
//
//	g_item.SetGenre(item.GetGenre());
//	a_item.SetArtist(item.GetArtist());
//	al_item.SetAlbum(item.GetAlbum());
//
//	m_List.Add(item);
//	r_List.EnQueue(s_item);
//
//	if (g_List.GetLength() == 0)
//	{
//		g_List.Add(g_item);
//	}
//	else
//	{
//		while (g_List.Get(g_item) == 0)		//중복이 아닐 때
//		{
//			g_List.Add(g_item);
//		}
//	}
//
//
//	if (a_List.GetLength() == 0)
//	{
//		a_List.Add(a_item);
//	}
//	else
//	{
//		while (a_List.Get(a_item) == 0)		//중복이 아닐 때
//		{
//			a_List.Add(a_item);
//		}
//	}
//
//
//	if (al_List.GetLength() == 0)
//	{
//		al_List.Add(al_item);
//	}
//	else
//	{
//		while (al_List.Get(al_item) == 0)		//중복이 아닐 때
//		{
//			al_List.Add(al_item);
//		}
//	}
//
//
//
//	NodeType<GenreList> *node = new NodeType<GenreList>;
//	NodeType<GenreList> *pre;
//	GenreList temp;  // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미
//	
//	node->data = g_item;
//	node->next = NULL;
//
//	g_List.ResetList();
//	while (1)
//	{
//		pre = pData;   //이전노드를 가리키는 포인터를 생성
//		pData = g_List.GetPoint(temp); //iteration을 이용해 노드 포인터 갱신
//		
//		if (temp.GetGenre() == item.GetGenre())
//		{
//			pData->data.GetGenreList()->Add(s_item);
//			break;
//		}
//	}
//
//
//	NodeType<ArtistList> *a_node = new NodeType<ArtistList>;
//	NodeType<ArtistList> *a_pre;
//	ArtistList a_temp;  // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미
//
//	a_node->data = a_item;
//	a_node->next = NULL;
//
//	a_List.ResetList();
//	while (1)
//	{
//		a_pre = pa_Data;   //이전노드를 가리키는 포인터를 생성
//		pa_Data = a_List.GetPoint(a_temp); //iteration을 이용해 노드 포인터 갱신
//
//		if (a_temp.GetArtist() == item.GetArtist())
//		{
//			pa_Data->data.GetArtistList()->Add(s_item);
//			break;
//		}
//	}
//
//	NodeType<AlbumList> *al_node = new NodeType<AlbumList>;
//	NodeType<AlbumList> *al_pre;
//	AlbumList al_temp;  // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미
//
//	al_node->data = al_item;
//	al_node->next = NULL;
//
//	al_List.ResetList();
//	while (1)
//	{
//		al_pre = pal_Data;   //이전노드를 가리키는 포인터를 생성
//		pal_Data = al_List.GetPoint(al_temp); //iteration을 이용해 노드 포인터 갱신
//
//		if (al_temp.GetAlbum() == item.GetAlbum())
//		{
//			pal_Data->data.GetAlbumList()->Add(s_item);
//			break;
//		}
//	}
//	// 현재 list 출력
//	DisplayAll();
//
//	return 1;
//}
//
//// Display all records in the list on screen.
//void Application::DisplayAll()
//{
//	MusicType data;
//
//	cout << "\n\tCurrent list" << endl;
//
//	m_List.ResetList();	// 리스트 초기화
//						// list의 모든 데이터를 화면에 출력
//	for (int i = 0; i < m_List.GetLength(); i++)
//	{
//		m_List.GetNextItem(data);
//		data.DisplayRecordOnScreen();
//	}
//}
//
//
////찾을 Title을 사용자에게 입력받고 SortedList의 Get함수를 호출한다.
//bool Application::Search()
//{
//	cout << "\t찾을";
//	MusicType data;	//Get함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
//	data.SetTitleFromKB();	//사용자에게서 Title값을 입력받는다.
//	if(m_List.Get(data))	//Title값만 가진 data를 Get으로 보내 나머지 정보를 채운다.  -Get함수 쓰기>
//	{
//		cout << "\t찾았습니다." << endl;
//		data.DisplayRecordOnScreen();
//		return 1;	//찾으면 그 항목을 출력해주고 1을 리턴한다.
//	}
//	else
//		cout << "\t찾지 못했습니다." << endl;
//	return 0;	//찾지 못하면 찾지 못했다는 메시지를 출력하고 0을 리턴한다.
//}
//
//
////찾을 Title를 사용자에게 입력받고 SortedList의 Delete함수를 호출한다.
//void Application::Delete()
//{
//	cout << "\t지울";
//	MusicType data;	//Delete함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
//	data.SetNumberFromKB();	//사용자에게서 Number값을 입력받는다.
//	if(m_List.Delete(data))	//Delete함수에 data를 넘겨준다.
//	{
//		cout << "\t삭제를 완료했습니다." << endl;	//삭제에 성공했으면 메시지를 출력한다.
//	}
//	else
//		cout << "\t삭제하지 못했습니다. 일치하는 항목을 찾을 수 없습니다." << endl;	//삭제에 실패했으면 메시지를 출력한다.
//}
//
//
////찾을 Title를 사용자에게 입력받고 수정할 Title의 정보를 찾아 기존의 정보를 갱신함.
//void Application::ReplaceMusic()
//{
//	cout << "\t변경을 원하는 항목의 ";
//	MusicType data;	//Replace함수는 MusicType을 파라미터로 갖기 때문에 임의로 만들어준다.
//	data.SetNumberFromKB();	//사용자에게서 수정할 항목의 Number를 입력받는다.
//	
//	if (!m_List.Get(data))	//사용자가 입력한 항목이 List에 있나 검색
//	{
//		cout << "\t항목을 찾을 수 없습니다." << endl;		//찾을 수 없을때 메시지를 출력한다.
//		return;
//	}
//
//	else	//찾을 수 있을때
//	{
//		data.SetArtistFromKB();	//사용자에게서 가수를 입력받는다.
//		data.SetAlbumFromKB();	//사용자에게서 앨범을 입력받는다.
//		data.SetGenreFromKB();	//사용자에게서 장르를 입력받는다.
//
//		if(m_List.Replace(data))//Replace함수에 data를 넘겨준다.
//		{
//			cout << "\t수정을 완료했습니다." << endl;	//수정을 성공했을 때 메시지를 출력한다.
//		}
//		else
//			cout << "\t수정을 실패했습니다." << endl;	//수정에 실패했을 때 메시지를 출력한다.
//	}
//	
//}
//
//
////사용자에게 찾고자하는 Title을 입력받고 넘겨주는 역할을 한다.
//void Application::RetreiveRecordByMemberName()
//{
//	MusicType temp;
//	cout << "\t찾을";
//	temp.SetTitleFromKB();	//SearchListByMemberName함수에 넘겨줄 temp의 name을 사용자에게 입력받는다.
//	temp.SetGenreFromKB();
//	SearchListByMemberName(temp);	//실질적으로 찾는 동작을 하는 SearchListByMemberName함수를 호출하고 temp값을 넘겨준다.
//}
//
//
////사용자가 찾고자하는 name(=Title)을 포함하는 inData로 m_List의 항목들 중 일치하는 항목을 찾고 출력해준다. **프로그램에 전반적으로 Array에 index를 직접 접근하는 방법을 선호했으나 이 함수는 Application 클래스의 메소드이므로 GetNextItem함수를 이용해 iteration을 이용했습니다.
//void Application::SearchListByMemberName(MusicType &inData)
//{
//	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 MusicType.
//	m_List.ResetList();
//
//	int length = m_List.GetLength();
//	int count = 0;
//	//m_List.GetPoint(temp);		//초기화시켜줘서 NULL이라 처음에 증가시켜줘야함_예전 랩보기
//	for (int i = 0; i < length; i++)
//	{
//		m_List.GetPoint(temp);
//
//
//		if (temp.GetGenre().find(inData.GetGenre()) != -1)
//		{
//			
//
//			if (temp.GetTitle().find(inData.GetTitle()) != -1)
//			{
//				temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
//				count++;	//찾은 개수를 1 늘려준다.
//			}			
//			
//		}
//
//	}
//	if (count == 0)
//		cout << "\t찾을 수 없습니다." << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
//}
//
//
//
//// Open a file by file descriptor as an input file.
//int Application::OpenInFile(char *fileName)
//{
//	m_InFile.open(fileName);	// file open for reading.
//	
//	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
//	if(!m_InFile)	return 0;
//	else	return 1;
//}
//
//
//// Open a file by file descriptor as an output file.
//int Application::OpenOutFile(char *fileName)
//{
//	m_OutFile.open(fileName);	// file open for writing.
//
//	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
//	if(!m_OutFile)	return 0;
//	else	return 1;
//}
//
//
//// Open a file as a read mode, read all data on the file, and set list by the data.
//int Application::ReadDataFromFile()
//{
//	int index = 0;
//	MusicType data;	// 읽기용 임시 변수
//	
//	char filename[FILENAMESIZE];
//	cout << "\n\tEnter Input file Name : ";
//	cin >> filename;
//
//	// file open, open error가 발생하면 0을 리턴
//	if(!OpenInFile(filename))
//		return 0;
//
//	// 파일의 모든 내용을 읽어 list에 추가
//	while(!m_InFile.eof())
//	{
//		// array에 학생들의 정보가 들어있는 structure 저장
//		data.ReadDataFromFile(m_InFile);
//		m_List.Add(data);
//	}
//
//	m_InFile.close();	// file close
//
//	// 현재 list 출력
//	DisplayAll();
//
//	return 1;
//}
//
//
//// Open a file as a write mode, and write all data into the file,
//int Application::WriteDataToFile()
//{
//	MusicType data;	// 쓰기용 임시 변수
//
//	char filename[FILENAMESIZE];
//	cout << "\n\tEnter Output file Name : ";
//	cin >> filename;
//
//	// file open, open error가 발생하면 0을 리턴
//	if(!OpenOutFile(filename))
//		return 0;
//
//	// list 포인터를 초기화
//	m_List.ResetList();
//
//	// list의 모든 데이터를 파일에 쓰기
//	int length = m_List.GetLength();
//	int curIndex = m_List.GetNextItem(data);
//	while(curIndex < length && curIndex != -1)
//	{
//		data.WriteDataToFile(m_OutFile);
//		curIndex = m_List.GetNextItem(data);
//	}
//
//	m_OutFile.close();	// file close
//
//	return 1;
//}
//
//
//// 입력된 정보로 리스트에서 제목을 찾아 정보출력
//int Application::SearchByTitle()
//{
//	MusicType item;
//	string input;
//
//	cout << "\t찾고자하는 음악 Title을 입력하세요 : ";
//	cin >> input;
//	cout << endl << endl;
//
//	// list의 모든 데이터를 화면에 출력
//	m_List.ResetList();      //리스트값을 리셋한다. 값은 -1이 된다.
//	int length = m_List.GetLength();   //리스트의 길이를 length에 저장한다.
//	m_List.GetNextItem(item);
//
//	for (int i = 0; i < m_List.GetLength(); i++)
//	{
//		if (item.GetTitle() == input)
//		{
//			item.DisplayRecordOnScreen();
//			break;
//		}
//		m_List.GetNextItem(item);
//	}
//
//	return 0;
//}
//
//// 입력된 정보로 리스트에서 가수를 찾아 정보출력
//int Application::SearchByArtist()
//{
//	MusicType item;
//	string input;
//
//	cout << "\t찾고자하는 음악 Title을 입력하세요 : ";
//	cin >> input;
//	cout << endl << endl;
//
//	// list의 모든 데이터를 화면에 출력
//	m_List.ResetList();      //리스트값을 리셋한다. 값은 -1이 된다.
//	int length = m_List.GetLength();   //리스트의 길이를 length에 저장한다.
//	m_List.GetNextItem(item);
//
//	for (int i = 0; i < m_List.GetLength(); i++)
//	{
//		if (item.GetTitle() == input)
//		{
//			item.DisplayRecordOnScreen();
//			break;
//		}
//		m_List.GetNextItem(item);
//	}
//
//	return 0;
//}
//// 입력된 정보로 리스트에서 앨범을 찾아 정보출력
//int Application::SearchByAlbum()
//{
//	MusicType item;
//	string input;
//
//	cout << "\t찾고자하는 음악 Title을 입력하세요 : ";
//	cin >> input;
//	cout << endl << endl;
//
//	// list의 모든 데이터를 화면에 출력
//	m_List.ResetList();      //리스트값을 리셋한다. 값은 -1이 된다.
//	int length = m_List.GetLength();   //리스트의 길이를 length에 저장한다.
//	m_List.GetNextItem(item);
//
//	for (int i = 0; i < m_List.GetLength(); i++)
//	{
//		if (item.GetTitle() == input)
//		{
//			item.DisplayRecordOnScreen();
//			break;
//		}
//		m_List.GetNextItem(item);
//	}
//
//	return 0;
//}
//
//// 입력된 정보로 리스트에서 장르를 찾아 정보출력
//int Application::SearchByGenre()
//{
//	MusicType item;
//	string input;
//
//	cout << "\t찾고자하는 음악 Title을 입력하세요 : ";
//	cin >> input;
//	cout << endl << endl;
//
//	// list의 모든 데이터를 화면에 출력
//	m_List.ResetList();      //리스트값을 리셋한다. 값은 -1이 된다.
//	int length = m_List.GetLength();   //리스트의 길이를 length에 저장한다.
//	m_List.GetNextItem(item);
//
//	for (int i = 0; i < m_List.GetLength(); i++)
//	{
//		if (item.GetTitle() == input)
//		{
//			item.DisplayRecordOnScreen();
//			break;
//		}
//		m_List.GetNextItem(item);
//	}
//
//	return 0;
//}
//
//
////최근에 추가된 30곡의 자세한 정보를 화면에 출력
//void Application::DisplayNewMusic()
//{
//	cout << "\n\tNew Music 30 list" << endl;
//
//	MusicType item;
//	SimpleType data;
//
//	r_List.ResetQueue();	//r_CurPointer 초기화
//	int length = r_List.GetTop(); // length에 리스트 길이 저장
//	int curIndex = r_List.GetNextItem(data); // data에 첫번째 칸 정보 저장
//
//
//	for (int i = length; i>0 ; i-- )
//	{
//		item.SetNumber(data.GetNumber());	//SimpleType의 data에서 곡번호를 받아 MusicType의 item에 곡번호를 준다.
//		m_List.Get(item);		//m_List에서 item에 저장된 곡번호에 맞는 정보를 찾는다.  
//		item.DisplayRecordOnScreen();		//곡번호, 곡명, 가수, 장르, 가사를 화면에 출력함.
//		curIndex = r_List.GetNextItem(data);	//r_CurPointer를 다음 index로 넘긴다.
//	}
//}
//
//
////장르별로 음악 화면출력
//int Application::DisplayMusicByGenre()
//{
//	GenreList data;
//	GenreList dummy;
//
//	cout << "\n\tCurrent list" << endl;
//
//	// genre list의 모든 데이터를 화면에 출력
//	g_List.ResetList();
//
//	for (int i = 0; i < g_List.GetLength(); i++)
//	{
//		cout << i + 1 << endl;
//		g_List.GetNextItem(data);
//		data.DisplayAll();
//	}
//
//	// 특정 장르의 음악 정보만 보고 싶을 때
//	string name;
//
//	cout << "찾고자하는 장르를 입력하세요 : ";
//	cin >> name;
//	dummy.SetGenre(name);
//
//	GenreList g_temp;
//	NodeType<GenreList> *pData;
//
//	g_List.ResetList();
//	for (int i = 0; i < g_List.GetLength(); i++)
//	{
//		pData = g_List.GetPoint(g_temp);
//		if (g_temp.GetGenre() == dummy.GetGenre())
//		{
//			pData->data.DisplayMusicDetailInGenre(&m_List); // 해당 장르 음악 출력
//			return 1;
//		}
//
//	}
//
//	cout << "해당 장르에 곡이 존재하지 않습니다.";
//	return 1;
//	
//}
//
////가수별로 음악 화면출력
//int Application::DisplayMusicByArtist()
//{
//	ArtistList data;
//	ArtistList dummy;
//
//	cout << "\n\tCurrent list" << endl;
//
//	// artist list의 모든 데이터를 화면에 출력
//	a_List.ResetList();
//
//	for (int i = 0; i < a_List.GetLength(); i++)
//	{
//		cout << i + 1 << endl;
//		a_List.GetNextItem(data);
//		data.DisplayAll();
//	}
//
//	// 특정 가수의 음악 정보만 보고 싶을 때
//	string name;
//
//	cout << "찾고자하는 가수를 입력하세요 : ";
//	cin >> name;
//	dummy.SetArtist(name);
//
//	ArtistList a_temp;
//	NodeType<ArtistList> *pa_Data;
//
//	a_List.ResetList();
//	for (int i = 0; i < a_List.GetLength(); i++)
//	{
//		pa_Data = a_List.GetPoint(a_temp);
//		if (a_temp.GetArtist() == dummy.GetArtist())
//		{
//			pa_Data->data.DisplayMusicDetailInArtist(&m_List); // 해당 장르 음악 출력
//			return 1;
//		}
//
//	}
//
//	cout << "해당 가수의 곡이 존재하지 않습니다.";
//	return 1;
//
//}
//
////앨범별로 음악 화면출력
//int Application::DisplayMusicByAlbum()
//{
//	AlbumList data;
//	AlbumList dummy;
//
//	cout << "\n\tCurrent list" << endl;
//
//	// album list의 모든 데이터를 화면에 출력
//	al_List.ResetList();
//
//	for (int i = 0; i < al_List.GetLength(); i++)
//	{
//		cout << i + 1 << endl;
//		al_List.GetNextItem(data);
//		data.DisplayAll();
//	}
//
//	// 특정 앨범의 음악 정보만 보고 싶을 때
//	string name;
//
//	cout << "찾고자하는 앨범을 입력하세요 : ";
//	cin >> name;
//	dummy.SetAlbum(name);
//
//	AlbumList al_temp;
//	NodeType<AlbumList> *pal_Data;
//
//	al_List.ResetList();
//	for (int i = 0; i < al_List.GetLength(); i++)
//	{
//		pal_Data = al_List.GetPoint(al_temp);
//		if (al_temp.GetAlbum() == dummy.GetAlbum())
//		{
//			pal_Data->data.DisplayMusicDetailInAlbum(&m_List); // 해당 장르 음악 출력
//			return 1;
//		}
//
//	}
//
//	cout << "해당 가수의 곡이 존재하지 않습니다.";
//	return 1;
//
//}
//
//
////Song name과 Genre가 일치하는 음악을 찾아서 화면에 출력
//int Application::RetrieveByNameNGenre()
//{
//	MusicType item;
//	RetreiveRecordByMemberName();
//	return 1;
//
//}
//
//////////////
//
//// Display recommand on screen and get a input from keyboard.
//int Application::Recommend_Menu()
//{
//	int recommend_num;
//	cout << endl << endl;
//	cout << "\t원하는 추천 범위를 고르세요" << endl;
//	cout << "\t**********************************" << endl;
//	cout << "\t   1 : 음원 전체에서 추천받기" << endl;		//m_List 내에서
//	cout << "\t   0 : 되돌아가기" << endl;
//	cout << endl << "\t --> ";
//
//	cin >> recommend_num;
//	cout << endl;
//
//	return recommend_num;
//}
//
//void Application::Recommend()
//{
//	r_Commend = Recommend_Menu();
//
//	switch (r_Commend)
//	{
//	case 1:		// 음원 전체
//		InMusicList();
//		break;
//	case 0:		//되돌아가기
//		return;
//	default:
//		cout << "\tIllegal selection...\n";
//		break;
//	}
//}
//
////m_List 내에서 저장된 곡들 중 랜덤으로 한 곡을 골라 준다
//int Application::InMusicList()
//{
//	MusicType item;	
//	m_List.ResetList();
//	int length = m_List.GetLength();
//	m_List.GetPoint(item);	
//	
//	srand((unsigned int)time(NULL));		////srand: seed 생성(랜덤으로 변수만들기 위해 사용)		
//	int num = (rand() % length) + 1;		//1~length까지 범위
//
//	for (int i = 0; i < num; i++)	//랜덤변수에 위치한 데이터를 얻기 위해 포인터 움직임.
//	{	
//		m_List.GetPoint(item);
//	}
//	item.DisplayRecordOnScreen();	//랜덤으로 선택한 위치에 있는 음원정보 화면에 띄우기
//	return 1;
//}
//
