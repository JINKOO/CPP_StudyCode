#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	//Ver1에서는 학생 3명의 성적 정보를 저장한다.
	int S1_No, S2_No, S3_No;          //학번
	int S1_Kor, S2_Kor, S3_Kor;       //국어 성적
	int S1_Math, S2_Math, S3_Math;    //수학 성적
	int S1_Eng, S2_Eng, S3_Eng;       //영어 성적
	float S1_Avg, S2_Avg, S3_Avg;     //개인 평균
	float Total_Avg = 0.0f;           //전체 평균
	int number_of_students = 0;        //현재까지 입력된 학생 수

	while (1)
	{
		//메뉴를 계속해서 보여준다.
		cout << "\n-----------MENU-----------" << "\n";
		cout << "1. 학생 성적 추가" << "\n";
		cout << "2. 전체 성적 보기" << "\n";
		cout << "Q. 프로그램 종료" << "\n";
		cout << "----------------------------\n\n";
		cout << "원하는 작업의 번호를 입력 하세요 >> ";

		//작업 입력받기
		char select_menu;
		cin >> select_menu;

		//선택된 값에 따른 처리
		switch (select_menu)
		{
		case '1':
			//학생의 성적 추가
		{
			//3명의 점수가 입력 되었으면 그만 입력
			if (number_of_students == 3)
			{
				cout << "\n더 이상 입력 할 수 없습니다." << "\n";
				break;
			}

			//각 과목 입력
			int kor, math, eng;
			cout << "\n국어, 수학, 영어 점수를 입력 하세요 >> ";
			cin >> kor >> math >> eng;

			//평균 계산
			float avg = float(kor + math + eng) / 3.0f;

			if (0 == number_of_students)
			{
				//1번쨰 학생 개인정보 입력
				S1_No = number_of_students + 1;
				S1_Kor = kor;
				S1_Math = math;
				S1_Eng = eng;
				S1_Avg = avg;

				Total_Avg = S1_Avg;
			}
			else if (1 == number_of_students)
			{
				//2번째 학생 개인정보 입력
				S2_No = number_of_students + 1;
				S2_Kor = kor;
				S2_Math = math;
				S2_Eng = eng;
				S2_Avg = avg;

				Total_Avg = (S1_Avg + S2_Avg) / 2;
			}

			else if (2 == number_of_students)
			{
				//3번째 학생의 개인정보 입력
				S3_No = number_of_students + 1;
				S3_Kor = kor;
				S3_Math = math;
				S3_Eng = eng;
				S3_Avg = avg;

				Total_Avg = (S1_Avg + S2_Avg + S3_Avg) / 3;
			}

			//입력 받은 학생 수 1증가
			number_of_students++;
			
			//작업의 성공 알림
			cout << "\n학생의 성적이 올바르게 입력 되었습니다." << "\n";

			break;
		}
		case '2':
			//전체 성적 보기
		{
			//실수 출력 시 소수점 이하 2자리만 표시.
			cout.precision(2);
			cout << fixed;

			cout << "\n	<전체 성적 보기>";
			cout << "\n   학번 국어 영어 수학   평균" << "\n";
			//cout << "\n전체 성적 보기가 선택 되었습니다." << "\n";

			for (int i = 0; i < number_of_students; i++)
			{
				if (i == 0)
				{
					cout << setw(7) << S1_No << setw(5) << S1_Kor << setw(5);
					cout << S1_Eng << setw(5) << S1_Math << setw(7) << S1_Avg << "\n";
				}

				else if (i == 1)
				{
					cout << setw(7) << S2_No << setw(5) << S2_Kor << setw(5) << S2_Eng << setw(5) << S2_Math << setw(7) << S2_Avg << "\n";
				}
				else
				{
					cout << setw(7) << S3_No << setw(5) << S3_Kor << setw(5) << S3_Eng << setw(5) << S3_Math << setw(7) << S3_Avg << "\n";
				}
			}

			cout << "\n전체 평균 = " << Total_Avg << "\n";

			break;
		}
		case 'Q':
		case 'q':
			cout << "\n프로그램을 종료 합니다." << "\n";
			return 0;
		default:
			//그 외의 번호 선택
			cout << "\n올바른 값을 입력해 주세요" << "\n";
			break;
		}
	}
	return 0;
}