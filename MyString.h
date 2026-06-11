#pragma once
#include <stack>
class MyString
{

private:

	stack<string>_Undo;
	stack<string>_Redo;
	string _Value;


public:

	void setValue(string value)
	{

		_Undo.push(_Value);
		_Value = value;
	}

	string getValue()
	{
		return _Value;
	}

	__declspec(property(get = getValue, put = setValue)) string value;


	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_Value);
			_Undo.pop();
			_Value = _Undo.top();
		}
		
	}

	void Redo()
	{

		if (!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}

	}


};

