#include<iostream>
#include<vector>
#include<utility>
#define WALL 3
using namespace std;

int lab[8][8] = {0};
int n, m;
vector<pair<int, int>> empty;
vector<pair<int, int>> virus;
int max_safe = 0;

void infect(int lab_cpy[8][8], pair<int, int> cur_virus)
{
    int x_axis[] = {0, 0, -1, 1};
    int y_axis[] = {-1, 1, 0, 0};
    int infected_x, infected_y;

    for(int i=0; i<4; i++){
        infected_x = cur_virus.first + x_axis[i];
        infected_y = cur_virus.second + y_axis[i];

        if(0 <= infected_x && infected_x < n && \
           0 <= infected_y && infected_y < m && \
           lab_cpy[infected_x][infected_y] == 0){
            lab_cpy[infected_x][infected_y] = 2;
            infect(lab_cpy, make_pair(infected_x, infected_y));
        }
    }
}

void calc_safe(unsigned long long mask)
{
    int lab_cpy[8][8];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            lab_cpy[i][j] = lab[i][j];
        }
    }

    int wall_num = 0;
    for(int i=0; i<empty.size(); i++){
        if(wall_num == WALL)    break;

        if(mask & (1ULL << i)){
            lab_cpy[empty[i].first][empty[i].second] = 1;
            wall_num++;
        }
    }
    
    for(int i=0; i<virus.size(); i++){
        infect(lab_cpy, virus[i]);
    }

    int safe = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(lab_cpy[i][j] == 0)  safe++;
        }
    }

    if(max_safe < safe){
        max_safe = safe;
    }
}

void make_walls(unsigned long long mask, int i, int cnt)
{
    if(cnt == WALL){
        calc_safe(mask);
        return;
    }

    for(int j=i; j<empty.size(); j++){
        if(mask & (1ULL << j)) continue;
        make_walls(mask | (1ULL << j), j, cnt + 1);
    }
}

int main()
{
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> lab[i][j];
            if(lab[i][j] == 0)
                empty.push_back(make_pair(i, j));
            else if(lab[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }

    make_walls(0, 0, 0);

    cout << max_safe << endl;
}
