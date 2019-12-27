class Solution {
public:
    vector<vector<string>> boards;
    
    void makeBoard(vector<int> a, int n) {
        string line = "";
        vector<string> board;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i] != j)  line += ".";
                else        line += "Q";
            }
            board.push_back(line);
            line.clear();
        }
        boards.push_back(board);
    }
    
    void backtrack(vector<int> a, int k, int n) {
        // If a is one of the solution, call makeBoard().
        if(k == n){
            makeBoard(a, n);
            return;
        }
        
        // c is candidates vector.
        vector<int> c;
        int iValid = 1;
        // i is potential candidate.
        for(int i=0; i<n; i++){
            iValid = 1;
            // Check if i can be real candidate.
            for(int j=0; j<k; j++){
                // Same column
                if(a[j] == i){
				    iValid = 0;
				    break;
			    }
                // Same diagonal
			    if(abs(i - a[j]) == abs(k - j)){
				    iValid = 0;
				    break;
			    }
            }
            // If iValid is 1, i is real candidate.
            if(iValid)  c.push_back(i);
        }
        
        // Extend current partial solution a
        // by all real candidates in c.
        int cLen = c.size();
        for(int i=0; i<cLen; i++){
            a[k] = c[i];
            backtrack(a, k+1, n);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<int> a(n);
        backtrack(a, 0, n);
        return boards;
    }
};
