#include<iostream>

using std::cout;
using std::endl;
using std::cin;
using std::ostream;

template<typename T>
class CList;

template <typename T>
void MyMain(T );

template <typename T>
void DisplayIterator(CList<T> &);

template<typename T>
class CNode
{
	T iData;
	CNode *pNext;
	CNode *pPrev;

public:
	CNode();
	~CNode();

	friend class CList<T>;
};


template<typename T>
class CList
{
	CNode<T> * pDummy;

public:
	CList();
	~CList();

	void InsertFirst(T );
	void InsertLast(T );                                                                                                                                                                                                    
	void InsertAtPosition(T ,int);
	int DeleteFirst();
	int DeleteLast();
	int DeleteAtPosition(int);
	int SearchFirstOccurence(T);
	int SearchLastOccurence(T);
	int SearchAllOccurence(T);
	void PhysicalReverse();
	void ReverseDisplay();
	void ConcatList(class CList &);
	void ConcatAtPosition(class CList &, int);
	int CountNode();
	void DeleteAll();
	void Display();
	int Empty();

	class Iterator
	{
		CNode<T> *pCurrent;
      
	public:
		Iterator::Iterator();
		Iterator::~Iterator();
		void SetCurrentNode(CNode<T> *);
		Iterator& operator ++( );
		Iterator operator ++(int);
		Iterator& operator --( );
		Iterator operator --(int);
	    bool operator !=(Iterator&);
	    bool operator ==(Iterator&);
	    bool operator <(Iterator&);
	    bool operator >(Iterator&);
	    bool operator <=(Iterator&);
	    bool operator >=(Iterator&);
	    T operator *();
	};

	Iterator& CList::begin();
	Iterator& CList::end();

private:
	Iterator EndIter;
	Iterator StartIter;
};


// CNode che  def
	template<typename T>
	CNode<T>::CNode()
	{
		iData = NULL;
		pNext = NULL;
	}

	template<typename T>
	CNode<T>::~CNode()
	{
		iData = NULL;
		pNext = NULL;
	}


// CList::Iterator che def

		template<typename T>
		CList<T>::Iterator::Iterator()
		{
			pCurrent = NULL;
		}
		
		template<typename T>
		CList<T>::Iterator::~Iterator()
		{	
			pCurrent = NULL;
		}

		template<typename T>
		void CList<T>::Iterator::SetCurrentNode(CNode<T> *pPtr)
		{
			pCurrent = pPtr;
		}

		template<typename T>
		typename CList<T>::Iterator& CList<T>::Iterator::operator ++( )
		{
			pCurrent = pCurrent->pNext;
			return *this;
		}

		template<typename T>
		typename CList<T>::Iterator CList<T>::Iterator::operator ++(int)
		{
			Iterator temp = *this;
			pCurrent = pCurrent->pNext;
			return temp;
		}

		template<typename T>
		typename CList<T>::Iterator& CList<T>::Iterator::operator --( )
		{
			pCurrent = pCurrent->pPrev;
			return *this;
		}

		template<typename T>
		typename CList<T>::Iterator CList<T>::Iterator::operator --(int)
		{
			Iterator temp = *this;
			pCurrent = pCurrent->pPrev;
			return temp;
		}
	    
		template<typename T>
	    bool CList<T>::Iterator::operator !=(Iterator& refObj)
	    {
	    	return pCurrent != refObj.pCurrent;
	    }

		template<typename T>
	    bool CList<T>::Iterator::operator ==(Iterator& refObj)
	    {
	    	return pCurrent == refObj.pCurrent;
	    }

		template<typename T>
	    bool CList<T>::Iterator::operator <(Iterator& refObj)
	    {
	    	return pCurrent < refObj.pCurrent;
	    }

		template<typename T>
	    bool CList<T>::Iterator::operator >(Iterator& refObj)
	    {
	    	return pCurrent > refObj.pCurrent;
	    }

		template<typename T>
	    bool CList<T>::Iterator::operator <=(Iterator& refObj)
	    {
	    	return pCurrent <= refObj.pCurrent;
	    }

		template<typename T>
	    bool CList<T>::Iterator::operator >=(Iterator& refObj)
	    {
	    	return pCurrent >= refObj.pCurrent;
	    }

		template<typename T>
	    T CList<T>::Iterator::operator *()
	    {
	    	return pCurrent->iData;
	    }


