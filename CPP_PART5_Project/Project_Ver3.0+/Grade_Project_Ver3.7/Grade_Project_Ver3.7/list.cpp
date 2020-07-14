#include "list.h"

List::List(FN_DELETE fn_delete, bool deleteData)
{
	this->fn_delete = fn_delete;
	this->deleteData = deleteData;

	this->head = new Node();
	this->head->prev = this->head;
	this->head->next = this->head;
	this->head->data = 0;
}

List::~List()
{
	std::cout << "~List() called" << "\n";
}