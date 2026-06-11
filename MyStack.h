#pragma once
#include "MyQueue.h"
#include <iostream>
using namespace std;

template <class T>

class MyStack : public MyQueue <T>
{

public:

	void push(T value)
	{
		MyQueue<T>::_List.InsertAtBeginning(value);
	}

	T top()
	{
		return	MyQueue<T>::front();
	}

	T bottom()
	{
		return	MyQueue<T>::back();
	}


};

