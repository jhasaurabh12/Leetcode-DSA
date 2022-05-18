
//Have to go through this algo again.
//Ref: https://youtu.be/RYaakWv5m6o
//Ref: https://cp-algorithms.com/graph/bridge-searching.html

class Solution {
public:
    void dfs(int curr, int parent,vector<bool> &visited, vector<int> &low, vector<int> &Id, vector<vector<int>> &bridges,vector<vector<int>> &graph, int currId){
        
        visited[curr]=true;
        Id[curr]=low[curr]=currId++;
        
        for(auto newNode:graph[curr]){
            if(newNode==parent) continue;
            
            if(visited[newNode])
                low[curr]=min(low[curr],Id[newNode]);
            else{
                dfs(newNode,curr,visited,low,Id,bridges,graph,currId);
                low[curr]=min(low[curr],low[newNode]);
                if(low[newNode]>Id[curr])
                    bridges.push_back({newNode,curr});
            }
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> graph(n);
        
        for(auto u:connections){
            graph[u[0]].push_back(u[1]);
            graph[u[1]].push_back(u[0]);
        }
        vector<vector<int>> bridges;
        vector<bool> visited(n,false);
        vector<int> low(n,-1), id(n,-1);
        dfs(0,-1,visited,low,id,bridges,graph,0);
        return bridges;
    }
};