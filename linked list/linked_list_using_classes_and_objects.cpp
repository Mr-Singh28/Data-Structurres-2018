#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
}*head;

class Linked_List
{
	public:
		void insert_at_begining(int value)
		{
			Node *temp;
			temp = new Node;
			temp->data = value;
			if(head == NULL)
			{
				temp->next = NULL;
				head  = temp;
			}
			else
			{
				temp->next = head;
				head = temp;
			}
		}
		void insert_at_end(int value)
		{
			Node *temp,*temp1;
			temp = head;
			temp1->data =value;
			temp1->next=NULL;
			if(head ==NULL)
			{
				head = temp1;
			}
			else
			{
				while(temp->next!=NULL)
				{
					temp = temp->next;
				}
				temp->next =temp1;
			}
		}
		void print()
		{
			Node *temp;
			temp = head;
			if(head==NULL)
			{
				cout<<"empty list\n";
				
			}
			else
			{
				while(temp != NULL)
				{
					cout<<temp->data<<endl;
					temp= temp->next;
				}
			}
		}
		void delete_from_begining()
		{
			Node *temp;
			temp = head;
			if(head == NULL)
			{
				cout<<"underflow\n";
			}
			else
			{
				head = temp->next;
				delete temp;
			}
		}
		void delete_from_end()
		{
			Node *temp,*temp1;
			temp = head;
			if(head==NULL)
			{
				cout<<"underflow\n";
			}
			else if(temp->next ==NULL)
			{
				head = NULL;
				delete temp;
			}
			else
			{
				while(temp->next !=NULL)
				{
					temp1 = temp;
					temp =temp->next;
				}
				temp1->next = NULL;
				delete temp;
			}
		}
};
int main()

{
	Linked_List obj;
	bool cond = true;
	while(cond)
	{
		cout<<"press 1 to  insert at the begining\n";
		cout<<"press 2 to insert at the end\n";
		cout<<"press 3 to delete form begining\n";
		cout<<"press 4 to delete from end\n";
		cout<<"press 5 to print the list\n";
		cout<<"press 6 to exit\n";
		int choice;
		int num;
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					cout<<"enter the number you want to add\n";
					cin>>num;
					obj.insert_at_begining(num);
					break;
				}
			case 2:
				{
					cout<<"enter the number you want to add\n";
					cin>>num;
					obj.insert_at_end(num);
					break;
				}
			case 3:
				{
					obj.delete_from_begining();
					cout<<"deleted\n";
					break;
				}
			case 4:
				{
					obj.delete_from_end();
					cout<<"deleted\n";
					break;
				}
			case 5:
				{
					obj.print();
					break;
				}
			case 6:
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
