#ifndef LIST_H
#define LIST_H

//node한개의 정보에 대한 class
class Node
{
	//friend로 선언된 class는 Node의 모든멤버에 접근 가능.
	friend class List;

private:
	Node* prev;
	Node* next;
	void* data;

public:
	Node* getNext() const;
	Node* getPrev() const;
	void* getData() const;
};


//전체 linked list관리하는 class.
class List
{

public:
	typedef void (*FN_DELETE)(void*);

private:
	Node* head;                 //headNode
	bool deleteData;
	FN_DELETE fn_delete;

public:
	//매개변수가 default 인자인 default 생성자.
	List(FN_DELETE fn_delete = 0, bool deleteData = true);
	~List();

public:
	void insertNodeAfter(Node* node, void* data);
	void removeNode(Node* node);

	Node* getHead() const;
	Node* getTail() const;

	void removeAll();
};
#endif