#pragma once
#include<iostream>
using namespace std;
/**
*	node for Binary Search Tree.
*/
template <typename T>
struct BinaryTreeNode
{
	T data;	// 노드의 데이터
	BinaryTreeNode* left;	// 노드의 왼쪽 원소
	BinaryTreeNode* right;	// 노드의 오른쪽 원소
};

/**
*	Binary Search Tree class for item management.
*/
template <typename T>
class BinarySearchTree
{
public:
	/**
	*	default constructor.
	*/
	BinarySearchTree(void);

	/**
	*	@brief	Copy constructor.
	*	@pre	None
	*	@post	Tree is deep copied.
	*	@param	other	Original tree to copy.
	*/
	BinarySearchTree(const BinarySearchTree<T>& other);

	/**
	*	destructor.
	*/
	~BinarySearchTree(void);

	/**
	*	@brief	Check if the tree is empty.
	*	@pre	None
	*	@post	None
	*	@return	1 if tree is empty, otherwise 0.
	*/
	bool IsEmpty() const;

	/**
	*	@brief	Check if allocation is possible.
	*	@pre	None
	*	@post	None
	*	@return	1 if allocation is possible, otherwise 0.
	*/
	bool IsFull() const;

	/**
	*	@brief	Initialize tree to empty state.
	*	@pre	None
	*	@post	Tree is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the tree.
	*	@pre	None.
	*	@post	Function value = number of elements in tree.
	*	@return	Number of elements in this tree.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into appropriate spot of this tree.
	*	@pre	Tree is not full. item is not in the tree.
	*	@post	Item is inserted into this tree.
	*/
	void Add(T item);

	/**
	*	@brief	Delete item from this tree.
	*	@pre	Tree is not empty. the item exists in tree.
	*	@post	Item is deleted from this tree.
	*/
	void Delete(T item);

	/**
	*	@brief	Retrieve tree element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@param	item	Item to find. Key member is initialized.
	*	@param	found	Represents if the item is found.
	*/
	void Retrieve(T& item, bool& found) const;

	/**
	*	@brief	Replace tree element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the item's record is copied to the element.
	*	@param	item	Item to replace.
	*	@param	found	Represents if the item is found.
	*/
	void Replace(T& item, bool& found);

	/**
	*	@brief	Print all elements of the tree.
	*	@pre	None
	*	@post	Every elements of the tree is printed.
	*/
	void PrintTree(ostream& out) const;

	/**
	*	@brief	Initialize pointer tree for GetNextItem() function.
	*	@pre	None
	*	@post	Pointer tree is made.
	*/
	void ResetList();

	/**
	*	@brief	Get a element from the tree.
	*	@pre	Tree should be reset.
	*	@post	Root of pointer tree is popped.
	*	@param	item	Get data of root of pointer tree. It does not need to be initialized.
	*	@return	Address of target element.
	*/
	T* GetNextItem(T& item);
private:
	BinaryTreeNode<T>* root;	// 트리의 루트
	BinaryTreeNode<T*>* iroot;	// 이건 포인터 트리의 루트
	bool isReset;	// 포인터 트리의 상태
};

//default constructor.
template <typename T>
BinarySearchTree<T>::BinarySearchTree(void)
{
	root = NULL;
	iroot = NULL;
	isReset = false;
}

//Copy constructor.
template <typename T>//복사 생성자 - 같은 형태의 객체를 인자로 전달하는 역할을 한다. 얕은복사(Shallow copy)의 문제점을 방지해주기 위함.
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	root = NULL;
	iroot = NULL;
	isReset = false;
	Copy(root, other.root); //복사의 역할을 하는 함수.
}

//destructor.
template <typename T>
BinarySearchTree<T>::~BinarySearchTree(void)
{
	MakeEmpty();
}

//Check if the tree is empty.
template <typename T>
bool BinarySearchTree<T>::IsEmpty() const
{
	if (root == NULL)
		return 1;
	else
		return 0;
}

