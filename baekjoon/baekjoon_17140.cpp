#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<int>> r_arith(vector<vector<int> >& v, int R, int C)
{
    vector<unordered_map<int, int> > vm(R);

    int max_pair = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(!v[i][j])    continue;

            auto itr = vm[i].find(v[i][j]);
            if(itr == vm[i].end()){
                vm[i].insert(make_pair(v[i][j], 1));
            }
            else{
                itr->second += 1;
            }
        }
        if(max_pair < vm[i].size()) max_pair = vm[i].size();
    }

    vector<vector<int> > v2(R, vector<int>(min(max_pair*2, 100)));
    vector<pair<int, int> > v_sort;
    for(int i=0; i<R; i++){
        for(auto j=vm[i].begin(); j!=vm[i].end(); j++){
            v_sort.emplace_back(j->second, j->first);
        }
        sort(v_sort.begin(), v_sort.end());

        int idx = 0;
        for(int j=0; j<v_sort.size(); j++){
            if(idx > 100)   break;
            v2[i][idx++] = v_sort[j].second;
            v2[i][idx++] = v_sort[j].first;
        }

        v_sort.clear();
    }

    return v2;
}

vector<vector<int>> c_arith(vector<vector<int> >& v, int R, int C)
{
    vector<unordered_map<int, int> > vm(C);

    int max_pair = 0;
    for(int j=0; j<C; j++){
        for(int i=0; i<R; i++){
            if(!v[i][j])    continue;

            auto itr = vm[j].find(v[i][j]);
            if(itr == vm[j].end()){
                vm[j].insert(make_pair(v[i][j], 1));
            }
            else{
                itr->second += 1;
            }
        }
        if(max_pair < vm[j].size()) max_pair = vm[j].size();
    }

    vector<vector<int> > v2(min(max_pair*2, 100), vector<int>(C));
    vector<pair<int, int> > v_sort;
    for(int i=0; i<C; i++){
        for(auto j=vm[i].begin(); j!=vm[i].end(); j++){
            v_sort.emplace_back(j->second, j->first);
        }
        sort(v_sort.begin(), v_sort.end());

        int idx = 0;
        for(int j=0; j<v_sort.size(); j++){
            if(idx > 100)   break;
            v2[idx++][i] = v_sort[j].second;
            v2[idx++][i] = v_sort[j].first;
        }

        v_sort.clear();
    }

    return v2;
}


int main()
{
    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<int>> v(3, vector<int>(3));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> v[i][j];
        }
    }

    int R = 3, C = 3, time = 0;
    vector<vector<int>> v2;

    while(true){
        if(time > 100)  break;
        if(v[r-1][c-1] == k)    break;

        if(R >= C)  v2 = r_arith(v, R, C);
        else    v2 = c_arith(v, R, C);

        v2.swap(v);
        v2.clear();
        R = v.size();
        C = v[0].size();
        time++;
    }

    if(time > 100)  cout << "-1";
    else    cout << time;
}