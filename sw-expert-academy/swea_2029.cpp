#include<iostream>
using namespace std;

int main()
{
	int t, a, b, q, r;
	cin >> t;
	
	for(int i=0; i<t; i++){
		cin >> a >> b;
		q = a / b;
		r = a % b;
		cout << "#" << i+1 << " " << q << " " << r << "\n";
	}
}
