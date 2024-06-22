#include<stdio.h>
#include<malloc.h>

struct Node 
{
	struct Node *pPrev;
	int iData;
	struct Node *pNext;
};

void InsertFirst(struct Node ** ,struct Node ** ,int);
void InsertLast(struct Node ** ,struct Node ** ,int);
void InsertAtPosition(struct Node ** ,struct Node ** ,int,int);
int DeleteFirst(struct Node ** ,struct Node ** );
int DeleteLast(struct Node ** ,struct Node **);
int DeleteAtPosition(struct Node ** ,struct Node **,int);
int SearchFirsOccurence(struct Node * , struct Node * ,int);
int SearchLastOccurence(struct Node * ,struct Node * ,int);
int SearchAllOccurence(struct Node * ,struct Node * ,int);
void PhysicalReverse(struct Node **,struct Node **);
void ReverseDisplay(struct Node * ,struct Node *);
void ConcatList(struct Node ** ,struct Node ** ,struct Node ** ,struct Node ** );
void ConcatAtPosition(struct Node ** ,struct Node ** ,struct Node ** ,struct Node ** ,int);
int CountNode(struct Node * ,struct Node * );
void DeleteAll(struct Node ** ,struct Node ** );
void Display(struct Node * ,struct Node *);

int main(void)
{
	int iChoice1;
	int iChoice2;
	int iChoice3;
	int iCount;
	int iData;
	int iPos;
	int iPos2;
	
	struct Node *pFirst = NULL;
	struct Node *pLast1 = NULL;

	struct Node *pSecond = NULL;
	struct Node *pLast2 = NULL;

	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.Search\n4.Reverse\n5.Concat\n6.Total Nodes\n7.Exit\n");

		printf("Enter Your Choice =\t");
		scanf("%d",&iChoice1);

		switch(iChoice1)
		{
		case 1:
			while(1)
			{	
                printf("\n-------------------------");
				printf("\n1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Back\n");
			
				printf("Enter your Choice =\t");
				scanf("%d",&iChoice2);
					

			
				switch(iChoice2)
				{
				case 1:
				case 2:
				case 3:
					if(iChoice2 == 3)
					{
				
						printf("Enter Position =\t");
						scanf("%d",&iPos);
				
						if(iPos <= 0 || iPos > CountNode(pFirst,pLast1)+1)
						{
							printf("Position is not Valid.\n");
							break;
						}
					}

					printf("Enetr Data =\t");
					scanf("%d",&iData);
				
					if(iChoice2 == 1)
						InsertFirst(&pFirst,&pLast1,iData);
					else if(iChoice2 == 2)			
						InsertLast(&pFirst,&pLast1,iData);
					else
						InsertAtPosition(&pFirst,&pLast1,iData,iPos);
					break;

				case 4:
					break;

				default:
					printf("Enter Valid Choice.");			
				}
				printf("\nLinked List is : \t");
				Display(pFirst,pLast1);

				if(iChoice2 == 4)
					break;
			}
			break;

		case 2:
			while(1)
			{
				iCount = CountNode(pFirst,pLast1);
				if(iCount == 0)
				{
					printf("Linked List is Empty\n");
					break;
				}

                printf("\n-------------------------");
				printf("\n1.Delete First\n2.Delete Last\n3.Delete At Position\n4.Back\n");

				printf("Enter your Choice =\t");
				scanf("%d",&iChoice2);

				switch(iChoice2)
				{
				case 1:
					printf("Delete data is %d\n",DeleteFirst(&pFirst,&pLast1));
					break;

				case 2:
					printf("Delete data is %d\n",DeleteLast(&pFirst,&pLast1));
					break;

				case 3:
					if(iChoice2 == 3)
					{
						printf("Enter Position =\t");
						scanf("%d",&iPos);

						if(iPos <= 0 || iPos > CountNode(pFirst,pLast1))
						{
							printf("Position is Not Valid.\n");
							break;
						}
					}					
					printf("Delete Data is %d\n",DeleteAtPosition(&pFirst,&pLast1,iPos));
					break;

				case 4:
					break;

				default:
					printf("Enter Valid Choice.\n");
				}

				printf("Linked is =\t");
				Display(pFirst,pLast1);

				if(iChoice2 == 4)
					break;
			}
			break;

		case 3:
			while(1)
			{
				if(pFirst == NULL)
				{
					printf("Linked List is Empty\n");
					break;
				}

                printf("\n-------------------------");
				printf("\n1.Search First Occurence\n2.Search Last Occurence\n3.Search All Occurence\n4.Back\n");

				printf("Enter you Choice =\t");
				scanf("%d",&iChoice2);

				switch(iChoice2)
				{
				case 1:
				case 2:
				case 3:

					printf("which data you want to search =\t");
					scanf("%d",&iData);

					if(iChoice2 == 1 || iChoice2 == 2)
					{
						if(iChoice2 == 1)	
							iPos = SearchFirstOccurence(pFirst,pLast1,iData);
						if(iChoice2 == 2)
							iPos = SearchLastOccurence(pFirst,pLast1,iData);

						if(iPos == 0)
						{	
							printf("Data not Found\n");
							break;
						}
						else
							printf("Data Position is %d\n",iPos);
					}
					else
					{
						printf("Total All Occurence  is %d\n",SearchAllOccurence(pFirst,pLast1,iData));
					}
					
				case 4:
					break;

				default:
					printf("Enter Valid Choice.\n");
				}
				printf("\nLinked List is = \t");
				Display(pFirst,pLast1);

				if(iChoice2 == 4)
					break;
			}
			break;

		case 4:
			while(1)
			{
				iCount = CountNode(pFirst,pLast1);
				if(iCount == 0)
				{
					printf("Linked List is Empty\n");
					break;
				}

                printf("\n-------------------------");
				printf("\n1.Physical Reverse\n2.Reverse Display\n3.Back\n");

				printf("Enter your Choice =\t");
				scanf("%d",&iChoice2);

				switch(iChoice2)
				{
				case 1:
					PhysicalReverse(&pFirst,&pLast1);
					break;
				case 2:
					printf("\nReverse Display = \t");
					ReverseDisplay(pFirst,pLast1);
					break;
				case 3:
					break;
				default:
					printf("Enter valid Choice.\n");
				}
				printf("\nLinked List is =\t");
				Display(pFirst,pLast1);

				if(iChoice2 == 3)
					break;
			}
			break;

		case 5:
			while(1)
			{
				start:
                printf("\n--------------------------------");
				printf("\n1.Concat List\n2.Concat At Position\n3.Back");

				printf("\nEnter Your Choice =\t");
				scanf("%d",&iChoice2);

				if(iChoice2 == 2)
				{
					printf("Enter Position =\t");
					scanf("%d",&iPos2);

					if(iPos2 <= 0 || iPos2 > CountNode(pFirst,pLast1)+1)
					{
						printf("Position is Invalid.\n");
						goto start;
					}
				}
				
				switch(iChoice2)
				{
				case 1:
				case 2:

					while(1)
					{
                        printf("\n-----------------------");
						printf("\n1.Insert First\n2.Insert Last\n3.Insert At Position\n4.Back\n");
				
						printf("Enter Your Choice =\t");
						scanf("%d",&iChoice3);

						switch(iChoice3)
						{
						case 1:
						case 2:
						case 3:
							
							if(iChoice3 == 3)
							{
								printf("Enter Position =\t");
								scanf("%d",&iPos);

								if(iPos <= 0 || iPos > CountNode(pSecond,pLast2)+1)
								{
									printf("Position is invalid\n");
									break;
								}
							}

							printf("Enter Data =\t");
							scanf("%d",&iData);

							if(iChoice3 == 1)
								InsertFirst(&pSecond,&pLast2,iData);
							
							if(iChoice3 == 2)
								InsertLast(&pSecond,&pLast2,iData);

							if(iChoice3 == 3)
								InsertAtPosition(&pSecond,&pLast2,iData,iPos);
							break;

						case 4:
							break;
							
						default:
							printf("Enter valid Choice.\n");
						}
						
						if(iChoice3 == 4)
						{								
							break;
						}

						printf("\npSecond Linked is =\t");
						Display(pSecond,pLast2);
					}

					if(iChoice2 == 1)
						ConcatList(&pFirst,&pLast1,&pSecond,&pLast2);
					else
						ConcatAtPosition(&pFirst,&pLast1,&pSecond,&pLast2,iPos2);

					break;

				case 3:
					break;

				default:
					printf("Enter valid Choice.\n");
					break;
				}

				if(iChoice2 == 3)
					break;

				printf("\nLinked List is(pFirst) =\t");
				Display(pFirst,pLast1);

				printf("\nLinked List is(pSecond) =\t");
				Display(pSecond,pLast2);
			}
			break;

		case 6:
			printf("Total Nodes are =\t%d",CountNode(pFirst,pLast1));
			break;

		case 7:
			DeleteAll(&pFirst,&pLast1);
			printf("\nLinked List(pFirst) =\t");
			Display(pFirst,pLast1);
			break;

		default:
			printf("\nEnter Valid Choice.");
		}
        printf("\n--------------------------------------------------\n");

		if(iChoice1 == 7)
			break;
	}

	return 0;
}

