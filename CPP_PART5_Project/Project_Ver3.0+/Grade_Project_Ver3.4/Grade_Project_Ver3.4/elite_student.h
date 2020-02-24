#ifndef ELITE_STUDENT_H
#define ELITE_STUDENT_H

#include "student.h"

//'고급 영어'를 추가로 수강하는 우등학생 class
//Student Class를 상속 받는다.
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