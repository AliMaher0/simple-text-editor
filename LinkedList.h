#pragma once
#include <string>
template <class T>
class Node
{
	public:
	Node<T>* next;
	T value;

	Node();
	Node(T val);
};

template <class T>
class LinkedList
{
	int count;
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList();
	int Length();
	
	void display_all();
	T At(int);
	void InsertAt(int,T);
	void Append(T);
	void DeleteAt(int);
	void findall(T s);
	void replace(T a, T b);
	~LinkedList(void);
};

 