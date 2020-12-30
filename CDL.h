#pragma once
#include <string>
#include <iostream>

class Node
{
public:

	int _posX, _posY;
	Node* next;
	Node* prev;

	Node(int posX, int posY)
	{
		_posX = posX;
		_posY = posY;
		next = NULL;
		prev = NULL;
	}
};

class CDL
{
private:
	Node* head;
	Node* tail;
	int size;

public:
	CDL()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	Node* getHead()
	{
		return head;
	}

	Node* getTail()
	{
		return tail;
	}

	void view()
	{

	}


	int getSize()
	{
		return size;
	}

	void deleteNode(Node* toDel)
	{
		Node* position;
		position = head;

		for (int i = 0; i < size; i++)
		{
			if (position != toDel)
			{
				position = position->next;
			}
		}

		if (position->next != NULL && position->prev != NULL)
		{
			position->prev->next = position->next;
			position->next->prev = position->prev;
		}
		else if (position->next == NULL && position->prev == NULL)
		{
			head = NULL;
			tail = NULL;
		}
		else if (position->next == NULL)
		{
			position->prev->next = NULL;
			tail = position->prev;
		}
		else if (position->prev == NULL)
		{
			position->next->prev = NULL;
			head = position->next;
		}

		delete position;

		tail->next = head;
		head->prev = tail;

		size--;
		std::cout << getSize() << std::endl;
	}

	void add(int posX, int posY)
	{
		Node* temp = new Node(posX, posY);

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		tail->next = head;
		head->prev = tail;
		size++;
	}
};
