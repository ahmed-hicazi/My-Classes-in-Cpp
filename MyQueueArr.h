#pragma once

#include "DynamicArray.h"
#include <iostream>
using namespace std;

template <class T>

class MyQueueArr 
{

public:

	DynamicArray <T> _List;


	void push(T value)
	{
		_List.InsertAtEnd(value);
	}

	void pop()
	{
		_List.DeleteFirstItem();
	}

	T front()
	{
		return _List[0];
	}

	T back()
	{
		return _List[Size() - 1];
	}

	int Size()
	{
		return	_List.Size();
	}

	void Print()
	{
		_List.Print();
	}

	void Reverse()
	{
		_List.Reverse();
	}

	T GetItem(int index)
	{
		return _List[index];
	}

	void UpdateItem(int index, T value)
	{
		_List.SetItem(index, value);
	}

	bool IsEmpty()
	{
		return _List.IsEmpty();
	}

	bool InsertAfter(int index, T value)
	{
		return	_List.InsertAfter(index, value);
	}

	bool InsertAtFront(T value)
	{
		return _List.InsertAtBeginning(value);
	}

	bool InsertAtBack(T value)
	{
		return _List.InsertAtEnd(value);
	}

	void Clear()
	{
		_List.Clear();
	}


};

