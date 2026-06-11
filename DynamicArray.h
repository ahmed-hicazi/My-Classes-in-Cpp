#pragma once
#include <iostream>
using namespace std;
template <class T>

class DynamicArray
{
protected:

	int _Size;
	T* _TempArray;
	T* OriginalArray;


public:




	DynamicArray(int size)
	{
		if (size < 0)
			size = 0;

		OriginalArray = new T[size];
		_Size = size;
	}

	DynamicArray()
	{ }

	bool SetItem(int index, T value)
	{
		if (index >= _Size || index < 0) return false;

		OriginalArray[index] = value;
		return true;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	int Size()
	{
		return _Size;
	}

	void Print()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << *(OriginalArray + i) << " ";
		}

	}

	void Resize(int NewSize)
	{
		if (NewSize == _Size) return;

		if (NewSize < 0) NewSize = 0;

		_TempArray = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;
		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}

	T& operator[](int index)
	{
		return OriginalArray[index];
	}

	void Reverse()
	{
		_TempArray = new T[_Size];

		int Counter = 0;
		for (int i = _Size - 1; i >= 0; i--)
		{
			_TempArray[Counter] = OriginalArray[i];
			Counter++;
		}
		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}


	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(int index)
	{
		if (index >= _Size || index < 0) return false;

		_Size--;
		_TempArray = new T[_Size];
		int Counter = 0;
		for (int i = 0; i < _Size; i++)
		{
			if (index == i) Counter++;

			_TempArray[i] = OriginalArray[Counter];
			Counter++;
		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	bool DeleteItem(T value)
	{
		return	DeleteItemAt(Find(value));
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == value) return i;
		}
		return -1;
	}

	bool InsertAt(int index, T value)
	{
		if (index > _Size || index < 0) return false;

		_Size++;

		_TempArray = new T[_Size];

		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];

		}

		_TempArray[index] = value;

		for (int i = index + 1; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i - 1];

		}
		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	bool InsertAtBeginning(T value)
	{
		return InsertAt(0, value);
	}

	bool InsertAtEnd(T value)
	{
		return InsertAt(_Size, value);
	}

	bool InsertAfter(int index,T value)
	{
		if (index >= _Size)
			return InsertAt(_Size - 1, value);
		else
			return InsertAt(index + 1, value);
	}

	bool InsertBefore(int index, T value)
	{
		if (index < 1)
			return InsertAt(0, value);
		else
			return InsertAt(index - 1, value);
	}

	~DynamicArray()
	{
		delete[]OriginalArray;
	}




};

