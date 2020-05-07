#include<iostream>
#include<unordered_map>
#include<utility>
using namespace std;

typedef struct Peo_Nat{
    int people;
    int nations;
} peo_nat;

int N, L, R;
int map[50][50];
int unite[50][50] = {0};
unordered_map<int, peo_nat> unite_map;

bool valid_idx(int x, int y)
{
    if(0 <= x && x < N && 0 <= y && y < N)
        return true;
    return false;
}

void DFS(int x, int y, int unite_num, int& people, int& nations)
{
    unite[x][y] = unite_num; // 해당 연합의 고유 번호
    people += map[x][y]; // 해당 연합에 포함된 나라의 인구수 합
    nations++; // 해당 연합에 포함된 나라 수

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    int temp_x, temp_y, diff;
    for(int i=0; i<4; i++){
        temp_x = x + dx[i];
        temp_y = y + dy[i];

        if(valid_idx(temp_x, temp_y) && !unite[temp_x][temp_y]){
            diff = abs(map[x][y] - map[temp_x][temp_y]);
            if(L <= diff && diff <= R){
                DFS(temp_x, temp_y, unite_num, people, nations);
            }
        }
    }
}

void move(int unite_num, int people, int nations)
{
    int distributed_people = people / nations;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(unite[i][j] == unite_num){
                map[i][j] = distributed_people;
            }
        }
    }
}

int main()
{
    cin >> N >> L >> R;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)  cin >> map[i][j];

    int unite_num = 1, people = 0, nations = 0, result = 0;
    bool move_flag = false;
    peo_nat pn;

    while(true){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!unite[i][j]){
                    DFS(i, j, unite_num, people, nations);
                    pn.people = people;
                    pn.nations = nations;
                    unite_map.insert(make_pair(unite_num, pn));

                    unite_num++;
                    people = 0;
                    nations = 0;
                }
            }
        }

        for(int i=0; i<unite_num; i++){
            people = (unite_map.find(i) -> second).people;
            nations = (unite_map.find(i) -> second).nations;

            if(nations >= 2){
                move(i, people, nations);
                move_flag = true;
            }
        }

        if(move_flag)   result++;
        else    break;

        move_flag = false;
        unite_map.clear();
    }

    cout << result;
}