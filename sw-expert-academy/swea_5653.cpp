#include<iostream>
#include<map>
#include<set>
using namespace std;

const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };

int spread(map<pair<int, int>, pair<int, int> >& m, int K)
{
    int time = 1, cx, cy, nx, ny, live, birth;
    set<pair<int, int> > dead;

    while (time <= K) {
        for (auto mitr = m.begin(); mitr != m.end(); mitr++) {
            if ((birth = mitr->second.second) == time) continue;

            cx = mitr->first.first; cy = mitr->first.second;
            live = mitr->second.first;

            if (live + birth < time && time <= live * 2 + birth) {
                for (int i = 0; i < 4; i++) {
                    nx = cx + dx[i]; ny = cy + dy[i];

                    if (dead.find(make_pair(nx, ny)) != dead.end()) continue;
                    auto itr = m.find(make_pair(nx, ny));
                    if (itr != m.end()) {
                        if (itr->second.second == time && itr->second.first < live)
                            itr->second.first = live;
                        else continue;
                    }
                    else m.emplace(make_pair(nx, ny), make_pair(live, time));
                }
            }

            else if (live * 2 + birth < time) {
                dead.emplace(mitr->first.first, mitr->first.second);
                mitr = m.erase(mitr); mitr--;
            }
        }

        time++;
    }

    int result = 0;
    for (auto mitr = m.begin(); mitr != m.end(); mitr++) {
        live = mitr->second.first; birth = mitr->second.second;
        if (K < live * 2 + birth) result++;
    }

    return result;
}

int main()
{
    int T, N, M, K, tmp;
    cin >> T;

    map<pair<int, int>, pair<int, int> > m;
    for (int t = 1; t <= T; t++) {
        cin >> N >> M >> K;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> tmp;
                if (tmp) m.emplace(make_pair(i, j), make_pair(tmp, 0));
            }
        }
        cout << "#" << t << " " << spread(m, K) << "\n";
        m.clear();
    }

    return 0;
}