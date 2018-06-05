#include<iostream>
#include<cstdlib>
using namespace std;
class node{
	double data;
	node * next;
	public:
	node(double d)
	{
		data=d;
		next=NULL;
	}
	double getdata()
	{
		return data;
	}
	void setdata(double d)
	{
		data=d;
	}
	friend class linkedList;
	friend void bucketSort(double *,int);
};
class linkedList{
	node * head;
	node * tail;
	public:
	linkedList()
	{
		head=tail=NULL;
	}
	~linkedList()
	{
		node * temp;
		while(head)
		{
			temp=head;
			head=head->next;
			delete temp;
		}
		tail=NULL;
	}
	void insertNode(double d)
	{
		if(head==NULL&&tail==NULL)
		{
			head=tail=new node(d);
		}
		else
		{
			tail->next=new node(d);
			tail=tail->next;
		}
	}
	void sortLinkedList()
	{
		head=insertionSort(head);
		node * temp=head;
		while(temp&&temp->next)
		{
			temp=temp->next;
		}
		tail=temp;
	}
	static node * insertionSort(node * head)
	{
		if(head==NULL)
		{
			return NULL;
		}
		head->next=insertionSort(head->next);
		node * temp=head;
		node * itr=head->next;
		node * parent=head;
		while(itr&&itr->data<temp->data)
		{
			parent=itr;
			itr=itr->next;
		}
		if(parent!=head)
		{
			head=head->next;
			temp->next=parent->next;
			parent->next=temp;
		}
		return head;
	}
	friend void bucketSort(double *,int);
};
void bucketSort(double * arr,int size)
{
	linkedList array[1000];
	int ind=0,maxsize=-1,index,minsize;
	for(int i=0;i<size;i++)
	{
		index=abs(int(size*arr[i]));
		if(index>maxsize)
		{
			maxsize=index;
		}
		else if(index<minsize)
		{
			minsize=index;
		}
		array[index].insertNode(arr[i]);
	}
	for(int i=minsize;i<=maxsize;i++)
	{
		array[i].sortLinkedList();
		node * temp=array[i].head;
		while(temp)
		{
			arr[ind++]=temp->getdata();
			temp=temp->next;
		}
	}
}
int main()
{
	cout<<"*******Bucket Sort*******"<<endl;
	double arr[1000];
	int size;
	cout<<"Enter the size of the array: ";
	cin>>size;
	cout<<"Enter the elements: "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	bucketSort(arr,size);
	cout<<"The sorted array is: "<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
