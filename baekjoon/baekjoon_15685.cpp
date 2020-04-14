#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void dragon_curve(int X, int Y, int D, int G, bool map[101][101])
{
    vector<int> dirs;
    dirs.push_back(D);

    int size;
    for(int i=1; i<=G; i++){
        size = dirs.size();
        for(int j=size-1; j>=0; j--){
            dirs.push_back((dirs[j] + 1) % 4);
        }
    }

    int dx[] = {0, -1, 0, 1};
    int dy[] = {1, 0, -1, 0};

    int cur_x = Y, cur_y = X;
    size = dirs.size();

    map[cur_x][cur_y] = true;

    for(int i=0; i<size; i++){
        cur_x += dx[dirs[i]];
        cur_y += dy[dirs[i]];

        map[cur_x][cur_y] = true;
    }
}

int main()
{
    int N;
    cin >> N;

    bool map[101][101] = {false};
    int x, y, d, g;
    for(int i=0; i<N; i++){
        cin >> x >> y >> d >> g;
        dragon_curve(x, y, d, g, map);
    }

    int square = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1]){
                square++;
            }
        }
    }

    cout << square;
}