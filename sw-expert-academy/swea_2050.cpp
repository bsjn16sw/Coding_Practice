#include<iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	
	int len = str.length();
	for(int i=0; i<len; i++)
		cout << str[i] - 64 << " ";
}
