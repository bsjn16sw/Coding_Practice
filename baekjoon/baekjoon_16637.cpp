#include<iostream>
#include<cstdio>
#include<string>
#include<climits>
#include<queue>
using namespace std;

int N, nums_size, paren_size;
int nums[10] = {0};
int ops[9] = {0};
int max_result = INT_MIN;
enum {EMPTY, START, BLOCKED};

int calc_inner(int x, int y, int op)
{
    if(op == '+')   return x + y;
    else if(op == '-')  return x - y;
    else    return x * y;
}

int calc(int paren[])
{
    queue<int> numsQ;
    queue<int> opsQ;

    for(int i=0; i<paren_size; i++){
        switch(paren[i]){
            case(EMPTY):
                numsQ.emplace(nums[i]);
                opsQ.emplace(ops[i]);
                break;

            case(START):
                numsQ.emplace(calc_inner(nums[i], nums[i+1], ops[i]));
                break;

            case(BLOCKED):
                opsQ.emplace(ops[i]);
                break;
        }
    }

    if(paren[paren_size-1] != START)    numsQ.emplace(nums[nums_size-1]);

    // 이제 큐에 있는 것을 앞에서부터 계산
    int result = numsQ.front(); numsQ.pop();
    while(!opsQ.empty()){
        result = calc_inner(result, numsQ.front(), opsQ.front());
        numsQ.pop(); opsQ.pop();
    }

    return result;
}

void make_parenthesis(int prev, bool select, int paren[])
{
    int sp; // search point
    if(select)  sp = prev + 2;
    else    sp = prev + 1;

    // 괄호 만들기의 끝에 다다름
    if(sp >= paren_size){
        max_result = max(max_result, calc(paren));
        return;
    }

    // 아직 괄호를 만들지 확인하지 않은 곳이 있음
    paren[sp] = START;
    if(sp+1 < paren_size)   paren[sp+1] = BLOCKED;
    make_parenthesis(sp, true, paren);

    paren[sp] = EMPTY;
    if(sp+1 < paren_size)   paren[sp+1] = EMPTY;
    make_parenthesis(sp, false, paren);
}

int main()
{
    string s;
    cin >> N >> s;

    if(N == 1) { cout << s[0]; return 0; }
    else if(N == 3) {
        cout << calc_inner(s[0] - '0', s[2] - '0', s[1]);
        return 0;
    }

    for(int i=0; i<N; i++){
        if(i % 2)   ops[(int)(i/2)] = s[i];
        else    nums[i/2] = s[i] - '0';
    }

    nums_size = (int)(N/2) + 1;
    paren_size = nums_size - 1;

    int paren[paren_size] = {EMPTY};
    make_parenthesis(-1, false, paren);
    cout << max_result;
}