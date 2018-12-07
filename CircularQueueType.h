
#include <iostream>
using namespace std;

#define maxsize 31

/**
*   @brief   Exception class thrown by Push when stack is full.
*/
class FullStack
{
public:
	/**
	*   @brief   Display a message for full stack on screen.
	*/
	void print()
	{
		cout << "FullStack exception thrown." << endl;
	}
};

/**
*   @brief   Exception class thrown by Pop and Top when stack is empty.
*/
class EmptyStack
{
public:
	/**
	*   @brief   Display a message for full stack on screen.
	*/
	void print()
	{
		cout << "EmtpyStack exception thrown." << endl;
	}
};

template <typename T>   //generic data�� ���� template ����
class CircularQueueType
{
public:
	/**
	*   @brief   size�� �ش��ϴ� ũ���� �迭�� �����Ҵ�
	*   @post   size�� ���� �ش�Ǵ� ũ���� �迭�� �������,�� ����������� �ʱ�ȭ��
	*/
	CircularQueueType(int size);
	/**
	*   @brief   �ִ�ũ��� ����
	*   @pre   �ִ�ũ�Ⱑ ����������
	*   @post   �ִ�ũ���� �迭�� ���������, �� ����������� �ʱ�ȭ��
	*/
	CircularQueueType(void);

	~CircularQueueType(void);


	/**
	*   @brief   queue�� �������ִ��� Ȯ��.
	*   @pre   queue�� �ʱ�ȭ �Ǿ����.
	*   @post   �������� ture �ƴϸ� false
	*/
	bool IsFull() const;

	/**
	*   @brief   queue�� ����ִ��� Ȯ��
	*   @pre   queue�� �ʱ�ȭ �Ǿ����.
	*   @post   ��������� ture �ƴϸ� false
	*/
	bool IsEmpty() const;

	/**
	*   @brief   queue�� ȸ���ϸ鼭 ���� ä��.
	*   @pre   queue�� �ʱ�ȭ �Ǿ����
	*   @post   ������������ FullStack Exception�� throw��, �ƴϸ� ���ο� ���� �߰���,rear�� ����
	*/
	int EnQueue(T item);

	/**
	*   @brief   queue�� ȸ���ϸ鼭 ���� ����(=front���� �ϳ� ����)
	*   @pre   Stack has been initialized.
	*   @post   ��������� empty Exception�� throw;�ƴϸ� ������ ���� ����
	*/
	void DeQueue(T& item);

	/**
	*   @brief   Returns a copy of top item on the stack.
	*   @pre   Stack has been initialized.
	*   @post   If (stack is empty), EmptyStack exception is thrown; otherwise, top element has been removed from stack.
	*/
	T Top();

	/**
	*   @brief   Front�� rear�� ���� ������ isEmpty���� �ֺ������ �����
	*   @pre   Front�� rear�� ���� �����ؾ� �ϰ� ���ƾ� ��.
	*   @post   None.
	*   @return   top=0
	*/
	void MakeEmpty();

	/**
	*   @brief   Get music number
	*   @pre   music number is set.
	*   @post   none.
	*   @return   music number.
	*/
	int GetNumber()
	{
		return r_Number;
	}

	/**
	*   @brief   Get music title
	*   @pre   music title is set.
	*   @post   none.
	*   @return   music title.
	*/
	string GetTitle()
	{
		return r_sTitle;
	}

	/**
	*   @brief   Set music Number.
	*   @pre   none.
	*   @post   music number is set.
	*   @param   inTitle   music number.
	*/
	void SetNumber(int inNumber)
	{
		r_Number = inNumber;
	}


	/**
	*   @brief   Set music Title.
	*   @pre   none.
	*   @post   music Title is set.
	*   @param   inTitle   music Title.
	*/
	void SetTitle(string inTitle)
	{
		r_sTitle = inTitle;
	}

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	Iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& data);


	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetQueue();

	/**
	*	@brief top �ޱ�.
	*	@pre	Top is set.
	*	@post	none.
	*	@return	Top.
	*/
	int GetTop();

private:
	int m_iFront;
	int m_iRear;
	int m_nMaxQueue;
	int top;   ///< Number of elements.
	T *items;   ///< Pointer for a stack.
	int r_CurPointer;

};

template <typename T>
CircularQueueType<T>::CircularQueueType(int size)
{
	items = new T[size];   //T�� �ڷ������� �����Ҵ�
	m_iFront = size - 1;
	m_iRear = size - 1;
	m_nMaxQueue = size;
	top = 0;
}
template <typename T>
CircularQueueType<T>::CircularQueueType()
{
	items = new T[maxsize];
	m_iFront = maxsize - 1;
	m_iRear = maxsize - 1;
	m_nMaxQueue = maxsize;
	top = 0;
}


// Destruct the object. Free the array dynamically allocated.
template <typename T>
CircularQueueType<T>::~CircularQueueType()
{
	delete[] items;
}


// Determines whether the CircularQueueType is full.
template <typename T>
bool CircularQueueType<T>::IsEmpty() const
{
	if (m_iRear == m_iFront)
		return true;
	else
		return false;
}


// Determines whether the CircularQueueType is empty.
template <typename T>
bool CircularQueueType<T>::IsFull() const
{
	if ((m_iRear + 1) % m_nMaxQueue == m_iFront)   //rear�� ����ĭ�� front���� �ƴ��� �˻�
		return true;
	else
		return false;
}

// Adds newItem to the top of the CircularQueueType.
template <typename T>
int CircularQueueType<T>::EnQueue(T newItem)
{
	if (IsFull())
	{
		m_iFront = (m_iFront + 1) % m_nMaxQueue;
		top--;
	}
	m_iRear = (m_iRear + 1) % m_nMaxQueue;
	items[m_iRear%m_nMaxQueue] = newItem;
	top++;
	return 1;
}


// Removes top item from the CircularQueueType.
template <typename T>
void CircularQueueType<T>::DeQueue(T& item)
{
	top--;
	if (IsEmpty())         //����ִ��� �˻�
		throw EmptyStack();
	else
	{
		m_iFront = (m_iFront + 1) % m_nMaxQueue; //front�� ������ ��ĭ �̵�
		item = items[m_iFront];   //��������, ���ٵ��� ���� ���� �˱����ؼ� item�� �ش� ���� ����
	}
}


// Removes top item from the CircularQueueType.
template <typename T>
T CircularQueueType<T>::Top()
{
	if (IsEmpty())
		throw EmptyStack();
	else
		return items[top];
}

template <typename T>
int CircularQueueType<T>::GetTop()
{
	return top;
}


template <typename T>
void CircularQueueType<T>::MakeEmpty()
{
	m_iFront = m_iRear; //Front�� rear�� ���� ������ isEmpty���� �ֺ������ �����
	top = 0;//
}

// move list iterator to the next item in list and get that item.
template <typename T>
int CircularQueueType<T>::GetNextItem(T& data)
{
	r_CurPointer = (r_CurPointer + (m_nMaxQueue - 1)) % m_nMaxQueue;
	data = items[r_CurPointer];
	return r_CurPointer;
}

template <typename T>
void CircularQueueType<T>::ResetQueue()
{
	r_CurPointer = m_iRear + 1; // �ʱ�ȭ
}

