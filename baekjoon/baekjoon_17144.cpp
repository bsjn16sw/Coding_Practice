#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int R, C, T;
int arr[50][50];
vector<pair<int, int>> cleaner;

typedef struct _Dust
{
    int x; int y; int n;
} Dust;

bool valid_2_diffuse(int x, int y)
{
    bool valid = true;
    if(x < 0 || x >= R || y < 0 || y >= C)
        valid = false;
    if((cleaner[0].first == x && cleaner[0].second == y) || \
       (cleaner[1].first == x && cleaner[1].second == y))
        valid = false;
    return valid;
}

void diffuse()
{
    vector<Dust> dusts;
    Dust d;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j] >= 5){
                d.x = i; d.y = j; d.n = arr[i][j];
                dusts.push_back(d);
            }
        }
    }

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    for(int i=0; i<dusts.size(); i++){
        int dif_n = dusts[i].n / 5;
        int valid_dir = 0;

        for(int j=0; j<4; j++){
            int dif_x = dusts[i].x + dx[j];
            int dif_y = dusts[i].y + dy[j];

            if(valid_2_diffuse(dif_x, dif_y)){
                arr[dif_x][dif_y] += dif_n;
                valid_dir++;
            }
        }

        arr[dusts[i].x][dusts[i].y] -= (dif_n * valid_dir);
    }
}

void clean()
{
    // Upper side
    int x = cleaner[0].first;

    for(int i=x-2; i>=0; i--)
        arr[i+1][0] = arr[i][0];
    for(int j=1; j<=C-1; j++)
        arr[0][j-1] = arr[0][j];
    for(int i=1; i<=x; i++)
        arr[i-1][C-1] = arr[i][C-1];
    for(int j=C-2; j>=1; j--)
        arr[x][j+1] = arr[x][j];
    arr[x][1] = 0;

    // Lower side
    x = cleaner[1].first;
    for(int i=x+2; i<=R-1; i++)
        arr[i-1][0] = arr[i][0];
    for(int j=1; j<=C-1; j++)
        arr[R-1][j-1] = arr[R-1][j];
    for(int i=R-2; i>=x; i--)
        arr[i+1][C-1] = arr[i][C-1];
    for(int j=C-2; j>=1; j--)
        arr[x][j+1] = arr[x][j];
    arr[x][1] = 0;
}

int main()
{
    cin >> R >> C >> T;
    int temp;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> temp;
            if(temp == -1)  cleaner.push_back(make_pair(i, j));
            arr[i][j] = temp;
        }
    }

    for(int i=0; i<T; i++){
        diffuse();
        clean();
    }

    int result = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j] > 0)   result += arr[i][j];
        }
    }

    cout << result;
}