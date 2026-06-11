#pragma once
#include <iostream>
using namespace std;

template <class T>

class DblLinkedList 
{ 

protected:
	int _Size = 0;
	
public:

	class Node
	{

	public:
		T value;
		Node* next;
		Node* prev;	
	};

	Node* head = NULL;

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	int Size()
	{
		return _Size;
	}

  void InsertAtBeginning(T value)
  {
	  Node* newnode = new Node;
	  newnode->value = value;
	  newnode->next = head;
	  newnode->prev = NULL;
	 
	  if (head != NULL)
	  {
		  head->prev = newnode;
	  }
	  head = newnode;
	  _Size++;
  }

  void PrintList()
  {
	  Node* Current = head;
	  
	  if (Current == NULL) return;

	  while (Current != NULL)
	  {
		  cout << Current->value << " ";
		  Current = Current->next;
	  }
		  cout << "\n";
  }

  Node* Find(T value)
  {
	  Node* Current = head;
	  while (Current != NULL)
	  {
		  if (Current->value == value)
			  return Current;

		  Current = Current->next;
	  }
	  return NULL;
  }

  void InsertAfter(Node* Current, T Value)
  {

	  if (Current == NULL) return;

	  Node* newnode = new Node;
	  newnode->value = Value;
	  newnode->next = Current->next;
	  newnode->prev = Current;

	  if (Current->next != NULL)
	  {
		  Current->next->prev = newnode;
	  }
	  Current->next = newnode;
	  _Size++;
  }

  bool InsertAfter(int index, T Value)
  {

	  Node* ItemNode = GetNode(index);

	  if (ItemNode != NULL)
	  {
		  InsertAfter(ItemNode, Value);
		  return true;
	  }
	  else
	  {
		  return false;
	  }
  }

  void InsertAtEnd(T Value)
  {

	  Node* newnode = new Node;
	  newnode->value = Value;
	  newnode->next = NULL;

	  if (head == NULL)
	  {
		  newnode->prev = NULL;
		  head = newnode;
	  }
	  else
	  {
		  Node* Current = head;
		  while (Current->next != NULL)
		  {
			  Current = Current->next;
		  }
		  Current->next = newnode;
		  newnode->prev = Current;
	  }
	  _Size++;
  }

  void DeleteNode(T Value)
  {

	  if (head == NULL) return;

	  Node* Current = head;

	  if (head->value == Value)
	  {
		  if (Current->next != NULL)
		  {
			  head = Current->next;
			  head->prev = NULL;
			  delete Current;
		  }
		  else
		  {
			  delete head;
			  head = nullptr;
		  }  
	  }
	  else
	  {
		  while (Current != NULL)
		  {
			  if (Current->value == Value)
				  break;
			  Current = Current->next;
		  }

		  if (Current == NULL) return;

		  if (Current->prev != NULL)
		  {
			  Current->prev->next = Current->next;
		  }

		  if (Current->next != NULL)
		  {
			  Current->next->prev = Current->prev;
		  }
		  delete Current;
	  }
	  _Size--;

  }

  void DeleteNode(Node*& NodeToDelete)
  {
	  if (head == NULL || NodeToDelete == NULL) return;

	  if (head == NodeToDelete)
	  {
		  head = NodeToDelete->next;
	  }

	  if (NodeToDelete->next != NULL)
	  {
		  NodeToDelete->next->prev = NodeToDelete->prev;
	  }

	  if (NodeToDelete->prev != NULL)
	  {
		  NodeToDelete->prev->next = NodeToDelete->next;
	  }	  
	  delete NodeToDelete;
	  NodeToDelete = nullptr;
	  _Size--;
  }

  void DeleteFirstNode()
  {
	  if (head == NULL) return;

	  Node* temp = head;
	  head = head->next;
	  if (head != NULL)
	  {
		  head->prev = NULL;
	  }
	  delete temp;
	  _Size--;
  }

  void DeleteLastNode()
  {

	  if (head == NULL) return;

	  Node* Current = head;

	  while (Current->next != NULL)
	  {
		  Current = Current->next;
	  }

	  if (Current == head) head = nullptr;

	  if (Current->prev != NULL)
	  {
		  Current->prev->next = NULL;
	  }
	  delete Current;
	  _Size--;
  }

  void Clear()
  {
	  while (_Size > 0)
	  {
		  DeleteFirstNode();
	  }
  }

  void Reverse()
  {

	  if (head == NULL) return;
	  Node* Current = head;
	  Node* temp = NULL;

	  while (Current != NULL)
	  {
		  temp = Current->prev;
		  Current->prev = Current->next;
		  Current->next = temp;
		  Current = Current->prev;
	  }  
	  
	  if (temp != nullptr)
	  {
		  head = temp->prev;
	  }
  }

  Node* GetNode(int index)
  {
	  if (index > _Size - 1 || index < 0) return NULL;

	  Node* Current = head;
	  int Counter = 0;

	  while (Current != NULL && (Current->next != NULL))
	  {
		  if (Counter == index) break;

		  Current = Current->next;
		  Counter++;
	  }
	  return Current;
  }

  T GetItem(int index)
  {
	  Node* ItemNode = GetNode(index);

	  if (ItemNode == NULL)
		  return NULL;
	  else
		  return ItemNode->value;
  }	

  bool UpdateItem(int Index, T NewItem)
  {

	  Node* ItemLoction = GetNode(Index);

	  if (ItemLoction != NULL)
	  {
		 ItemLoction->value = NewItem;
		 return true;
	  }
	  else
	  {
		  return false;
	  }
  }
};

