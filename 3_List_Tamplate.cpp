#include<iostream>

using std::cout;
using std::endl;
using std::cin;
using std::ostream;

template <typename T>
class CList;

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
	
	template<typename T>
	friend ostream& operator << (ostream &, CList<T>&);
};

template <typename T>
class CList
{
	CNode<T> *pFirst;
	CNode<T> *pLast;

public:
	CList();
	~CList();

	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPosition(T,int);
	int DeleteFirst();
	int DeleteLast();
	int DeleteAtPosition(int);
	int SearchFirstOccurence(T);
	int SearchLastOccurence(T);
	int SearchAllOccurence(T);
	void ReverseDisplay();
	void PhysicalReverse();
	void ConcatList(class CList);
	void ConcatAtPosition(class CList,int);
	int CountNode();
	void DeleteAll();
	void Display();
	int Empty();
	void Reset();

	template<typename T>
	friend ostream& operator << (ostream &, CList &);
};

	template<typename T>
	CNode<T>::CNode()
	{
		iData = 0;
		pNext = NULL;
	}

	template<typename T>
	CNode<T>::~CNode()
	{
		iData = 0;
		pNext = NULL;
	}

	template<typename T>
	CList<T>::CList()
	{
		pFirst = NULL;
		pLast = NULL;
	}

	template<typename T>
	CList<T>::~CList()
	{
		if(pFirst != NULL)
		{
			DeleteAll();
			pFirst = NULL;
			pLast = NULL;
		}
	}

	template<typename T>
	void CList<T>::InsertFirst(T iNo)
	{
		CNode<T> *pNewNode = NULL;

		pNewNode = new CNode<T>;
		if(NULL == pNewNode)
		{
			cout<< "Memory Allocation is Failed.\n";
			return;
		}

		pNewNode->iData = iNo;

		if(NULL == pFirst)
		{
			pFirst = pLast = pNewNode;
			pFirst->pPrev = pLast;
			pLast->pNext = pFirst;
		}
		else
		{
			pNewNode->pNext = pFirst;
			pFirst->pPrev = pNewNode;
			pFirst = pNewNode;
			pFirst->pPrev = pLast;
			pLast->pNext = pFirst;
		}

		pNewNode = NULL;
	}

	template<typename T>
	void CList<T>::InsertLast(T iNo)
	{
		CNode<T> *pNewNode = NULL;

		pNewNode = new CNode<T>;
		if(NULL == pNewNode)
		{
			printf("Memory Allocation is Falied!\n");
			return;
		}

		pNewNode->iData = iNo;

		if(NULL == pFirst)
		{
			pFirst = pLast = pNewNode;
			pFirst->pPrev = pLast;
			pLast->pNext = pFirst;
		}
		else
		{
			pNewNode->pPrev = pLast;
			pNewNode->pNext = pFirst;
			pLast->pNext = pNewNode;
			pFirst->pPrev = pNewNode;
			pLast = pNewNode;
		}
		pNewNode = NULL;
	}

	template<typename T>
	void CList<T>::InsertAtPosition(T iNo,int iPos)
	{
		int iCount = 0;
		CNode<T> *pTemp = NULL;
		CNode<T> *pNewNode = NULL;

		iCount = CountNode();

		if(iPos <= 0 || iPos > iCount+1)
		{
			cout << "Position is not valid.\n";
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
			pTemp = pFirst;
			iCount = 1;

			pNewNode = new CNode<T>;
			if(pNewNode == NULL)
			{
				cout << "Memory Allocation is Failed.\n";
				return;
			}

			while(iCount != iPos-1)
			{
				iCount++;
				pTemp = pTemp->pNext;
			}

			pNewNode->iData = iNo;

			pNewNode->pNext = pTemp->pNext;
			pNewNode->pPrev = pTemp;
			pTemp->pNext->pPrev = pNewNode;
			pTemp->pNext = pNewNode;
			pTemp = NULL;
		}
	}

	template<typename T>
	int CList<T>::DeleteFirst()
	{
		T iDelData;

		if(pFirst == NULL)
		{
			cout << "\nLinked List is Empty\n";
			return -1;
		}

		iDelData = pFirst->iData;

		if(pLast == pFirst)
		{
			pLast->pPrev = pLast->pNext = NULL;
			delete(pFirst);
			pFirst = pLast = NULL;
		}
		else
		{
			pLast->pNext = pFirst->pNext;
			pFirst->pNext->pPrev = pLast;
			pFirst->pNext = pFirst->pPrev = NULL;
			delete(pFirst);
			pFirst = pLast->pNext;
		}
	
		return iDelData;
	}

	template<typename T>
	int CList<T>::DeleteLast()
	{
		T iDelData;

		if(pFirst == NULL)
		{
			cout << "Linked List is Empty\n";
			return -1;
		}

		iDelData = pLast->iData;

		if(pFirst == pLast)
		{
			pFirst->pNext = pFirst->pPrev = NULL;
			delete(pFirst);
			pFirst = pLast = NULL;
		}
		else
		{
			pFirst->pPrev = pLast->pPrev;
			pLast->pPrev->pNext = pLast->pNext;
			pLast->pNext = pLast->pPrev = NULL;
			delete(pLast);
			pLast = pFirst->pPrev;
		}

		return iDelData;
	}

	template<typename T>
	int CList<T>::DeleteAtPosition(int iPos)
	{
		T iDelData;
		int iCount;
		CNode<T> *pTemp = NULL;

		if(NULL == pFirst)
		{
			cout << "\nLinked List is Empty\n";
			return -1;
		}

		iCount = CountNode();

		if(iPos <= 0 || iPos > iCount+1)
		{
			cout << "Position is Invalid\n";
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
			pTemp = pFirst;

			while(iCount != iPos)
			{
				iCount++;
				pTemp = pTemp->pNext;
			}

			iDelData = pTemp->iData;

			pTemp->pPrev->pNext = pTemp->pNext;
			pTemp->pNext->pPrev = pTemp->pPrev;

			pTemp->pPrev = pTemp->pNext = NULL;
			delete(pTemp);
			pTemp = NULL;
		}	

		return iDelData; 
	}

	template<typename T>
	int CList<T>::SearchFirstOccurence(T iKey)
	{
		CNode<T> *pTemp = NULL;
		int iPos = 0;

		pTemp = pFirst;

		do
		{
			iPos++;

			if(iKey == pTemp->iData)
				return iPos;

			pTemp = pTemp->pNext;
		}while(pTemp != pLast->pNext);

		pTemp = NULL;

		return 0;
	}

	template<typename T>
	int CList<T>::SearchLastOccurence(T iKey)
	{
		int iPos = 0;
		int iCount = 0;
		CNode<T> *pTemp = NULL;


		pTemp = pFirst;
		do
		{
			iCount++;

			if(pTemp->iData == iKey)
				iPos = iCount;

			pTemp = pTemp->pNext;
		}while(pTemp != pLast->pNext);

		pTemp = NULL;
		return iPos;
	}

	template<typename T>
	int CList<T>::SearchAllOccurence(T iKey)
	{
		int iCount = 0;
		CNode<T> *pTemp = NULL;

		pTemp = pFirst;

		do
		{
			if(pTemp->iData == iKey)
				iCount++;

			pTemp = pTemp->pNext;
		}while(pTemp != pLast->pNext);
		pTemp = NULL;	

		return iCount;
	}

	template<typename T>
	void CList<T>::PhysicalReverse()
	{
		CNode<T> *pPrev = pLast;
		CNode<T> *pCurrent = pFirst;
		CNode<T> *pNext = NULL	;

		do
		{
			pNext = pCurrent->pNext;
			pCurrent->pNext = pCurrent->pPrev;
			pCurrent->pPrev = pNext;
			pPrev = pCurrent;
			pCurrent = pNext;
		}while(pFirst != pCurrent);

		pLast = pFirst;
		pFirst = pPrev;	
	}

	template<typename T>
	void CList<T>::ReverseDisplay()
	{
		PhysicalReverse();
		Display();
		PhysicalReverse();
	}

	template<typename T>
	void CList<T>::ConcatList(class CList obj2)
	{
		if(obj2.pFirst == NULL)
			return;
		else if(pFirst == NULL)
		{
			pFirst = obj2.pFirst;
			pLast = obj2.pLast;
		}
		else
		{
			pLast->pNext = obj2.pFirst;
			obj2.pFirst->pPrev = pLast;
			pLast = obj2.pLast;
			pLast->pNext = pFirst;
			pFirst->pPrev = pLast;
		}
		
		obj2.pFirst = obj2.pLast = NULL;
		return;
	}

	template<typename T>
	void CList<T>::ConcatAtPosition(class CList obj2, int iPos)
	{
		int iCount;
		CNode<T> *pTemp = NULL;

		iCount = CountNode();
		if(iPos <= 0 || iPos > iCount+1)
		{
			printf("Position is Invalid.\n");
			return;
		}
		
		if(iPos == iCount+1)
		{
			ConcatList(obj2);
		}
		else if(iPos == 1)
		{
			if(pFirst == NULL)
			{
				pFirst = obj2.pFirst;
				pLast = obj2.pLast;
			}
			else
			{
				obj2.pFirst->pPrev = pLast;
				obj2.pLast->pNext =  pFirst;
				pLast->pNext = obj2.pFirst;
				pFirst->pPrev = obj2.pLast;
				pFirst = obj2.pFirst; 
			}
		}
		else
		{
			iCount = 1;
			pTemp = pFirst;

			while(iCount != iPos-1)
			{
				iCount++;
				pTemp = pTemp->pNext;
			}

			obj2.pFirst->pPrev = pTemp;
			obj2.pLast->pNext = pTemp->pNext;
			pTemp->pNext->pPrev = obj2.pLast;
			pTemp->pNext = obj2.pFirst;
			pTemp = NULL;
		}
		obj2.pFirst = obj2.pLast = NULL;
	}
	
	template<typename T>
	int CList<T>::CountNode()
	{
		int iCount = 0;
		CNode<T> *pTemp = NULL;

		if(NULL == pFirst)
			return 0;
		pTemp = pFirst;

		do
		{
			iCount++;
			pTemp = pTemp->pNext;
		}while(pTemp != pLast->pNext);

		pTemp = NULL;

		return iCount;
	}

	template<typename T>
	void CList<T>::DeleteAll()
	{
		if(pFirst == NULL)
			return;

		do 
		{
			pLast->pNext = pFirst->pNext;
			pFirst->pNext->pPrev = pLast;
			pFirst->pNext = pFirst->pPrev = NULL;
			delete(pFirst);
			pFirst = pLast->pNext;
		}while(pFirst != pLast);

		delete(pLast);
		pFirst = pLast = NULL;
	}

	template<typename T>
	void CList<T>::Display()
	{
		if(pFirst == NULL)
		{
			cout << "\nLinked List is Empty.\n";
			return;
		}

		do
		{
			cout << "|" << pFirst->iData << "|" << "->";
			pFirst = pFirst->pNext;
		}while(pLast->pNext != pFirst);
	}

	template<typename T>
	int CList<T>::Empty()
	{
		if(pFirst != NULL)
			return 1;
		return 0;
	}

	template<typename T>
	void CList<T>::Reset()
	{
		pFirst = NULL;
		pLast = NULL;
	}

