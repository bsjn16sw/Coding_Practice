#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

enum side {U, F, D, B, L, R};
const char org_cube[6][3][3] = { {{'w', 'w', 'w'}, {'w', 'w', 'w'}, {'w', 'w', 'w'}}, \
                                 {{'r', 'r', 'r'}, {'r', 'r', 'r'}, {'r', 'r', 'r'}}, \
                                 {{'y', 'y', 'y'}, {'y', 'y', 'y'}, {'y', 'y', 'y'}}, \
                                 {{'o', 'o', 'o'}, {'o', 'o', 'o'}, {'o', 'o', 'o'}}, \
                                 {{'g', 'g', 'g'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}}, \
                                 {{'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'}} };
char cube[6][3][3];

void rotate(int side, char dir)
{
    char save[3];

    if(dir == '+'){
        char temp[3][3];
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                temp[i][j] = cube[side][i][j];
            }
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cube[side][j][2-i] = temp[i][j];
            }
        }

        switch(side){
            case(U): // 확인함
                for(int i=0; i<3; i++)  save[i] = cube[L][0][i];
                for(int i=0; i<3; i++)  cube[L][0][i] = cube[F][0][i];
                for(int i=0; i<3; i++)  cube[F][0][i] = cube[R][0][i];
                for(int i=0; i<3; i++)  cube[R][0][i] = cube[B][0][i];
                for(int i=0; i<3; i++)  cube[B][0][i] = save[i];
                break;
            
            case(F): // 확인함
                for(int i=0; i<3; i++)  save[i] = cube[L][i][2];
                for(int i=0; i<3; i++)  cube[L][2-i][2] = cube[D][2][i]; // 수정
                for(int i=0; i<3; i++)  cube[D][2][i] = cube[R][i][0];
                for(int i=0; i<3; i++)  cube[R][i][0] = cube[U][2][i];
                for(int i=0; i<3; i++)  cube[U][2][2-i] = save[i]; // 수정
                break;

            case(D): // 확인함
                for(int i=0; i<3; i++)  save[i] = cube[R][2][i];
                for(int i=0; i<3; i++)  cube[R][2][i] = cube[F][2][i];
                for(int i=0; i<3; i++)  cube[F][2][i] = cube[L][2][i];
                for(int i=0; i<3; i++)  cube[L][2][i] = cube[B][2][i];
                for(int i=0; i<3; i++)  cube[B][2][i] = save[i];
                break;

            case(B): // 고침
                for(int i=0; i<3; i++)  save[i] = cube[R][i][2];
                for(int i=0; i<3; i++)  cube[R][i][2] = cube[D][0][i];
                for(int i=0; i<3; i++)  cube[D][0][2-i] = cube[L][i][0]; // 수정
                for(int i=0; i<3; i++)  cube[L][2-i][0] = cube[U][0][i]; // 수정
                for(int i=0; i<3; i++)  cube[U][0][i] = save[i];
                break;

            case(L): // 확인함
                for(int i=0; i<3; i++)  save[i] = cube[B][i][2];
                for(int i=0; i<3; i++)  cube[B][i][2] = cube[D][i][2];
                for(int i=0; i<3; i++)  cube[D][2-i][2] = cube[F][i][0]; // 수정
                for(int i=0; i<3; i++)  cube[F][i][0] = cube[U][i][0];
                for(int i=0; i<3; i++)  cube[U][2-i][0] = save[i]; // 수정
                break;

            case(R): // 확인함
                for(int i=0; i<3; i++)  save[i] = cube[F][i][2];
                for(int i=0; i<3; i++)  cube[F][2-i][2] = cube[D][i][0]; // 수정
                for(int i=0; i<3; i++)  cube[D][i][0] = cube[B][i][0];
                for(int i=0; i<3; i++)  cube[B][2-i][0] = cube[U][i][2]; // 수정
                for(int i=0; i<3; i++)  cube[U][i][2] = save[i];
                break;
        }
    }

    else{
        char temp[3][3];
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                temp[i][j] = cube[side][i][j];
            }
        }
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cube[side][2-j][i] = temp[i][j];
            }
        }

        switch(side){
            case(U): // 확인함
                for(int i=0; i<3; i++)  save[i] = cube[B][0][i];
                for(int i=0; i<3; i++)  cube[B][0][i] = cube[R][0][i];
                for(int i=0; i<3; i++)  cube[R][0][i] = cube[F][0][i];
                for(int i=0; i<3; i++)  cube[F][0][i] = cube[L][0][i];
                for(int i=0; i<3; i++)  cube[L][0][i] = save[i];
                break;
            
            case(F): // 확인함
                for(int i=0; i<3; i++)  save[i] = cube[U][2][i];
                for(int i=0; i<3; i++)  cube[U][2][i] = cube[R][i][0];
                for(int i=0; i<3; i++)  cube[R][i][0] = cube[D][2][i];
                for(int i=0; i<3; i++)  cube[D][2][2-i] = cube[L][i][2]; // 수정
                for(int i=0; i<3; i++)  cube[L][2-i][2] = save[i]; // 수정
                break;

            case(D): // 확인함
                for(int i=0; i<3; i++)  save[i] = cube[B][2][i];
                for(int i=0; i<3; i++)  cube[B][2][i] = cube[L][2][i];
                for(int i=0; i<3; i++)  cube[L][2][i] = cube[F][2][i];
                for(int i=0; i<3; i++)  cube[F][2][i] = cube[R][2][i];
                for(int i=0; i<3; i++)  cube[R][2][i] = save[i];
                break;

            case(B): // 고침
                for(int i=0; i<3; i++)  save[i] = cube[U][0][i];
                for(int i=0; i<3; i++)  cube[U][0][2-i] = cube[L][i][0]; // 수정
                for(int i=0; i<3; i++)  cube[L][2-i][0] = cube[D][0][i]; // 수정
                for(int i=0; i<3; i++)  cube[D][0][i] = cube[R][i][2];
                for(int i=0; i<3; i++)  cube[R][i][2] = save[i];
                break;

            case(L): // 확인함
                for(int i=0; i<3; i++)  save[i] = cube[U][i][0];
                for(int i=0; i<3; i++)  cube[U][i][0] = cube[F][i][0];
                for(int i=0; i<3; i++)  cube[F][2-i][0] = cube[D][i][2]; // 수정
                for(int i=0; i<3; i++)  cube[D][i][2] = cube[B][i][2];
                for(int i=0; i<3; i++)  cube[B][2-i][2] = save[i]; // 수정
                break;

            case(R):
                for(int i=0; i<3; i++)  save[i] = cube[U][i][2];
                for(int i=0; i<3; i++)  cube[U][2-i][2] = cube[B][i][0]; // 수정
                for(int i=0; i<3; i++)  cube[B][i][0] = cube[D][i][0];
                for(int i=0; i<3; i++)  cube[D][2-i][0] = cube[F][i][2]; // 수정
                for(int i=0; i<3; i++)  cube[F][i][2] = save[i];
                break;
        }
    }
}

int main()
{
    int T, N;
    cin >> T;

    string s;
    while(T--){
        copy(&org_cube[0][0][0], &org_cube[0][0][0] + 6*3*3, &cube[0][0][0]);

        cin >> N;
        while(N--){
            cin >> s;
            switch(s[0]){
                case('U'): rotate(U, s[1]); break;
                case('F'): rotate(F, s[1]); break;
                case('D'): rotate(D, s[1]); break;
                case('B'): rotate(B, s[1]); break;
                case('L'): rotate(L, s[1]); break;
                case('R'): rotate(R, s[1]); break;
            }
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout << cube[U][i][j];
            }
            cout << "\n";
        }
    }
}