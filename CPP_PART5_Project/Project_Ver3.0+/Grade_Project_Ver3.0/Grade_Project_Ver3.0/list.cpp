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

//Linked List�� defualt ������.
//default ���ڸ� ����.
List::List(FN_DELETE fn_delete, bool deleteData)
{
	this->fn_delete = fn_delete;
	this->deleteData = deleteData;

	//headNode�� �ʱ�ȭ
	this->head = new Node();
	this->head->data = NULL;
	this->head->prev = this->head;
	this->head->next = this->head;
}

//Linked List�� �Ҹ���
List::~List()
{
	//��� node�� ����
	removeAll();

	//headNode�� ����
	delete this->head;
	this->head = NULL;
}

//���ο� node�߰�
//node :: �� node�ڿ� ���Ե�.
void List::insertNodeAfter(Node* node, void* data)
{
	//1. before, after Node����
	Node* before = node;
	Node* after = node->next;    //node->next = headNode(Circular�����̴ϱ�)

	//2. newNode����
	Node* newNode = new Node;
	newNode->data = data;
	newNode->prev = before;
	newNode->next = after;

	//3. before, after�� ������ ����.
	before->next = newNode;
	after->prev = newNode;
}

void List::removeNode(Node* node)
{
	Node* before = node->prev;
	Node* after = node->next;

	before->next = after;
	after->prev = before;

	//node�� data����.
	if (deleteData)
	{
		if (this->fn_delete)
			(*fn_delete)(node->data);
		else
			delete node->data;
	}

	//node����
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
	//���⼱, headNode�� next���� remove�Ѵ�.
	//�̷��� �ϸ�, headNode�� ��� �ֱ� ������,
	//removeAll()�Ŀ��� ����Ʈ ��ü �ٽ� ��� ����.
	Node* current = this->head->next;

	while (current != this->head)
	{
		//���� node�� ������̹Ƿ�
		//���� node�� ���� ���´�.
		Node* next = current->next;

		//���� node�� data����
		if (deleteData)
		{
			if (this->fn_delete)
				(*fn_delete)(current->data);
			else
				delete current->data;
		}

		//���� node����
		delete current;

		//current�� ���� node����Ű����
		//�޸� ������ ����������, �ּڰ��� ��밡��.
		current = next;
	}

	//headNode �ʱ�ȭ.
	this->head->next = this->head;
	this->head->prev = this->head;
}