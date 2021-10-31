class Solution { // find node with only in-degree
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        bool in[100001] = {0};
        vector<int> ans;
        for(auto i:edges){
            in[i[1]] = true;
        }
        for(int i = 0; i < n; i++){
            if(!in[i]) ans.push_back(i);
        }
        return ans;
    }
};