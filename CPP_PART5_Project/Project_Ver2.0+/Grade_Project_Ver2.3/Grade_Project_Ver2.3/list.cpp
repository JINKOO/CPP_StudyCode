#include "list.h"
#include "student.h"
#include <iostream>

//List ����.
//��ȯ�� :: list
//list�� �����ϰ� �ʱ�ȭ �Ѵ�.
//headNode�� ���� �� �ʱ�ȭ �Ѵ�.
List* createList()
{
	//1.headNode ���� �� �ʱ�ȭ
	//prev, next��� �ڱ� �ڽ��� ����Ű���� �ʱ�ȭ�Ѵ�.
	//���� linked list�� ���� �� ���̱� ����.
	Node* head = new Node;
	head->prev = head;
	head->next = head;
	head->data = NULL;

	//2.list ���� �� �ʱ�ȭ
	List* list = new List;
	list->head = head;

	return list;
}

//���ο� Node�� �����Ѵ�.
//��ȯ�� :: void
//node :: �� node �ڿ� newnode�� ����.
//data :: newNode�� �� data.
void insertNodeAfter(Node* node, void* data)
{
	//1. newnode�� ��, �� node�ּڰ� ����.
	Node* before = node;
	Node* after = node->next;

	//2. newnode ����
	Node* newNode = new Node;
	newNode->prev = before;
	newNode->next = after;
	newNode->data = data;

	//3. newNode�� ��, �� node�� prev, next����.
	before->next = newNode;
	after->prev = newNode;
}

//node�� ���� �Ѵ�.
//node :: ���� �� node
//deleteData :: true�� data�� ���� ����
void removeNode(Node* node, bool deleteData)
{
	//1. remove�� node�� ��, �� node�� �ּڰ� ����.
	Node* before = node->prev;
	Node* after = node->next;

	//2. ��, �� node���� prev, next ����(���⼭�� ���� ����)
	before->next = after;
	after->prev = before;

	//3. node ����
	if (deleteData)
		delete node->data;
	delete node;
}

//List��ü ����
//1. ��� ����, �� node�� data���� ���� ��
//2. ����Ʈ ����
void removeList(List* list, bool deleteData)
{
	//1. headNode���� ������ ������.
	Node* current = list->head;
	do
	{
		//2. next node�� ���� ���� �Ѵ�.(headNode�� ������ ���̴ϱ�)
		Node* next = current->next;
		
		//3. data��� �ִ� ù��° node���� ����
		if (deleteData)
			//delete�����ڿ��� �����ϰ����ϴ� Ÿ���� �˷������.
			delete (Student*)current->data;
		delete current;

		current = next;
	} while (current != list->head);
	/*
	 list->head�� ����Ű�� ���� �޸𸮴� ���� �Ǿ�����,
	 ����Ű�� ���� �ּڰ��� ��� �����ϴ�.
	 current�� ��������
	*/

	//4. ���������� ���� list ����.
	delete list;
}


//������ node�� ���Ѵ�.
//list :: headernode�� ����Ű�� node
//��ȯ�� :: ������ node
Node* getTail(List* list)
{
	//circlular �����̹Ƿ� ������ node�� headNode->prev�� �ȴ�.
	//������ ��尡 �ڱ� �ڽ��� �� �ִ�.
	return list->head->prev;
}
