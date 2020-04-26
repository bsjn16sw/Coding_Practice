#include<iostream>
using namespace std;

int N, M, K;
int map[20][20];
enum {EAST=1, WEST, NORTH, SOUTH};


void roll(int dice[], int* x, int* y, int move)
{
    int temp = dice[5];

    if(move == EAST){
        if(*y + 1 >= M)  return;
        (*y)++;
        dice[5] = dice[3];
        dice[3] = dice[2];
        dice[2] = dice[1];
        dice[1] = temp;
    }
    else if(move == WEST){
        if(*y - 1 < 0)   return;
        (*y)--;
        dice[5] = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[3];
        dice[3] = temp;
    }
    else if(move == NORTH){
        if(*x - 1 < 0)   return;
        (*x)--;
        dice[5] = dice[4];
        dice[4] = dice[2];
        dice[2] = dice[0];
        dice[0] = temp;
    }
    else{
        if(*x + 1 >= N)  return;
        (*x)++;
        dice[5] = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[4];
        dice[4] = temp;
    }

    if(map[*x][*y]){
        dice[5] = map[*x][*y];
        map[*x][*y] = 0;
    }
    else{
        map[*x][*y] = dice[5];
    }

    cout << dice[2] << '\n';
}

int main()
{
    int x, y;
    cin >> N >> M >> x >> y >> K;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> map[i][j];

    int dice[6] = {0};
    int move;
    for(int i=0; i<K; i++){
        cin >> move;
        roll(dice, &x, &y, move);
    }
}