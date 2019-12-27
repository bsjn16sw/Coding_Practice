#include<iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	
	int len = str.length();
	string result = "";
	for(int i=0; i<len; i++){
		if(97 <= str[i] && str[i] <= 122)
			result += str[i] - 32;
		else
			result += str[i];
	}
	
	cout << result;
}
