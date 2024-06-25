#include "List_Server.h"

int main(void)
{
	int iChoice1;
	int iChoice2;
	int iChoice3;
	int iCount;
	int iData;
	int iPos;
	int iPos2;

	CList obj1;
	CList obj2;
	
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
					cout << "\nDelete Data is " << obj1.DeleteAtPosition(iPos);
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
						obj2 = CList();
					}
					else
					{
						obj1.ConcatAtPosition(obj2,iPos2);
						obj2 = CList();
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
