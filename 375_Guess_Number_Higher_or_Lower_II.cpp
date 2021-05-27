class Solution {
public:
    int check[201][201];
    int solver(int i, int j){
        if(check[i][j] != INT_MAX) return check[i][j];
        int ans = INT_MAX;
        for(int k = i+1; k <= j-1; k++)
            ans = min(ans, k + max(solver(i,k-1), solver(k+1,j)));
        check[i][j] = ans;
        return ans;
    }
    int getMoneyAmount(int n) {
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i == j) check[i][j] = 0;
                else if(i == j-1) check[i][j] = i;
                else check[i][j] = INT_MAX;
            }
        }
        return solver(1, n);
    }
    
};
