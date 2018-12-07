#pragma once
#include<iostream>
using namespace std;
/**
*	node for Binary Search Tree.
*/
template <typename T>
struct BinaryTreeNode
{
	T data;	// ����� ������
	BinaryTreeNode* left;	// ����� ���� ����
	BinaryTreeNode* right;	// ����� ������ ����
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
	BinaryTreeNode<T>* root;	// Ʈ���� ��Ʈ
	BinaryTreeNode<T*>* iroot;	// �̰� ������ Ʈ���� ��Ʈ
	bool isReset;	// ������ Ʈ���� ����
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
template <typename T>//���� ������ - ���� ������ ��ü�� ���ڷ� �����ϴ� ������ �Ѵ�. ��������(Shallow copy)�� �������� �������ֱ� ����.
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	root = NULL;
	iroot = NULL;
	isReset = false;
	Copy(root, other.root); //������ ������ �ϴ� �Լ�.
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
	}	//���̻� �Ҵ��� ���� ���� �� true ����
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
	//�ƹ��͵� �������� ������
	if (iroot == NULL)
		return NULL;

	//ResetList(); ���İ� �ƴҶ�
	if (!isReset)
	{
		//left child�� �������� ������
		if (iroot->left == NULL)
		{
			BinaryTreeNode<T*>* temp = iroot;
			iroot = iroot->right;
			delete temp;
		}
		//right child�� �������� ������
		else if (iroot->right == NULL)
		{
			BinaryTreeNode<T*>* temp = iroot;
			iroot = iroot->left;
			delete temp;
		}
		//�� �� �����Ҷ�
		else
		{
			BinaryTreeNode<T*>* pLeft = iroot->left;
			BinaryTreeNode<T*>* prev = NULL;
			//left child���� ���� ū �� ã��
			while (pLeft->right != NULL)
			{
				prev = pLeft;
				pLeft = pLeft->right;
			}
			//���� ū child�� ���� iroot�� ����
			iroot->data = pLeft->data;
			//���� ū child�� child�� ������ ������
			if (pLeft->left != NULL)
			{
				//���� ū child�� iroot�� left child�϶�
				if (prev == NULL)
				{
					iroot->left = iroot->left->left;
					delete pLeft;
				}
				//���� ū child�� iroot�� left child�� �ƴҶ�
				else
				{
					prev->right = pLeft->left;
					delete pLeft;
				}
			}
			//���� ū child�� leaf node�϶�
			else
			{
				//���� ū child�� iroot�� left child�϶�
				if (prev == NULL)
					iroot->left = NULL;
				//���� ū child�� iroot�� left child�� �ƴҶ�
				else
					prev->right = NULL;
				delete pLeft;
			}
		}
	}
	//���̻� ResetList()�� ���İ� �ƴϴ�.
	isReset = false;
	//pointer tree�� �������
	if (iroot == NULL)
		return NULL;
	//item�� data ����
	item = *iroot->data;
	//data �ּҰ� return
	return iroot->data;
}

//////////////////////���� �Լ�

//copy a node.
template <typename T>
void Copy(BinaryTreeNode<T>*& root, const BinaryTreeNode<T>* origin)
{
	//������ ������
	if (origin == NULL)
		return;
	//root�� node�� ������
	if (root == NULL)
	{
		BinaryTreeNode<T>* newnode = new BinaryTreeNode<T>;
		newnode->data = origin->data;
		newnode->left = newnode->right = NULL;
		root = newnode;
	}
	//origin�� left child�� ������ ������
	if (origin->left != NULL)
	{
		Copy(root->left, origin->left);
	}
	//origin�� right child�� ������ ������
	if (origin->right != NULL)
	{
		Copy(root->right, origin->right);
	}
}

//make pointer tree for GetNextItem() //�����ڷ� 45������ ����
template <typename T>
void makeIterTree(BinaryTreeNode<T*>*& iroot, BinaryTreeNode<T>* origin)
{
	////������ ������
	if (origin == NULL)
		return;
	//root�� node�� ������
	if (iroot == NULL)
	{
		BinaryTreeNode<T*>* newnode = new BinaryTreeNode<T*>;
		newnode->data = &origin->data;
		newnode->left = newnode->right = NULL;
		iroot = newnode;
	}
	////origin�� left child�� ������ ������
	if (origin->left != NULL)
	{
		makeIterTree(iroot->left, origin->left);
	}
	////origin�� right child�� ������ ������
	if (origin->right != NULL)
	{
		makeIterTree(iroot->right, origin->right);
	}
}

//Initialize tree to empty state.
template <typename T>
void MakeEmptyTree(BinaryTreeNode<T>*& root)
{
	if (root->left != NULL)	//left�� node�� ������ ��
		DeleteNode(root->left);
	if (root->right != NULL)	//right�� node�� ������ ��
		DeleteNode(root->right);
	DeleteNode(root);	//node ����
}

