#pragma once
#include<Windows.h>
template <class T> class DoublySortedLinkedList; //명시적 선언
template <class T> struct DoublyNodeType; // 이 또한 명시적선언



/**
*  @brief DoublyIterator class
*/
template <class T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>; //Freind declaration for access private variables.
public:
	/**
	*  @brief  User define iterator
	*  @post   Make list and m_pCurpointer first address.
	*/
	DoublyIterator(const DoublySortedLinkedList<T>& list) : m_List(&list), m_pCurpointer(list.m_pFirst) {};

	/*
	*  @brief  Normal destructor
	*/
	~DoublyIterator();

	/**
	*  @brief  Funct that check whether what current pointer pointing is Null.
	   @return If the pointing node is null, return ture. And if it is correct, also return true.
	*/
	bool NotNull();
	/**
	*  @brief  Funct that checks whether current pointer is null.
	*  @return If it is null, then return true. Otherwise, false.
	*/
	bool IsNull() { return m_pCurpointer == NULL; }

	/**/
	bool NextNotNull();

	/**/
	T First();

	/**/
	T Next();

	/**/
	DoublyNodeType<T>GetCurrentNode();

	/**/
	T& operator*();

	/**/
	DoublyIterator<T>& operator++();

	/**/
	DoublyIterator<T> operator++(int);

	/**/
	DoublyIterator<T>& operator--();

	/**/
	DoublyIterator<T>operator--(int);

	/**/
	bool operator==(DoublyIterator<T>& itor);

	/**/
	DoublyIterator<T>& operator=(DoublySortedLinkedList<T>& list);

private:
	/**/
	const DoublySortedLinkedList<T>* m_List;
	/**/
	DoublyNodeType<T> *m_pCurpointer;

};

//Normal destructor

template<class T>
DoublyIterator<T>::~DoublyIterator()
{

}

/**/
template<class T>
bool DoublyIterator<T>::NotNull()
{
	return m_pCurpointer != NULL;
}

/**/
template<class T>
bool DoublyIterator<T>::NextNotNull()
{
	return m_pCurpointer->next != NULL;
}

/**/
template<class T>
T DoublyIterator<T>::First()
{
	return m_List.m_pFirst->data;
}

/**/
template<class T>
T DoublyIterator<T>::Next()
{
	m_pCurpointer = m_pCurpointer->next;
	if (m_pCurpointer == NULL)
		return T();
	return m_pCurpointer->data;
}

/**/
template<class T>
DoublyNodeType<T>DoublyIterator<T>::GetCurrentNode()
{
	return *m_pCurpointer;
}

/**/
template<class T>
inline T & DoublyIterator<T>::operator*()
{
	return m_pCurpointer->data;
}

template<class T>
inline DoublyIterator<T>& DoublyIterator<T>::operator++()
{
	m_pCurpointer = m_pCurpointer->next;
	return *this;
}

template<class T>
inline DoublyIterator<T>DoublyIterator<T>::operator++(int)
{
	DoublyIterator<T>temporaryItem = *this;
	m_pCurpointer = m_pCurpointer->next;
	return temporaryItem;
}

template<class T>
inline DoublyIterator<T>& DoublyIterator<T>::operator--()
{
	m_pCurpointer = m_pCurpointer->prev;
	return *this;
}

template<class T>
inline DoublyIterator<T>DoublyIterator<T>::operator--(int)
{
	DoublyIterator<T>temporaryItem = *this;
	m_pCurpointer = m_pCurpointer->prev;
	return temporaryItem;
}

template<class T>
inline bool DoublyIterator<T>::operator==(DoublyIterator<T>& itor)
{
	return itor.m_pCurpointer == m_pCurpointer;
}

template<class T>
inline DoublyIterator<T>& DoublyIterator<T>::operator=(DoublySortedLinkedList<T>& list)
{
	m_pCurpointer = list.m_pFirst;
	m_List = &list;
	return *this;
}
