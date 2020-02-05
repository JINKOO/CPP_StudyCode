#ifndef LIST_H
#define LIST_H

//node�Ѱ��� ������ ���� class
class Node
{
	//friend�� ����� class�� Node�� ������� ���� ����.
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


//��ü linked list�����ϴ� class.
class List
{

public:
	typedef void (*FN_DELETE)(void*);

private:
	Node* head;                 //headNode
	bool deleteData;
	FN_DELETE fn_delete;

public:
	//�Ű������� default ������ default ������.
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