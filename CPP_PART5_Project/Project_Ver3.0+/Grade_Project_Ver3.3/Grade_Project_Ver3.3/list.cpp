#include "list.h"

List::List(FN_DELETE fn_delete, bool deleteData)
{
	this->fn_delete = fn_delete;
	this->deleteData = deleteData;

	//headNode�� ���� �� �ʱ�ȭ
	this->head = new Node;
	this->head->data = NULL;
	this->head->prev = this->head;
	this->head->next = this->head;

}

List::~List()
{
	std::cout << "~List() called" << "\n";

	//1. ��� node����
	removeAll();

	//2. headNode����
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

	//node�� data����
	if (deleteData)
	{
		if (this->fn_delete)
			(*fn_delete)(node->data);
		else
			delete node->data;
	}

	//node ����
	delete node;
}

void List::removeAll()
{
	Node* current = this->head->next;

	while (current != this->head)
	{
		//���� node�� ���� ���̹Ƿ�, ���� node�� ���� ���´�.
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

		current = next;
	}

	//headNode�ʱ�ȭ.
	this->head->prev = this->head;
	this->head->next = this->head;
}