#include<iostream>
#include<vector>
#include<utility>
using namespace std;

typedef struct _CCTV {
    _CCTV(int _x, int _y, int _num): x(_x), y(_y), num(_num) {}
    int x, y, num, dir;
} CCTV;

enum {RIGHT, UP, LEFT, DOWN};

int N, M;
int map[8][8];
int map2[8][8];
vector<CCTV> cctvs;
const int possible_dirs[] = {0, 4, 2, 4, 4, 1};
int min_blind = 64;

void surveil_1_dir(int x, int y, int dir)
{
    if(dir == RIGHT){
        for(int j=y; j<M; j++){
            if(map[x][j] == 6)  break;
            map2[x][j] = 7;
        }
    }

    else if(dir == UP){
        for(int i=x; i>=0; i--){
            if(map[i][y] == 6)  break;
            map2[i][y] = 7;
        }
    }

    else if(dir == LEFT){
        for(int j=y; j>=0; j--){
            if(map[x][j] == 6)  break;
            map2[x][j] = 7;
        }
    }

    else{
        for(int i=x; i<N; i++){
            if(map[i][y] == 6)  break;
            map2[i][y] = 7;
        }
    }
}

void surveil()
{
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            map2[i][j] = map[i][j];
        }
    }

    for(int i=0; i<cctvs.size(); i++){
        int x = cctvs[i].x, y = cctvs[i].y;
        int num = cctvs[i].num, dir = cctvs[i].dir;

        if(num == 1 && dir == 0)    surveil_1_dir(x, y, RIGHT);
        else if(num == 1 && dir == 1)   surveil_1_dir(x, y, UP);
        else if(num == 1 && dir == 2)   surveil_1_dir(x, y, LEFT);
        else if(num == 1 && dir == 3)   surveil_1_dir(x, y, DOWN);
        else if(num == 2 && dir == 0){
            surveil_1_dir(x, y, RIGHT);
            surveil_1_dir(x, y, LEFT);
        }
        else if(num == 2 && dir == 1){
            surveil_1_dir(x, y, UP);
            surveil_1_dir(x, y, DOWN);
        }
        else if(num == 3 && dir == 0){
            surveil_1_dir(x, y, RIGHT);
            surveil_1_dir(x, y, UP);
        }
        else if(num == 3 && dir == 1){
            surveil_1_dir(x, y, RIGHT);
            surveil_1_dir(x, y, DOWN);
        }
        else if(num == 3 && dir == 2){
            surveil_1_dir(x, y, LEFT);
            surveil_1_dir(x, y, UP);
        }
        else if(num == 3 && dir == 3){
            surveil_1_dir(x, y, LEFT);
            surveil_1_dir(x, y, DOWN);
        }
        else if(num == 4 && dir == 0){
            surveil_1_dir(x, y, RIGHT);
            surveil_1_dir(x, y, LEFT);
            surveil_1_dir(x, y, UP);
        }
        else if(num == 4 && dir == 1){
            surveil_1_dir(x, y, RIGHT);
            surveil_1_dir(x, y, LEFT);
            surveil_1_dir(x, y, DOWN);
        }
        else if(num == 4 && dir == 2){
            surveil_1_dir(x, y, UP);
            surveil_1_dir(x, y, DOWN);
            surveil_1_dir(x, y, RIGHT);
        }
        else if(num == 4 && dir == 3){
            surveil_1_dir(x, y, UP);
            surveil_1_dir(x, y, DOWN);
            surveil_1_dir(x, y, LEFT);
        }
        else{
            surveil_1_dir(x, y, RIGHT);
            surveil_1_dir(x, y, UP);
            surveil_1_dir(x, y, LEFT);
            surveil_1_dir(x, y, DOWN);
        }
    }

    int blind = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!map2[i][j]) blind++;
        }
    }

    min_blind = min(blind, min_blind);
}

void DFS(int k)
{
    // k: 지금 새롭게 방향 지정하려는 CCTV 인덱스

    if(k == cctvs.size()){
        surveil();
        return;
    }

    int num = cctvs[k].num;
    for(int i=0; i<possible_dirs[num]; i++){
        cctvs[k].dir = i;
        DFS(k + 1);
    }
}

int main()
{
    cin >> N >> M;
    int temp;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> temp;
            map[i][j] = temp;
            if(1 <= temp && temp <= 5){
                CCTV cctv(i, j, temp);
                cctvs.push_back(cctv);
            }
        }
    }

    DFS(0);

    cout << min_blind;
}