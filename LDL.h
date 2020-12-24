#pragma once
#include <string>
#include <iostream>

class Node
{
public:

	int _posX, _posY;
	Node* next;
	Node* prev;
	int _Out;
	bool _markas;

	Node(int posX, int posY)
	{
		_posX = posX;
		_posY = posY;

		_markas = true;
		//_warnaPion = warnaPion;

		next = NULL;
		prev = NULL;
		_Out = 1;
	}

	bool getmarkas()
	{
		return _markas;
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

	Node* getHead();
	Node* getTail();
	void view();
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
		};
	};
};
