#include<iostream>
using namespace std;

void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void perm(unsigned int mask, int k, int n, int max, int arr[])
{
    if(k == n){
        print(arr, n);
        return;
    }
    for(int i=0; i<max; i++){
        if(mask & (1 << i))     continue;
        arr[k] = i;
        perm(mask | (1 << i), k + 1, n, max, arr);
    }
}

void combi(unsigned int mask, int k, int n, int max, int arr[], int prev)
{
    if(k == n){
        print(arr, n);
        return;
    }
    for(int i=prev+1; i<max; i++){
        if(mask & (1 << i))     continue;
        arr[k] = i;
        combi(mask | (1 << i), k + 1, n, max, arr, i);
    }
}

int main()
{
    int n = 3, max = 5;
    int arr[n];

    perm(0, 0, n, max, arr);
    cout << endl;
    combi(0, 0, n, max, arr, -1);
}