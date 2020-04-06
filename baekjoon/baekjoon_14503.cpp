#include<iostream>
using namespace std;

enum { EMPTY, WALL, CLEAN };
enum { NORTH, WEST, SOUTH, EAST };

int main()
{
    int n, m;
    cin >> n >> m;

    int x, y, d;
    cin >> x >> y >> d;
    if(d == WEST)   d = EAST;
    else if(d == EAST)  d = WEST;

    int room[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> room[i][j];
        }
    }

    int left_x[] = {0, 1, 0, -1};
    int left_y[] = {-1, 0, 1, 0};

    int back_x[] = {1, 0, -1, 0};
    int back_y[] = {0, 1, 0, -1};

    int closed = 1;

    while(1){
        room[x][y] = CLEAN;

        if(room[x + left_x[d]][y + left_y[d]] == EMPTY){
            x += left_x[d];
            y += left_y[d];
            d++;
            if(d == 4)  d = NORTH;
        }
        else{
            closed = 1;
            for(int i=0; i<4; i++){
                if(room[x + left_x[i]][y + left_y[i]] == EMPTY){
                    closed = 0;
                    break;
                }
            }

            if(!closed){
                d++;
                if(d == 4)  d = NORTH;
            }
            else if(room[x + back_x[d]][y + back_y[d]] == WALL){
                break;
            }
            else{
                x += back_x[d];
                y += back_y[d];
            }
        }
    }

    int clean_num = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(room[i][j] == CLEAN) clean_num++;
        }
    }

    cout << clean_num;
}