#include<iostream>
#include<string>
using namespace std;

/*
  # 다중 상속
   - CPP에서는 java와 다르게 class를 다중 상속 받을 수 있다.
   - 하지만, 2개이상의 부모 class에 동일한 이름의 함수가 존재하면,
     이를 호출할 때 구분해야 한다. 

   *편의상 소스코드 분할 하지 않음.
*/

//학부생 class
class UnderGradStudent
{
public:
    string name;
    string department;

    //학사경고
    void warn()
    {
        cout << "UnderGradStudent's warn() called()" << "\n";
    }
};


//기숙사생 class
class DormStudent
{
public:
    string building;
    string roomNumber;

    //퇴실 경고
    void warn()
    {
        cout << "DormStudent's warn() called()" << "\n";
    }
};

//기숙사 사는 학부생 class
//2개의 class로 부터 상속 받음.
class UnderGrad_DormStudent :
    public UnderGradStudent,
    public DormStudent
{
public:
    int livedTerm;

};

int main()
{
    UnderGradStudent ugs;
    DormStudent ds;
    UnderGrad_DormStudent std;

    cout << "UnderGradStudent's instance(Parent) size : " << sizeof(ugs) << "\n";
    cout << "DormStudens's instance size(Parent) : " << sizeof(ds) << "\n";
    cout << "UnderGrad_DormStudent's instnace size(Child) : " << sizeof(std) << "\n";

    std.name = "고진권";
    std.department = "Computer science";
    std.building = "A동";
    std.roomNumber = "2603";
    std.livedTerm = 1;

    //다중 상속 일때 함수 이름 같을 때 충돌 회피.
    std.UnderGradStudent::warn();
    std.DormStudent::warn();

    return 0;
}