//Check if allocation is possible.
template <typename T>
bool BinarySearchTree<T>::IsFull() const
{
	BinaryTreeNode<T>* location;
	try
	{
		location = new BinaryTreeNode<T>;
		delete location;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}	//더이상 할당이 되지 않을 때 true 리턴
}

//Initialize tree to empty state.
template <typename T>
void BinarySearchTree<T>::MakeEmpty()
{
	MakeEmptyTree(root);
}

//Get number of elements in the tree.
template <typename T>
int BinarySearchTree<T>::GetLength() const
{
	return CountNodes(root);
}

//Add item into appropriate spot of this tree.
template <typename T>
void BinarySearchTree<T>::Add(T item)
{
	if (IsFull())
		return;
	Insert(root, item);
}

//Delete item from this tree.
template <typename T>
void BinarySearchTree<T>::Delete(T item)
{
	if (IsEmpty())
		return;
	DeleteItem(root, item);
}

//Retrieve tree element whose key matches item's key (if present).
template <typename T>
void BinarySearchTree<T>::Retrieve(T& item, bool& found) const
{
	RetrieveItem(root, item, found);
}

//Replace tree element whose key matches item's key (if present).
template <typename T>
void BinarySearchTree<T>::Replace(T& item, bool& found)
{
	ReplaceItem(root, item, found);
}

//Print all elements of the tree.
template <typename T>
void BinarySearchTree<T>::PrintTree(ostream& out) const
{
	out << "Inorder : " << endl;
	PrintInOrderTraversal(root, out);
	out << endl << "Preorder : " << endl;
	PrintPreOrderTraversal(root, out);
	out << endl << "Postorder : " << endl;
	PrintPostOrderTraversal(root, out);
	out << endl;
}

//Initialize pointer tree for GetNextItem() function.
template <typename T>
void BinarySearchTree<T>::ResetList()
{
	makeIterTree(iroot, root);
	isReset = true;
}

//Get a element from the tree.
template <typename T>
T* BinarySearchTree<T>::GetNextItem(T& item)
{
	//아무것도 존재하지 않을때
	if (iroot == NULL)
		return NULL;

	//ResetList(); 직후가 아닐때
	if (!isReset)
	{
		//left child가 존재하지 않을때
		if (iroot->left == NULL)
		{
			BinaryTreeNode<T*>* temp = iroot;
			iroot = iroot->right;
			delete temp;
		}
		//right child가 존재하지 않을때
		else if (iroot->right == NULL)
		{
			BinaryTreeNode<T*>* temp = iroot;
			iroot = iroot->left;
			delete temp;
		}
		//둘 다 존재할때
		else
		{
			BinaryTreeNode<T*>* pLeft = iroot->left;
			BinaryTreeNode<T*>* prev = NULL;
			//left child에서 가장 큰 값 찾기
			while (pLeft->right != NULL)
			{
				prev = pLeft;
				pLeft = pLeft->right;
			}
			//가장 큰 child의 값을 iroot에 복사
			iroot->data = pLeft->data;
			//가장 큰 child가 child를 가지고 있을때
			if (pLeft->left != NULL)
			{
				//가장 큰 child가 iroot의 left child일때
				if (prev == NULL)
				{
					iroot->left = iroot->left->left;
					delete pLeft;
				}
				//가장 큰 child가 iroot의 left child가 아닐때
				else
				{
					prev->right = pLeft->left;
					delete pLeft;
				}
			}
			//가장 큰 child가 leaf node일때
			else
			{
				//가장 큰 child가 iroot의 left child일때
				if (prev == NULL)
					iroot->left = NULL;
				//가장 큰 child가 iroot의 left child가 아닐때
				else
					prev->right = NULL;
				delete pLeft;
			}
		}
	}
	//더이상 ResetList()의 직후가 아니다.
	isReset = false;
	//pointer tree가 비었을때
	if (iroot == NULL)
		return NULL;
	//item에 data 복사
	item = *iroot->data;
	//data 주소값 return
	return iroot->data;
}

