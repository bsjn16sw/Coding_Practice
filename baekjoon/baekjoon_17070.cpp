#include<iostream>
#define MAXN 16
using namespace std;

int N;
int map[MAXN][MAXN];
enum cell { EMPTY, WALL };
enum direction { HOR, VIR, DIA };
int methods = 0;

// 이동할 때 쓸 델타 배열
const int dx[] = {0, 1, 1}; // HOR, VIR, DIA
const int dy[] = {1, 0, 1}; // HOR, VIR, DIA

// 현재 방향에 따라 이동할 수 있는 방향
const int moving[3][3] = { {HOR, DIA, -1}, {VIR, DIA, -1}, {HOR, VIR, DIA} };

bool is_valid(int x, int y)
{
    if(x < 0 || x >= N || y < 0 || y >= N || map[x][y] == WALL)
        return false;
    return true;
}

void dfs(int hx, int hy, int dir)
{
    // 한 번 이동했을 때 파이프의 head
    // 현재의 tail과 동일하므로 항상 valid한 index
    int next_hx = hx + dx[dir];
    int next_hy = hy + dy[dir];

    int next_tx, next_ty, next_dir;
    for(int i=0; i<3; i++){
        next_dir = moving[dir][i];
        if(next_dir == -1)  break;
        next_tx = next_hx + dx[next_dir];
        next_ty = next_hy + dy[next_dir];

        // valid 해야할 공간이 valid하지 않다면 무시함
        if(!is_valid(next_tx, next_ty)) continue;
        if(next_dir == DIA){
            if(!is_valid(next_hx + dx[HOR], next_hy + dy[HOR]) || \
               !is_valid(next_hx + dx[VIR], next_hy + dy[VIR])) continue;
        }

        // (next_tx, next_ty)가 (N-1, N-1)에 도달하면 끝냄
        if(next_tx == N-1 && next_ty == N-1){ methods++; continue; }

        dfs(next_hx, next_hy, next_dir);
    }

}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    dfs(0, 0, HOR);
    cout << methods;
}