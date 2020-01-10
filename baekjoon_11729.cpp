#include<iostream>
#include<cmath>
using namespace std;

void hanoi(int num, int from, int sub, int to)
{
	// Terminate condition:
	// if one disk remained, just move it from -> to.
	if(num == 1)	cout << from << " " << to << "\n";
	
	// Recursive:
	// 1) Move (num - 1) disks from -> sub.
	// 2) Move one disk from -> to. (Just print it)
	// 3) Move (num - 1) disks sub -> to.
	else{
		hanoi(num - 1, from, to, sub);
		cout << from << " " << to << "\n";
		hanoi(num - 1, sub, from, to);
	}
}

int main()
{
	int num;
	cin >> num;
	
	// It takes 2^num - 1 times.
	cout << (int)(pow(2, num) - 1) << "\n";
	hanoi(num, 1, 2, 3);
}
