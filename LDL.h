#pragma once
#include <string>
#include <iostream>

class Node
{
public:

	int _posX, _posY, _markas;
	std::string _warnaPion;
	Node* next;
	Node* prev;

	Node(int posX, int posY, int markas, std::string warnaPion)
	{
		_posX = posX;
		_posY = posY;
		_markas = markas;
		_warnaPion = warnaPion;
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

	void add(int posX, int posY, int markas, std::string warnaPion)
	{
		Node* temp = new Node(posX, posY, markas, warnaPion);

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
	}

	void view()
	{
		Node* position = head;
		for (int i = 0; i < size; i++)
		{
			std::cout << "[" << position[i]._posX << "]";
			position = position->next;
		}
		std::cout << std::endl;
	}

	Node* getHead()
	{
		return head;
	}
	Node* getTail()
	{
		return tail;
	}
};

