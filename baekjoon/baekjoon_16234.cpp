#include<iostream>
#include<utility>
#include<tuple>
#include<cmath>
#include<cstring>
using namespace std;

int N, L, R;
int A[50][50];	// 인구
int B[50][50];	// 연합 번호
int C[2500];	// 연합 번호 별 각 나라의 새로운 인구

bool valid_unite(int x, int y, int temp_x, int temp_y)
{
	if(0 <= temp_x && temp_x < N && 0 <= temp_y && temp_y < N){
		if(B[temp_x][temp_y] == -1){
			int diff = abs(A[x][y] - A[temp_x][temp_y]);
			if(L <= diff && diff <= R){
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

pair<int, int> make_unite(int x, int y, int num)
{
	// x, y: 연합을 이룰 시작점 좌표 (B[x][y] == -1) 
	// num: 연합 번호
	
	B[x][y] = num;
	int people = A[x][y], nation = 1;
	
	int dx[] = {0, 0, -1, 1};
	int dy[] = {-1, 1, 0, 0};
	
	int temp_x, temp_y;
	for(int i=0; i<4; i++){
		temp_x = x + dx[i];
		temp_y = y + dy[i];
		
		if(valid_unite(x, y, temp_x, temp_y)){
			int add_people, add_nation;
			tie(add_people, add_nation) = make_unite(temp_x, temp_y, num);
			people += add_people;
			nation += add_nation;
		}
	}
	
	return make_pair(people, nation);
}

int main()
{
	cin >> N >> L >> R;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> A[i][j];
		}
	}
	
	int move = 0; // 인구 이동 횟수
	bool move_flag = false;
	int people, nation;
	
	while(true){
		int unite_num = 0;
		memset(B, -1, sizeof(B));
		memset(C, 0, sizeof(C));
		move_flag = false;
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(B[i][j] == -1){ // 연합을 이룰 시작점 (아직 연합이 없음)
					tie(people, nation) = make_unite(i, j, unite_num);
					if(nation > 1)	move_flag = true;
					
					C[unite_num] = people / nation;
					unite_num++;
				}
			}
		}
		
		if(move_flag){
			move++;
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					A[i][j] = C[B[i][j]]; // B[i][j]가 unite_num에 해당
				}
			}
		}
		else	break;
	}
	
	cout << move;
}