template<typename T>
ostream& operator << (ostream &out, CList<T> &lst)
{
	CNode<T> *pHead = lst.pFirst;

	if(NULL == pHead)
	{
		out << "Linked List is Empty.";
		return out;
	}

	do
	{
		out << "|" << pHead->iData << "|" << "->";

		pHead = pHead->pNext;
	}while(pHead != lst.pLast->pNext);

	return out;
}

int main(void)
{
	int iChoice1;
	int iChoice2;
	int iChoice3;
	int iCount;
	int iPos;
	int iPos2;
	int iData;		//char,int,float,double

	CList<int> obj1;
	CList<int> obj2;
	
	while(1)
	{
		cout << "\n|Doubly Linked List|";
		cout << "\n1.Insert\n2.Delete\n3.Search\n4.Reverse\n5.Concat\n6.Total Nodes\n7.Exit\n";

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
				cout << "Linked List is :\t" << obj1;
				//cout << obj1;

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
					cout << "\nDelete Data is" << obj1.DeleteAtPosition(iPos);
					break;

				case 4:
					break;

				default:
					cout << "Enter Valid Choice.\n";
				}

				cout << "\nLinked is =\t" << obj1;
				//obj1.Display();

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
				cout << "\nLinked List is =\t" << obj1;
				//obj1.Display();

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
				cout << "\nLinked List is =\t" << obj1;
				//obj1.Display();

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

						cout << "\npSecond Linked is =\t" << obj2;
						//obj2.Display();
					}


					if(iChoice2 == 1)
					{	
						obj1.ConcatList(obj2);
						obj2.Reset();
					}
					else
					{
						obj1.ConcatAtPosition(obj2,iPos2);
						obj2.Reset();
					}
					break;

				case 3:
					break;

				default:
					cout << "Enter valid Choice.\n";
					break;
				}

				cout << "\nLinked List is(pFirst) =\t" << obj1;
				//obj1.Display();

				if(iChoice2 == 3)
					break;

				cout << "\nLinked List is(pSecond) =\t" << obj2;
				//obj2.Display();
			}
			break;

		case 6:
			cout << "Total Nodes are =\t" << obj1.CountNode();
			break;

		case 7:
			obj1.DeleteAll();
			cout << "\nLinked List(pFirst) =\t" << obj1;
			//obj1.Display();
			break;

		default:
			cout << "\nEnter Valid Choice.";
		}
        cout << "\n--------------------------------------------------\n";

		if(iChoice1 == 7)
			break;
	}

	return 0;
}