void InsertFirst(struct Node **ppHead,struct Node **ppTail,int iNo)
{
	struct Node *pNewNode = NULL;

	pNewNode = (struct Node *) malloc(sizeof(struct Node));

	if(NULL == pNewNode)
	{
		printf("Memory Allocation is Failed\n");
		return;
	}

	pNewNode->iData = iNo;

	if(*ppHead == NULL)
	{
		*ppHead = *ppTail = pNewNode;
		(*ppHead)->pPrev = *ppTail;
		(*ppTail)->pNext = *ppHead;
	}
    else
    {
        pNewNode -> pPrev = (*ppTail);
        (*ppTail) -> pNext = pNewNode;
        (*ppHead) -> pPrev = pNewNode;
        pNewNode -> pNext = (*ppHead);
        (*ppHead) = pNewNode;
    }
    
    pNewNode = NULL;
}

void InsertLast(struct Node **ppHead,struct Node **ppTail,int iNo)
{
	struct Node *pNewNode = NULL;

	pNewNode = (struct Node *) malloc(sizeof(struct Node));

	if(pNewNode == NULL)
	{
		printf("Memory Allocation is Falied.\n");
		return;
	}

	pNewNode->iData = iNo;

	if(*ppHead == NULL)
	{
		*ppHead = *ppTail = pNewNode;
		(*ppHead)->pPrev = *ppTail;
		(*ppTail)->pNext = *ppHead; 
	}
	else
	{
		pNewNode->pNext = *ppHead;
		pNewNode->pPrev = *ppTail;
		(*ppHead)->pPrev = pNewNode;
		(*ppTail)->pNext = pNewNode;
		*ppTail = pNewNode;
	}
	pNewNode = NULL;
}

