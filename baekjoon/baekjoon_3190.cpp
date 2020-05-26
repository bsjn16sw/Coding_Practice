#include<iostream>
#include<list>
#include<queue>
#include<tuple>
using namespace std;

int N;
bool apple[100][100] = {false};
queue<pair<int, int> > q;
bool map[100][100] = {false};

enum {RIGHT, DOWN, LEFT, UP};
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};


int dummy(list<pair<int, int> >& snake, int dir, int cur_time)
{
    int nx = snake.begin()->first + dx[dir];
    int ny = snake.begin()->second + dy[dir];

    // 벽이나 자기 자신에 부딪히면 게임 오버
    if(nx < 0 || nx >= N || ny < 0 || ny >= N){
        return ++cur_time;
    }
    else if(map[nx][ny]){
        return ++cur_time;
    }

    // 머리 추가
    snake.emplace_front(nx, ny);
    map[nx][ny] = true;

    // 머리가 이동한 곳에 사과가 있는지 확인
    if(apple[nx][ny]){
        apple[nx][ny] = false;
    }
    else{
        int tx = (--snake.end())->first;
        int ty = (--snake.end())->second;
        map[tx][ty] = false;
        snake.pop_back();
    }

    // 방향 전환 확인
    if(!q.empty()){
        int rot_time, rot_dir;
        tie(rot_time, rot_dir) = q.front();

        if(rot_time == ++cur_time){
            q.pop();
            if(rot_dir == RIGHT)    dir = (dir + 1) % 4;
            else{
                if(dir == 0)    dir = 3;
                else    dir--;;
                /* 이거 안 됨...^^
                dir = (dir - 1) % 4;
                */
            }
        }
    }
    else{
        ++cur_time;
    }
    
    return dummy(snake, dir, cur_time);
}

int main()
{
    int K, L;
    cin >> N >> K;

    int x, y;
    for(int i=0; i<K; i++){
        cin >> x >> y;
        apple[x-1][y-1] = true;
    }

    cin >> L;
    char c;
    for(int i=0; i<L; i++){
        cin >> x >> c;
        if(c == 'D')    q.push(make_pair(x, RIGHT));
        else    q.push(make_pair(x, LEFT));
    }

    list<pair<int, int> > snake;
    snake.emplace_front(0, 0);
    map[0][0] = true;

    cout << dummy(snake, RIGHT, 0);
}