class Solution {
public:
	int length[101][101] = {INT_MAX};
    int dist[101] = {INT_MAX};
	bool s[101] = {false};
	
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    	map<int, vector<pair<int, int>>> length;
        for(auto i: times){
            length[i[0]].push_back(make_pair(i[1], i[2]));
            dist[i[0]] = INT_MAX;
            dist[i[1]] = INT_MAX;
            s[i[0]] = false;
            s[i[1]] = false;
        }
        dist[k] = 0;
        pq.push(make_pair(0, k));
        while(!pq.empty()){
        	pair<int, int> top = pq.top();
        	pq.pop();
        	s[top.second] = true;
        	for(auto neighbor: length[top.second]){
        		if(!s[neighbor.first] && neighbor.second != INT_MAX && dist[neighbor.first] > neighbor.second + top.first){
        			pq.push(make_pair(neighbor.second + top.first , neighbor.first));
        			dist[neighbor.first] = neighbor.second + top.first;
        		}
        	}
        }   
        int max = INT_MIN;
        for(int i = 1; i <=n; i++){
        	if(!s[i])
                return -1;
            if(max < dist[i]) 
                max = dist[i];
        }
        return max;
    }
};


