#pragma once

//Node 구조체 정의
struct Node
{
	Node* prev;
	Node* next;

	void* data;
};

//List 구조체 정의
struct List
{
	Node* head;
};

List* createList();
void insertNodeAfter(Node* node, void* data);
void removeNode(Node* node, bool deleteData);
void removeList(List* list, bool deleteData);
//void showAll(List* list);

Node* getTail(List* list);
