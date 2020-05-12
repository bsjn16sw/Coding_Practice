#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int map[500][500];

bool valid_idx(int x, int y)
{
    if(0 <= x && x < N && 0 <= y && y < M)
        return true;
    return false;
}

int main()
{
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)  cin >> map[i][j];
    }

    short dx[][4] = {{0, 0, 0, 0}, {0, 1, 2, 3}, {0, 0, 1, 1}, \
                     {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 0, 1, 2}, {0, 0, 0, -1}, \
                     {0, 1, 2, 2}, {0, 1, 1, 1}, {0, 1, 2, 0}, {0, 0, 0, 1}, \
                     {0, 1, 1, 2}, {0, 1, 1, 2}, {0, 0, -1, -1}, {0, 0, 1, 1}, \
                     {0, 0, 0, 1}, {0, 0, 0, -1}, {0, 1, 1, 2}, {0, 1, 1, 2}};

    short dy[][4] = {{0, 1, 2, 3}, {0, 0, 0, 0}, {0, 1, 0, 1}, \
                     {0, 0, 0, 1}, {0, 1, 2, 0}, {0, 1, 1, 1}, {0, 1, 2, 2}, \
                     {0, 0, 0, -1}, {0, 0, 1, 2}, {0, 0, 0, 1}, {0, 1, 2, 2}, \
                     {0, 0, 1, 1}, {0, 0, -1, -1}, {0, 1, 1, 2}, {0, 1, 1, 2}, \
                     {0, 1, 2, 1}, {0, 1, 2, 1}, {0, 0, 1, 0}, {0, -1, 0, 0}};

    int result = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<19; k++){
                bool valid_sum = true;
                for(int l=0; l<4; l++){
                    if(!valid_idx(i + dx[k][l], j + dy[k][l])){
                        valid_sum = false;
                        break;
                    }
                }

                if(!valid_sum)  continue;

                int sum = 0;
                for(int l=0; l<4; l++){
                    sum += map[i + dx[k][l]][j + dy[k][l]];
                }

                result = max(result, sum);
            }
        }
    }

    cout << result;
}