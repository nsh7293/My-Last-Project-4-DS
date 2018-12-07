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
//		case 1:		// ���� �߰�
//			AddItem();
//			break;
//		case 2:		//����Ʈ���� ���� ����
//			Delete();
//			break;
//		case 3:		//����Ʈ�� �ִ� ���� ����
//			ReplaceMusic();	
//			break;
//		case 4:		//����Ʈ�� �ִ� ���� �˻�(�˻�� ��� ���ԵǸ� ���)
//			SearchByTitle();
//			break;
//		case 5:		//����Ʈ �ִ� ���� �˻�(�˻�� ������ ���ԵǸ� ���)
//			SearchByArtist();
//			break;
//		case 6:		//����Ʈ�� �ִ� �ٹ� �˻�(�˻�� �ٹ��� ���ԵǸ� ���)
//			SearchByAlbum();
//			break;
//		case 7:			//����Ʈ�� �ִ� �帣�˻�(�˻�� �帣�� ���ԵǸ� ���)
//			SearchByGenre();
//			break;
//		case 8:		// ����Ʈ�� �ִ� ��� ���� ���� ���
//			DisplayAll();
//			break;
//		case 9:		// txt ���Ͽ��� ���� ���� �о��
//			ReadDataFromFile();
//			break;
//		case 10:		// txt ���Ͽ� �������� ��
//			WriteDataToFile();
//			break;
//		case 11:		// �ֱٿ� �߰��� 30���� �ڼ��� ������ ȭ�鿡 ���
//			DisplayNewMusic();
//			break;
//		case 12:		// �帣���� ���� ȭ�����
//			DisplayMusicByGenre();
//			break;
//		case 13:		// �帣���� ���� ȭ�����
//			DisplayMusicByArtist();
//			break;
//		case 14:		// �帣���� ���� ȭ�����
//			DisplayMusicByAlbum();
//			break;
//		case 15:		//Song name�� Genre�� ��ġ�ϴ� ������ ã�Ƽ� ȭ�鿡 ���
//			RetrieveByNameNGenre();
//			break;
//		case 16:		//Song name�� Genre�� ��ġ�ϴ� ������ ã�Ƽ� ȭ�鿡 ���
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
//		cout << "\t���ȣ�� �ߺ��˴ϴ�." << endl;
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
//		while (g_List.Get(g_item) == 0)		//�ߺ��� �ƴ� ��
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
//		while (a_List.Get(a_item) == 0)		//�ߺ��� �ƴ� ��
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
//		while (al_List.Get(al_item) == 0)		//�ߺ��� �ƴ� ��
//		{
//			al_List.Add(al_item);
//		}
//	}
//
//
//
//	NodeType<GenreList> *node = new NodeType<GenreList>;
//	NodeType<GenreList> *pre;
//	GenreList temp;  // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����
//	
//	node->data = g_item;
//	node->next = NULL;
//
//	g_List.ResetList();
//	while (1)
//	{
//		pre = pData;   //������带 ����Ű�� �����͸� ����
//		pData = g_List.GetPoint(temp); //iteration�� �̿��� ��� ������ ����
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
//	ArtistList a_temp;  // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����
//
//	a_node->data = a_item;
//	a_node->next = NULL;
//
//	a_List.ResetList();
//	while (1)
//	{
//		a_pre = pa_Data;   //������带 ����Ű�� �����͸� ����
//		pa_Data = a_List.GetPoint(a_temp); //iteration�� �̿��� ��� ������ ����
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
//	AlbumList al_temp;  // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����
//
//	al_node->data = al_item;
//	al_node->next = NULL;
//
//	al_List.ResetList();
//	while (1)
//	{
//		al_pre = pal_Data;   //������带 ����Ű�� �����͸� ����
//		pal_Data = al_List.GetPoint(al_temp); //iteration�� �̿��� ��� ������ ����
//
//		if (al_temp.GetAlbum() == item.GetAlbum())
//		{
//			pal_Data->data.GetAlbumList()->Add(s_item);
//			break;
//		}
//	}
//	// ���� list ���
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
//	m_List.ResetList();	// ����Ʈ �ʱ�ȭ
//						// list�� ��� �����͸� ȭ�鿡 ���
//	for (int i = 0; i < m_List.GetLength(); i++)
//	{
//		m_List.GetNextItem(data);
//		data.DisplayRecordOnScreen();
//	}
//}
//
//
////ã�� Title�� ����ڿ��� �Է¹ް� SortedList�� Get�Լ��� ȣ���Ѵ�.
//bool Application::Search()
//{
//	cout << "\tã��";
//	MusicType data;	//Get�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
//	data.SetTitleFromKB();	//����ڿ��Լ� Title���� �Է¹޴´�.
//	if(m_List.Get(data))	//Title���� ���� data�� Get���� ���� ������ ������ ä���.  -Get�Լ� ����>
//	{
//		cout << "\tã�ҽ��ϴ�." << endl;
//		data.DisplayRecordOnScreen();
//		return 1;	//ã���� �� �׸��� ������ְ� 1�� �����Ѵ�.
//	}
//	else
//		cout << "\tã�� ���߽��ϴ�." << endl;
//	return 0;	//ã�� ���ϸ� ã�� ���ߴٴ� �޽����� ����ϰ� 0�� �����Ѵ�.
//}
//
//
////ã�� Title�� ����ڿ��� �Է¹ް� SortedList�� Delete�Լ��� ȣ���Ѵ�.
//void Application::Delete()
//{
//	cout << "\t����";
//	MusicType data;	//Delete�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
//	data.SetNumberFromKB();	//����ڿ��Լ� Number���� �Է¹޴´�.
//	if(m_List.Delete(data))	//Delete�Լ��� data�� �Ѱ��ش�.
//	{
//		cout << "\t������ �Ϸ��߽��ϴ�." << endl;	//������ ���������� �޽����� ����Ѵ�.
//	}
//	else
//		cout << "\t�������� ���߽��ϴ�. ��ġ�ϴ� �׸��� ã�� �� �����ϴ�." << endl;	//������ ���������� �޽����� ����Ѵ�.
//}
//
//
////ã�� Title�� ����ڿ��� �Է¹ް� ������ Title�� ������ ã�� ������ ������ ������.
//void Application::ReplaceMusic()
//{
//	cout << "\t������ ���ϴ� �׸��� ";
//	MusicType data;	//Replace�Լ��� MusicType�� �Ķ���ͷ� ���� ������ ���Ƿ� ������ش�.
//	data.SetNumberFromKB();	//����ڿ��Լ� ������ �׸��� Number�� �Է¹޴´�.
//	
//	if (!m_List.Get(data))	//����ڰ� �Է��� �׸��� List�� �ֳ� �˻�
//	{
//		cout << "\t�׸��� ã�� �� �����ϴ�." << endl;		//ã�� �� ������ �޽����� ����Ѵ�.
//		return;
//	}
//
//	else	//ã�� �� ������
//	{
//		data.SetArtistFromKB();	//����ڿ��Լ� ������ �Է¹޴´�.
//		data.SetAlbumFromKB();	//����ڿ��Լ� �ٹ��� �Է¹޴´�.
//		data.SetGenreFromKB();	//����ڿ��Լ� �帣�� �Է¹޴´�.
//
//		if(m_List.Replace(data))//Replace�Լ��� data�� �Ѱ��ش�.
//		{
//			cout << "\t������ �Ϸ��߽��ϴ�." << endl;	//������ �������� �� �޽����� ����Ѵ�.
//		}
//		else
//			cout << "\t������ �����߽��ϴ�." << endl;	//������ �������� �� �޽����� ����Ѵ�.
//	}
//	
//}
//
//
////����ڿ��� ã�����ϴ� Title�� �Է¹ް� �Ѱ��ִ� ������ �Ѵ�.
//void Application::RetreiveRecordByMemberName()
//{
//	MusicType temp;
//	cout << "\tã��";
//	temp.SetTitleFromKB();	//SearchListByMemberName�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
//	temp.SetGenreFromKB();
//	SearchListByMemberName(temp);	//���������� ã�� ������ �ϴ� SearchListByMemberName�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
//}
//
//
////����ڰ� ã�����ϴ� name(=Title)�� �����ϴ� inData�� m_List�� �׸�� �� ��ġ�ϴ� �׸��� ã�� ������ش�. **���α׷��� ���������� Array�� index�� ���� �����ϴ� ����� ��ȣ������ �� �Լ��� Application Ŭ������ �޼ҵ��̹Ƿ� GetNextItem�Լ��� �̿��� iteration�� �̿��߽��ϴ�.
//void Application::SearchListByMemberName(MusicType &inData)
//{
//	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� MusicType.
//	m_List.ResetList();
//
//	int length = m_List.GetLength();
//	int count = 0;
//	//m_List.GetPoint(temp);		//�ʱ�ȭ�����༭ NULL�̶� ó���� �������������_���� ������
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
//				temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
//				count++;	//ã�� ������ 1 �÷��ش�.
//			}			
//			
//		}
//
//	}
//	if (count == 0)
//		cout << "\tã�� �� �����ϴ�." << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
//}
//
//
//
//// Open a file by file descriptor as an input file.
//int Application::OpenInFile(char *fileName)
//{
//	m_InFile.open(fileName);	// file open for reading.
//	
//	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
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
//	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
//	if(!m_OutFile)	return 0;
//	else	return 1;
//}
//
//
//// Open a file as a read mode, read all data on the file, and set list by the data.
//int Application::ReadDataFromFile()
//{
//	int index = 0;
//	MusicType data;	// �б�� �ӽ� ����
//	
//	char filename[FILENAMESIZE];
//	cout << "\n\tEnter Input file Name : ";
//	cin >> filename;
//
//	// file open, open error�� �߻��ϸ� 0�� ����
//	if(!OpenInFile(filename))
//		return 0;
//
//	// ������ ��� ������ �о� list�� �߰�
//	while(!m_InFile.eof())
//	{
//		// array�� �л����� ������ ����ִ� structure ����
//		data.ReadDataFromFile(m_InFile);
//		m_List.Add(data);
//	}
//
//	m_InFile.close();	// file close
//
//	// ���� list ���
//	DisplayAll();
//
//	return 1;
//}
//
//
//// Open a file as a write mode, and write all data into the file,
//int Application::WriteDataToFile()
//{
//	MusicType data;	// ����� �ӽ� ����
//
//	char filename[FILENAMESIZE];
//	cout << "\n\tEnter Output file Name : ";
//	cin >> filename;
//
//	// file open, open error�� �߻��ϸ� 0�� ����
//	if(!OpenOutFile(filename))
//		return 0;
//
//	// list �����͸� �ʱ�ȭ
//	m_List.ResetList();
//
//	// list�� ��� �����͸� ���Ͽ� ����
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
//// �Էµ� ������ ����Ʈ���� ������ ã�� �������
//int Application::SearchByTitle()
//{
//	MusicType item;
//	string input;
//
//	cout << "\tã�����ϴ� ���� Title�� �Է��ϼ��� : ";
//	cin >> input;
//	cout << endl << endl;
//
//	// list�� ��� �����͸� ȭ�鿡 ���
//	m_List.ResetList();      //����Ʈ���� �����Ѵ�. ���� -1�� �ȴ�.
//	int length = m_List.GetLength();   //����Ʈ�� ���̸� length�� �����Ѵ�.
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
//// �Էµ� ������ ����Ʈ���� ������ ã�� �������
//int Application::SearchByArtist()
//{
//	MusicType item;
//	string input;
//
//	cout << "\tã�����ϴ� ���� Title�� �Է��ϼ��� : ";
//	cin >> input;
//	cout << endl << endl;
//
//	// list�� ��� �����͸� ȭ�鿡 ���
//	m_List.ResetList();      //����Ʈ���� �����Ѵ�. ���� -1�� �ȴ�.
//	int length = m_List.GetLength();   //����Ʈ�� ���̸� length�� �����Ѵ�.
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
//// �Էµ� ������ ����Ʈ���� �ٹ��� ã�� �������
//int Application::SearchByAlbum()
//{
//	MusicType item;
//	string input;
//
//	cout << "\tã�����ϴ� ���� Title�� �Է��ϼ��� : ";
//	cin >> input;
//	cout << endl << endl;
//
//	// list�� ��� �����͸� ȭ�鿡 ���
//	m_List.ResetList();      //����Ʈ���� �����Ѵ�. ���� -1�� �ȴ�.
//	int length = m_List.GetLength();   //����Ʈ�� ���̸� length�� �����Ѵ�.
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
//// �Էµ� ������ ����Ʈ���� �帣�� ã�� �������
//int Application::SearchByGenre()
//{
//	MusicType item;
//	string input;
//
//	cout << "\tã�����ϴ� ���� Title�� �Է��ϼ��� : ";
//	cin >> input;
//	cout << endl << endl;
//
//	// list�� ��� �����͸� ȭ�鿡 ���
//	m_List.ResetList();      //����Ʈ���� �����Ѵ�. ���� -1�� �ȴ�.
//	int length = m_List.GetLength();   //����Ʈ�� ���̸� length�� �����Ѵ�.
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
////�ֱٿ� �߰��� 30���� �ڼ��� ������ ȭ�鿡 ���
//void Application::DisplayNewMusic()
//{
//	cout << "\n\tNew Music 30 list" << endl;
//
//	MusicType item;
//	SimpleType data;
//
//	r_List.ResetQueue();	//r_CurPointer �ʱ�ȭ
//	int length = r_List.GetTop(); // length�� ����Ʈ ���� ����
//	int curIndex = r_List.GetNextItem(data); // data�� ù��° ĭ ���� ����
//
//
//	for (int i = length; i>0 ; i-- )
//	{
//		item.SetNumber(data.GetNumber());	//SimpleType�� data���� ���ȣ�� �޾� MusicType�� item�� ���ȣ�� �ش�.
//		m_List.Get(item);		//m_List���� item�� ����� ���ȣ�� �´� ������ ã�´�.  
//		item.DisplayRecordOnScreen();		//���ȣ, ���, ����, �帣, ���縦 ȭ�鿡 �����.
//		curIndex = r_List.GetNextItem(data);	//r_CurPointer�� ���� index�� �ѱ��.
//	}
//}
//
//
////�帣���� ���� ȭ�����
//int Application::DisplayMusicByGenre()
//{
//	GenreList data;
//	GenreList dummy;
//
//	cout << "\n\tCurrent list" << endl;
//
//	// genre list�� ��� �����͸� ȭ�鿡 ���
//	g_List.ResetList();
//
//	for (int i = 0; i < g_List.GetLength(); i++)
//	{
//		cout << i + 1 << endl;
//		g_List.GetNextItem(data);
//		data.DisplayAll();
//	}
//
//	// Ư�� �帣�� ���� ������ ���� ���� ��
//	string name;
//
//	cout << "ã�����ϴ� �帣�� �Է��ϼ��� : ";
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
//			pData->data.DisplayMusicDetailInGenre(&m_List); // �ش� �帣 ���� ���
//			return 1;
//		}
//
//	}
//
//	cout << "�ش� �帣�� ���� �������� �ʽ��ϴ�.";
//	return 1;
//	
//}
//
////�������� ���� ȭ�����
//int Application::DisplayMusicByArtist()
//{
//	ArtistList data;
//	ArtistList dummy;
//
//	cout << "\n\tCurrent list" << endl;
//
//	// artist list�� ��� �����͸� ȭ�鿡 ���
//	a_List.ResetList();
//
//	for (int i = 0; i < a_List.GetLength(); i++)
//	{
//		cout << i + 1 << endl;
//		a_List.GetNextItem(data);
//		data.DisplayAll();
//	}
//
//	// Ư�� ������ ���� ������ ���� ���� ��
//	string name;
//
//	cout << "ã�����ϴ� ������ �Է��ϼ��� : ";
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
//			pa_Data->data.DisplayMusicDetailInArtist(&m_List); // �ش� �帣 ���� ���
//			return 1;
//		}
//
//	}
//
//	cout << "�ش� ������ ���� �������� �ʽ��ϴ�.";
//	return 1;
//
//}
//
////�ٹ����� ���� ȭ�����
//int Application::DisplayMusicByAlbum()
//{
//	AlbumList data;
//	AlbumList dummy;
//
//	cout << "\n\tCurrent list" << endl;
//
//	// album list�� ��� �����͸� ȭ�鿡 ���
//	al_List.ResetList();
//
//	for (int i = 0; i < al_List.GetLength(); i++)
//	{
//		cout << i + 1 << endl;
//		al_List.GetNextItem(data);
//		data.DisplayAll();
//	}
//
//	// Ư�� �ٹ��� ���� ������ ���� ���� ��
//	string name;
//
//	cout << "ã�����ϴ� �ٹ��� �Է��ϼ��� : ";
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
//			pal_Data->data.DisplayMusicDetailInAlbum(&m_List); // �ش� �帣 ���� ���
//			return 1;
//		}
//
//	}
//
//	cout << "�ش� ������ ���� �������� �ʽ��ϴ�.";
//	return 1;
//
//}
//
//
////Song name�� Genre�� ��ġ�ϴ� ������ ã�Ƽ� ȭ�鿡 ���
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
//	cout << "\t���ϴ� ��õ ������ ������" << endl;
//	cout << "\t**********************************" << endl;
//	cout << "\t   1 : ���� ��ü���� ��õ�ޱ�" << endl;		//m_List ������
//	cout << "\t   0 : �ǵ��ư���" << endl;
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
//	case 1:		// ���� ��ü
//		InMusicList();
//		break;
//	case 0:		//�ǵ��ư���
//		return;
//	default:
//		cout << "\tIllegal selection...\n";
//		break;
//	}
//}
//
////m_List ������ ����� ��� �� �������� �� ���� ��� �ش�
//int Application::InMusicList()
//{
//	MusicType item;	
//	m_List.ResetList();
//	int length = m_List.GetLength();
//	m_List.GetPoint(item);	
//	
//	srand((unsigned int)time(NULL));		////srand: seed ����(�������� ��������� ���� ���)		
//	int num = (rand() % length) + 1;		//1~length���� ����
//
//	for (int i = 0; i < num; i++)	//���������� ��ġ�� �����͸� ��� ���� ������ ������.
//	{	
//		m_List.GetPoint(item);
//	}
//	item.DisplayRecordOnScreen();	//�������� ������ ��ġ�� �ִ� �������� ȭ�鿡 ����
//	return 1;
//}
//
