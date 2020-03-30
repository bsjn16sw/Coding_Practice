#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int tp[n][2];
    for(int i=0; i<n; i++)
        cin >> tp[i][0] >> tp[i][1];

    int max_after[n];
    int next_avail_day;
    for(int i=n-1; i>=0; i--){
        next_avail_day = i + tp[i][0];
        if(next_avail_day > n)
            max_after[i] = 0;
        else if(next_avail_day == n)
            max_after[i] = tp[i][1];
        else
            max_after[i] = tp[i][1] + max_after[next_avail_day];
        

        if(i + 1 < n && max_after[i] < max_after[i + 1])
            max_after[i] = max_after[i + 1];
    }

    cout << max_after[0];
}
