#include<iostream>
using namespace std;
void bubble_sort(int arr[],int num)
{	/*
		best case complexity  = O(n)
		average case complexity = O(n^2)
		worst case complexity = O(n^2)
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
	//printing the sorted array
	cout<<"sorted  array = \n";
	for(int i=0;i<num;i++)cout<<arr[i]<<endl;
}
void improvised_bubble_sort(int arr[],int num)
{
/*
		best case complexity  = O(n)
		average case complexity = O(n^2)
		worst case complexity = O(n^2)
	*/
	//improvised bubble sort algo
	for(int i=0;i<num-1;i++)
	{int flag =0
		for(int j=0;j<num-i-1;j++)
		{
		
			if(arr[j]>arr[j+1])
			{
				int temp ;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag=1;
			}
		}
		if(flag==0)break;
	}
	//printing the sorted array
	cout<<"sorted  array = \n";
	for(int i=0;i<num;i++)cout<<arr[i]<<endl;

}
void insertion_sort(int arr[],int num)
{
	/*
		best case complexity  = O(n)
		average case complexity = O(n^2)
		worst case complexity = O(n^2)
	*/
	//insertion sort algo
	for(int i=0;i<num;i++)
	{
		int value = arr[i];
		int pos = i;
		while(pos>0 && value<arr[pos -1])
		{
			int temp;
			temp = arr[pos -1];
			arr[pos - 1] = arr[i];
			
			arr[i]  = temp;
			value = arr[i];
			pos--;
			
		}
	}
	//printing the sorted array
	cout<<"sorted  array = \n";
	for(int i=0;i<num;i++)cout<<arr[i]<<endl;
	
}
void selection_sort(int arr[],int num)
{
	/*
		best case complexity  = O(n^2)
		average case complexity = O(n^2)
		worst case complexity = O(n^2)
	*/
	//selection sort algo
	for(int i=0;i<num-1;i++)
	{
		for(int j = num;j>i;j--)
		{
			if(arr[i]>arr[j])
			{
				int temp;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		
	}
	//printing the sorted array
	cout<<"sorted  array = \n";
	for(int i=0;i<num;i++)cout<<arr[i]<<endl;	
}
int main()
{
	int arr[5000],num;
	cout<<"enter the number of elements in the array\n";
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cout<<"enter any num\n";
		cin>>arr[i];
	}
	cout<<"bubble sort\n";
	 bubble_sort(arr,num);
	 cout<<"improvised bubble sort\n";
	 improvised_bubble_sort(arr,num);
	 cout<<"insertion sort\n";
	 insertion_sort(arr,num);
	 cout<<"selection sort\n";
	 selection_sort(arr,num);
	 return 0;
}