//CList che def
	template<typename T>
	typename CList<T>::Iterator& CList<T>::begin()
	{
		StartIter.SetCurrentNode(pDummy->pNext);
		return StartIter;
	}

	template<typename T>
	typename CList<T>::Iterator& CList<T>::end()
	{ 
		EndIter.SetCurrentNode(pDummy);
		return EndIter;
	}

	template<typename T>
	CList<T>::CList()
	{
		pDummy = new CNode<T>;

		if(NULL == pDummy)
		{
			printf("Memory Allocation is Failed");
			return;
		}
		pDummy->pNext = pDummy->pPrev = pDummy;
	}

	template<typename T>
	CList<T>::~CList()
	{
		if(pDummy != pDummy->pNext)
		{
			DeleteAll();
		}

		pDummy->pNext = pDummy->pPrev = NULL;

		delete(pDummy);
		pDummy = NULL;
	}

	template<typename T>
	void CList<T>::InsertFirst(T iNo)
	{
		CNode<T> *pNewNode = NULL;

		pNewNode = new CNode<T>;

		if(pNewNode == NULL)
		{
			cout << "Memory Allocation is Failed.";
			return;
		}

		pNewNode->iData = iNo;

		pNewNode->pPrev = pDummy;
		pNewNode->pNext = pDummy->pNext;
		pDummy->pNext->pPrev = pNewNode;
		pDummy->pNext = pNewNode;  

		pNewNode = NULL;
	}

	template<typename T>
	void CList<T>::InsertLast(T iNo)
	{
		CNode<T> *pNewNode = NULL;
		
		pNewNode = new CNode<T>;
	
		if(pNewNode == NULL)
		{
			printf("Memory Allocation is Failed.");
			return;
		}

		pNewNode->iData = iNo;

		pNewNode->pNext = pDummy;
		pNewNode->pPrev = pDummy->pPrev;
		pDummy->pPrev->pNext = pNewNode;
		pDummy->pPrev = pNewNode;

		pNewNode = NULL;
	}

 	template<typename T>                                                                                                                                                                                                   
	void CList<T>::InsertAtPosition(T iNo,int iPos)
	{
		int iCount = 0;
		CNode<T> *pNewNode = NULL;
		CNode<T> *pTemp = NULL;

		iCount = CountNode();

		if(iPos <= 0 || iCount+1 < iPos)
		{
			printf("Position is Not Valid.");
			return;
		}

		if(iPos == 1)
		{
			InsertFirst(iNo);
		}
		else if(iPos == iCount+1)
		{
			InsertLast(iNo);
		}
		else
		{
			pNewNode = new CNode<T>;

			if(NULL == pNewNode)
			{
				printf("Memory Allocation is Failed.\n");
				return;
			}

			iCount = 1;
			pTemp = pDummy->pNext;


			while(iPos-1 != iCount)
			{
				iCount++;
				pTemp = pTemp->pNext;
			}

			pNewNode->iData = iNo;

			pNewNode->pPrev = pTemp;
			pNewNode->pNext = pTemp->pNext;
			pTemp->pNext->pPrev = pNewNode;
			pTemp->pNext = pNewNode;

			pTemp = pNewNode = NULL;
		}		
	}

	template<typename T>
	int CList<T>::DeleteFirst()
	{
		T iDelData;
		CNode<T> *pTemp = NULL;

		if(pDummy == pDummy->pPrev)
		{

			printf("Linked List is empty!\n");
			return -1;
		}

		pTemp = pDummy->pNext;

		iDelData = pTemp->iData;

		pDummy->pNext = pTemp->pNext;
		pTemp->pNext->pPrev = pTemp->pPrev;		// = pDummy;
		pTemp->pNext = pTemp->pPrev = NULL;

		delete(pTemp); 
		pTemp = NULL;

		return iDelData;
	}

	template<typename T>
	int CList<T>::DeleteLast()
	{
		T iDelData;
		CNode<T> *pTemp = NULL;

		if(pDummy == pDummy->pPrev)
		{
			cout << "Linked List is empty!\n";
			return -1;
		}

		pTemp = pDummy->pPrev;

		iDelData = pTemp->iData;

		pDummy->pPrev = pTemp->pPrev;
		pTemp->pPrev->pNext = pTemp->pNext;
		pTemp->pNext = pTemp->pPrev = NULL;

		delete(pTemp); 
		pTemp = NULL;

		return iDelData;
	}

	template<typename T>
	int CList<T>::DeleteAtPosition(int iPos)
	{
		T iDelData;
		int iCount = 0;
		CNode<T> *pTemp = NULL;

		if(pDummy == pDummy->pPrev)
		{
			cout << "Linked List is empty!\n";
			return -1;
		}

		iCount = CountNode();

		if(iPos <= 0 || iCount+1 < iPos)
		{
			cout << "Position is Not  Valid\n";
			return -1;
		}

		if(iPos == 1)
		{
			iDelData = DeleteFirst();
		}
		else if(iPos == iCount)
		{
			 iDelData = DeleteLast();
		}
		else
		{
			iCount = 1;
			pTemp = pDummy->pNext;

			while(iCount != iPos)
			{
				iCount++;
				pTemp = pTemp->pNext;
			}

			iDelData = pTemp->iData;

			pTemp->pPrev->pNext = pTemp->pNext;
			pTemp->pNext->pPrev = pTemp->pPrev;
			pTemp->pNext = pTemp->pPrev = NULL;

			delete(pTemp);
			pTemp = NULL;
		}

		return iDelData;
	}

	template<typename T>
	int CList<T>::SearchFirstOccurence(T iKey)
	{
		int iPos = 0;
		CNode<T> *pTemp = NULL;

		pTemp = pDummy->pNext;

		while(pDummy != pTemp)
		{
			iPos++;

			if(iKey == pTemp->iData)
				return iPos;

			pTemp = pTemp->pNext;
		}

		pTemp = NULL;

		return 0;
	}

	template<typename T>
	int CList<T>::SearchLastOccurence(T iKey)
	{
		int iPos = 0;
		int iCount = 0;
		CNode<T> *pTemp = NULL;

		pTemp = pDummy->pNext;

		while(pDummy != pTemp)
		{
			iCount++;

			if(iKey == pTemp->iData)
				iPos  = iCount;

			pTemp = pTemp->pNext;
		}

		pTemp = NULL;

		return iPos;
	}

	template<typename T>
	int CList<T>::SearchAllOccurence(T iKey)
	{
		int iCount = 0;
		CNode<T> * pTemp = NULL;

		pTemp = pDummy->pNext;

		while(pDummy != pTemp)
		{
			if(iKey == pTemp->iData)
				iCount++;

			pTemp = pTemp->pNext;
		}

		pTemp = NULL;

		return iCount;
	}

	template<typename T>
	void CList<T>::PhysicalReverse()
	{
		CNode<T> *pPrev = pDummy->pPrev;   		//pLast1
		CNode<T> *pCurrent = pDummy; 		//pFirst
		CNode<T> *pNext = NULL	;

		do
		{
			pNext =pCurrent->pNext;
			pCurrent->pNext = pCurrent->pPrev;
			pCurrent->pPrev = pNext;
			pPrev = pCurrent;
			pCurrent = pNext;	
		}while(pDummy != pCurrent);
	}

	template<typename T>
	void CList<T>::ReverseDisplay()
	{
		CNode<T> *pTemp = NULL;

		if(pDummy == pDummy->pNext)
		{
			cout << "Linked List is Empty.";
			return;
		}

		pTemp = pDummy->pPrev;

		while(pTemp != pDummy)
		{
			cout << "|" << pTemp->iData << "|->";
			pTemp = pTemp->pPrev;
		}

		pTemp = NULL;
	}

	template<typename T>
	void CList<T>::ConcatList(class CList &obj2)
	{
		if(pDummy == pDummy->pPrev)		//1st linked list empty asel tar
		{
			pDummy = obj2.pDummy;
		}
		else if(obj2.pDummy == obj2.pDummy->pNext)		//2nd linked list empty asel tar
		{
			return;
		}
		else
		{
			obj2.pDummy->pNext->pPrev = pDummy->pPrev;
			obj2.pDummy->pPrev->pNext = pDummy;
			pDummy->pPrev->pNext = obj2.pDummy->pNext;
			pDummy->pPrev = obj2.pDummy->pPrev;
		}

		obj2.pDummy->pPrev=obj2.pDummy->pNext = obj2.pDummy;			//ithe pDummy NULL karun chalnar nahi
	}

	template<typename T>
	void CList<T>::ConcatAtPosition(class CList &obj2, int iPos)
	{
		int iCount;
		CNode<T> *pTemp = NULL;


		if(pDummy == pDummy->pNext)
		{
			cout << "Linked List is Empty.";
			return;
		}

		iCount = CountNode();

		if(iPos <= 0 || iPos > iCount+1)
		{
			cout << "Position is not valid.";
			return;
		}

		if(iPos == iCount+1)
		{
			ConcatList(obj2);
		}
		else if(iPos == 1)
		{
			obj2.pDummy->pPrev->pNext = pDummy->pNext;
			obj2.pDummy->pNext->pPrev = pDummy;
			pDummy->pNext->pPrev = obj2.pDummy->pPrev;
			pDummy->pNext = obj2.pDummy->pNext;
		}
		else
		{
			iCount = 1;
			pTemp = pDummy->pNext;

			while(iCount != iPos-1)
			{
				iCount++;
				pTemp = pTemp->pNext;
			}

			obj2.pDummy->pNext->pPrev = pTemp;
			obj2.pDummy->pPrev->pNext = pTemp->pNext;
			pTemp->pNext->pPrev = obj2.pDummy->pPrev;
			pTemp->pNext = obj2.pDummy->pNext;
		}
		obj2.pDummy->pPrev=obj2.pDummy->pNext = obj2.pDummy;
	}
	
	template<typename T>
	int CList<T>::CountNode()
	{
		int iCount = 0;
		CNode<T> *pTemp = NULL;

		pTemp = pDummy->pNext;

		while(pTemp != pDummy)
		{
			iCount++;
			pTemp = pTemp->pNext;
		}
		pTemp = NULL;
		return iCount;
	}

	template<typename T>
	void CList<T>::DeleteAll()
	{
		CNode<T> * pTemp = NULL;
		if(pDummy == pDummy->pNext)
			return;


		while(pDummy != pDummy->pNext)
		{
			pTemp = pDummy->pNext;
			pTemp->pNext->pPrev = pDummy;
			pDummy->pNext = pTemp->pNext;
			pTemp->pNext = pTemp->pPrev = NULL;
			delete(pTemp);
		}

		pTemp = NULL;
	}

	template<typename T>
	void CList<T>::Display()
	{
		CNode<T> *pTemp = NULL;

		if(pDummy == pDummy->pNext)
		{
			cout << "Linked List is Empty.";
			return;
		}

		pTemp = pDummy->pNext;

		while(pTemp != pDummy)
		{
			cout << "|" << pTemp->iData << "|->";
			pTemp = pTemp->pNext;
		}

		pTemp = NULL;
	}

	template<typename T>
	int CList<T>::Empty()
	{
		if(pDummy == pDummy->pNext)
			return 0;
		return 1;
	}

