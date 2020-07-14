#ifndef LIST_H
#define LIST_H
#include <iostream>

class Node
{
	friend class List;

private:
	Node* prev;
	Node* next;
	void* data;
};

class List
{
	typedef void (*FN_DELETE)(void*);

private:
	Node* head;
	FN_DELETE fn_delete;
	bool deleteData;

public:
	List(FN_DELETE fn_delete = NULL, bool deleteData =  true);
	~List();

public:
	Node* getHead() const { return this->head; }
	Node* getTail() const { return this->head->prev; }

	void insertAfterNode(Node* node, void* data);
	void removeNode(Node* node);
	void removeAll();
};
#endif