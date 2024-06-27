#include "List_Server.h"

// CNode Def

	CNode::CNode()
	{
		iData = 0;
		pNext = NULL;
		pPrev = NULL;
	}

	CNode::~CNode()
	{
		iData = 0;
		pNext = NULL;
		pPrev = NULL;
	}


// Iterator Def.
	CList::Iterator::Iterator()
	{
		pCurrent = NULL;
	}
	
	CList::Iterator::~Iterator()
	{	
		pCurrent = NULL;
	}

	void CList::Iterator::SetCurrentNode(CNode *pPtr)
	{
		pCurrent = pPtr;
	}

	CList::Iterator& CList::Iterator::operator ++( )
	{
		pCurrent = pCurrent->pNext;
		return *this;
	}

	CList::Iterator CList::Iterator::operator ++(int)
	{
		Iterator temp = *this;
		pCurrent = pCurrent->pNext;
		return temp;
	}

	CList::Iterator& CList::Iterator::operator --( )
	{
		pCurrent = pCurrent->pPrev;
		return *this;
	}

	CList::Iterator CList::Iterator::operator --(int)
	{
		Iterator temp = *this;
		pCurrent = pCurrent->pPrev;
		return temp;
	}
    
    bool CList::Iterator::operator !=(Iterator& refObj)
    {
    	return pCurrent != refObj.pCurrent;
    }

    bool CList::Iterator::operator ==(Iterator& refObj)
    {
    	return pCurrent == refObj.pCurrent;
    }

    bool CList::Iterator::operator <(Iterator& refObj)
    {
    	return pCurrent < refObj.pCurrent;
    }

    bool CList::Iterator::operator >(Iterator& refObj)
    {
    	return pCurrent > refObj.pCurrent;
    }

    bool CList::Iterator::operator <=(Iterator& refObj)
    {
    	return pCurrent <= refObj.pCurrent;
    }

    bool CList::Iterator::operator >=(Iterator& refObj)
    {
    	return pCurrent >= refObj.pCurrent;
    }

    int CList::Iterator::operator *()
    {
    	return pCurrent->iData;
    }


// CList Def.

	CList::Iterator& CList::begin()
	{
		StartIter.SetCurrentNode(pFirst);
		return StartIter;
	}

	CList::Iterator& CList::end()
	{ 
		EndIter.SetCurrentNode(pLast);
		return EndIter;
	}

	CList::CList()
	{
		pFirst = NULL;
		pLast = NULL;
	}
     
	CList::~CList()
	{
		if(pFirst != NULL)
		{
			DeleteAll();
			pFirst = NULL;
			pLast = NULL;
		}
	}

	void CList::InsertFirst(int iNo)
	{
		CNode *pNewNode = NULL;

		pNewNode = new CNode;
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

	void CList::InsertLast(int iNo)
	{
		CNode *pNewNode = NULL;

		pNewNode = new CNode;
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

	void CList::InsertAtPosition(int iNo,int iPos)
	{
		int iCount = 0;
		CNode *pTemp = NULL;
		CNode *pNewNode = NULL;

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

			pNewNode = new CNode;
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

	int CList::DeleteFirst()
	{
		int iDelData;

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

	int CList::DeleteLast()
	{
		int iDelData;

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

	int CList::DeleteAtPosition(int iPos)
	{
		int iDelData;
		int iCount;
		CNode *pTemp = NULL;

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

	int CList::SearchFirstOccurence(int iKey)
	{
		CNode *pTemp = NULL;
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

	int CList::SearchLastOccurence(int iKey)
	{
		int iPos = 0;
		int iCount = 0;
		CNode *pTemp = NULL;


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

	int CList::SearchAllOccurence(int iKey)
	{
		int iCount = 0;
		CNode *pTemp = NULL;

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

	void CList::PhysicalReverse()
	{
		CNode *pPrev = pLast;
		CNode *pCurrent = pFirst;
		CNode *pNext = NULL	;

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

	void CList::ReverseDisplay()
	{
		PhysicalReverse();
		Display();
		PhysicalReverse();
	}

	void CList::ConcatList(class CList obj2)
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

	void CList::ConcatAtPosition(class CList &obj2, int iPos)
	{
		int iCount;
		CNode *pTemp = NULL;

		iCount = CountNode();
		if(iPos <= 0 || iPos > iCount+1)
		{
			cout << "Position is Invalid.\n";
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
	
	int CList::CountNode()
	{
		int iCount = 0;
		CNode *pTemp = NULL;

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

	void CList::DeleteAll()
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

	void CList::Display()
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

	int CList::Empty()
	{
		if(pFirst != NULL)
			return 1;
		return 0;
	}

/*
ostream& operator << (ostream &out, CList &lst)
{
	CNode *pHead = lst.pFirst;

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
*/
