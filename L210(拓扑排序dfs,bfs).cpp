class BFS{
public:
	vector<vector<int>> edges;
    	vector<int> in;
    	vector<int> ans;

    	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       	edges.resize(numCourses);
        	in.resize(numCourses);
        	for(const auto& edge : prerequisites){
            		edges[edge[1]].push_back(edge[0]);
            		in[edge[0]]++;
    		}
    
	       queue<int> q;
        	for(int i = 0; i < numCourses; i++){
            		if(in[i] == 0) q.push(i);
    		}
        	while(!q.empty()){
            		int cur = q.front();
            		ans.push_back(cur);
            		q.pop();
            		for(auto& v : edges[cur]){
                		--in[v];
                		if(in[v] == 0) q.push(v);
            		}
        	}
        	if(ans.size() != numCourses) return {};
        	return ans;
	}
};

class DFS{
public:
	vector<vector<int>> edges;
	vector<bool> vis;
	vector<int> ans;
	vector<int> in;
	
	// vis状态为1表示当此进行dfs时已经遍历过，再次遇到属于环。即不满足拓扑排序；
	// vis状态为-1表示之前dfs已经遍历过当前结点，相当于给dfs剪枝吧。
	 void dfs(int index){
        	if(vis[index] || in[index] != 0) return ;
        	vis[index] = 1;
        	ans.push_back(index);
        	for(auto& x : edges[index]){
            		--in[x];
            		if(in[x] == 0) dfs(x);
        	}		
        
    	}

    	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        	edges.resize(numCourses);
        	in.resize(numCourses);
        	vis.resize(numCourses);
        	for(const auto& edge : prerequisites){
            		edges[edge[1]].push_back(edge[0]);
            		in[edge[0]]++;
        	}
        	for(int i = 0; i < numCourses; i++) dfs(i);
        	if(ans.size() != numCourses) return {};
        	return ans;
    	}
};
