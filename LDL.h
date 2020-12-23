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

	Node(int posX, int posY)
	{
		_posX = posX;
		_posY = posY;
		next = NULL;
		prev = NULL;
		_Out = 1;
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

