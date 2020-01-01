#include<iostream>
using namespace std;

int main()
{
	int n, result;
	cin >> n;
	
	result = (n + 1) * (n / 2);
	
	if(n % 2 == 0)
		cout << result;
	else{
		result += (n / 2) + 1;
		cout << result;
	}
		
}
