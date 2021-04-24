class Solution {
public:
    vector <vector<int>> map;
    vector<int> ans;
    bool check[2001];
    bool check_cycle[2001];
    bool valid;
    
    void DFS(int course){
        if(check_cycle[course]) {
            valid = false;
            return;
        }
        if(check[course]) return;
        check_cycle[course] = true;
        for(auto it: map[course]){
            if(it != course){
                DFS(it);
            }
        }
        ans.insert(ans.begin(), course);
        check[course] = true;
        check_cycle[course] = false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> index;
        valid = true;
        
        if(prerequisites.size() == 0){
            for(int i = 0; i <numCourses;i++ ) ans.push_back(i);
            return ans;
        }
        
        for(int i = 0; i < numCourses; i++){
            vector<int> v;
            v.push_back(i);
            check[i] = false;
            map.push_back(v);
        }
        
        for(auto it: prerequisites)
                map[it[1]].push_back(it[0]); 
        
        for(int i = 0; i < numCourses; i++)
            if(map[i].size() > 1)
                DFS(i);
        
        if(!valid) return index;
        for(int i = 0; i < numCourses; i++)
            if(!check[i]) ans.push_back(i);
        
        return ans;
    }
};
