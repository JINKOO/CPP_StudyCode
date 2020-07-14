#ifndef ELITE_STUDENT_H
#define ELITE_STUDENT_H
#include "student.h"

class EliteStudent : public Student
{
private:
	int advanced_eng;

public:
	EliteStudent(int id_number);
	virtual ~EliteStudent();

public:
	virtual void setStudentInfo();
	virtual void showStudentInfo(BaseOutput& out) const;

	int getAdvancedEng() const { return this->advanced_eng; };
};
#endif