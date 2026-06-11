#pragma once

#include "DblLinkedList.h"
#include <iostream>
using namespace std;

template <class T>


class MyQueue
{

protected:
	DblLinkedList <T> _List;

public:


	void push(T value)
	{
		_List.InsertAtEnd(value);
	}

	void pop()
	{
		_List.DeleteFirstNode();
	}

	int size()
	{
		return	_List.Size();
	}

	T front()
	{
		return _List.GetItem(0);
	}

	T back()
	{
		return _List.GetItem(size() - 1);
	}

	bool IsEmpty()
	{
		return _List.IsEmpty();
	}
	
	T GetItem(int index)
	{
		return _List.GetItem(index);
	}

	void InsertAtFront(T value)
	{
		_List.InsertAtBeginning(value);

	}

	void InsertAtBack(T value)
	{
		_List.InsertAtEnd(value);
	}

	bool InsertAfter(int index, T value)
	{
		return _List.InsertAfter(index, value);
	}

	bool UpdateItem(int index, T value)
	{
		return _List.UpdateItem(index, value);
	}

	void Reverse()
	{
		_List.Reverse();
	}


	void Clear()
	{
		_List.Clear();
	}

	void Print()
	{
		_List.PrintList();
	}

};

