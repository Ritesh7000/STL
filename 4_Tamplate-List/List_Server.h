#include<iostream>

using std::cout;
using std::endl;
using std::cin;
using std::ostream;

class CList;

class CNode
{
	int iData;
	CNode *pNext;
	CNode *pPrev;

public:
	CNode();
	~CNode();

	friend class CList;
};

class CList
{
	CNode * pFirst;
	CNode * pLast;

public:
	CList();
	~CList();

	void InsertFirst(int);
	void InsertLast(int);
	void InsertAtPosition(int,int);
	int DeleteFirst();
	int DeleteLast();
	int DeleteAtPosition(int);
	int SearchFirstOccurence(int);
	int SearchLastOccurence(int);
	int SearchAllOccurence(int);
	void ReverseDisplay();
	void PhysicalReverse();
	void ConcatList(class CList);
	void ConcatAtPosition(class CList &,int);
	int CountNode();
	void DeleteAll();
	void Display();
	int Empty();

	class Iterator
	{
		CNode *pCurrent;

	public:
		Iterator();
		~Iterator();

		void SetCurrentNode(CNode *);

		Iterator& operator ++( );
		Iterator operator ++(int);
		Iterator& operator --( );
		Iterator operator --(int);

    	bool operator ==(Iterator &);
    	bool operator !=(Iterator &);
    	bool operator <(Iterator &);
    	bool operator >(Iterator &);
    	bool operator <=(Iterator &);
    	bool operator >=(Iterator &);

    	int operator *();
	};

	Iterator& begin();
	Iterator& end();


private:
	Iterator EndIter;
	Iterator StartIter;
};
  


