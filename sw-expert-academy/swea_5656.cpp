#include<iostream>
#include<algorithm>
#include<climits>
#include<cstdio>
#define MAXN 4
#define MAXW 12
#define MAXH 15
using namespace std;

int N, W, H;
int org_board[MAXH][MAXW];
int my_board[MAXH][MAXW];
int order[MAXN] = { 0 };
bool visited[MAXH][MAXW];
int min_left_bricks = INT_MAX;
enum {UP, DOWN, LEFT, RIGHT};

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

void shoot(int x, int y)
{
    int break_num = my_board[x][y] - 1;

    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i] * break_num;
        ny = y + dy[i] * break_num;

        // (x, y)는 무조건 터짐
        visited[x][y] = true;

        if (i == UP) {
            for (int j = x - 1; j >= nx; j--) {
                if (j < 0 || j >= H || y < 0 || y >= W) break;

                if (my_board[j][y] == 1 && !visited[j][y]) {
                    visited[j][y] = true;
                }
                else if (my_board[j][y] > 1 && !visited[j][y]) {
                    visited[j][y] = true;
                    shoot(j, y);
                }
            }
        }

        else if (i == DOWN) {
            for (int j = x + 1; j <= nx; j++) {
                if (j < 0 || j >= H || y < 0 || y >= W) break;

                if (my_board[j][y] == 1 && !visited[j][y]) {
                    visited[j][y] = true;
                }
                else if (my_board[j][y] > 1 && !visited[j][y]) {
                    visited[j][y] = true;
                    shoot(j, y);
                }
            }
        }

        else if (i == LEFT) {
            for (int j = y - 1; j >= ny; j--) {
                if (x < 0 || x >= H || j < 0 || j >= W) break;

                if (my_board[x][j] == 1 && !visited[x][j]) {
                    visited[x][j] = true;
                }
                else if (my_board[x][j] > 1 && !visited[x][j]) {
                    visited[x][j] = true;
                    shoot(x, j);
                }
            }
        }

        else {
            for (int j = y + 1; j <= ny; j++) {
                if (x < 0 || x >= H || j < 0 || j >= W) break;

                if (my_board[x][j] == 1 && !visited[x][j]) {
                    visited[x][j] = true;
                }
                else if (my_board[x][j] > 1 && !visited[x][j]) {
                    visited[x][j] = true;
                    shoot(x, j);
                }
            }
        }

    }
}

void break_brick()
{
    // my_board에 org_board를 복사
    for (int i = 0; i < MAXH; i++) {
        for (int j = 0; j < MAXW; j++) {
            my_board[i][j] = org_board[i][j];
        }
    }

    // 각 열마다 남아있는 벽돌 수를 셈
    int left_bricks[MAXW] = { 0 };
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H; i++) {
            if (my_board[i][j]) left_bricks[j]++;
        }
    }
    
    fill_n(*visited, sizeof(visited), false);

    // order를 traverse
    for (int i = 0; i < N; i++) {
        if (!left_bricks[order[i]]) continue;

        for (int j = 0; j < H; j++) {
            if (my_board[j][order[i]]) { shoot(j, order[i]); break; }
        }

        // 남은 벽돌을 아래쪽으로 당김
        int point;
        for (int b = 0; b < W; b++) {
            point = H - 1;
            for (int a = H - 1; a >= 0; a--) {
                if (!my_board[a][b]) break;

                if (!visited[a][b]) {
                    my_board[point][b] = my_board[a][b];
                    point--;
                }
            }

            for (int a = point; a >= 0; a--) {
                my_board[a][b] = 0;
            }

            left_bricks[b] = H - 1 - point;
        }

        // visited를 다시 false로 초기화
        fill_n(*visited, sizeof(visited), false);
    }

    int sum = 0;
    for (const auto& lb : left_bricks) {
        sum += lb;
    }
    min_left_bricks = min(min_left_bricks, sum);
}

void make_order(int k)
{
    if (k == N) {
        break_brick();
        return;
    }

    for (int i = 0; i < W; i++) {
        order[k] = i;
        make_order(k + 1);
    }
}

int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> W >> H;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> org_board[i][j];
            }
        }

        make_order(0);

        cout << "#" << t << " " << min_left_bricks << "\n";
        min_left_bricks = INT_MAX;
    }
}