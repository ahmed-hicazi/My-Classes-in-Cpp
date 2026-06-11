#pragma once

template <class T>

class node
{


public:

	T Data;
	node* Next;


};

template <class T>


class Stack
{

	node<T>* Head;

public:

	Stack()
	{
		Head = NULL;
	}

	bool IsEmpty()
	{
		return (Head == NULL);
	}


	T Top()
	{
		if (Head == NULL) return IsEmpty();

		return (Head->Data);
	}

	void Push(T Data)
	{
		node<T>* new_node = new node<T>();


		new_node->Data = Data;
		new_node->Next = Head;
		Head = new_node;
	}

	void Pop()
	{
		if (Head == NULL) return;

		node<T>* Current = Head;
		Head = Current->Next;
		delete Current;
	}

	~Stack()
	{
		while (Head != NULL)
		{
			Pop();
		}

	}


};

