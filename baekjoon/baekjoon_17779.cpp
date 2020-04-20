#include<iostream>
#include<climits>
using namespace std;

int city[20][20];
int total = 0;

int calc_area(int x, int y, int d1, int d2, int N)
{
    int area[6] = {0};

    for(int i=0; i<=d1; i++){
        for(int j=0; j<x+i; j++)    area[1] += city[j][y-i];
        for(int j=x+d2+i+1; j<=N-1; j++)    area[4] += city[j][y+d2-i];
    }

    for(int i=0; i<=d2; i++){
        for(int j=y+i+1; j<=N-1; j++)   area[2] += city[x+i][j];
        for(int j=0; j<y-d1+i; j++) area[3] += city[x+d1+i][j];
    }

    for(int i=0; i<x+d1; i++){
        for(int j=0; j<y-d1; j++)   area[1] += city[i][j];
    }

    for(int i=0; i<x; i++){
        for(int j=y+1; j<=N-1; j++) area[2] += city[i][j];
    }

    for(int i=x+d1+d2+1; i<=N-1; i++){
        for(int j=0; j<y-d1+d2; j++)    area[3] += city[i][j];
    }

    for(int i=x+d2+1; i<=N-1; i++){
        for(int j=y+d2+1; j<=N-1; j++)  area[4] += city[i][j];
    }

    area[5] = total - area[1] - area[2] - area[3] - area[4];

    int max_area = area[1], min_area = area[1];
    for(int i=2; i<=5; i++){
        if(area[i] > max_area)  max_area = area[i];
        if(area[i] < min_area)  min_area = area[i];
    }

    return max_area - min_area;
}

int make_bound(int N)
{
    int min_diff = INT_MAX, tmp_diff, max_d1, max_d2;

    for(int i=0; i<=N-3; i++){ // x
        for(int j=1; j<=N-2; j++){ // y
            max_d1 = j;
            max_d2 = N - 1 - j;

            for(int k=1; k<=max_d1; k++){ // d1
                for(int l=1; l<=min(max_d2, N-1-j+k); l++){ // d2
                    tmp_diff = calc_area(i, j, k, l, N);
                    if(tmp_diff < min_diff) min_diff = tmp_diff;
                }
            }
        }
    }

    return min_diff;
}

int main()
{
    int N;
    cin >> N;

    int tmp;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> tmp;
            total += tmp;
            city[i][j] = tmp;
        }
    }

    cout << make_bound(N);
}