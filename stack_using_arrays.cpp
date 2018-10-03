#include<iostream>
using namespace std;
class stack
{
	private:
		int arr[1000],num,top=0,value;
	public:
		void size_of_stack(int value)
		{
			cout<<"enter the number of elements"<<endl;
			num = value;
		}
		void push()
		{
			if(top==num)
			{
				cout<<"stack is full"<<endl;
			}
			else
			{
				cout<<"enter the element :"<<endl;
				cin>>value;
				arr[top] = value;
				top++;
			}
		}
		void pop()
		{
			if(top == 0)
			{
				cout<<"stack is empty"<<endl;
			}
			else
			{
				top--;
			}
		}
		void traverse()
		{
			cout<<"the elements in the stack are :-"<<endl;
			for(int i=top-1;i>=0;i--)
			{
				cout<<arr[i]<<endl;
			}
		}
		void top()
		{
			if(top ==-1)
			{
				cout<<"Empty stack\n";
			}
			else
			{
				cout<<arr[top]<<endl;
			}
		}
};
int main()
{
	stack obj;
	int value;
	bool cond=true;
	cout<<"enter the size of the stack"<<endl;
	cin>>value;
	obj.size_of_stack(value);
	while(cond)
	{
		int choice;
		cout<<"press 1 to push"<<endl;
		cout<<"press 2 to pop"<<endl;
		cout<<"press 3 to display"<<endl;
		cout<<"press 4 to display top"<<endl;
		cout<<"press 5 to exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					
					obj.push();
					break;
				}
			case 2:
				{
					obj.pop();
					cout<<"element poped from stack"<<endl;
					break;
				}
			case 3:
			{
				obj.traverse();
				break;
				
			}	
			case 4:
				{
					obj.top();
					break;
				}
			case 5:
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
