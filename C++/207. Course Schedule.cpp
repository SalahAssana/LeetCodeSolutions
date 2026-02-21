class Solution
{
public:
    bool iscycle(vector<int> graph[], vector<int> &visited, int id)
    {
        if(visited[id] == 1) return true;
        
        if(visited[id] == 0)
        {
            visited[id] = 1;
            
            for(auto edge : graph[id])
            {
                if(iscycle(graph, visited, edge)) return true;
            }
        }
        
        visited[id] = 2;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre)
    {
        vector<int> graph[n];
        
        for (vector<int> edge : pre)
            graph[edge[1]].push_back(edge[0]);
        
        vector<int> visited(n,0);
        
        for(int i=0; i < n; i++)
        {
            if(iscycle(graph, visited, i)) return false;
        }
        
        return true;
    }
};