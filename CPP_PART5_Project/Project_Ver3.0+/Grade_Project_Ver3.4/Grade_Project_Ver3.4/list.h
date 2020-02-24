#ifndef LIST_H
#define LIST_H

class Node
{
	friend class List;

private:
	Node* prev;
	Node* next;
	void* data;

public:
	Node* getPrev() const { return this->prev; };
	Node* getNext() const { return this->next; };
	void* getData() const { return this->data; };
};


class List
{
public:
	typedef void (*FN_DELETE)(void*);

private:
	Node* head;
	bool deleteData;
	FN_DELETE fn_delete;

public:
	List(FN_DELETE fn_delete = 0, bool deleteData = true);
	~List();

public:
	void insertAfterNode(Node* node, void* data);
	void removeNode(Node* node);
	void removeAll();

	Node* getHead() const { return this->head; };
	Node* getTail() const { return this->head->prev; };
};

#endif