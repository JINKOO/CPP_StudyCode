#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	//Ver1������ �л� 3���� ���� ������ �����Ѵ�.
	int S1_No, S2_No, S3_No;          //�й�
	int S1_Kor, S2_Kor, S3_Kor;       //���� ����
	int S1_Math, S2_Math, S3_Math;    //���� ����
	int S1_Eng, S2_Eng, S3_Eng;       //���� ����
	float S1_Avg, S2_Avg, S3_Avg;     //���� ���
	float Total_Avg = 0.0f;           //��ü ���
	int number_of_students = 0;        //������� �Էµ� �л� ��

	while (1)
	{
		//�޴��� ����ؼ� �����ش�.
		cout << "\n-----------MENU-----------" << "\n";
		cout << "1. �л� ���� �߰�" << "\n";
		cout << "2. ��ü ���� ����" << "\n";
		cout << "Q. ���α׷� ����" << "\n";
		cout << "----------------------------\n\n";
		cout << "���ϴ� �۾��� ��ȣ�� �Է� �ϼ��� >> ";

		//�۾� �Է¹ޱ�
		char select_menu;
		cin >> select_menu;

		//���õ� ���� ���� ó��
		switch (select_menu)
		{
		case '1':
			//�л��� ���� �߰�
		{
			//3���� ������ �Է� �Ǿ����� �׸� �Է�
			if (number_of_students == 3)
			{
				cout << "\n�� �̻� �Է� �� �� �����ϴ�." << "\n";
				break;
			}

			//�� ���� �Է�
			int kor, math, eng;
			cout << "\n����, ����, ���� ������ �Է� �ϼ��� >> ";
			cin >> kor >> math >> eng;

			//��� ���
			float avg = float(kor + math + eng) / 3.0f;

			if (0 == number_of_students)
			{
				//1���� �л� �������� �Է�
				S1_No = number_of_students + 1;
				S1_Kor = kor;
				S1_Math = math;
				S1_Eng = eng;
				S1_Avg = avg;

				Total_Avg = S1_Avg;
			}
			else if (1 == number_of_students)
			{
				//2��° �л� �������� �Է�
				S2_No = number_of_students + 1;
				S2_Kor = kor;
				S2_Math = math;
				S2_Eng = eng;
				S2_Avg = avg;

				Total_Avg = (S1_Avg + S2_Avg) / 2;
			}

			else if (2 == number_of_students)
			{
				//3��° �л��� �������� �Է�
				S3_No = number_of_students + 1;
				S3_Kor = kor;
				S3_Math = math;
				S3_Eng = eng;
				S3_Avg = avg;

				Total_Avg = (S1_Avg + S2_Avg + S3_Avg) / 3;
			}

			//�Է� ���� �л� �� 1����
			number_of_students++;
			
			//�۾��� ���� �˸�
			cout << "\n�л��� ������ �ùٸ��� �Է� �Ǿ����ϴ�." << "\n";

			break;
		}
		case '2':
			//��ü ���� ����
		{
			//�Ǽ� ��� �� �Ҽ��� ���� 2�ڸ��� ǥ��.
			cout.precision(2);
			cout << fixed;

			cout << "\n	<��ü ���� ����>";
			cout << "\n   �й� ���� ���� ����   ���" << "\n";
			//cout << "\n��ü ���� ���Ⱑ ���� �Ǿ����ϴ�." << "\n";

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

			cout << "\n��ü ��� = " << Total_Avg << "\n";

			break;
		}
		case 'Q':
		case 'q':
			cout << "\n���α׷��� ���� �մϴ�." << "\n";
			return 0;
		default:
			//�� ���� ��ȣ ����
			cout << "\n�ùٸ� ���� �Է��� �ּ���" << "\n";
			break;
		}
	}
	return 0;
}