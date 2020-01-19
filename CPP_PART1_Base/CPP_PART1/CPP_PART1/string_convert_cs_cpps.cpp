#include<iostream>
#include<string>
#include<cstring>
using namespace std;

char* cpps_to_cs(string str)
{
	char* cstyle = new char[str.size() + 1];
	strcpy_s(cstyle, str.size() + 1, str.c_str());

	cstyle[0] = 'K';

	return cstyle;
}

string cs_to_cpps(const char* str)
{
	string s = str;
	s[0] = 'C';
	return s;
}


int main()
{
	string cppstyle = "cpp_to_cs";
	char cstyle[] = "cs_to_cpps";

	char* result1 = cpps_to_cs(cppstyle);
	cout << "origin :: " << cppstyle << ", converted :: " << result1 << "\n";

	string result2 = cs_to_cpps(&cstyle[0]);
	cout << "origin :: " << cstyle << ", converted :: " << result2 << "\n";

	return 0;
}
