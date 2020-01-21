#include<iostream>
#include<string>
using namespace std;

/*
  # ���� ���
   - CPP������ java�� �ٸ��� class�� ���� ��� ���� �� �ִ�.
   - ������, 2���̻��� �θ� class�� ������ �̸��� �Լ��� �����ϸ�,
     �̸� ȣ���� �� �����ؾ� �Ѵ�. 

   *���ǻ� �ҽ��ڵ� ���� ���� ����.
*/

//�кλ� class
class UnderGradStudent
{
public:
    string name;
    string department;

    //�л���
    void warn()
    {
        cout << "UnderGradStudent's warn() called()" << "\n";
    }
};


//������ class
class DormStudent
{
public:
    string building;
    string roomNumber;

    //��� ���
    void warn()
    {
        cout << "DormStudent's warn() called()" << "\n";
    }
};

//����� ��� �кλ� class
//2���� class�� ���� ��� ����.
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

    std.name = "������";
    std.department = "Computer science";
    std.building = "A��";
    std.roomNumber = "2603";
    std.livedTerm = 1;

    //���� ��� �϶� �Լ� �̸� ���� �� �浹 ȸ��.
    std.UnderGradStudent::warn();
    std.DormStudent::warn();

    return 0;
}