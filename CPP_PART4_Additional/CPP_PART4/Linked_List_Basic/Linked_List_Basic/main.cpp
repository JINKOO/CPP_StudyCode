#include<iostream>
#include<string>

/*
   #. Linked List
     - singly Linked List
	 - doubly Linked List
	 - 링크드 리스트는 배열과 다르게, 메모리 공간에 차례대로 존재하지 않음.

	 1. Linked List의 장점(Vs Array)
	  - 노드의 삽입, 삭제가 훨씬 간단하다.
	  --> 배열의 경우, 우선은 충분한 크기의 공간이 있어야 하고,
	      중간에 삽입, 삭제 할 시에는 이미 있는 data들을 뒤로 또는 앞으로 모두 이동시켜야 한다.
	  --> 링크드 리스트에서는 삽입할 노드, 앞뒤에 있는 노드들에서만 포인터 변수를 가지고 적당히 변경만 시켜주면 된다.

	 2. Linked List의 구현
	  - 노드 구조체(or class)의 설계.
	    노드 구조체에는 2가지 정보
		1). 노드에 보관할 data.
		2). 연결된 노드의 위치.
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

//node 구조체 정의
//여기서는 doubly linked list
struct Node
{
	Node* prev;   //앞선 node의 주솟값
	Node* next;   //다음 node의 주솟값

	//Student data; //node에 저장할 data
	void* data;   //Student타입의 data말고도 모든 type의 data를 부가적으로 저장 할 수 있다.
};

//Linked List에 해당하는 구조체 정의
//연결된 node들 중 첫번째 node를 가리키는 역할을 한다. 
struct List
{
	Node* head;
};

//Linked List의 생성 및 초기화
//반환 값: 새로운 링크드 리스트의 포인터.
List* createList()
{
	//head node를 만들고 초기화
	//head node는 data를 가지지 않고
	//단순히 위치(맨 앞자리)만 차지한다. 
	Node* head = new Node;
	head->prev = head;
	head->next = head;
	head->data = NULL;

	//링크드 리스트 생성 및 초기화.
	List* list = new List;

	//앞서만든 head node를 가리키도록 한다.
	list->head = head;
	std::cout << list << "\n";

	return list;
}

//새로운 node를 추가한다.
//node : 이 node뒤에 새로운 node가 추가된다.
//data : 새 node의 data.
void insertNodeAfter(Node* node, void* data)
{
	Node* before = node;
	Node* after = node->next;

	//1. 새로운 node 생성
	//   새로운 node의 next, prev를 지정.
	Node* newNode = new Node;
	newNode->data = data;
	newNode->prev = before;
	newNode->next = after;

	//2. newNode 전, 후 node 포인터 변경
	after->prev = newNode;
	before->next = newNode;

	//반드시 newNode의 next,prev 조정 후, 
	//앞 뒤 node의 next, prev 조정해야
}

//노드를 remove한다.
//node : remove 할 node
//deleteData : true면, node가 가리키는 data도 제거.
void removeNode(Node* node, bool deleteData)
{
	//1. remove하려는 앞, 뒤 node의 주소값 저장.
	Node* before = node->prev;
	Node* after = node->next;

	//2. before, after를 서로 연결
	before->next = after;
	after->prev = before;

	//3. node자신과 node의 data 삭제
	if (deleteData)
		delete node->data;  //true면, node의 data도 remove
	delete node;            //node 제거.
}

//node 탐색
//하나씩 탐색 하게 된다.
void showNames(List* students)
{
	//첫번째 data가 있는 node부터 탐색하기 위해
	//즉, headNode의 다음 node부터 시작.
	Node* current = students->head->next;

	while (current != students->head)
	{
		//현재 node에서 data를 꺼내온다.
		const Student* student = (Student*)current->data;
		
		//현재 node의 data의 name출력
		std::cout << student->name << "\n";

		//current가 다음 node로 가리키도록 한다.
		current = current->next;
	}
}

//모든 node정리 및 제거, 마지막으로 List정리 및 제거
void removeList(List* list, bool deleteData)
{
	Node* current = list->head;

	//do While을 사용한 이유: 일단 head Node제거 한 다음,  조건을 비교해야 하므로
	do
	{
		//head node를 우선 제거하기 전,
		//next node를 저장 시킨다.
		Node* next = current->next;

		if (deleteData)
			delete current->data;
		delete current;
		
		current = next;

	} while (current != list->head);

	//list 제거
	delete list;
}

Student* setStudentInfo()
{
	Student* student = new Student;
	std::cout << "학생 정보 입력" << "\n";
	std::cout << "이름:: ";
	std::cin >> student->name;
	std::cout << "국어성적 :: ";
	std::cin >> student->kor;
	std::cout << "영어성적 :: ";
	std::cin >> student->eng;
	std::cout << "수학 성적 :: ";
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