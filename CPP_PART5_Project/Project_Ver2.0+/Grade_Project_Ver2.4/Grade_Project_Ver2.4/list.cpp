#include "list.h"
#include <iostream>

List* createList(FN_DELETE fn_delete)
{
	//1. headNode ���� �� �ʱ�ȭ
	//circular���� �̴ϱ� �ʱ�ȭ �� �ڱ��ڽ� ����Ű����
	Node* head = new Node;
	head->data = NULL;
	head->prev = head;
	head->next = head;

	//2. List ���� �� �ʱ�ȭ
	//list�� ������ headNode�� ����Ű���� �ʱ�ȭ.
	List* list = new List;
	list->head = head;

	//3. data���ſ� �Լ��� �ּҸ� ��� ������ ����.
	list->fn_delete = fn_delete;

	return list;
}

void insertAfterNode(Node* node, void* data)
{
	//1. before, after ����
	Node* before = node; 
	Node* after = node->next;   //node_next = header node = after.

	//2. newNode����
	Node* newNode = new Node;
	newNode->data = data;
	newNode->prev = before;
	newNode->next = after;

	//3. before, after�� ������ ����.
	before->next = newNode;
	after->prev = newNode;
}

void removeNode(List* list, Node* node, bool deleteData)
{
	//1. before, after ����
	Node* before = node->prev;
	Node* after = node->next;

	//2. before, after������ ����.
	before->next = after;
	after->prev = before;

	//3. node ����
	if (deleteData)
	{
		//list->fn_delete�ȿ� ������ �Լ��� �ּҰ� �ִ��� Ȯ��
		if (list->fn_delete) //NULL�� ���, �ɰ��� ������ �߻� �� �� �ִ�. 
			(*list->fn_delete)(node->data);
		else 
			delete node->data;
	}

	delete node;
}

void removeList(List* list, bool deleteData)
{
	Node* current = list->head;
	
	do  //1. headnode�� �켱 ���� ���� do While��
	{
		Node* next = current->next;
		
		//2. node����
		if (deleteData)
		{
			if (list->fn_delete)
				(*list->fn_delete)(current->data);
			else
				delete current->data;
		}

		delete current;

		current = next;

	} while (current != list->head);
}

Node* getNext(Node* node)
{
	return node->next;
}

Node* getPrev(Node* node)
{
	return node->prev;
}

Node* getTail(List* list)
{
	//circular�����̹Ƿ�, ������ ������ ���� �׻� headNode�� prev.
	//node�� ���� ���, headNode�ڽ��� �� �� �ִ�.
	return list->head->prev;
}

void* getData(Node* node)
{
	return node->data;
}