void InsertAtPosition(struct Node **ppHead,struct Node **ppTail,int iNo,int iPos)
{
	int iCount;
	struct Node *pNewNode = NULL;
	struct Node *pTemp = NULL;

	iCount = CountNode(*ppHead,*ppTail);

	if( 0 >= iPos || iPos > iCount+1)
	{
		printf("Position is not valid.");
		return;
	}

	if(iPos == 1)
	{
		InsertFirst(ppHead,ppTail,iNo);
	}
	else if(iPos == iCount+1)
	{
		InsertLast(ppHead,ppTail,iNo);
	}
	else
	{
		pNewNode = (struct Node *) malloc(sizeof(struct Node));

		if(NULL == pNewNode)
		{
			printf("Memory Allocation is Failed.\n");
			return;
		}

		pTemp = *ppHead;
		iCount = 1;

		while(iCount != iPos-1)
		{
			iCount++;
			pTemp = (pTemp)->pNext;
		}

		pNewNode->iData = iNo;
		pNewNode->pNext = (pTemp)->pNext;
		pNewNode->pPrev = pTemp;
		(pTemp)->pNext->pPrev = pNewNode;
		(pTemp)->pNext = pNewNode;

		pTemp = NULL;
	}
}

int DeleteFirst(struct Node **ppHead,struct Node **ppTail)
{
	int iDelData; 

	if(NULL == *ppHead)
	{
		printf("Linked List is Empty.\n");
		return -1;
	}

	iDelData = (*ppHead)->iData;

	if(*ppHead == *ppTail)
	{
		(*ppHead)->pPrev = (*ppHead)->pNext = NULL;
		free(*ppHead);
		*ppHead = *ppTail = NULL;
	}
	else
	{
		(*ppTail)->pNext = (*ppHead)->pNext;
		(*ppHead)->pNext->pPrev = *ppTail;
		(*ppHead)->pNext = (*ppHead)->pPrev = NULL;
		free(*ppHead);
		*ppHead = (*ppTail)->pNext;
	}

	return iDelData;
}

