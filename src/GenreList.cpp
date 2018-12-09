#include "GenreList.h"

void GenreList::AddMusicInGenre(SimpleType indata)
{
	mg_List.Add(indata);		//g_List안의 리스트인 mg_List안에 저장함.
}

//장르 선택을 받고 원하는 장르에 해당하는 구체적인 곡 정보를 받는 합수
void GenreList::DisplayMusicDetailInGenre(SingleLinkedList<MusicType> *list)
{
	SimpleType data;
	MusicType m_item;

	cout << "\n\tCurrent list" << endl;

	mg_List.ResetList();
	list->ResetList();		//빈 리스트(list)를 만들어서 m_List를 복사하여 집어넣음.

	for (int i = 0; i < mg_List.GetLength(); i++)
	{
		mg_List.GetNextItem(data);
		list->GetNextItem(m_item);

		while (data.GetNumber() != m_item.GetNumber())
		{
			list->GetNextItem(m_item);
		}
		m_item.DisplayRecordOnScreen();
	}
}


