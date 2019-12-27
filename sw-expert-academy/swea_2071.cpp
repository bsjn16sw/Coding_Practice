#include<iostream>
#include<cmath>
using namespace std;

float myRound(float x, int n){
    return (int)(x * pow(10, n-1) + 0.5) / pow(10, n-1);
}

int main()
{
	int t, sum, tmp;
	float avg;
	cin >> t;
	
	for(int i=0; i<t; i++){
		sum = 0;
		for(int j=0; j<10; j++){
			cin >> tmp;
			sum += tmp;
		}
		avg = (float)sum / 10;
		avg = myRound(avg, 1);
		cout << "#" << i+1 << " " << avg << "\n";
	}
}
