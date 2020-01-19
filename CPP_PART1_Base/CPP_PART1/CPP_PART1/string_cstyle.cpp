#include<iostream>
#include<cstring>
using namespace std;

int my_strlen(const char* src);
char* my_strcpy_s(char* dest, int len, const char* src);

typedef int (*STR_FUNC1)(const char*);
typedef void (*STR_FUNC2)(char*, int, const char*);

int main()
{
	char src[] = "Hanbit-Media";
	STR_FUNC1 fp = &my_strlen;

	//1. 문자열 길이 함수(널 문자 제외 계산)
	int len1 = strlen(src);

	//2. 새 문자열이 담길 메모리 할당.
	char* dest1 = new char[len1 + 1];

	//3. 문자열 복사
	strcpy_s(dest1, len1 + 1, src);

	cout << "src : " << src << "\n";
	cout << "strlen : " << len1 << "\n";
	cout << "dest1 : " << dest1 << "\n";

	int len2 = fp(src);

	char* dest2 = new char[len2 + 1];
	
	my_strcpy_s(dest2, len2 + 1, src);

	cout << "src : " << src << "\n";
	cout << "strlen : " << len2 << "\n";
	cout << "dest2 : " << dest2 << "\n";

	delete[] dest1, dest2;
	dest1, dest2 = NULL;

	return 0;
}

int my_strlen(const char* src)
{
	int count = 0;
	while (*src != '\0')
	{
		count++;
		src++;
	}

	return count;
}

char* my_strcpy_s(char* dest, int len, const char* src)
{
	for (int i = 0; i < len; i++)
		dest[i] = src[i];

	return dest;
}