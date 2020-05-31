#include<iostream>
#define MAX_INNING 50
#define PLAYER 9
using namespace std;

int N;
int inning[MAX_INNING][9];
int max_score = 0;
enum {OUT, HIT1, HIT2, HIT3, HOMERUN};

void baseball(int order[])
{
    // 0번 선수를 4번 타자(인덱스 3)로 끼워 넣음
    // order는 dfs에서 다시 사용되는 포인터이므로
    // 새로운 배열 my_order가 필요
    int my_order[9];
    for(int i=0; i<3; i++)  my_order[i] = order[i];
    for(int i=3; i<8; i++)  my_order[i+1] = order[i];
    my_order[3] = 0;

    int score = 0, nth_player = 0;

    // N 이닝을 진행
    for(int i=0; i<N; i++){
        int outcount = 0;
        bool base1 = false, base2 = false, base3 = false;

        while(outcount < 3){
            switch(inning[i][ my_order[nth_player] ]){
                case(OUT):
                    outcount++; break;

                case(HIT1):
                    if(base3){ score++; base3 = false; }
                    if(base2){ base3 = true; base2 = false; }
                    if(base1){ base2 = true; base1 = false; }
                    base1 = true; break;

                case(HIT2):
                    if(base3){ score++; base3 = false; }
                    if(base2){ score++; base2 = false; }
                    if(base1){ base3 = true; base1 = false; }
                    base2 = true; break;

                case(HIT3):
                    if(base3){ score++; base3 = false; }
                    if(base2){ score++; base2 = false; }
                    if(base1){ score++; base1 = false; }
                    base3 = true; break;

                case(HOMERUN):
                    if(base3){ score++; base3 = false; }
                    if(base2){ score++; base2 = false; }
                    if(base1){ score++; base1 = false; }
                    score++; break;
            }
            nth_player = (nth_player + 1) % 9;
        }
    }

    max_score = max(max_score, score);
}

void dfs(unsigned int mask, int k, int prev, int order[])
{
    // order[0] ~ order[7]에 1 ~ 8의 순열을 만듦 (1번 ~ 8번 선수 순서 정하기)
    // order[8]은 그대로 0인 상태

    if(k == PLAYER-1){
        baseball(order);
        return;
    }

    for(int i=0; i<PLAYER-1; i++){
        if(mask & (1 << i)) continue;
        order[k] = i + 1;
        dfs(mask | (1 << i), k+1, i, order);
    }
}

int main()
{
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<PLAYER; j++){
            cin >> inning[i][j];
        }
    }

    int order[9] = {0};
    dfs(0, 0, -1, order);

    cout << max_score;
}
