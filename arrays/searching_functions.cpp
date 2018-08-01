#include<iostream>
using namespace std;
void linear_search(int arr[],int num,int value)
{
	/*
		best case complexity  = O(1)
		average case complexity = O(n)
		worst case complexity = O(n)
	*/
	int flag =0,pos;
	//linear search algo
	for(int i =0;i<num;i++)
	{
		if(value == arr[i])
		{
			flag=1;
			pos =i;
			break;
		}
	}
	if(flag ==1)
	{
		cout<<"element found at "<<pos+1<<"th position"<<endl;
	}
	else
	{
		cout<<"element not found\n";
	}
}
void binary_search(int arr[],int num,int value)
{
	/*
		best case complexity  = O(1)
		average case complexity = O(log2 n)
		worst case complexity = O(log2 n)
	*/
	//bubble sort algo
	for(int i=0;i<num-1;i++)
	{
		for(int j=0;j<num-i-1;j++)
		{
		
			if(arr[j]>arr[j+1])
			{
				int temp ;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	//binary search algo
	int beg,end,mid,flag=0,pos;
	beg =0;
	end =num;
	mid = (end + beg)/2;
		while(arr[mid] != value &&beg<=end)
		{
			if(value>arr[mid])
			{
				beg = mid +1;
			}
			else
			{
				end = end +1;
			}
			mid = (end + beg)/2;
			if(arr[mid] == value)
			{
				flag =1;
				pos = mid;
			}
		}
		if(flag ==1)
		{
			cout<<"element found at "<<pos+1<<"th position\n";
		}
		else
		{
			cout<<"element not found\n";
		}
	
}
int main()
{
	int arr[5000],num,value;
	cout<<"enter the number of elements in the array\n";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"enter any num\n";
		cin>>arr[i];
	}
	cout<<"enter the value you want to search \n";
	cin>>value;
	linear_search(arr,num,value);
	binary_search(arr,num,value);
	return 0;
}
