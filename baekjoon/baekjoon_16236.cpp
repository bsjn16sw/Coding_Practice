#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
#include<climits>
#define MAXN 20
using namespace std;

int N;
int aqua[MAXN][MAXN];
int shark_x, shark_y, shark_size = 2, shark_fish = 0;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

bool valid_index(int x, int y)
{
    return (0 <= x && x < N && 0 <= y && y < N);
}

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}

tuple<bool, int, int, int> find_fish()
{
    int small_fish = 0;

    // 현재 상어 크기보다 작은 물고기의 수를 셈
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (aqua[i][j] < shark_size && aqua[i][j]) small_fish++;
        }
    }

    // 작은 물고기가 없음 (끝)
    if (small_fish == 0)
        return make_tuple(false, 0, 0, 0);

    // 이동 가능한 곳의 좌표와 거리를 저장하는 큐
    queue<tuple<int, int, int> > q;
    q.emplace(shark_x, shark_y, 0);

    // 방문한 곳에 true 처리를 하는 배열
    bool visited[MAXN][MAXN] = { false };
    visited[shark_x][shark_y] = true;

    // 작은 물고기가 여러 마리일 경우 정렬하기 위한 벡터
    vector<pair<int, int> > v;

    int cx, cy, dist, nx, ny, last_dist = INT_MAX;
    while (!q.empty()) {
        tie(cx, cy, dist) = q.front(); q.pop();
        if (dist > last_dist) break;

        // 네 방향에 대해 검색함
        for (int i = 0; i < 4; i++) {
            nx = cx + dx[i]; ny = cy + dy[i];

            // 인덱스 아웃이거나 이미 방문한 곳이면 패스
            if (!valid_index(nx, ny)) continue;
            if (visited[nx][ny]) continue;

            // 큰 물고기
            if (shark_size < aqua[nx][ny]) continue;
            // 작은 물고기
            else if (aqua[nx][ny] < shark_size && aqua[nx][ny] != 0) {

                // 작은 물고기가 한 마리
                if (small_fish == 1)
                    return make_tuple(true, nx, ny, dist + 1);

                // 작은 물고기가 여러 마리
                last_dist = dist;
                v.emplace_back(nx, ny);
                visited[nx][ny] = true;
            }
            // 사이즈가 같은 물고기 또는 빈 공간
            else {
                q.emplace(nx, ny, dist + 1);
                visited[nx][ny] = true;
            }
        }
    }

    // 작은 물고기가 있어도 도달할 수 없어 v가 비어있을 수 있음
    if (v.empty())
        return make_tuple(false, 0, 0, 0);

    // 작은 물고기가 여러 마리인 경우 v를 소팅
    sort(v.begin(), v.end(), compare);
    return make_tuple(true, v.front().first, v.front().second, last_dist + 1);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> aqua[i][j];
            if (aqua[i][j] == 9) {
                shark_x = i; shark_y = j;
                aqua[i][j] = 0;
            }
        }
    }
    
    bool found;
    int nx, ny, dist, time = 0;

    while (true) {
        tie(found, nx, ny, dist) = find_fish();
        if (!found) break;

        shark_x = nx;
        shark_y = ny;
        shark_fish++;
        time += dist;
        aqua[nx][ny] = 0;

        if (shark_size == shark_fish) {
            shark_size++;
            shark_fish = 0;
        }
    }

    cout << time;
    return 0;
}