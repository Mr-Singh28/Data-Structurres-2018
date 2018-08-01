#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
}*head;//declaring the start or the head node of the linked list
void insert_at_begining(int value)
{
	Node *temp = new Node;
	temp->data = value;//assinging the value to be inserted
	if(head == NULL)
	{
		//if the list is empty
		//initialize the temp with the head node
		temp->next = NULL;
		head = temp;
	}
	else
	{
		//give the address of head in temp and then assign emp to head
		temp->next = head;
		head = temp;
	}
}
void insert_at_end(int value)
{
	Node *temp,*temp1;
	temp = new Node;
	temp1 = head;
	temp->data = value;
	temp->next = NULL;
	if(head==NULL)
	{
		//if the list is empty
		//initialize the temp with the head node
		head = temp;
	}
	else
	{
		//traversing through the list
		while(temp1->next!=NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next=temp;//assigning the last term's address to the input 
		//remember when addding at the end of the linked list last term should contain NULL  in its temp->next
	}
}
void delete_from_begining()
{
	Node *temp;
	//assign head to a temporary variable so that its address is not lost
	temp = head;
	if(head==NULL)
	{
		//if the list is empty there is nothing to delete
		cout<<"underflow\n";
	}
	else
	{
		//assign next term to head and then delete the  temp(the previous head)
		head = temp->next;
		delete temp;
	}
}
void delete_from_end()
{
	Node *temp,*temp1;
	temp =head;
	if(head == NULL)
	{
		//if the list is empty there is nothing to delete
		cout<<"underflow\n";
	}
	else if(temp->next == NULL)
	{
		temp = head;
		head = NULL;
		delete temp;
	}
	else
	{
		//traversing the list and storing the previous addresses in another variable
		while(temp->next !=NULL)
		{
			temp1 = temp;
			temp = temp->next;
		}
		//assign the next address of the variable to NUll and delete the temp
		temp1->next = NULL;
		delete temp;
	}
}
void sort()
{
	Node *temp,*temp1;
	temp = head;
	while(temp != NULL)
	{
		temp1 = temp->next;
		while(temp1 != NULL)
		{
			if(temp->data>temp1->data)
			{
				int i = temp->data;
				temp->data = temp1->data;
				temp1->data = i;
				
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
}
void remove_duplicate()
{
	Node *temp,*temp1,*temp2;
	temp = head;
	while(temp->next != NULL)
	
	{
		temp1 = temp->next;
		if(temp->data == temp1->data)
		{
			temp->next = temp1->next;
			
			delete temp1;
		}
		else
		{
			temp = temp->next;
		}
	}
}
void print()
{
	Node *temp  = head;
	//traversing the list
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp  = temp->next;
		
	}
}

void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node *current = head;
        Node *prev = NULL, *next = NULL;
 
 
        while (current != NULL)
        {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
    
int main()

{
	bool cond = true;
	while(cond)
	{
		cout<<"press 1 to  insert at the begining\n";
		cout<<"press 2 to insert at the end\n";
		cout<<"press 3 to delete form begining\n";
		cout<<"press 4 to delete from end\n";
		cout<<"press 5 to print the list\n";
		cout<<"press 6 to reverse\n";
		cout<<"press 7 to sort the list\n";
		cout<<"press 8 to remove the duplicates\n";
		cout<<"press 9 to exit\n";
		int choice;
		int num;
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					cout<<"enter the number you want to add\n";
					cin>>num;
					insert_at_begining(num);
					break;
				}
			case 2:
				{
					cout<<"enter the number you want to add\n";
					cin>>num;
					insert_at_end(num);
					break;
				}
			case 3:
				{
					delete_from_begining();
					cout<<"deleted\n";
					break;
				}
			case 4:
				{
					delete_from_end();
					cout<<"deleted\n";
					break;
				}
			case 5:
				{
					print();
					break;
				}
			case 6:
				{
					reverse();
					cout<<"reversed\n";
					break;
				}
			
			case 7:
				{
					sort();
					cout<<"sorted\n";
					break;
				}
			case 8:
				{
					remove_duplicate();
					cout<<"removed\n";
					break;
				}
			case 9:
				{
					cond = false;
					break;
				}
			default:
				{
					cond = false;
					break;
				}
		}
	}
	return 0;
}
