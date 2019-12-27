class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS so use Queue
        queue<pair<int, int>> q;
        int ROW = grid.size(), COL = grid[0].size();
        int pushNum = 0;
        
        // Push coordinate of 2-valued element to Queue
        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i, j));
                    pushNum++;
                }
            }
        }
        
        int pushNumNext = 0;
        int r, c;
        int time = 0;
        
        while(!q.empty()){
            if(!pushNum){
                time++;
                pushNum = pushNumNext;
                pushNumNext = 0;
            }
            
            r = q.front().first;
            c = q.front().second;
            
            // Push adjacent and 1-valued element
            if(c-1 >= 0 && grid[r][c-1] == 1){
                q.push(make_pair(r, c-1));
                grid[r][c-1] = 2;
                pushNumNext++;
            }
            if(c+1 < COL && grid[r][c+1] == 1){
                q.push(make_pair(r, c+1));
                grid[r][c+1] = 2;
                pushNumNext++;
            }
            if(r-1 >= 0 && grid[r-1][c] == 1){
                q.push(make_pair(r-1, c));
                grid[r-1][c] = 2;
                pushNumNext++;
            }
            if(r+1 < ROW && grid[r+1][c] == 1){
                q.push(make_pair(r+1, c));
                grid[r+1][c] = 2;
                pushNumNext++;
            }
            
            q.pop();
            pushNum--;
        }
        
        // Edge case
        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        
        return time;
    }
};
