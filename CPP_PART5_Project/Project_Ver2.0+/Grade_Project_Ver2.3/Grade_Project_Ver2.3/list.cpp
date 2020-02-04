#include "list.h"
#include "student.h"
#include <iostream>

//List 생성.
//반환값 :: list
//list를 생성하고 초기화 한다.
//headNode를 생성 후 초기화 한다.
List* createList()
{
	//1.headNode 생성 및 초기화
	//prev, next모두 자기 자신을 가리키도록 초기화한다.
	//원형 linked list를 구현 할 것이기 때문.
	Node* head = new Node;
	head->prev = head;
	head->next = head;
	head->data = NULL;

	//2.list 생성 및 초기화
	List* list = new List;
	list->head = head;

	return list;
}

//새로운 Node를 삽입한다.
//반환값 :: void
//node :: 이 node 뒤에 newnode가 삽입.
//data :: newNode에 들어갈 data.
void insertNodeAfter(Node* node, void* data)
{
	//1. newnode의 앞, 뒤 node주솟값 저장.
	Node* before = node;
	Node* after = node->next;

	//2. newnode 생성
	Node* newNode = new Node;
	newNode->prev = before;
	newNode->next = after;
	newNode->data = data;

	//3. newNode의 앞, 뒤 node의 prev, next조정.
	before->next = newNode;
	after->prev = newNode;
}

//node를 삭제 한다.
//node :: 삭제 할 node
//deleteData :: true면 data도 같이 삭제
void removeNode(Node* node, bool deleteData)
{
	//1. remove할 node의 앞, 뒤 node의 주솟값 저장.
	Node* before = node->prev;
	Node* after = node->next;

	//2. 앞, 뒤 node들의 prev, next 조정(여기서는 서로 연결)
	before->next = after;
	after->prev = before;

	//3. node 삭제
	if (deleteData)
		delete node->data;
	delete node;
}

//List전체 제거
//1. 모든 노드들, 각 node이 data들을 제거 후
//2. 리스트 제거
void removeList(List* list, bool deleteData)
{
	//1. headNode부터 제거해 나간다.
	Node* current = list->head;
	do
	{
		//2. next node를 구해 놔야 한다.(headNode를 제거할 것이니까)
		Node* next = current->next;
		
		//3. data들어 있는 첫번째 node부터 제거
		if (deleteData)
			//delete연산자에게 해제하고자하는 타입을 알려줘야함.
			delete (Student*)current->data;
		delete current;

		current = next;
	} while (current != list->head);
	/*
	 list->head가 가리키는 곳의 메모리는 해제 되었지만,
	 가리키는 곳의 주솟값은 사용 가능하다.
	 current도 마찬가지
	*/

	//4. 마지막으로 남은 list 제거.
	delete list;
}


//마지막 node를 구한다.
//list :: headernode를 가리키는 node
//반환값 :: 마지막 node
Node* getTail(List* list)
{
	//circlular 구조이므로 마지막 node는 headNode->prev가 된다.
	//마지막 노드가 자기 자신일 수 있다.
	return list->head->prev;
}
