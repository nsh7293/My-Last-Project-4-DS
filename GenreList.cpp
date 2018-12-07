#include "GenreList.h"

void GenreList::AddMusicInGenre(SimpleType indata)
{
	mg_List.Add(indata);		//g_List���� ����Ʈ�� mg_List�ȿ� ������.
}

//�帣 ������ �ް� ���ϴ� �帣�� �ش��ϴ� ��ü���� �� ������ �޴� �ռ�
void GenreList::DisplayMusicDetailInGenre(SingleLinkedList<MusicType> *list)
{
	SimpleType data;
	MusicType m_item;

	cout << "\n\tCurrent list" << endl;

	mg_List.ResetList();
	list->ResetList();		//�� ����Ʈ(list)�� ���� m_List�� �����Ͽ� �������.

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


