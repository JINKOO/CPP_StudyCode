#ifndef LIST_H
#define LIST_H
#include<iostream>

//node 1개의 data를 관리하는 class
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


//전체 List를 관리하는 class
//List는 Circular doubly Linked List로 구현 할 것.
class List
{
public:
	//data제거용 함수 포인터 선언.
	typedef void (*FN_DELETE)(void*);

private:
	Node* head;
	FN_DELETE fn_delete;
	bool deleteData;

public:
	//List생성 및 초기화.
	List(FN_DELETE fn_delete = NULL, bool deleteData = true);
	//사용한 리소스 정리.
	~List();

public:
	void insertAfterNode(Node* node, void* data);
	void removeNode(Node* node);
	void removeAll();

	Node* getHead() const { return this->head; }
	Node* getTail() const { return this->head->prev; }
};

#endif