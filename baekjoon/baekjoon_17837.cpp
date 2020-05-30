#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#define MAXN 12
#define MAXK 10
using namespace std;

typedef struct _Horse{
    _Horse(int _x, int _y, int _d): x(_x), y(_y), d(_d) {}
    int x, y, d;
}Horse;

int N, K;
int color[MAXN][MAXN];
vector<int> board[MAXN][MAXN]; // n
vector<Horse> horse_info; // x, y, d
enum {WHITE, RED, BLUE};

bool turn()
{
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    // K개의 말을 움직임
    int cx, cy, cd, nx, ny;
    for(int k=0; k<K; k++){

        // 각각 current x/y/d, next x/y
        cx = horse_info[k].x;
        cy = horse_info[k].y;
        cd = horse_info[k].d;
        nx = cx + dx[cd];
        ny = cy + dy[cd];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N || color[nx][ny] == BLUE){
            if(cd % 2 == 0)     horse_info[k].d++;
            else    horse_info[k].d--;

            nx = cx + dx[horse_info[k].d];
            ny = cy + dy[horse_info[k].d];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N || color[nx][ny] == BLUE); // stay
            else    k--;
        }

        else{ // 흰색 or 빨간색
            auto itr = find(begin(board[cx][cy]), end(board[cx][cy]), k);

            for(auto it=itr; it!=end(board[cx][cy]); it++){
                board[nx][ny].emplace_back(*it);
                horse_info[*it].x = nx;
                horse_info[*it].y = ny;
            }

            if(board[nx][ny].size() >= 4)  return false;
            board[cx][cy].erase(itr, end(board[cx][cy]));

            if(color[nx][ny] == RED){ // 빨간색이면 방금 추가한 부분 reverse
                auto rev_itr = find(begin(board[nx][ny]), end(board[nx][ny]), k);
                reverse(rev_itr, end(board[nx][ny]));
            }
        }
    }

    return true;
}

int main()
{
    cin >> N >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> color[i][j];
        }
    }

    int x, y, d;
    for(int i=0; i<K; i++){
        cin >> x >> y >> d;
        board[x-1][y-1].emplace_back(i);
        horse_info.emplace_back(x-1, y-1, d-1);
    }

    int turn_num = 0;
    bool go_flag = true;
    while(go_flag){
        turn_num++;
        if(turn_num > 1000){
            turn_num = -1;
            break;
        }
        go_flag = turn();
    }

    cout << turn_num;
}