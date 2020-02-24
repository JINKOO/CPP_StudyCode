#include "students.h"
#include "student.h"
#include "elite_student.h"
#include "baseoutput.h"
#include "console_output.h"
#include "html_output.h"
#include "textfile_output.h"

Students::Students()
	:list(&Students::deleteData)
{
	this->number_of_students = 0;
	this->total_avg = 0.0f;
}

Students::~Students()
{

}

bool Students::addStudent(bool is_genral)
{
	//1. 학생 한명의 정보 입력
	Student* student = NULL;
	
	if (is_genral)
		student = new Student(this->number_of_students + 1);
	else
		student = new EliteStudent(this->number_of_students + 1);
	
	student->setStdInfo();

	//2. 전체 평균, 학생 수 조정
	int previous = this->number_of_students;
	int current = this->number_of_students + 1;

	total_avg = (total_avg * previous + student->getAvg()) / current;
	this->number_of_students++;

	//3. List에 추가.
	this->list.insertAfterNode(this->list.getTail(), student);

	return true;
}

void Students::showAllList(FORMAT format) const
{
	BaseOutput* out = NULL;
	if (format == FORMAT::CONSOLE)
		out = new ConsoleOutput();
	else if (format == FORMAT::TEXTFILE)
		out = new TextFileOutput("report.txt");
	else
		out = new HTMLOutput("report.html");

	//1. 성적표 table 시작
	out->beginTable("<전체 성적 보기>");

	//2. 성적표에 header 지정
	std::string header[7] = { "학번", "이름", "국어", "영어", "수학", "고급영어", "평균" };
	out->putHeaders(header, 7);


	//3. 모든 Node의 출력
	Node* current = this->list.getHead()->getNext();
	while (current != this->list.getHead())
	{
		Student* student = (Student*)current->getData();
		
		student->showStdInfo(*out);
		
		current = current->getNext();
	}

	//4. 성적표 출력 끝 알림
	out->endTable();

	//5. 전체 평균의 정보를 하나의 문자열로 만든다.
	std::stringstream ss;
	ss.precision(2);
	ss << std::fixed;
	ss << "전체 평균 = " << this->total_avg;

	out->write(ss.str());

	delete out;
	out = NULL;
}

void Students::deleteData(void* data)
{
	//각 node의 void* data를 삭제
	delete (Student*)data;
}