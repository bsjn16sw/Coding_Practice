#include<iostream>
#include<cstdio>
#include<climits>
#define MAXSIZE 10
using namespace std;

int board[MAXSIZE][MAXSIZE] = {0};
int remained_paper[6] = {0, 5, 5, 5, 5, 5};
int min_paper = INT_MAX;
enum {EMPTY, OPEN, CLOSED};

bool can_attach(int sx, int sy, int size)
{
    if(sx + size - 1 >= MAXSIZE || \
       sy + size - 1 >= MAXSIZE || \
       !remained_paper[size])   return false;

    for(int i=sx; i<sx+size; i++){
        for(int j=sy; j<sy+size; j++){
            if(board[i][j] != OPEN) return false;
        }
    }

    return true;
}

void fill_board(int sx, int sy, int size, int num)
{
    for(int i=sx; i<sx+size; i++){
        for(int j=sy; j<sy+size; j++){
            board[i][j] = num;
        }
    }
}

void dfs(int sx, int sy, int used_paper)
{
    if(used_paper > min_paper)  return;

    register int i, j;
    bool fin_flag = true;
    for(i=sx; i<MAXSIZE; i++){
        for(j=0; j<MAXSIZE; j++){
            if(board[i][j] == OPEN){
                fin_flag = false; break;
            }
        }
        if(fin_flag == false)   break;
    }

    if(fin_flag){
        min_paper = min(min_paper, used_paper);
        return;
    }

    for(int size=5; size>=1; size--){
        if(can_attach(i, j, size)){

            remained_paper[size]--;
            fill_board(i, j, size, CLOSED);
            dfs(i, j, used_paper + 1);

            remained_paper[size]++;
            fill_board(i, j, size, OPEN);
        }
    }
}

int main()
{
    register int i, j;
    int count = 0;
    for(i=0; i<MAXSIZE; i++){
        for(j=0; j<MAXSIZE; j++){
            scanf("%d", &board[i][j]);
            if(board[i][j]) count++;
        }
    }

    if(count == MAXSIZE * MAXSIZE){
        printf("4"); return 0;
    }

    dfs(0, 0, 0);
    if(min_paper == INT_MAX)    min_paper = -1;
    printf("%d", min_paper);
    return 0;
}