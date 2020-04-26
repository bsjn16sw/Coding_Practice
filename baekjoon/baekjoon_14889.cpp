#include<iostream>
#include<climits>
using namespace std;

int N;
int syn[20][20];
int min_diff = INT_MAX;

void make_pair(unsigned int org_mask, unsigned int mask, int prev, int k, int* synergy)
{
    if(k == 2){
        unsigned pair_mask = org_mask ^ mask;
        int pair[2] = {-1};
        int j = 0;

        for(int i=0; i<N; i++){
            if(j >= 2)  break;
            if(pair_mask & (1 << i))    pair[j++] = i;
        }

        *synergy += syn[pair[0]][pair[1]];
        *synergy += syn[pair[1]][pair[0]];
        return;
    }

    for(int i=prev; i<N; i++){
        if(mask & (1 << i))  continue;
        make_pair(org_mask, mask | (1 << i), i, k + 1, synergy);
    }
}

void calc_diff(unsigned int mask)
{
    int syn1 = 0, syn2 = 0;
    make_pair(mask, mask, 0, 0, &syn1);
    make_pair(~mask, ~mask, 0, 0, &syn2);

    int diff = abs(syn1 - syn2);
    if(diff < min_diff) min_diff = diff;
}

void make_team(unsigned int mask, int prev, int k)
{
    if(k == N/2){
        calc_diff(mask);
        return;
    }

    for(int i=prev+1; i<N; i++){
        if(mask & (1 << i))  continue;
        make_team(mask | (1 << i), i, k + 1);
    }
}


int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)  cin >> syn[i][j];

    make_team(1, 0, 1);
    cout << min_diff;
}
