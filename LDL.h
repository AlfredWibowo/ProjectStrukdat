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

class LDL
{
private:
	Node* head;
	Node* tail;
	int size;

public:
	LDL()
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
	};
};
