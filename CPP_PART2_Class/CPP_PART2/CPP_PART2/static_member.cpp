#include<iostream>
#include<string>
using namespace std;

/*
  static member(���� ���)
  - static member�� ��ü�� ������ �ƴ� class�� �����̴�.
  - �Ϲ� ��� ����, �Լ��� �� ��ü�� ����������, static member�� class�� �����̸� class�� �ϳ��� ����(����).
  - ���� ��� ������ ���Ǵ� class �ܺο��� ���� �ϵ��� �Ѵ�.(�Ϲ� ����� class���ο��� �����ؾ��Ѵ�.)
  - ���� ��� �Լ������� �Ϲ� ����� ���� �� �� ���� --> ���� ��ü�� ���̱� �𸣱� ������
    --> ���� ���� ��� �Լ� �������� �Ϲ� ��� ���� �Ҷ�, ��ü.����� ���� �Ѵ�.
*/

class Student
{
public:
    string name;
    int sNo;

    //constructor, destructor
    Student(const string& name_arg, int stdNumber);
    ~Student();

public:
    //static member
    static int student_count;
    static void print_student_count();

};

//static member ������ ����.
int Student::student_count = 0;

//static member �Լ��� ����
void Student::print_student_count()
{
    //static member�Լ����� �Ϲ� ��� ���ٽ�, ������������ ���Ͽ� ����ؾ� �Ѵ�.
    //�׳� name, sNo�δ� ���� �Ұ�.
    Student std("", 0);
    std.name = "������";
    std.sNo = 4444;
  
    cout << "Studnet��ü �� : " << student_count << "\n";
}

Student::Student(const string& name_arg, int stdNumber)
{
    student_count++;
    
    name = name_arg;
    sNo = stdNumber;
}

Student::~Student()
{
    cout << "destructor called" << "\n";
    student_count--;
}

//�Լ� ����� ������� ��ü�� ��� �Ҹ��ϰ� �ȴ�.
void make_instance()
{
    cout << "make_instance() called" << "\n";
    Student st1("������", 11165);
    Student st2("������", 11188);

    Student::print_student_count();
}

int main()
{
 
    Student::print_student_count();

    Student std("�ڼ���", 11192);

    Student::print_student_count();

    make_instance();

    Student::print_student_count();

    return 0;
}