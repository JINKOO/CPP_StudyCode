#ifndef ELITE_STUDENT_H
#define ELITE_STUDENT_H

#include "student.h"

class EliteStudent : public Student
{
private:
	int advanced_eng;

public:
	EliteStudent(int student_id);
	~EliteStudent();

public:
	virtual void setStdInfo();
	virtual void showStdInfo() const;

	int getAdvancedEng() const { return this->advanced_eng; }
};

#endif