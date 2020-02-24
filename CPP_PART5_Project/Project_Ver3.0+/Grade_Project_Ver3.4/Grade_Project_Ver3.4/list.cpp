#include "list.h"
#include <iostream>

List::List(FN_DELETE fn_delete, bool deleteData)
{
	this->fn_delete = fn_delete;
	this->deleteData = deleteData;

	//headNode생성
	this->head = new Node;
	this->head->data = NULL;
	this->head->prev = this->head;
	this->head->next = this->head;
}

List::~List()
{
	std::cout << "~List() called" << "\n";
	
	removeAll();

	delete this->head;
	this->head = NULL;

	std::cout << "~List() end..." << "\n";
}

void List::insertAfterNode(Node* node, void* data)
{
	Node* before = node;
	Node* after = node->next;

	Node* newNode = new Node;
	newNode->data = data;
	newNode->prev = before;
	newNode->next = after;

	before->next = newNode;
	after->prev = newNode;
}

void List::removeNode(Node* node)
{
	Node* before = node->prev;
	Node* after = node->next;

	before->next = after;
	after->prev = before;

	if (deleteData)
	{
		if (this->fn_delete)
			(*fn_delete)(node->data);
		else
			delete node->data;
	}

	delete node;
	node = NULL;
}

void List::removeAll()
{
	//headNode->next까지만 remove
	//List를 다시 사용 할 수 있도록.
	Node* current = this->head->next;
	
	while (current != this->head)
	{
		//current delete할 것이니까
		//next를 구해 놓는다.
		Node* next = current->next;

		if (deleteData)
		{
			if (this->fn_delete)
				(*fn_delete)(current->data);
			else
				delete current->data;
		}

		delete current;
		
		current = next;
	}

	this->head->next = this->head;
	this->head->prev = this->head;
}

