#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, temp;
    cin >> N;

    unordered_set<int> s;
    for(int i=0; i<N; i++){
        cin >> temp;
        s.insert(temp);
    }

    cin >> M;
    for(int i=0; i<M; i++){
        cin >> temp;
        if(s.find(temp) != s.end())
            cout << "1\n";
        else
            cout << "0\n";
    }
}