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
void printLists(CList<T> &, CList<T> &);

template <typename T, typename Iterator>
typename Iterator find(Iterator, Iterator, T);

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
		Iterator();
		~Iterator();
		void SetCurrentNode(CNode<T> *);
		CNode<T>* GetCurrentNode();
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

	Iterator& begin();
	Iterator& end();
	void push_back(T);
	void push_front(T);
	CList& operator = (CList& );
	void splice(Iterator,CList&);
	void splice(Iterator , CList& , Iterator);
	void sort();
	void unique(); 
	void merge(class CList&);

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
		CNode<T>* CList<T>::Iterator::GetCurrentNode()
		{
			return pCurrent; 
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

		cout << "\nDeleted All Nodes Successfully";
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
		CNode<T> *pCurrent = pDummy; 			//pFirst
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

	template<typename T>
	void CList<T>::push_back(T iNo)
	{
		InsertLast(iNo);
	}

	template<typename T>
	void CList<T>::push_front(T iNo)
	{
		InsertFirst(iNo);
	}

	template<typename T>
    CList<T>& CList<T>::operator = (CList& list)
    {
    	int iCount = CountNode();
    	int iCount1 = list.CountNode();
    	CNode<T> * pTemp1 = pDummy->pNext;
    	CNode<T> * pTemp2 = list.pDummy->pNext;

    	if(pDummy->pNext == pDummy)
    	{
    		//pTemp2 = list.pDummy->pNext;

    		while(pTemp2 != list.pDummy)
    		{
    			InsertLast(pTemp2->iData);
    			pTemp2 = pTemp2->pNext;
    		}
    	}
    	else if(iCount < iCount1)
    	{
    		while(pTemp1 != pDummy)
    		{
    			pTemp1->iData = pTemp2->iData;
    			pTemp1 = pTemp1->pNext;
    			pTemp2 = pTemp2->pNext;
    		}

    		while(pTemp2 != list.pDummy)
    		{
    			InsertLast(pTemp2->iData);
    			pTemp2 = pTemp2->pNext;
    		}
    	}
    	else if(iCount > iCount1)
    	{
    		CNode<T> *pDelete = NULL;

    		while(pTemp2 != list.pDummy)
    		{
    			pTemp1->iData = pTemp2->iData;
    			pTemp1 = pTemp1->pNext;
    			pTemp2 = pTemp2->pNext;
    		}

    		while(pTemp1 != pDummy)
    		{
    			pTemp1 = pTemp1->pNext;
    			pDelete ->pNext = pDelete->pPrev = NULL;
    			delete pDelete;
    		}
    		pDummy->pNext = pDummy;
    	}
    	else if(iCount == iCount1)
    	{
    		while(pTemp1 != pDummy && pTemp2 != list.pDummy)
    		{
    			pTemp1->iData =  pTemp2->iData;
    			
    			pTemp1 = pTemp1->pNext;
    			pTemp2 = pTemp2->pNext;
    		}
    	}

    	pTemp1 = NULL;
    	pTemp2 = NULL;

        return *this;
    }

	template<typename T>
	void CList<T>::splice(Iterator iter, CList& list) 
	{
	    CNode<T> *pNode = iter.GetCurrentNode();
	        
	    list.pDummy->pNext->pPrev = pNode->pPrev;
	    list.pDummy->pPrev->pNext = pNode;
        pNode->pPrev->pNext = list.pDummy->pNext;
	    pNode->pPrev = list.pDummy->pPrev;
	        
	    list.pDummy->pNext = list.pDummy;		//list1 la reset kel
	    list.pDummy->pPrev = list.pDummy;
	}

	template<typename T>
	void CList<T>::splice(Iterator destination, CList& list, Iterator source)
	{
	    CNode<T> *pNode1 = destination.GetCurrentNode();
    	CNode<T> *pNode2 = source.GetCurrentNode();

        pNode2->pPrev->pNext = pNode2->pNext;
        pNode2->pNext->pPrev = pNode2->pPrev;

	   	pNode2->pNext = pNode1;
        pNode2->pPrev = pNode1->pPrev;
        pNode1->pPrev->pNext = pNode2;
        pNode1->pPrev = pNode2;

        pNode1 = pNode2 = NULL;
	}

	template<typename T>
	void CList<T>::sort() 		//Bubble sort
	{
	    CNode<T> *pCurrent = NULL;
	    CNode<T> *pNext = NULL;
	    bool bSwapped = false;

	    if(pDummy == pDummy->pNext || pDummy->pNext->pNext == pDummy) 
	        return;

	    do 
	    {
	        bSwapped = false;
	        pCurrent = pDummy->pNext;
	        pNext = pCurrent->pNext;

	        while (pNext != pDummy) 
	        {
	            if (pCurrent->iData > pNext->iData) 
	            {
	                pCurrent->pNext = pNext->pNext;			// Node change kele ahe naki data.
	                pNext->pNext->pPrev = pCurrent;
	                pNext->pPrev = pCurrent->pPrev;
	                pNext->pNext = pCurrent;
	                pCurrent->pPrev->pNext = pNext;
	                pCurrent->pPrev = pNext;

	                bSwapped = true;
	            }

	            pCurrent = pNext;				//next node sathi pudhe jail
	            pNext = pNext->pNext;
	        }

	    }while (bSwapped);
	}

	template<typename T>
	void CList<T>::unique()
	{
		CNode<T> *pPtr = pDummy->pNext;
		CNode<T> *pTemp = NULL;
		CNode<T> *pTemp1 = NULL;

		while(pPtr != pDummy)
		{
			pTemp = pPtr->pNext;

			while(pTemp != pDummy)
			{
				if(pPtr->iData == pTemp->iData)
				{
					pTemp1 = pTemp;
					pTemp->pPrev->pNext = pTemp->pNext;
					pTemp->pNext->pPrev = pTemp->pPrev;
					pTemp = pTemp->pNext;
					pTemp1->pNext = pTemp1->pPrev = NULL;
					delete(pTemp1);
					continue;				//2 vela pNext nahi honar.			
				}
				pTemp = pTemp->pNext;
			}
			pPtr = pPtr->pNext;
		}
	}

	template<typename T>
	void CList<T>::merge(class CList & list)
	{
		ConcatList(list);
		sort();
	}

template<typename T>
void printLists(CList<T> &list1, CList<T> &list2)
{
	cout << "\nList1 : ";
	for(CList<T>::Iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";

	cout << "\nList2 : ";
	for(CList<T>::Iterator iter = list2.begin(); iter != list2.end(); ++iter)
		cout << *iter << " ";	

	cout << endl;
}

template <typename T, typename Iterator>
typename Iterator find(Iterator start,Iterator end,T iKey)  
{	
	//itor.set

   while (start != end) 
   {
	    if (*start == iKey)
	        return start;
        ++start;
	}

	//Iterator.SetCurrentNode()

	return Iterator();
}

template<typename T>
void MyMain(T Type)
{
	printf("\n-------------------------------------------");
	CList<T> list1,list2;

	for(int i=0; i<6; i++)
	{
		list1.push_back(i + 65);
		list2.push_front(i + 65);
	}

	printLists(list1, list2);

	list2.splice(find(list2.begin(),list2.end(), 69), list1);

	printLists(list1, list2);

	list2.splice(list2.end(),list2,list2.begin());

	printLists(list1, list2); 

	list2.sort();
	list1 = list2;
	list2.unique();

	printLists(list1, list2);

	list1.merge(list2);

	printLists(list1, list2);
}

int main(void)
{
	int iChoice;

	while(1)
	{
		printf("\n------------------------------------------------");
		cout << "\n|Doubly LinkedList Data Type|\n";
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