int DeleteLast(struct Node **ppHead,struct Node **ppTail)
{
	int iDelData;

	if(NULL == *ppHead)
	{
		printf("Linnked List is Empty.\n");
		return -1;
	}

	iDelData = (*ppTail)->iData;

	if(*ppHead == *ppTail)
	{
		(*ppHead)->pNext = (*ppHead)->pPrev;
		free(*ppHead);
		*ppHead = *ppTail = NULL;
	}
	else
	{
		(*ppHead)->pPrev = (*ppTail)->pPrev;
		(*ppTail)->pPrev->pNext = *ppHead;
		(*ppTail)->pNext = (*ppTail)->pPrev = NULL;
		free(*ppTail);
		*ppTail = (*ppHead)->pPrev;
	}
	return iDelData;
}

int DeleteAtPosition(struct Node **ppHead,struct Node **ppTail,int iPos)
{
	int iDelData;
	int iCount;
	struct Node *pTemp = NULL;

	if(NULL == *ppHead)
	{
		printf("Linnked List is empty.\n");
		return -1;
	}

	iCount = CountNode(*ppHead,*ppTail);

	if(iPos <= 0 || iPos > iCount)
	{
		printf("Position is invalid.\n");
		return -1;
	}

	if(iPos == 1)
	{
		iDelData = DeleteFirst(ppHead,ppTail);
	}
	else if(iPos == iCount)
	{
		iDelData = DeleteLast(ppHead,ppTail);
	}
	else
	{
		pTemp = *ppHead;
		iCount = 1;

		while(iCount != iPos)
		{
			iCount++;
			pTemp = pTemp->pNext;
		}

		pTemp->pNext->pPrev = pTemp->pPrev;
		pTemp->pPrev->pNext = pTemp->pNext;

		iDelData = pTemp->iData;
		pTemp->pNext = pTemp->pPrev = NULL;
		free(pTemp);
		pTemp = NULL;
	}

	return iDelData;
}

int SearchFirstOccurence(struct Node *pHead, struct Node *pTail,int iKey)
{
	int iPos = 0;

	do
	{
		iPos++;
		if((pHead)->iData == iKey)
			return iPos;

		pHead = (pHead)->pNext;
	}while(pHead != (pTail)->pNext);

	return 0;
}

int SearchLastOccurence(struct Node *pHead,struct Node *pTail,int iKey)
{
	int iCount = 0;
	int iPos = 0;

	do{
		iCount++;

		if((pHead)->iData == iKey)
			iPos = iCount;

		pHead = pHead->pNext;
	}while(pHead != (pTail)->pNext);

	return iPos;
}

int SearchAllOccurence(struct Node *pHead,struct Node *pTail,int iKey)
{
	int iCount = 0;

	do{
		if((pHead)->iData == iKey)
			iCount++;

		pHead = (pHead)->pNext;
	}while(pHead != (pTail)->pNext);

	return iCount;
}

