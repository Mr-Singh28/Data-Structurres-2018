#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class graph
{
    int **AM;
    int vertices;
public:
    graph(int vert)
    {
        vertices=vert;
        AM=new int *[vertices];
        for(int i=0;i<vertices;++i)
            AM[i]=new int[vertices];
        for(int i=0;i<vertices;++i)
            for(int j=0;j<vertices;++j)
                AM[i][j]=0;
    }
    void create_graph();
    void in_degree(int);
    void out_degree(int);
    void depth_first_traversal();
    void display_graph();
    void get_neighbours(int *,int);
    void depth_first_traversal1();
    void breadth_first_traversal();
};
void graph::create_graph()
{
    char op;
    do
    {
        cout<<"Enter vertices you want to connect:"<<endl;
        cout<<"Enter first vertex: ";
        int vert1;
        cin>>vert1;
        cout<<"Enter second vertex: ";
        int vert2;
        cin>>vert2;
        AM[vert1][vert2]=1;
        AM[vert2][vert1]=1;
        cout<<"Do you want to continue(y/n): ";
        cin>>op;
    }
    while(op=='y' || op=='Y');
}
void graph::in_degree(int in)
{
    int count=0;
    for(int i=0;i<vertices;++i)
        if(AM[in][i]==1)
            ++count;
    cout<<"In degree of "<<in<<" is "<<count;
}
void graph::out_degree(int out)
{
    int count=0;
    for(int i=0;i<vertices;++i)
        if(AM[i][out]==1)
            ++count;
    cout<<"In degree of "<<out<<" is "<<count;
}
void graph::get_neighbours(int *arr,int vert)
{
    int j=0;
    for(int i=0;i<vertices;++i)
        if(AM[vert][i]==1)
        {
            arr[j]=i;
            ++j;
        }
}
void graph::depth_first_traversal()
{
    cout<<"Enter source vertex: ";
    int vert;
    cin>>vert;
    stack<int>s;
    int track[vertices]={0};
    s.push(vert);
    cout<<"Depth first traversal is:"<<endl;
    while(!s.empty())
    {
        vert=s.top();
        if(track[vert]==0)
        {
            cout<<vert<<" ";
            track[vert]=1;
        }
        int arr[vertices];
        for(int i=0;i<vertices;++i)
            arr[i]=-1;
        get_neighbours(arr,vert);
        int i;
        for(i=0;track[arr[i]]==1;++i);
        int min_neighbor=arr[i];
        if(min_neighbor==-1)
            s.pop();
        else
            s.push(min_neighbor);
    }
}
void graph::depth_first_traversal1()
{
    cout<<"Enter source vertex: ";
    int vert;
    cin>>vert;
    stack<int>s;
    int track[vertices]={0};
    s.push(vert);
    track[vert]=1;
    cout<<"Depth first traversal is:"<<endl;
    cout<<vert<<" ";
    while(!s.empty())
    {
        int flag=0;
        int store=s.top();
        for(int i=0;i<vertices;++i)
        {
            if(track[i]==0)
            {
                if(AM[store][i]==1)
                {
                    flag=1;
                    track[i]=1;
                    s.push(i);
                    cout<<i<<" ";
                    break;
                }
            }
        }
        if(flag==0)
            s.pop();
    }
}
void graph::breadth_first_traversal()
{
    cout<<"Enter source vertex: ";
    int vert;
    cin>>vert;
    queue<int>q;
    int track[vertices]={0};
    q.push(vert);
    track[vert]=1;
    cout<<"Breadth first traversal is:"<<endl;
    while(!q.empty())
    {
        int store=q.front();
        q.pop();
        cout<<store<<" ";
        for(int i=0;i<vertices;++i)
        {
            if(track[i]==0)
            {
                if(AM[store][i]==1)
                {
                    track[i]=1;
                    q.push(i);
                }
            }
        }
    }
}
void graph::display_graph()
{
    cout<<"Graph:"<<endl;
    for(int i=0;i<vertices;++i)
    {
        for(int j=0;j<vertices;++j)
            cout<<AM[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    cout<<"Enter vertices of graph: ";
    int vert;
    cin>>vert;
    graph obj(vert);
    int ch;
    do
    {
        cout<<"\nEnter\n1 to create graph\n2 for depth first traversal\n3 for breadth first traversal\n4 to calculate in degree\n5 to calculate out degree\n6 to display graph\n0 to exit:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            obj.create_graph();
            cout<<"Graph created"<<endl;
            break;
        case 2:
            obj.depth_first_traversal1();
            break;
        case 3:
            obj.breadth_first_traversal();
            break;
        case 4:
            cout<<"Enter element whose in degree you want to calculate: ";
            int in;
            cin>>in;
            obj.in_degree(in);
            break;
        case 5:
            cout<<"Enter element whose in degree you want to calculate: ";
            int out;
            cin>>out;
            obj.out_degree(out);
            break;
        case 6:
            obj.display_graph();
            break;
        case 0:
            ch=0;
            break;
        default:
            cout<<"Invalid input,try aagin"<<endl;
        }
    }
    while(ch!=0);
    return 0;
}
