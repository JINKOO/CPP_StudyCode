#ifndef LIST_H
#define LIST_H
#include<iostream>

//node 1���� data�� �����ϴ� class
class Node
{
	friend class List;

protected:
	Node* prev;
	Node* next;
	void* data;

public:
	Node* getPrev() const { return this->prev; }
	Node* getNext() const { return this->next; }
	void* getData() const { return this->data; }
};


//��ü List�� �����ϴ� class
//List�� Circular doubly Linked List�� ���� �� ��.
class List
{
public:
	//data���ſ� �Լ� ������ ����.
	typedef void (*FN_DELETE)(void*);

private:
	Node* head;
	FN_DELETE fn_delete;
	bool deleteData;

public:
	//List���� �� �ʱ�ȭ.
	List(FN_DELETE fn_delete = NULL, bool deleteData = true);
	//����� ���ҽ� ����.
	~List();

public:
	void insertAfterNode(Node* node, void* data);
	void removeNode(Node* node);
	void removeAll();

	Node* getHead() const { return this->head; }
	Node* getTail() const { return this->head->prev; }
};

#endif