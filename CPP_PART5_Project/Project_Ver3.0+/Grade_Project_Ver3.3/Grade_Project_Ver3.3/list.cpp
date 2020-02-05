#include "list.h"

List::List(FN_DELETE fn_delete, bool deleteData)
{
	this->fn_delete = fn_delete;
	this->deleteData = deleteData;

	//headNode의 생성 및 초기화
	this->head = new Node;
	this->head->data = NULL;
	this->head->prev = this->head;
	this->head->next = this->head;

}

List::~List()
{
	std::cout << "~List() called" << "\n";

	//1. 모든 node제거
	removeAll();

	//2. headNode제거
	delete this->head;
	this->head = NULL;

	std::cout << "~List() end.." << "\n";
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

	//node의 data제거
	if (deleteData)
	{
		if (this->fn_delete)
			(*fn_delete)(node->data);
		else
			delete node->data;
	}

	//node 제거
	delete node;
}

void List::removeAll()
{
	Node* current = this->head->next;

	while (current != this->head)
	{
		//현재 node를 지울 것이므로, 다음 node를 구해 놓는다.
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

		current = next;
	}

	//headNode초기화.
	this->head->prev = this->head;
	this->head->next = this->head;
}