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
	//���ٸ� �۾� ����
}

//List �ʱ�ȭ
List::List(FN_DELETE fn_delete, bool deleteData)
{
	this->fn_delete = fn_delete;
	this->deleteData = deleteData;

	this->head = new Node();
	this->head->prev = this->head;
	this->head->next = this->head;
	this->head->data = NULL;
}

//List����
List::~List()
{
	removeAll();

	delete this->head;
	this->head = NULL;
}

//Circular LinkedList�� ����
void List::insertAfterNode(Node* node, void* data)
{
	if (node == NULL)
		throw std::invalid_argument("�� �� ���� ������ �ֽ��ϴ�.(337)");

	Node* before = node;
	Node* after = node->next;

	Node* newNode = new Node();
	newNode->prev = before;
	newNode->next = after;
	newNode->data = data;

	before->next = newNode;
	after->prev = newNode;

}

//Node�Ѱ� ����
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

//headNode�� �����ϰ� ��� ��� ����
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