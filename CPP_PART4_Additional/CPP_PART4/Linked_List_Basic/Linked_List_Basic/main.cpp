#include<iostream>
#include<string>

/*
   #. Linked List
     - singly Linked List
	 - doubly Linked List
	 - ��ũ�� ����Ʈ�� �迭�� �ٸ���, �޸� ������ ���ʴ�� �������� ����.

	 1. Linked List�� ����(Vs Array)
	  - ����� ����, ������ �ξ� �����ϴ�.
	  --> �迭�� ���, �켱�� ����� ũ���� ������ �־�� �ϰ�,
	      �߰��� ����, ���� �� �ÿ��� �̹� �ִ� data���� �ڷ� �Ǵ� ������ ��� �̵����Ѿ� �Ѵ�.
	  --> ��ũ�� ����Ʈ������ ������ ���, �յڿ� �ִ� ���鿡���� ������ ������ ������ ������ ���游 �����ָ� �ȴ�.

	 2. Linked List�� ����
	  - ��� ����ü(or class)�� ����.
	    ��� ����ü���� 2���� ����
		1). ��忡 ������ data.
		2). ����� ����� ��ġ.
*/

struct Student
{
	int sNo;
	std::string name;
	int kor;
	int eng;
	int math;
	float avg;
};

//node ����ü ����
//���⼭�� doubly linked list
struct Node
{
	Node* prev;   //�ռ� node�� �ּڰ�
	Node* next;   //���� node�� �ּڰ�

	//Student data; //node�� ������ data
	void* data;   //StudentŸ���� data���� ��� type�� data�� �ΰ������� ���� �� �� �ִ�.
};

//Linked List�� �ش��ϴ� ����ü ����
//����� node�� �� ù��° node�� ����Ű�� ������ �Ѵ�. 
struct List
{
	Node* head;
};

//Linked List�� ���� �� �ʱ�ȭ
//��ȯ ��: ���ο� ��ũ�� ����Ʈ�� ������.
List* createList()
{
	//head node�� ����� �ʱ�ȭ
	//head node�� data�� ������ �ʰ�
	//�ܼ��� ��ġ(�� ���ڸ�)�� �����Ѵ�. 
	Node* head = new Node;
	head->prev = head;
	head->next = head;
	head->data = NULL;

	//��ũ�� ����Ʈ ���� �� �ʱ�ȭ.
	List* list = new List;

	//�ռ����� head node�� ����Ű���� �Ѵ�.
	list->head = head;
	std::cout << list << "\n";

	return list;
}

//���ο� node�� �߰��Ѵ�.
//node : �� node�ڿ� ���ο� node�� �߰��ȴ�.
//data : �� node�� data.
void insertNodeAfter(Node* node, void* data)
{
	Node* before = node;
	Node* after = node->next;

	//1. ���ο� node ����
	//   ���ο� node�� next, prev�� ����.
	Node* newNode = new Node;
	newNode->data = data;
	newNode->prev = before;
	newNode->next = after;

	//2. newNode ��, �� node ������ ����
	after->prev = newNode;
	before->next = newNode;

	//�ݵ�� newNode�� next,prev ���� ��, 
	//�� �� node�� next, prev �����ؾ�
}

//��带 remove�Ѵ�.
//node : remove �� node
//deleteData : true��, node�� ����Ű�� data�� ����.
void removeNode(Node* node, bool deleteData)
{
	//1. remove�Ϸ��� ��, �� node�� �ּҰ� ����.
	Node* before = node->prev;
	Node* after = node->next;

	//2. before, after�� ���� ����
	before->next = after;
	after->prev = before;

	//3. node�ڽŰ� node�� data ����
	if (deleteData)
		delete node->data;  //true��, node�� data�� remove
	delete node;            //node ����.
}

//node Ž��
//�ϳ��� Ž�� �ϰ� �ȴ�.
void showNames(List* students)
{
	//ù��° data�� �ִ� node���� Ž���ϱ� ����
	//��, headNode�� ���� node���� ����.
	Node* current = students->head->next;

	while (current != students->head)
	{
		//���� node���� data�� �����´�.
		const Student* student = (Student*)current->data;
		
		//���� node�� data�� name���
		std::cout << student->name << "\n";

		//current�� ���� node�� ����Ű���� �Ѵ�.
		current = current->next;
	}
}

//��� node���� �� ����, ���������� List���� �� ����
void removeList(List* list, bool deleteData)
{
	Node* current = list->head;

	//do While�� ����� ����: �ϴ� head Node���� �� ����,  ������ ���ؾ� �ϹǷ�
	do
	{
		//head node�� �켱 �����ϱ� ��,
		//next node�� ���� ��Ų��.
		Node* next = current->next;

		if (deleteData)
			delete current->data;
		delete current;
		
		current = next;

	} while (current != list->head);

	//list ����
	delete list;
}

Student* setStudentInfo()
{
	Student* student = new Student;
	std::cout << "�л� ���� �Է�" << "\n";
	std::cout << "�̸�:: ";
	std::cin >> student->name;
	std::cout << "����� :: ";
	std::cin >> student->kor;
	std::cout << "����� :: ";
	std::cin >> student->eng;
	std::cout << "���� ���� :: ";
	std::cin >> student->math;

	return student;
}


int main()
{
	List* student = createList();

	Student* s1 = setStudentInfo();
	Student* s2 = setStudentInfo();
	Student* s3 = setStudentInfo();

	insertNodeAfter(student->head, s1);
	insertNodeAfter(student->head, s2);
	insertNodeAfter(student->head, s3);

	showNames(student);

	return 0;
}