void PhysicalReverse(struct Node **ppHead,struct Node **ppTail)
{
	struct Node *pPrev = *ppTail;
	struct Node *pCurrent = *ppHead;
	struct Node *pNext = NULL;

	do{
		pNext = (pCurrent)->pNext;
		(pCurrent)->pNext = (pCurrent)->pPrev;
		(pCurrent)->pPrev = pNext;
		pPrev = pCurrent;
		pCurrent = pNext;
	}while(*ppHead != pCurrent);

	*ppTail = *ppHead;
	*ppHead = pPrev;
}

void ReverseDisplay(struct Node *pHead,struct Node *pTail)
{
	PhysicalReverse(&pHead,&pTail);
	Display(pHead,pTail);
	PhysicalReverse(&pHead,&pTail);
}

void ConcatList(struct Node **ppHead1,struct Node **ppTail1,struct Node **ppHead2,struct Node **ppTail2)
{
	if(*ppHead2 == NULL)
		return;
	else if(*ppHead1 == NULL)
	{
		*ppHead1 = *ppHead2;
		*ppTail1 = *ppTail2;
	}
	else
	{
		(*ppHead1)->pPrev = *ppTail2;
		(*ppTail2)->pNext = *ppHead1;
		(*ppTail1)->pNext = *ppHead2;
		(*ppHead2)->pPrev = *ppTail1;
		*ppTail1 = *ppTail2;
	}
	
	*ppHead2 = *ppTail2 = NULL;
	return;
}

void ConcatAtPosition(struct Node **ppHead1,struct Node **ppTail1,struct Node **ppHead2,struct Node **ppTail2,int iPos)
{
	int iCount = 0;
	struct Node *pTemp = NULL;
	iCount = CountNode(*ppHead1,*ppTail1);

	if(iPos <= 0 || iPos > iCount+1)
	{
		printf("Position is not valid.");
		return;
	}

	if(iPos == iCount+1)
	{
		ConcatList(ppHead1,ppTail1,ppHead2,ppTail2);
	}
	else if(iPos == 1)
	{
		ConcatList(ppHead2,ppTail2,ppHead1,ppTail1);
		*ppHead1 = *ppHead2;
		*ppTail1 = *ppTail2;
		*ppHead2 = *ppTail2 = NULL;
	}
	else
	{
		pTemp = *ppHead1;
		iCount = 1;

		while(iPos-1 != iCount)
		{
			iCount++;
			pTemp = (pTemp)->pNext;
		}

		(*ppHead2)->pPrev = pTemp;
		(*ppTail2)->pNext = (pTemp)->pNext;
		(pTemp)->pNext->pPrev = *ppTail2;
		(pTemp)->pNext = *ppHead2;

		*ppHead2 = *ppTail2 = pTemp = NULL;
	}
}

int CountNode(struct Node *pHead,struct Node *pTail)
{
	int iCount = 0;

	if(NULL == pHead)
		return 0;

	do
	{
		iCount++;
		pHead = (pHead)->pNext;
	}while(pHead != (pTail)->pNext);

	return iCount;
}

void DeleteAll(struct Node **ppHead,struct Node **ppTail)
{
	if(NULL == *ppHead)
		return;

	do{
		(*ppTail)->pNext = (*ppHead)->pNext;
		(*ppHead)->pNext->pPrev = *ppTail;
		(*ppHead)->pNext=(*ppHead)->pPrev = NULL;
		free(*ppHead);
		*ppHead = (*ppTail)->pNext;
	}while(*ppHead != *ppTail);

	free(*ppTail);
	*ppHead = *ppTail = NULL;
}

void Display(struct Node *pHead,struct Node *pTail)
{
	if(NULL == pHead)
	{
		printf("Linked List is Empty.\n");
		return;
	}

	do{
		printf("|%d|->",(pHead)->iData);
		pHead = (pHead)->pNext;
	}while((pTail)->pNext != pHead);
}