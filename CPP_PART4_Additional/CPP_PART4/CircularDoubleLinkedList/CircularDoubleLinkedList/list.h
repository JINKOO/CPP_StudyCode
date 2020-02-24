#ifndef LIST_H
#define LIST_H
#include <iostream>

class Node
{
public:
	friend class List;

private:
	Node* prev;
	Node* next;
	void* data;

public:
	Node* getPrev() { return this->prev; }
	Node* getNext() { return this->next; }
	void* getData() { return this->data; }
};

class List
{

public:
	typedef void(*FN_DELETE)(void*);

private:
	Node* head;
	FN_DELETE fn_delete;
	bool deleteData;

public:
	List(FN_DELETE fn_delete = NULL, bool deleteData = true);
	~List();

public:
	void insertAfterNode(Node* node, void* data);
	void removeNode(Node* node);
	void removeAll();

public:
	Node* getHead() { return this->head; }
	Node* getTail() { return this->head->prev; }
};
#endif