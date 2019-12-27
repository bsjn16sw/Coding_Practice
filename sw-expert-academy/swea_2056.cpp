#include<iostream>
#include<string>
using namespace std;

int isValidDate(string str)
{
	int month = stoi(str.substr(4, 2));
	if(month < 1 || month > 12)
		return -1;
	
	int day = stoi(str.substr(6, 2));
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(day > 31)	return -1;
			break;
		case 2:
			if(day > 28)	return -1;
			break;
		default:
			if(day > 30)	return -1;
			break;
	}
	
	return 0;
}

int main()
{
	int t, valid;
	cin >> t;
	
	string tmp;
	for(int i=0; i<t; i++){
		cin >> tmp;
		valid = isValidDate(tmp);
		
		cout << "#" << i+1 << " ";
		if(valid == -1)
			cout << "-1\n";
		else
			cout << tmp.substr(0, 4) << "/" << tmp.substr(4, 2) << "/" << tmp.substr(6, 2) << "\n";
	}
}