//////////////////////전역 함수

//copy a node.
template <typename T>
void Copy(BinaryTreeNode<T>*& root, const BinaryTreeNode<T>* origin)
{
	//원본이 없을때
	if (origin == NULL)
		return;
	//root에 node가 없을때
	if (root == NULL)
	{
		BinaryTreeNode<T>* newnode = new BinaryTreeNode<T>;
		newnode->data = origin->data;
		newnode->left = newnode->right = NULL;
		root = newnode;
	}
	//origin이 left child를 가지고 있을때
	if (origin->left != NULL)
	{
		Copy(root->left, origin->left);
	}
	//origin이 right child를 가지고 있을때
	if (origin->right != NULL)
	{
		Copy(root->right, origin->right);
	}
}

//make pointer tree for GetNextItem() //강의자료 45페이지 참조
template <typename T>
void makeIterTree(BinaryTreeNode<T*>*& iroot, BinaryTreeNode<T>* origin)
{
	////원본이 없을때
	if (origin == NULL)
		return;
	//root에 node가 없을때
	if (iroot == NULL)
	{
		BinaryTreeNode<T*>* newnode = new BinaryTreeNode<T*>;
		newnode->data = &origin->data;
		newnode->left = newnode->right = NULL;
		iroot = newnode;
	}
	////origin이 left child를 가지고 있을때
	if (origin->left != NULL)
	{
		makeIterTree(iroot->left, origin->left);
	}
	////origin이 right child를 가지고 있을때
	if (origin->right != NULL)
	{
		makeIterTree(iroot->right, origin->right);
	}
}

//Initialize tree to empty state.
template <typename T>
void MakeEmptyTree(BinaryTreeNode<T>*& root)
{
	if (root->left != NULL)	//left에 node가 존재할 때
		DeleteNode(root->left);
	if (root->right != NULL)	//right에 node가 존재할 때
		DeleteNode(root->right);
	DeleteNode(root);	//node 제거
}

//Get number of elements in the tree.
template <typename T>
int CountNodes(BinaryTreeNode<T>* root)
{
	if (root == NULL)	//root이 가리키는 값이 없을때
		return 0;
	if (root->left == NULL && root->right == NULL)	//left와 right 모두 가리키는 값이 없을때
		return 1;
	else if (root->left != NULL && root->right != NULL)	//좌우의 개수를 모두 더하고 1을 더한다.
		return CountNodes(root->left) + CountNodes(root->right) + 1;
	else if (root->left != NULL)	//left가 가리키는 값이 있을때
		return CountNodes(root->left) + 1;
	else if (root->right != NULL)	//right가 가리키는 값이 있을때
		return CountNodes(root->right) + 1;
	else
		return 0;
}

//Add item into appropriate spot of this tree.
template <typename T>
void Insert(BinaryTreeNode<T>*& root, T item)
{
	if (root == NULL)	//root이 가리키는 node가 존재하지 않을 때
	{
		BinaryTreeNode<T>* newnode;
		newnode = new BinaryTreeNode<T>;
		newnode->data = item;
		newnode->left = newnode->right = NULL;
		root = newnode;
	}	//새로운 노드를 할당해 root에 연결
	else if (root->data > item)	//넣으려는 값이 root의 값보다 작을때
		Insert(root->left, item); //왼쪽에다가 삽입
	else if (root->data < item)	//넣으려는 값이 root의 값보다 클때
		Insert(root->right, item); //오른쪽에다가 삽입
}

//Delete item from this tree.
template <typename T>
void DeleteItem(BinaryTreeNode<T>*& root, T item)
{
	if (root == NULL)	//root에 node가 없을때
	{
	}
	else if (root->data > item)	//지우려는 값이 root의 값보다 작을때
		DeleteItem(root->left, item);  //왼쪽 값 삭제
	else if (root->data < item)	//지우려는 값이 root의 값보다 클때
		DeleteItem(root->right, item); //오른쪽 값 삭제
	else	//찾았을때 node를 지운다.
		DeleteNode(root);
}

