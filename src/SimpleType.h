
#ifndef _SIMPLETYPE_H
#define _SIMPLETYPE_H

#include <string>
#include <iostream>



using namespace std;

/**
*	������ ������ ���� ����
*/

/**
*	item information class.
*/
class SimpleType
{
public:
	/**
	*	default constructor.
	*/
	SimpleType()
	{
		s_Number = 0;
		s_Title = "";
	}

	/**
	*	destructor.
	*/
	~SimpleType() {}

	/**
	*	@brief	���ȣ �ޱ�.
	*	@pre	number is set.
	*	@post	none.
	*	@return	number.
	*/
	int GetNumber()
	{
		return s_Number;
	}

	/**
	*	@brief	��� �ޱ�.
	*	@pre	Title is set.
	*	@post	none.
	*	@return	Title.
	*/
	string GetTitle()
	{
		return s_Title;
	}

	/**
	*	@brief	Set Number.
	*	@pre	none.
	*	@post	Number is set.
	*	@param	inNumber	Title.
	*/
	void SetNumber(int inNumber)
	{
		s_Number = inNumber;
	}

	/**
	*	@brief	Set Title.
	*	@pre	none.
	*	@post	Title is set.
	*	@param	inTitle	Title.
	*/
	void SetTitle(string inTitle)
	{
		s_Title = inTitle;
	}

	/**
	*	@brief	display simple music information on screen.
	*/
	void DisplayAll()
	{
		cout << "Number : " << s_Number << endl;
		cout << "Title : " << s_Title << endl;
	}

	/**
	*	@brief	�л� ID�� ��´�
	*	@pre	�л� ID�� �Է¹޴´�
	*	@post	none
	*	@return	�л� ID�� ����
	*/
	int GetId() const
	{
		return m_Id;
	}

	/**
	*	@brief	�л� �̸��� ��´�
	*	@pre	�л� �̸��� �Է¹޴´�
	*	@post	none
	*	@return	�л� �̸��� ����
	*/
	string GetName() const
	{
		return m_sName;
	}


	/**
	*	@brief	�л� �ּҸ� ��´�
	*	@pre	�л� �ּҸ� �Է¹޴´�
	*	@post	none
	*	@return	�л� �ּҸ� ����
	*/
	string GetAddress() const
	{
		return m_sAddress;
	}

	/**
	*	@brief	�л� ID�� �Է¹޴´�
	*	@pre	none
	*	@post	�л� ID�� �Էµ�
	*	@param	inId	student id.
	*/
	void SetId(int inId)
	{
		m_Id = inId;
	}

	/**
	*	@brief	�л� �̸��� �Է¹޴´�
	*	@pre	none
	*	@post	�л� �̸��� �Էµ�
	*	@param	inName	student name.
	*/
	void SetName(string inName)
	{
		m_sName = inName;
	}

	/**
	*	@brief	�л� �ּҸ� �Է¹޴´�
	*	@pre	none
	*	@post	�л� �ּҰ� �Էµ�
	*	@param	inAddress	student address
	*/
	void SetAddress(string inAddress)
	{
		m_sAddress = inAddress;
	}
	/**
	*	@brief	�л� ����(���ڵ�)�� �Է�
	*	@pre	none
	*	@post	�л� ������ �Էµ�
	*	@param	inId	student id
	*	@param	inName	student name
	*	@param	inAddress	student address
	*/
	void SetRecord(int inId, string inName, string inAddress)
	{
		SetId(inId);
		SetName(inName);
		SetAddress(inAddress);
	}

	/**
	*	@brief	�л� ID�� ��ũ���� ���
	*	@pre	�л� ID�� �Էµ�
	*	@post	�л� ID�� ��ũ���� ��µ�
	*/
	void DisplayIdOnScreen()
	{
		cout << "\tID   : " << m_Id << endl;
	};

