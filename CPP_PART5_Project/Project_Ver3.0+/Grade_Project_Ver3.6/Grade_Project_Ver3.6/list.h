#ifndef LIST_H
#define LIST_H
#include <iostream>

//각 node에 대한 class
class Node
{
	friend class List;

private:
	Node* prev;
	Node* next;
	void* data;

public:
	Node();
	~Node();

public:
	Node* getPrev() const { return this->prev; }
	Node* getNext() const { return this->next; }
	void* getData() const { return this->data; }
};


//LinkedList를 만들기 위한 class
class List
{
public:
	typedef void (*FN_DELETE)(void*);

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

	Node* getHead() const { return this->head; }
	Node* getTail() const { return this->head->prev; }
};
#endif