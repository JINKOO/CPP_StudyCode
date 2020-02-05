#ifndef ELITE_STUDENT_H
#define ELITE_STUDENT_H

#include "student.h"

//'고급영어'를 추가적으로 수강하는 
//EliteStudent class
class EliteStudent : public Student
{
private:
	int advanced_eng;

public:
	EliteStudent(int sNo);
	~EliteStudent();

public:
	virtual void setInfo();
	virtual void showInfo() const;
};
#endif;