class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int check[graph.size()];
        queue<int> q;
        for(int i = 0; i < graph.size(); i++) check[i] = 0;
        for(int i = 0; i < graph.size(); i++) {
            if(graph[i].size() > 0 && check[i] == 0){
                q.push(i);
                check[i] = 1;
                while(!q.empty()){
                    int front = q.front();
                    q.pop();
                    for(auto node: graph[front]){
                        if(check[node] == 0){
                            check[node] = (check[front] == 1) ? 2 : 1;
                            q.push(node); 
                        }
                        if(check[node] == check[front]) return false;
                    }
                }
            }
        }
        return true;
    }
};