	/**
	*	@brief	�л� �̸��� ��ũ���� ���
	*	@pre	�л� �̸��� �Էµ�
	*	@post	�л� �̸��� ��ũ���� ��µ�
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_sName << endl;
	};

	/**
	*	@brief	�л� �ּҸ� ��ũ���� ���
	*	@pre	�л� �ּҰ� �Էµ�
	*	@post	�л� �ּҰ� ��ũ���� ��µ�
	*/
	void DisplayAddressOnScreen()
	{
		cout << "\tAddress : " << m_sAddress << endl;
	};

	/**
	*	@brief	�л� ����(���ڵ�)�� ��ũ���� ���
	*	@pre	�л� ������ �Էµ�
	*	@post	�л� ������ ��ũ���� ��µ�
	*/
	void DisplayRecordOnScreen()
	{
		DisplayIdOnScreen();
		DisplayNameOnScreen();
	};

	/**
	*	@brief	Ű����κ��� �л� ID�� �Է¹���
	*	@pre	none
	*	@post	�л� ID�� �Էµ�
	*/
	void SetIdFromKB();

	/**
	*	@brief	Ű����κ��� �л� �̸��� �Է¹���
	*	@pre	none
	*	@post	�л� �̸��� �Էµ�
	*/
	void SetNameFromKB();

	/**
	*	@brief	Ű����κ��� �л� �ּҸ� �Է¹���
	*	@pre	none
	*	@post	�л� �ּҰ� �Էµ�
	*/
	void SetAddressFromKB();

	/**
	*	@brief	Ű����κ��� �л� ������ �Է¹���
	*	@pre	none
	*	@post	�л� ������ �Էµ�
	*/
	void SetRecordFromKB();

	void SetPlayedFromKB();
	/**
	*	@brief	���Ͽ��� ���ڵ带 �д´�
	*	@pre	Ÿ�� ������ ���µǾ�����
	*	@post	�л� ������ �Էµ�
	*	@param	fin	file descriptor.
	*	@return	�Լ��� �� ���ư��� 1�� ���� �ƴϸ� 0�� ����
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	���Ͽ� ������ ����
	*	@pre	Ÿ�� ������ ���µǾ�����, ����Ʈ�� �ʱ�ȭ��
	*	@post	Ÿ�� ������ �� �л� ������ ������
	*	@param	fout	file descriptor.
	*	@return	�Լ��� �� ���ư��� 1�� ���� �ƴϸ� 0�� ����
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	�� ������Ÿ���� ���Ѵ�
	*	@brief	Item ID�� �� ������Ÿ���� ���Ѵ�
	*	@pre	�� ������Ÿ���� �ʱ�ȭ�Ǿ���Ѵ�
	*	@post	Ÿ�� ������ �� �л� ������ ������
	*	@param	data	target item for comparing.
	*	@return	����ID�� DATA�� ID���� ���� ��� LESS�� ����,
	*			����ID�� DATA�� ID���� Ŭ ��� GREATER�� ����,
	*			�ƴϸ� EQUAL�� ����
	*/

	/**
	*	@brief  ���ȣ�� ���� �񱳷� ������ �����ε�
	*	@pre	none.
	*	@post	none.
	*	@return	�����ڿ� �´� 1,0 ��
	*/
	bool operator== (const SimpleType &T)const
	{
		if (this->s_Number == T.s_Number)return 1;
		return 0;
	}
	bool operator> (const SimpleType &T)
	{
		if (this->s_Number > T.s_Number)return 1;
		return 0;
	}
	bool operator< (const SimpleType &T)
	{
		if (this->s_Number < T.s_Number)return 1;
		return 0;
	}

	bool operator!=(const SimpleType &T)
	{
		if (this->s_Number != T.s_Number)return 1;
		return 0;
	}

protected:
	int s_Number;  //  ���ȣ
	string s_Title;	// ���
	int m_Id;		// ���� ID
	string m_sName;	// ��������
	string m_sAddress; //???
	
	
};


#endif	// _SIMPLETYPE_H
