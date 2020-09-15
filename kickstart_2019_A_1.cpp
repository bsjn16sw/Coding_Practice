#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minTrain(int N, int P, vector<int> s){
	int minHour = 0;
	int temp = 0;
	
	// Sort vector in decreasing order
	sort(s.begin(), s.end(), greater<int>());
	
	// Set initial value of minHour with 1st case
	for(int j=1; j<P; j++){
		minHour += s[0] - s[j];
	}
	
	// Update minHour	
	for(int i=1; i<=N-P; i++){
		for(int j=1; j<P; j++){
			temp += s[i] - s[i + j];
		}
		minHour = min(minHour, temp);
		temp = 0;
	}
	
	return minHour;
}

int main()
{
	int T, N, P, temp;
	vector<int> skill;
	vector<int> hours;
	cin >> T;
	
	for(int i=0; i<T; i++){
		cin >> N;
		cin >> P;
		
		for(int j=0; j<N; j++){
			cin >> temp;
			skill.push_back(temp);
		}
		
		hours.push_back(minTrain(N, P, skill));
		skill.clear();
	}
	
	for(int i=0; i<T; i++){
		cout << "Case#" << i+1 << ": " << hours[i] << "\n";
	}
}
