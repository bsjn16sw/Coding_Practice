#include<iostream>
using namespace std;

int main()
{
	int num, tmp, sum;
	cin >> num;
	for(int i=0; i<num; i++){
		sum = 0;
		for(int j=0; j<10; j++){
			cin >> tmp;
			if(tmp % 2 == 1)	sum += tmp;
		}
		cout << "#" << i+1 << " " << sum << "\n";
	}
}
