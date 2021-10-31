class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int graph[n+1][n+1];
        int a[n+1][n+1];
        int ans[n+1];
        for(int i = 0; i < n; i++){
            ans[i] = 0;
            for(int j = 0; j < n; j++){
                graph[i][j] = INT_MAX;
                a[i][j] = INT_MAX;
            }
            graph[i][i] = 0;
            a[i][i] = 0;
        }
        for(auto i:edges){
            graph[i[0]][i[1]] = i[2];
            a[i[1]][i[0]] = i[2];
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if((a[i][k] != INT_MAX && a[k][j] != INT_MAX) && a[i][j] > a[i][k] + a[k][j]){
                        a[i][j] = a[i][k] + a[k][j]; 
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == INT_MAX){
                    cout << a[j][i] << ' ';
                }
                else {
                    cout << a[i][j] << ' ';
                }
            }
            cout << endl; 
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == INT_MAX && a[j][i] <= distanceThreshold){
                    ans[i] += 1;
                }
                else if(a[i][j] <= distanceThreshold){
                    ans[i] += 1;
                }
            }
        }
        int min = INT_MAX;
        int idx = 0;
        for(int i = 0; i < n; i++){
            cout << ans[i] << endl;
            if(min >= ans[i]){
                min = ans[i];
                idx = i;
            }
        }
        return idx;
    }
};