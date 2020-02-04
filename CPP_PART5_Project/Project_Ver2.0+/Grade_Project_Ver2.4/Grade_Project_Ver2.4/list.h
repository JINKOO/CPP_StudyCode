#ifndef LIST_H
#define LIST_H

//node���� data���Ÿ� ���� �Լ� ������.
//linked list�� node���� void* data�� ���� �Ҷ�
//�� �Լ��� ȣ���Ѵ�.
typedef void(*FN_DELETE)(void*);

struct Node
{
	Node* prev;
	Node* next;

	void* data;
};

struct List
{
	Node* head;

	//data ���Ž� ȣ���� �Լ�.
	FN_DELETE fn_delete;
};

//createList()�� data���� �Լ������� �߰���.
List* createList(FN_DELETE fn_delete);
void insertAfterNode(Node* node, void* data);
void removeNode(List* list, Node* node, bool deleteData);
void removeList(List* list, bool deleteData);

Node* getNext(Node* node);
Node* getPrev(Node* node);
Node* getTail(List* list);
void* getData(Node* node);
#endif