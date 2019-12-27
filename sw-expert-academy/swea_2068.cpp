#include<iostream>
using namespace std;

int main()
{
	int t, tmp, max;
	cin >> t;
	
	for(int i=0; i<t; i++){
		cin >> tmp;
		max = tmp;
		for(int j=1; j<10; j++){
			cin >> tmp;
			if(tmp > max)	max = tmp;
		}
		cout << "#" << i+1 << " " << max << "\n";
	}
}
