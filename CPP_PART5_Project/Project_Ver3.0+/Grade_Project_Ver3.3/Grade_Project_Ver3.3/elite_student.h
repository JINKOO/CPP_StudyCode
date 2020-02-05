#ifndef ELITE_STUDENT_H
#define ELITE_STUDENT_H

#include "student.h"

//'��޿���'�� �߰������� �����ϴ� 
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