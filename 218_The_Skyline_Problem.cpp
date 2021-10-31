class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> skyline;
        map<int, vector<pair<int, bool>>> map; // key : pos, value : vector of <height, start|end> pairs
        for (auto& building : buildings) {
        	map[building[0]].push_back({building[2], true}); // start
        	map[building[1]].push_back({building[2], false}); // end
        }
        multiset<int> q;
        int max_height = 0;
        for (auto& [pos, heights] : map) {
            for(auto& [height, type] : heights){
            	if(type) q.insert(height);
            	else q.erase(q.find(height));
            }
            if (!q.empty())	max_height = *q.rbegin();
            else max_height = 0;
            
            if(!skyline.empty() && max_height == skyline.back()[1]) continue;
            else skyline.push_back(vector<int>{pos, max_height});
        }
        return skyline;
    }
};