template <typename T>
void MyMain(T Type)
{
	int iChoice1;
	int iChoice2;
	int iChoice3;
	int iCount;
	int iPos;
	int iPos2;
	T iData;				//char, int, ...

	CList<T> obj1;
	CList<T> obj2;
	
	while(1)
	{
		cout << "\n----------------------------------";
		cout << "\n|Operation's on LinkedList|";	
		cout << "\n1.Insert\n2.Delete\n3.Search\n4.Reverse\n5.Concat\n6.Total Nodes\n7.Back\n";

		cout << "\nEnter Your Choice =\t";
		cin >> iChoice1;

		switch(iChoice1)
		{
		case 1:
			while(1)
			{	
                cout << "\n-------------------------";
				cout << "\n1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Back\n";
			
				cout << "\nEnter your Choice =\t";
				cin >> iChoice2;					
			
				switch(iChoice2)
				{
				case 1:
				case 2:
				case 3:
					if(iChoice2 == 3)
					{
				
						cout << "Enter Position =\t";
						cin >> iPos;
				
						if(iPos <= 0 || iPos > obj1.CountNode()+1)
						{
							cout << "Position is not Valid.\n";
							break;
						}
					}

					cout << "Enetr Data =\t";
					cin >> iData;
				
					if(iChoice2 == 1)
						obj1.InsertFirst(iData);
					else if(iChoice2 == 2)			
						obj1.InsertLast(iData);
					else
						obj1.InsertAtPosition(iData,iPos);
					break;

				case 4:
					break;

				default:
					cout << "Enter Valid Choice.\n";			
				}
				cout << "Linked List is :\t";
				//cout << obj1;
				DisplayIterator(obj1);
			
				if(iChoice2 == 4)
					break;
			}
			break;

		case 2:
			while(1)
			{
				if(obj1.Empty() == 0)
				{
					cout << "Linked List is Empty.";
					break;
				}

                cout << "\n-------------------------";
				cout << "\n1.Delete First\n2.Delete Last\n3.Delete At Position\n4.Back\n";

				cout << "\nEnter your Choice =\t";
				cin >> iChoice2;

				switch(iChoice2)
				{
				case 1:
					cout << "\nDelete data is " << obj1.DeleteFirst();
					break;

				case 2:
					cout << "\nDelete data is " << obj1.DeleteLast();
					break;

				case 3:
					if(iChoice2 == 3)
					{
						cout << "Enter Position =\t";
						cin >> iPos;

						if(iPos <= 0 || iPos > obj1.CountNode())
						{
							cout << "Position is Not Valid.\n";
							break;
						}
					}					
					cout << "\nDelete Data is " << obj1.DeleteAtPosition(iPos);
					break;

				case 4:
					break;

				default:
					cout << "Enter Valid Choice.\n";
				}

				cout << "\nLinked is =\t";
				//obj1.Display();
				DisplayIterator(obj1);
				if(iChoice2 == 4)
					break;
			}
			break;

		case 3:
			while(1)
			{
				if(obj1.Empty() == 0)
				{
					cout << "Linked List is Empty\n";
					break;
				}

                cout << "\n-------------------------";
				cout << "\n1.Search First Occurence\n2.Search Last Occurence\n3.Search All Occurence\n4.Back\n";

				cout << "\nEnter you Choice =\t";
				cin >> iChoice2;

				switch(iChoice2)
				{
				case 1:
				case 2:
				case 3:

					cout << "which data you want to search =\t";
					cin >> iData;

					if(iChoice2 == 1 || iChoice2 == 2)
					{
						if(iChoice2 == 1)	
							iPos = obj1.SearchFirstOccurence(iData);
						if(iChoice2 == 2)
							iPos = obj1.SearchLastOccurence(iData);

						if(iPos == 0)
						{	
							cout << "\nData not Found";
							break;
						}
						else
							cout << "\nData Position is "<< iPos;
					}
					else
					{
						cout << "Total All Occurence  is " << obj1.SearchAllOccurence(iData);
					}
					
				case 4:
					break;

				default:
					cout << "Enter Valid Choice.\n";
				}
				cout << "\nLinked List is =\t";
				//obj1.Display();
				DisplayIterator(obj1);

				if(iChoice2 == 4)
					break;
			}
			break;

		case 4:
			while(1)
			{
				if(obj1.Empty() == 0)
				{
					cout << "Linked List is Empty\n";
					break;
				}

                cout << "\n-------------------------";
				cout << "\n1.Physical Reverse\n2.Reverse Display\n3.Back\n";

				cout << "\nEnter your Choice =\t";
				cin >> iChoice2;

				switch(iChoice2)
				{
				case 1:
					obj1.PhysicalReverse();
					break;
				case 2:
					cout << "\nReverse Display = \t";
					obj1.ReverseDisplay();
					break;
				case 3:
					break;
				default:
					cout << "Enter valid Choice.\n";
				}
				cout << "\nLinked List is =\t";
				//obj1.Display();
				DisplayIterator(obj1);

				if(iChoice2 == 3)
					break;
			}
			break;

		case 5:
			while(1)
			{
				start:
                cout << "\n--------------------------------";
				cout << "\n1.Concat List\n2.Concat At Position\n3.Back";

				cout << "\nEnter Your Choice =\t";
			    cin >> iChoice2;

				if(iChoice2 == 2)
				{
					cout << "Enter Position =\t";
					cin >> iPos2;

					if(iPos2 <= 0 || iPos2 > obj1.CountNode()+1)
					{
						cout << "Position is Invalid.\n";
						goto start;
					}
				}
				
				switch(iChoice2)
				{
				case 1:
				case 2:

					while(1)
					{
                        cout << "\n-----------------------";
						cout << "\n1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Back\n";
				
						cout << "\nEnter Your Choice =\t";
						cin >> iChoice3;

						switch(iChoice3)
						{
						case 1:
						case 2:
						case 3:
							
							if(iChoice3 == 3)
							{
								cout << "Enter Position =\t";
								cin >> iPos;

								if(iPos <= 0 || iPos > obj2.CountNode()+1)
								{
									cout << "Position is invalid\n";
									break;
								}
							}

							cout << "Enter Data =\t";
							cin >> iData;

							if(iChoice3 == 1)
								obj2.InsertFirst(iData);
							
							if(iChoice3 == 2)
								obj2.InsertLast(iData);

							if(iChoice3 == 3)
								obj2.InsertAtPosition(iData,iPos);
							break;

						case 4:
							break;
						 	
						default:
							cout << "Enter valid Choice.\n";
						}

						if(iChoice3 == 4)
						{								
							break;
						}

						cout << "\npSecond Linked is =\t";
						//obj2.Display();
						DisplayIterator(obj2);						 
					}

					if(iChoice2 == 1)
					{	
						obj1.ConcatList(obj2);
						//obj2.DeleteAll();
					}
					else
					{
						obj1.ConcatAtPosition(obj2,iPos2);
						//obj2.DeleteAll();
					}
					break;

				case 3:
					break;

				default:
					cout << "Enter valid Choice.\n";
					break;
				}

				cout << "\nLinked List is(pFirst) =\t";
				//obj1.Display();
				DisplayIterator(obj1);

				if(iChoice2 == 3)
					break;

				cout << "\nLinked List is(pSecond) =\t";
				//obj2.Display();
				DisplayIterator(obj2);
			}
			break;

		case 6:
			cout << "Total Nodes are =\t" << obj1.CountNode();
			break;

		case 7:
			obj1.DeleteAll();
			cout << "\nLinked List(pFirst) =\t";
			//obj1.Display();
			DisplayIterator(obj1);
			break;

		default:
			cout << "\nEnter Valid Choice.";
		}
        cout << "\n--------------------------------------------------\n";

		if(iChoice1 == 7)
			break;
	}

}

int main(void)
{
	int iChoice;

	while(1)
	{
		cout << "|Doubly LinkedList Data Type|\n";
		printf("1.INT\n2.CHAR\n3.FLOAT\n4.DOUBLE\n5.EXIT\n\n");
		printf("Enter Your Choice :\t");
		scanf("%d",&iChoice);

		switch(iChoice)
		{
		case 1:
			MyMain(10);
			break;
		case 2:
			MyMain('A');
			break;
		case 3:
			MyMain(60.70f);
			break;
		case 4:
			MyMain(76.80);
			break;
		case 5:
			break;
		default:
			printf("Enter Valid Choice");			
		}

		if(iChoice == 5)
			break;
	}

	return 0;
}

template <typename T>
void DisplayIterator(CList<T> &list)
{
 	cout  << "\nIterator display start : Linked list is :\n";
 	for(CList<T>::Iterator iter = list.begin(); iter != list.end(); ++iter)
 		cout << "<-|" << *iter << "|->";
 
 	cout << endl;
} 