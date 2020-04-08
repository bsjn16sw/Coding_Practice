#include<iostream>
using namespace std;

int N, L;

bool validate_line(int line[])
{
    int slope[N] = {0};
    bool valid_line;

    for(int i=0; i<N-1;){
        valid_line = true;

        if(line[i] == line[i+1])    i++;

        else if(line[i] == line[i+1] + 1){ // |__
            if(i + L >= N){
                valid_line = false;
                break;
            }
            for(int j=1; j<=L; j++){
                if(line[i+1] != line[i+j] || slope[i+j]){
                    valid_line = false;
                    break;
                }
            }
            if(valid_line){
                for(int j=1; j<=L; j++) slope[i+j] = 1;
                i = i + L;
            }
            else break;
        }

        else if(line[i] == line[i+1] - 1){ // __|
            if(i - L + 1 < 0){
                valid_line = false;
                break;
            }
            for(int j=0; j<L; j++){
                if(line[i] != line[i-j] || slope[i-j]){
                    valid_line = false;
                    break;
                }
            }
            if(valid_line){
                for(int j=0; j<L; j++)  slope[i-j] = 1;
                i++;
            }
            else break;
        }

        else{
            valid_line = false;
            break;
        }
    }

    return valid_line;
}

int main()
{
    cin >> N >> L;
    int arr[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)  cin >> arr[i][j];

    int line[N] = {0};
    int line_num = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)  line[j] = arr[i][j];
        if(validate_line(line)) line_num++;
    }

    for(int j=0; j<N; j++){
        for(int i=0; i<N; i++)  line[i] = arr[i][j];
        if(validate_line(line)) line_num++;
    }

    cout << line_num;
}