#include<iostream>

using std::cout;
using std::endl;
using std::cin;
using std::ostream;

class CList;
void DisplayIterator(CList &);

class CNode
{
	int iData;
	CNode *pNext;
	CNode *pPrev;

public:
	CNode()
	{
		iData = NULL;
		pNext = NULL;
	}

	~CNode()
	{
		iData = NULL;
		pNext = NULL;
	}

	friend class CList;
};

class CList
{
	CNode * pDummy;


public:
	CList()
	{
		pDummy = new CNode;

		if(pDummy == NULL)
		{
			printf("Memory Allocation is Failed");
			return;
		}
		pDummy->pNext = pDummy->pPrev = pDummy;
	}

	~CList()
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

	void InsertFirst(int iNo)
	{
		CNode *pNewNode = NULL;

		pNewNode = new CNode;

		if(pNewNode == NULL)
		{
			printf("Memory Allocation is Failed.");
			return;
		}

		pNewNode->iData = iNo;

		pNewNode->pPrev = pDummy;
		pNewNode->pNext = pDummy->pNext;
		pDummy->pNext->pPrev = pNewNode;
		pDummy->pNext = pNewNode;  

		pNewNode = NULL;
	}

	void InsertLast(int iNo)
	{
		CNode *pNewNode = NULL;
		
		pNewNode = new CNode;
	
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
                                                                                                                                                                                                    
	void InsertAtPosition(int iNo,int iPos)
	{
		int iCount = 0;
		CNode *pNewNode = NULL;
		CNode *pTemp = NULL;

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
			pNewNode = new CNode;

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

	int DeleteFirst()
	{
		int iDelData;
		CNode *pTemp = NULL;

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

	int DeleteLast()
	{
		int iDelData;
		CNode *pTemp = NULL;

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

	int DeleteAtPosition(int iPos)
	{
		int iDelData;
		int iCount = 0;
		CNode *pTemp = NULL;

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

	int SearchFirstOccurence(int iKey)
	{
		int iPos = 0;
		CNode *pTemp = NULL;

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

	int SearchLastOccurence(int iKey)
	{
		int iPos = 0;
		int iCount = 0;
		CNode *pTemp = NULL;

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

	int SearchAllOccurence(int iKey)
	{
		int iCount = 0;
		CNode * pTemp = NULL;

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

	void PhysicalReverse()
	{
		CNode *pPrev = pDummy->pPrev;   		//pLast1
		CNode *pCurrent = pDummy; 		//pFirst
		CNode *pNext = NULL	;


		do
		{
			pNext =pCurrent->pNext;
			pCurrent->pNext = pCurrent->pPrev;
			pCurrent->pPrev = pNext;
			pPrev = pCurrent;
			pCurrent = pNext;	
		}while(pDummy != pCurrent);

	}

	void ReverseDisplay()
	{
		CNode *pTemp = NULL;

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

	void ConcatList(class CList &obj2)
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

	void ConcatAtPosition(class CList &obj2, int iPos)
	{
		int iCount;
		CNode *pTemp = NULL;


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
	
	int CountNode()
	{
		int iCount = 0;
		CNode *pTemp = NULL;

		pTemp = pDummy->pNext;

		while(pTemp != pDummy)
		{
			iCount++;
			pTemp = pTemp->pNext;
		}
		pTemp = NULL;
		return iCount;
	}

	void DeleteAll()
	{
		CNode * pTemp = NULL;
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


	void Display()
	{
		CNode *pTemp = NULL;

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

	int Empty()
	{
		if(pDummy == pDummy->pNext)
			return 0;
		return 1;
	}

	class Iterator
	{
		CNode *pCurrent;

	public:
		Iterator::Iterator()
		{
			pCurrent = NULL;
		}
		
		Iterator::~Iterator()
		{	
			pCurrent = NULL;
		}

		void SetCurrentNode(CNode *pPtr)
		{
			pCurrent = pPtr;
		}

		CNode* GetCurrentNode()
		{
			return pCurrent; 
		}

		Iterator& operator ++( )
		{
			pCurrent = pCurrent->pNext;
			return *this;
		}

		Iterator operator ++(int)
		{
			Iterator temp = *this;
			pCurrent = pCurrent->pNext;
			return temp;
		}

		Iterator& operator --( )
		{
			pCurrent = pCurrent->pPrev;
			return *this;
		}

		Iterator operator --(int)
		{
			Iterator temp = *this;
			pCurrent = pCurrent->pPrev;
			return temp;
		}
	    
	    bool operator !=(Iterator& refObj)
	    {
	    	return pCurrent != refObj.pCurrent;
	    }

	    bool operator ==(Iterator& refObj)
	    {
	    	return pCurrent == refObj.pCurrent;
	    }

	    bool operator <(Iterator& refObj)
	    {
	    	return pCurrent < refObj.pCurrent;
	    }

	    bool operator >(Iterator& refObj)
	    {
	    	return pCurrent > refObj.pCurrent;
	    }

	    bool operator <=(Iterator& refObj)
	    {
	    	return pCurrent <= refObj.pCurrent;
	    }

	    bool operator >=(Iterator& refObj)
	    {
	    	return pCurrent >= refObj.pCurrent;
	    }

	    int operator *()
	    {
	    	return pCurrent->iData;
	    }
	};

	Iterator& CList::begin()
	{
		StartIter.SetCurrentNode(pDummy->pNext);
		return StartIter;
	}

	Iterator& CList::end()
	{ 
		EndIter.SetCurrentNode(pDummy);
		return EndIter;
	}

//---------------------
	void CList::push_back(int iNo)
	{
		InsertLast(iNo);
	}

	void CList::push_front(int iNo)
	{
		InsertFirst(iNo);
	}

	CList& CList::operator = (CList& list)
    {
    	int iCount = CountNode();
    	int iCount1 = list.CountNode();
    	CNode * pTemp1 = pDummy->pNext;
    	CNode * pTemp2 = list.pDummy->pNext;

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
    		CNode *pDelete = NULL;

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

	void CList::splice(Iterator iter, CList& list) 
	{
	    CNode *pNode = iter.GetCurrentNode();
	        
	    list.pDummy->pNext->pPrev = pNode->pPrev;
	    list.pDummy->pPrev->pNext = pNode;
        pNode->pPrev->pNext = list.pDummy->pNext;
	    pNode->pPrev = list.pDummy->pPrev;
	        
	    list.pDummy->pNext = list.pDummy;		//list1 la reset kel
	    list.pDummy->pPrev = list.pDummy;
	}


void CList::splice(Iterator destination, CList& list, Iterator source) 
{
    CNode *pNode1 = destination.GetCurrentNode();
    CNode *pNode2 = source.GetCurrentNode();

        pNode2->pPrev->pNext = pNode2->pNext;
        pNode2->pNext->pPrev = pNode2->pPrev;

	   	pNode2->pNext = pNode1;
        pNode2->pPrev = pNode1->pPrev;
        pNode1->pPrev->pNext = pNode2;
        pNode1->pPrev = pNode2;

        pNode1 = pNode2 = NULL;
}


	CList::Iterator CList::find(Iterator start, Iterator end, int iKey)
	{
	
	    while (start != end) 
	    {
	        if (*start == iKey)
	            return start;

	        ++start;
	    }

	    return end;
	}

	void CList::sort() 		//Bubble sort
	{
	    CNode *pCurrent = NULL;
	    CNode *pNext = NULL;
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

	void unique()
	{
		CNode *pPtr = pDummy->pNext;
		CNode *pTemp = NULL;
		CNode *pTemp1 = NULL;

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

	void merge(class CList & list)
	{
		ConcatList(list);
		sort();
	}


private:
	Iterator EndIter;
	Iterator StartIter;
};


void printLists(CList &list1, CList &list2)
{
	cout << "\nList1 : ";
	for(CList::Iterator iter = list1.begin(); iter != list1.end(); ++iter)
		cout << *iter << " ";

	cout << "\nList2 : ";
	for(CList::Iterator iter = list2.begin(); iter != list2.end(); ++iter)
		cout << *iter << " ";	

	cout << endl;
}

int main(void)
{
	CList list1,list2;

	for(int i=0; i<6; i++)
	{
		list1.push_back(i + 65);
		list2.push_front(i + 65);
	}

	printLists(list1, list2);

	list2.splice(list2.find(list2.begin(),list2.end(), 69), list1);

	printLists(list1, list2);


	list2.splice(list2.end(),list2,list2.begin());

	printLists(list1, list2);

	list2.sort();
	list1 = list2;
	list2.unique();

	printLists(list1, list2);

	list1.merge(list2);

	printLists(list1, list2);

	return 0;
}

