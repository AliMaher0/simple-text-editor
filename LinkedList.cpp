#include "LinkedList.h"
#include <assert.h>
#include <iostream>
#include<sstream>
#include <string>
#include <vector>
using namespace std;

template <class T>
Node<T>::Node()
{
	value=0;
	next=0;
}

template <class T>
Node<T>::Node(T val)
{
	value=val;
	next=0;
}

template <class T>
LinkedList<T>::LinkedList(void)
{
	head=tail=0;
	count=0;
}

template <class T>
int LinkedList<T>::Length()
{
	return count;
}

template <class T>
void LinkedList<T>::Append(T val)
{
	Node<T>* newNode=new Node<T>(val);
	if(head==0)
		head=tail=newNode;
	else
	{
		tail->next=newNode;
		tail=newNode;
	}
	count++;
	
}

template <class T>
T LinkedList<T>::At(int pos)
{
	assert(pos>=0&&pos<=count);
	Node<T>* tmp=head;
	for(int i=0;i<pos;i++)
		tmp=tmp->next;
	return tmp->value;
}

template <class T>
void LinkedList<T>::InsertAt(int pos, T val)
{
	assert(pos>=0&&pos<=count);
	Node<T>* tmp=head;
	Node<T>* newNode=new Node<T>(val);
	if(pos==0)
	{
		newNode->next=head;
		head=newNode;
	}
	else
	{
		for(int i=0;i<pos-1;i++)
			tmp=tmp->next;
	
		newNode->next=tmp->next;
		tmp->next=newNode;
	}
	count++;
}




template <class T>
void LinkedList<T>::DeleteAt(int pos)
{
	assert(pos>=0&&pos<=count);
	Node<T>* tmp=head;
	if(pos==0)
	{
		head=head->next;
		delete tmp;
	}
	else
	{
		for(int i=0;i<pos-1;i++)
			tmp=tmp->next;
		Node<T>* del=tmp->next;
		tmp->next=del->next;
		delete del;
		if(pos==count-1)
			tail=tmp;
	}
	count--;
}
template <class T>
void LinkedList<T>::display_all()
{
	Node<T>* temp = head;
	
	while(temp!=NULL)
	{

		cout << temp->value << endl;
		temp = temp->next;
	

	}
}





template <class T>
LinkedList<T>::~LinkedList(void)
{
	while (head)
	{
		Node<T>* p = head;
		delete (p);
		head = head->next;
		cout << head->value;
	}
}
template <class T>
void LinkedList<T>::findall(T w)
{
	int i = 0;
	cout << "Find text at index: ";
	while (i < count)
	{
		string s1 = At(i);
		if (s1 != "")
		{
			istringstream iss(s1);
			vector<string> result;
			for (string s; iss >> s;)
				result.push_back(s);
			int n = result.size();
			for (int j = 0; j < n; j++)
			{
				if (result[j] == w)
					cout << i <<" ";
			}
		}
		i++;




	}
}


template <class T>
void LinkedList<T>::replace(T w , T x)
{
	int i = 0;
	bool search = 0;
	while (i < Length())
	{
		string collect = "";
		string s1 = At(i);

		if (s1 != "")
		{

			istringstream iss(s1);
			vector<string> result;
			for (string s; iss >> s;)
				result.push_back(s);
			int n = result.size();
			for (int j = 0; j < n; j++)
			{
				if (result[j] == w)
				{
					result[j] = x;
					search = 1;
				}
				collect = collect + result[j]+' ';
			}
			if (search == 1)
			{
				DeleteAt(i);
				InsertAt(i, collect);
			}
		}

		i++;
	}


}


