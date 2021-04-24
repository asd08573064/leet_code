class Solution {
public:
    int x_;
    int y_;
    bool **check;
    void DFS(int x, int y, vector<vector<char>>& board){
        if(x >= 0 && x < x_ && y >= 0 && y < y_ && board[x][y] == 'O'&& !check[x][y]){
            check[x][y] = true;
            DFS(x+1, y, board);
            DFS(x, y+1, board);
            DFS(x-1, y, board);
            DFS(x, y-1, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        x_ = board.size();
        y_ = board[0].size();
        check = new bool*[x_];
        for(int i=0; i<x_; i++)
             check[i] = new bool[y_];
        
        for (int i  = 0; i < x_; i++)
            for(int j = 0; j < y_; j++)
                check[i][j] = false;
        
        for(int i = 0; i  < x_; i++){
            DFS(i, y_-1, board);
            DFS(i, 0, board);
        }
        for(int i = 0; i < y_; i++){
            DFS(x_-1, i, board);
            DFS(0, i, board);
        }
        
        for(int i = 0; i < x_; i++)
            for(int j = 0; j < y_; j++)
                if(check[i][j] == false) board[i][j] = 'X';
    }
};