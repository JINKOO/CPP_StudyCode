#include "list.h"
#include <iostream>
#include <exception>

Node::Node()
{
	this->prev = NULL;
	this->next = NULL;
	this->data = NULL;
}

Node::~Node()
{
	//별다른 작업 없음
}

//List 초기화
List::List(FN_DELETE fn_delete, bool deleteData)
{
	this->fn_delete = fn_delete;
	this->deleteData = deleteData;

	this->head = new Node();
	this->head->prev = this->head;
	this->head->next = this->head;
	this->head->data = NULL;
}

//List제거
List::~List()
{
	removeAll();

	delete this->head;
	this->head = NULL;
}

//Circular LinkedList에 삽입
void List::insertAfterNode(Node* node, void* data)
{
	if (node == NULL)
		throw std::invalid_argument("알 수 없는 오류가 있습니다.(337)");

	Node* before = node;
	Node* after = node->next;

	Node* newNode = new Node();
	newNode->prev = before;
	newNode->next = after;
	newNode->data = data;

	before->next = newNode;
	after->prev = newNode;

}

//Node한개 삭제
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

//headNode를 제외하고 모든 노드 삭제
void List::removeAll()
{
	Node* current = this->head->next;

	while (current != this->head)
	{
		Node* next = current->next;

		if (deleteData)
		{
			if (this->fn_delete)
				delete current->data;
			else
				delete current->data;
		}

		delete current;

		current = next;
	}

	this->head->prev = this->head;
	this->head->next = this->head;
}