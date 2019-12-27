#include<iostream>
using namespace std;

int main()
{
	int t, a, b;
	char sign;
	cin >> t;
	
	for(int i=0; i<t; i++){
		cin >> a >> b;
		if(a > b)	sign = '>';
		else if(a == b)	sign = '=';
		else	sign = '<';
		
		cout << "#" << i+1 << " " << sign << "\n";
	}
}
