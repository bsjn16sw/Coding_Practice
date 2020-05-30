#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#define MAX 100
using namespace std;

int arr[MAX][MAX] = {0};

int r_arith(int r_num, int c_num)
{
    int max_c_num = 0;
    unordered_map<int, int> m;
    vector<pair<int, int> > v;

    for(int i=0; i<r_num; i++){
        for(int j=0; j<c_num; j++){
            if(!arr[i][j])  continue;

            auto itr = m.find(arr[i][j]);
            if(itr == m.end())  m.emplace(arr[i][j], 1);
            else    itr->second++;
        }

        for(auto itr=m.begin(); itr!=m.end(); itr++)
            v.emplace_back(itr->second, itr->first);
        sort(v.begin(), v.end());

        int idx = 0;
        for(int j=0; j<v.size(); j++){
            if(idx >= MAX)  break;
            arr[i][idx++] = v[j].second;
            arr[i][idx++] = v[j].first;
        }

        for(int j=idx; j<MAX; j++)  arr[i][j] = 0;
        if(idx > max_c_num) max_c_num = idx;

        m.clear();
        v.clear();
    }

    return max_c_num;
}

int c_arith(int r_num, int c_num)
{
    int max_r_num = 0;
    unordered_map<int, int> m;
    vector<pair<int, int> > v;

    for(int j=0; j<c_num; j++){
        for(int i=0; i<r_num; i++){
            if(!arr[i][j])  continue;

            auto itr = m.find(arr[i][j]);
            if(itr == m.end())  m.emplace(arr[i][j], 1);
            else    itr->second++;
        }

        for(auto itr=m.begin(); itr!=m.end(); itr++)
            v.emplace_back(itr->second, itr->first);
        sort(v.begin(), v.end());

        int idx = 0;
        for(int i=0; i<v.size(); i++){
            if(idx >= MAX)  break;
            arr[idx++][j] = v[i].second;
            arr[idx++][j] = v[i].first;
        }

        for(int i=idx; i<MAX; i++)  arr[i][j] = 0;
        if(idx > max_r_num) max_r_num = idx;

        m.clear();
        v.clear();
    }

    return max_r_num;
}

int main()
{
    int r, c, k;
    cin >> r >> c >> k;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }

    int r_num = 3, c_num = 3, result = 0;
    while(arr[r-1][c-1] != k){
        if(result > 100){
            result = -1;
            break;
        }

        if(r_num >= c_num)
            c_num = r_arith(r_num, c_num);
        else
            r_num = c_arith(r_num, c_num);
        
        result++;
    }

    cout << result;
}
