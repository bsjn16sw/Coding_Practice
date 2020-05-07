#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<climits>
#include<bitset>
using namespace std;

int N, M, H, C, min_city_dist = INT_MAX;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int calc_dist(pair<int, int> p, pair<int, int> q)
{
    return abs(p.first - q.first) + abs(p.second - q.second);
}

int calc_home_dist(int h, unsigned int mask)
{
    // h: 계산하고자 하는 집의 인덱스
    // mask: M개를 고른 치킨집 비트마스크

    int temp, min = INT_MAX;
    for(int i=0; i<C; i++){
        if(mask & (1 << i)){
            temp = calc_dist(home[h], chicken[i]);
            if(temp < min)  min = temp;
        }
    }

    return min;
}

int calc_city_dist(unsigned int mask)
{
    int city_dist = 0;
    for(int i=0; i<H; i++){
        city_dist += calc_home_dist(i, mask);
    }

    return city_dist;
}

void select_chicken(unsigned int mask, int k, int l, bool reverse)
{
    // k: 직전에 포함시킨 치킨집 인덱스
    // l: 지금까지 포함시킨 치킨집 개수

    if(l == M){
        //cout << bitset<32>(mask) << endl;
        if(reverse) mask = ~mask;
        int city_dist = calc_city_dist(mask);
        if(city_dist < min_city_dist)   min_city_dist = city_dist;
        return;
    }

    for(int i=k; i<C; i++){
        if(!(mask & (1 << i)))
            select_chicken(mask | (1 << i), i, l + 1, reverse);
    }
}

int main()
{
    cin >> N >> M;

    int cell;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> cell;
            if(cell == 1)
                home.push_back(make_pair(i, j));
            else if(cell == 2)
                chicken.push_back(make_pair(i, j));
        }
    }

    H = home.size();
    C = chicken.size();

    // 가령 13개의 치킨집 중 8개를 고른다면
    // 5개를 골라 mask만 반대로 뒤집어주면 되기 때문에
    // 시간을 절약하고자 reverse 인자를 뒀음.
    bool reverse = false;
    if(C - M < M){
        M = C - M;
        reverse = true;
    }
    select_chicken(0, 0, 0, reverse);

    cout << min_city_dist;
}