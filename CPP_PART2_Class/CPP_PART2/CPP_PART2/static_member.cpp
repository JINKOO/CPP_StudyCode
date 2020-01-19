#include<iostream>
#include<string>
using namespace std;

/*
  static member(정적 멤버)
  - static member는 객체의 소유가 아닌 class의 소유이다.
  - 일반 멤버 변수, 함수는 각 객체가 소유하지만, static member는 class의 소유이며 class당 하나만 존재(공유).
  - 정적 멤버 변수의 정의는 class 외부에서 정의 하도록 한다.(일반 멤버는 class내부에서 정의해야한다.)
  - 정적 멤버 함수에서는 일반 멤버에 접근 할 수 없음 --> 누구 객체의 것이기 모르기 때문에
    --> 따라서 정적 멤버 함수 내에서는 일반 멤버 접근 할때, 객체.멤버로 접근 한다.
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

//static member 변수의 정의.
int Student::student_count = 0;

//static member 함수의 정의
void Student::print_student_count()
{
    //static member함수에서 일반 멤버 접근시, 누구것인지에 대하여 명시해야 한다.
    //그냥 name, sNo로는 접근 불가.
    Student std("", 0);
    std.name = "고진권";
    std.sNo = 4444;
  
    cout << "Studnet객체 수 : " << student_count << "\n";
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

//함수 종료시 만들었던 객체는 모두 소멸하게 된다.
void make_instance()
{
    cout << "make_instance() called" << "\n";
    Student st1("고진권", 11165);
    Student st2("박지상", 11188);

    Student::print_student_count();
}

int main()
{
 
    Student::print_student_count();

    Student std("박성준", 11192);

    Student::print_student_count();

    make_instance();

    Student::print_student_count();

    return 0;
}