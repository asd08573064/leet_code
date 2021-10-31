class Solution {
public:
    
    double ans_val;
    
    class Node{
        public:
            string id;
            double value;
            Node(string id, double value): id(id), value(value){};
    };
    map<string, vector<Node>> graph;
    
    
    void DFS(string now, string target, double val, map<string, bool> visit){
        if(now == target){
            ans_val = val;
            return;
        }
        if(visit[now]){
            return;
        }
        visit[now] = true;
        for(auto neighbor: graph[now]){
            DFS(neighbor.id, target, val*neighbor.value,visit);
            if(neighbor.id == target) break;
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        
        for(int i = 0; i < equations.size(); i++){
            graph[equations[i][0]].push_back(Node(equations[i][1], values[i]));
            graph[equations[i][1]].push_back(Node(equations[i][0], 1.0/values[i])); 
        }
        for(auto q:queries){
            auto s = graph.find(q[0]);
            auto t = graph.find(q[1]);
            if (s == graph.end() || t == graph.end()){
                ans.push_back(-1);
                continue;
            }
            ans_val = -1;
            map<string, bool> visit;
            DFS(q[0], q[1], 1,visit);
            ans.push_back(ans_val);
        }
        return ans;
    }
};