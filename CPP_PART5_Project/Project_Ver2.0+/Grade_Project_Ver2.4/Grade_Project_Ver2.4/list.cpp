#include "list.h"
#include <iostream>

List* createList(FN_DELETE fn_delete)
{
	//1. headNode 생성 및 초기화
	//circular구조 이니까 초기화 시 자기자신 가리키도록
	Node* head = new Node;
	head->data = NULL;
	head->prev = head;
	head->next = head;

	//2. List 생성 및 초기화
	//list는 생성한 headNode를 가리키도록 초기화.
	List* list = new List;
	list->head = head;

	//3. data제거용 함수의 주소를 멤버 변수에 저장.
	list->fn_delete = fn_delete;

	return list;
}

void insertAfterNode(Node* node, void* data)
{
	//1. before, after 정의
	Node* before = node; 
	Node* after = node->next;   //node_next = header node = after.

	//2. newNode생성
	Node* newNode = new Node;
	newNode->data = data;
	newNode->prev = before;
	newNode->next = after;

	//3. before, after의 포인터 조정.
	before->next = newNode;
	after->prev = newNode;
}

void removeNode(List* list, Node* node, bool deleteData)
{
	//1. before, after 정의
	Node* before = node->prev;
	Node* after = node->next;

	//2. before, after포인터 조정.
	before->next = after;
	after->prev = before;

	//3. node 제거
	if (deleteData)
	{
		//list->fn_delete안에 보관된 함수의 주소가 있는지 확인
		if (list->fn_delete) //NULL일 경우, 심각한 오류가 발생 할 수 있다. 
			(*list->fn_delete)(node->data);
		else 
			delete node->data;
	}

	delete node;
}

void removeList(List* list, bool deleteData)
{
	Node* current = list->head;
	
	do  //1. headnode를 우선 제거 위해 do While문
	{
		Node* next = current->next;
		
		//2. node제거
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
	//circular구조이므로, 마지막 삽입한 노드는 항상 headNode의 prev.
	//node가 없을 경우, headNode자신이 될 수 있다.
	return list->head->prev;
}

void* getData(Node* node)
{
	return node->data;
}