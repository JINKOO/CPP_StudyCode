#include "list.h"

List::List(FN_DELETE fn_delete, bool deleteData)
{

	this->fn_delete = fn_delete;
	this->deleteData = deleteData;

	this->head = new Node();

	this->head->next = this->head;
	this->head->prev = this->head;
	this->head->data = 0;
}

List::~List()
{

}

void List::insertAfterNode(Node* node, void* data)
{
	Node* before = node;
	Node* after = node->next;

	Node* newNode = new Node();
	newNode->next = after;
	newNode->prev = before;
	newNode->data = data;

	before->next = newNode;
	after->prev = newNode;
}

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
}

void List::removeAll()
{
	
}