//Get number of elements in the tree.
template <typename T>
int CountNodes(BinaryTreeNode<T>* root)
{
	if (root == NULL)	//root�� ����Ű�� ���� ������
		return 0;
	if (root->left == NULL && root->right == NULL)	//left�� right ��� ����Ű�� ���� ������
		return 1;
	else if (root->left != NULL && root->right != NULL)	//�¿��� ������ ��� ���ϰ� 1�� ���Ѵ�.
		return CountNodes(root->left) + CountNodes(root->right) + 1;
	else if (root->left != NULL)	//left�� ����Ű�� ���� ������
		return CountNodes(root->left) + 1;
	else if (root->right != NULL)	//right�� ����Ű�� ���� ������
		return CountNodes(root->right) + 1;
	else
		return 0;
}

//Add item into appropriate spot of this tree.
template <typename T>
void Insert(BinaryTreeNode<T>*& root, T item)
{
	if (root == NULL)	//root�� ����Ű�� node�� �������� ���� ��
	{
		BinaryTreeNode<T>* newnode;
		newnode = new BinaryTreeNode<T>;
		newnode->data = item;
		newnode->left = newnode->right = NULL;
		root = newnode;
	}	//���ο� ��带 �Ҵ��� root�� ����
	else if (root->data > item)	//�������� ���� root�� ������ ������
		Insert(root->left, item); //���ʿ��ٰ� ����
	else if (root->data < item)	//�������� ���� root�� ������ Ŭ��
		Insert(root->right, item); //�����ʿ��ٰ� ����
}

//Delete item from this tree.
template <typename T>
void DeleteItem(BinaryTreeNode<T>*& root, T item)
{
	if (root == NULL)	//root�� node�� ������
	{
	}
	else if (root->data > item)	//������� ���� root�� ������ ������
		DeleteItem(root->left, item);  //���� �� ����
	else if (root->data < item)	//������� ���� root�� ������ Ŭ��
		DeleteItem(root->right, item); //������ �� ����
	else	//ã������ node�� �����.
		DeleteNode(root);
}

//Delete node from this tree.
template <typename T>
void DeleteNode(BinaryTreeNode<T>*& root)
{
	if (root->left == NULL)	//left�� ����Ű�� node�� ������ root�� root�� right�� �����Ѵ�. ������� node�� �޸𸮸� �����Ѵ�.
	{
		BinaryTreeNode<T>* temp = root;
		root = root->right;
		delete temp;
	}
	else if (root->right == NULL)	//right�� ����Ű�� node�� ������ root�� root�� left�� �����Ѵ�. ������� node�� �޸𸮸� �����Ѵ�.
	{
		BinaryTreeNode<T>* temp = root;
		root = root->left;
		delete temp;
	}
	else	//������� node�� left�� right ��� ������ �ִ� ��� node�� left���� ���� ū ���� ã�� ��ü���ش�.
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
	while (root->right != NULL)	//right�� ���ܱ��� �����Ѵ�.
		root = root->right;
	item = root->data;	//item�� ���� �������ش�.
}

//Retrieve tree element whose key matches item's key (if present).
template <typename T>
void RetrieveItem(BinaryTreeNode<T>* root, T& item, bool& found)
{
	if (root == NULL)	//root�� ����Ű�� node�� ������
		return;
	if (root->data == item)	//���ϴ� ���� ã������
	{
		item = root->data;
		found = true;
	}
	else if (root->data > item)	//ã������ ���� root�� data���� ������
		RetrieveItem(root->left, item, found);
	else if (root->data < item)	//ã������ ���� root�� data���� Ŭ��
		RetrieveItem(root->right, item, found);
}

////Replace tree element whose key matches item's key (if present).
template <typename T>
void ReplaceItem(BinaryTreeNode<T>* root, T& item, bool& found)
{
	if (root == NULL)	//root�� ����Ű�� node�� ������
		return;
	if (root->data == item)	//���ϴ� ���� ã������
	{
		root->data = item;
		found = true;
	}
	else if (root->data > item)	//ã������ ���� root�� data���� ������
		ReplaceItem(root->left, item, found);
	else if (root->data < item)	//ã������ ���� root�� data���� Ŭ��
		ReplaceItem(root->right, item, found);
}

//Print this tree in-order.
template <typename T>  //sin
void PrintInOrderTraversal(BinaryTreeNode<T>* root, ostream& out)
{
	if (root->left != NULL)	//left�� ���� ���
		PrintInOrderTraversal(root->left, out);

	out << root->data << ' ';	//�ڽ��� ���

	if (root->right != NULL)	//right�� ���߿� ���
		PrintInOrderTraversal(root->right, out);
}

//Print this tree pre-order.
template <typename T>  //cos
void PrintPreOrderTraversal(BinaryTreeNode<T>* root, ostream& out)
{
	out << root->data << ' ';	//�ڽ��� ���� ���

	if (root->left != NULL)	//left�� �� ������ ���
		PrintInOrderTraversal(root->left, out);

	if (root->right != NULL)	//right�� �������� ���
		PrintInOrderTraversal(root->right, out);
}

//Print this tree post-order.
template <typename T>  //tan
void PrintPostOrderTraversal(BinaryTreeNode<T>* root, ostream& out)
{
	if (root->left != NULL)	//left�� ���� ���
		PrintInOrderTraversal(root->left, out);

	if (root->right != NULL)	//right�� �� ������ ���
		PrintInOrderTraversal(root->right, out);

	out << root->data << ' ';	//�ڽ��� �������� ���
}
