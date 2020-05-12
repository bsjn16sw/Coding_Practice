#include<iostream>
#include<queue>
#include<utility>
#include<tuple>
#include<cmath>
using namespace std;

int cogwheel[4][8];

void rotate(int cog, int cw)
{
    int temp;
    if(cw == 1){ // Clockwise
        temp = cogwheel[cog][7];
        for(int i=6; i>=0; i--) // 덮어쓰지 않게 주의
            cogwheel[cog][i+1] = cogwheel[cog][i];
        cogwheel[cog][0] = temp;
    }

    else{ // Counter-clockwise
        temp = cogwheel[cog][0];
        for(int i=0; i<7; i++)
            cogwheel[cog][i] = cogwheel[cog][i+1];
        cogwheel[cog][7] = temp;
    }
}

void rotate_check(int cog, int cw)
{
    queue<pair<int, int>> q;
    int org_cw = cw;

    q.push(make_pair(cog, cw));

    for(int i=cog+1; i<4; i++){
        if(cogwheel[i-1][2] != cogwheel[i][6]){
            q.push(make_pair(i, -cw));
            cw = -cw;
        }
        else    break;
    }

    cw = org_cw;
    for(int i=cog-1; i>=0; i--){
        if(cogwheel[i][2] != cogwheel[i+1][6]){
            q.push(make_pair(i, -cw));
            cw = -cw;
        }
        else break;
    }

    int cog2, cw2;
    while(!q.empty()){
        tie(cog2, cw2) = q.front();
        rotate(cog2, cw2);
        q.pop();
    }
}

int calc_score()
{
    int score = 0;
    for(int i=0; i<4; i++){
        if(cogwheel[i][0] == 1){ // S pole
            score += pow(2, i);
        }
    }

    return score;
}

int main()
{
    string s;
    for(int i=0; i<4; i++){
        cin >> s;
        for(int j=0; j<8; j++){
            cogwheel[i][j] = s[j] - '0';
        }
    } 

    int r_num, r_cog, r_cw;
    cin >> r_num;
    for(int i=0; i<r_num; i++){
        cin >> r_cog >> r_cw;
        rotate_check(r_cog - 1, r_cw);
    }

    cout << calc_score();
}