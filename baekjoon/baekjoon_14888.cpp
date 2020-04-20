#include<iostream>
#include<cmath>
using namespace std;

int max_result = -pow(10, 8);
int min_result = pow(10, 8);
enum {ADD, SUB, MUL, DIV};

void calc_formula(int N, int order[], int nums[])
{
    int tmp_result = nums[0];

    for(int i=0; i<=N-2; i++){
        switch(order[i]){
            case ADD:
                tmp_result += nums[i+1];
                break;
            case SUB:
                tmp_result -= nums[i+1];
                break;
            case MUL:
                tmp_result *= nums[i+1];
                break;
            case DIV:
                tmp_result /= nums[i+1];
                break;
        }
    }

    if(tmp_result > max_result) max_result = tmp_result;
    if(tmp_result < min_result) min_result = tmp_result;
}

void make_order(int a, int s, int m, int d, int N, int k, int order[], int nums[])
{
    if(k >= N-1){
        calc_formula(N, order, nums);
        return;
    }

    if(a){
        order[k] = ADD;
        make_order(a-1, s, m, d, N, k+1, order, nums);
    }
    if(s){
        order[k] = SUB;
        make_order(a, s-1, m, d, N, k+1, order, nums);
    }
    if(m){
        order[k] = MUL;
        make_order(a, s, m-1, d, N, k+1, order, nums);
    }
    if(d){
        order[k] = DIV;
        make_order(a, s, m, d-1, N, k+1, order, nums);
    }
}

int main()
{
    int N;
    cin >> N;

    int nums[N];
    for(int i=0; i<N; i++)  cin >> nums[i];

    int a, s, m, d;
    cin >> a >> s >> m >> d;

    int order[N-1] = {-1};
    make_order(a, s, m, d, N, 0, order, nums);

    cout << max_result << "\n" << min_result;
}