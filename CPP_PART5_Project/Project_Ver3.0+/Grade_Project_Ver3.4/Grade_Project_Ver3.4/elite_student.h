#ifndef ELITE_STUDENT_H
#define ELITE_STUDENT_H

#include "student.h"

//'��� ����'�� �߰��� �����ϴ� ����л� class
//Student Class�� ��� �޴´�.
class EliteStudent : public Student
{
private:
	int advanced_eng;

public:
	EliteStudent(int sNo);
	~EliteStudent();

public:
	virtual void setInfo();
	virtual void showInfo(BaseOutput& out) const;

public:
	int getAdvancedEng() const { return this->advanced_eng; }
};
#endif