//Delete node from this tree.
template <typename T>
void DeleteNode(BinaryTreeNode<T>*& root)
{
	if (root->left == NULL)	//left가 가리키는 node가 없으면 root에 root의 right를 연결한다. 지우려는 node의 메모리를 해제한다.
	{
		BinaryTreeNode<T>* temp = root;
		root = root->right;
		delete temp;
	}
	else if (root->right == NULL)	//right가 가리키는 node가 없으면 root에 root의 left를 연결한다. 지우려는 node의 메모리를 해제한다.
	{
		BinaryTreeNode<T>* temp = root;
		root = root->left;
		delete temp;
	}
	else	//지우려는 node가 left와 right 모두 가지고 있는 경우 node의 left에서 가장 큰 값을 찾아 대체해준다.
	{
		T temp;
		GetPredecessor(root->left, temp);
		root->data = temp;
		DeleteItem(root->left, temp);
	}
}

//Retrieve the biggest element of current node's left.
template <typename T>
void GetPredecessor(BinaryTreeNode<T>* root, T& item)
{
	while (root->right != NULL)	//right의 말단까지 도달한다.
		root = root->right;
	item = root->data;	//item에 값을 복사해준다.
}

//Retrieve tree element whose key matches item's key (if present).
template <typename T>
void RetrieveItem(BinaryTreeNode<T>* root, T& item, bool& found)
{
	if (root == NULL)	//root이 가리키는 node가 없을때
		return;
	if (root->data == item)	//원하는 값을 찾았을때
	{
		item = root->data;
		found = true;
	}
	else if (root->data > item)	//찾으려는 값이 root의 data보다 작을때
		RetrieveItem(root->left, item, found);
	else if (root->data < item)	//찾으려는 값이 root의 data보다 클때
		RetrieveItem(root->right, item, found);
}

////Replace tree element whose key matches item's key (if present).
template <typename T>
void ReplaceItem(BinaryTreeNode<T>* root, T& item, bool& found)
{
	if (root == NULL)	//root이 가리키는 node가 없을때
		return;
	if (root->data == item)	//원하는 값을 찾았을때
	{
		root->data = item;
		found = true;
	}
	else if (root->data > item)	//찾으려는 값이 root의 data보다 작을때
		ReplaceItem(root->left, item, found);
	else if (root->data < item)	//찾으려는 값이 root의 data보다 클때
		ReplaceItem(root->right, item, found);
}

//Print this tree in-order.
template <typename T>  //sin
void PrintInOrderTraversal(BinaryTreeNode<T>* root, ostream& out)
{
	if (root->left != NULL)	//left를 먼저 출력
		PrintInOrderTraversal(root->left, out);

	out << root->data << ' ';	//자신을 출력

	if (root->right != NULL)	//right를 나중에 출력
		PrintInOrderTraversal(root->right, out);
}

//Print this tree pre-order.
template <typename T>  //cos
void PrintPreOrderTraversal(BinaryTreeNode<T>* root, ostream& out)
{
	out << root->data << ' ';	//자신을 먼저 출력

	if (root->left != NULL)	//left를 그 다음에 출력
		PrintInOrderTraversal(root->left, out);

	if (root->right != NULL)	//right를 마지막에 출력
		PrintInOrderTraversal(root->right, out);
}

//Print this tree post-order.
template <typename T>  //tan
void PrintPostOrderTraversal(BinaryTreeNode<T>* root, ostream& out)
{
	if (root->left != NULL)	//left를 먼저 출력
		PrintInOrderTraversal(root->left, out);

	if (root->right != NULL)	//right를 그 다음에 출력
		PrintInOrderTraversal(root->right, out);

	out << root->data << ' ';	//자신을 마지막에 출력
}
