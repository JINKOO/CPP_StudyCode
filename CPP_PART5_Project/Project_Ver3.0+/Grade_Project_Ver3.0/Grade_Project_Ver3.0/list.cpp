#include "list.h"
#include <iostream>

Node* Node::getNext() const
{
	return this->next;
}

Node* Node::getPrev() const
{
	return this->prev;
}

void* Node::getData() const
{
	return this->data;
}

//Linked List의 defualt 생성자.
//default 인자를 받음.
List::List(FN_DELETE fn_delete, bool deleteData)
{
	this->fn_delete = fn_delete;
	this->deleteData = deleteData;

	//headNode의 초기화
	this->head = new Node();
	this->head->data = NULL;
	this->head->prev = this->head;
	this->head->next = this->head;
}

//Linked List의 소멸자
List::~List()
{
	//모든 node의 제거
	removeAll();

	//headNode의 제거
	delete this->head;
	this->head = NULL;
}

//새로운 node추가
//node :: 이 node뒤에 삽입됨.
void List::insertNodeAfter(Node* node, void* data)
{
	//1. before, after Node정의
	Node* before = node;
	Node* after = node->next;    //node->next = headNode(Circular구조이니까)

	//2. newNode생성
	Node* newNode = new Node;
	newNode->data = data;
	newNode->prev = before;
	newNode->next = after;

	//3. before, after의 포인터 조정.
	before->next = newNode;
	after->prev = newNode;
}

void List::removeNode(Node* node)
{
	Node* before = node->prev;
	Node* after = node->next;

	before->next = after;
	after->prev = before;

	//node의 data제거.
	if (deleteData)
	{
		if (this->fn_delete)
			(*fn_delete)(node->data);
		else
			delete node->data;
	}

	//node제거
	delete node;
}

Node* List::getHead() const
{
	return this->head;
}

Node* List::getTail() const
{
	return this->head->prev;
}

void List::removeAll()
{
	//여기선, headNode의 next부터 remove한다.
	//이렇게 하면, headNode가 살아 있기 때문에,
	//removeAll()후에도 리스트 객체 다시 사용 가능.
	Node* current = this->head->next;

	while (current != this->head)
	{
		//현재 node를 지울것이므로
		//다음 node를 구해 놓는다.
		Node* next = current->next;

		//현재 node의 data제거
		if (deleteData)
		{
			if (this->fn_delete)
				(*fn_delete)(current->data);
			else
				delete current->data;
		}

		//현재 node제거
		delete current;

		//current가 다음 node가리키도록
		//메모리 공간은 없어졌지만, 주솟값은 사용가능.
		current = next;
	}

	//headNode 초기화.
	this->head->next = this->head;
	this->head->prev = this->head;
}