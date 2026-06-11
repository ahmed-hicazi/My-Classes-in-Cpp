#pragma once
#include "MyQueueArr.h"


template <class T>

class MyStackArr : public MyQueueArr <T>
{


public:

	void push(T value)
	{
		MyQueueArr<T>::_List.InsertAtBeginning(value);
	}

	T top()
	{
		return	MyQueueArr<T>::front();
	}

	T bottom()
	{
		return	MyQueueArr<T>::back();
	}


};

