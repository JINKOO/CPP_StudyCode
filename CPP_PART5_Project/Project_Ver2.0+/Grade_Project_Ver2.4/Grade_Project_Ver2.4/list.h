#ifndef LIST_H
#define LIST_H

//node안의 data제거를 위한 함수 포인터.
//linked list가 node안의 void* data를 해제 할때
//이 함수를 호출한다.
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

	//data 제거시 호출할 함수.
	FN_DELETE fn_delete;
};

//createList()에 data제거 함수포인터 추가함.
List* createList(FN_DELETE fn_delete);
void insertAfterNode(Node* node, void* data);
void removeNode(List* list, Node* node, bool deleteData);
void removeList(List* list, bool deleteData);

Node* getNext(Node* node);
Node* getPrev(Node* node);
Node* getTail(List* list);
void* getData(Node* node);
#endif