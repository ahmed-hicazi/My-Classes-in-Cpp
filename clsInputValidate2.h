#pragma once
#include <iostream>
#include <string>
#include <limits>
using namespace std;

template <typename T>

class clsInputValidate2
{
public:


	static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To);
	}

	static T ReadNumber(string ErrorMessage = "Invalid Number , Enter again: ")
	{
		T Num;
		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Num;
	}

	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, enter again: ")
	{
		T Num=ReadNumber();
		while (!IsNumberBetween(Num, From, To))
		{
			cout << ErrorMessage;
			Num = ReadNumber();
		}
		return Num;
	}

};

