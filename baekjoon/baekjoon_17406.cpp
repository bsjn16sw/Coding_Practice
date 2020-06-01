#include<iostream>
#include<climits>
#define MAXSIZE 50
#define MAXK 6
using namespace std;

int N, M, K;
int org_map[MAXSIZE][MAXSIZE] = {0};
int rotate_info[MAXK][3];
int min_score = INT_MAX;


void rotate_square(int sx, int sy, int n, int my_map[][MAXSIZE])
{
    int ex = sx + n, ey = sy + n;
    int tmp1, tmp2, tmp3;

    tmp1 = my_map[sx][ey];
    for(int i=ey-1; i>=sy; i--)  my_map[sx][i+1] = my_map[sx][i];

    tmp2 = my_map[ex][ey];
    for(int i=ex-1; i>=sx+1; i--)  my_map[i+1][ey] = my_map[i][ey];
    my_map[sx+1][ey] = tmp1;

    tmp3 = my_map[ex][sy];
    for(int i=sy+1; i<=ey-1; i++)    my_map[ex][i-1] = my_map[ex][i];
    my_map[ex][ey-1] = tmp2;

    for(int i=sx+1; i<=ex-1; i++)  my_map[i-1][sy] = my_map[i][sy];
    my_map[ex-1][sy] = tmp3;
}


int get_score(int my_map[][MAXSIZE])
{
    int local_min = INT_MAX, line_sum;

    for(int i=0; i<N; i++){
        line_sum = 0;
        for(int j=0; j<M; j++){
            line_sum += my_map[i][j];
        }
        local_min = min(local_min, line_sum);
    }

    return local_min;
}


void make_order(unsigned int mask, int k, int order[])
{
    if(k == K){
        // 회전시킬 맵을 org_map에서 복사해옴
        int my_map[MAXSIZE][MAXSIZE] = {0};
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                my_map[i][j] = org_map[i][j];
            }
        }

        // order에 따라 회전함
        for(int i=0; i<K; i++){
            int r = rotate_info[ order[i] ][0] - 1;
            int c = rotate_info[ order[i] ][1] - 1;
            int s = rotate_info[ order[i] ][2];

            int sx = r - s, sy = c - s, n = 2*s;
            for(int j=n; j>0; j-=2, sx++, sy++){
                rotate_square(sx, sy, j, my_map);
            }
        }

        min_score = min(min_score, get_score(my_map));
        return;
    }

    for(int i=0; i<K; i++){
        if(mask & (1 << i)) continue;
        order[k] = i;
        make_order(mask | (1 << i), k+1, order);
    }
}

int main()
{
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> org_map[i][j];
        }
    }

    for(int i=0; i<K; i++){
        for(int j=0; j<3; j++){
            cin >> rotate_info[i][j];
        }
    }

    int order[K] = {-1};
    make_order(0, 0, order);
    cout << min_score;
}