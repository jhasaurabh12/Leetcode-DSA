#inlude<bits/stdc++.h>
usig namespace std;
public:
//Function to find number of strongly connected components in the graph.
void dfs1(int curr,stack<int>&order,vector<int>&visited, vector<int> adj[]){
    if(visited[curr])
        return;
    visited[curr]=true;
    for(auto x:adj[curr]){
        dfs1(x,order,visited,adj);
    }
    order.push(curr);
}

void dfs2(int curr,vector<int>&visited,vector<int> adj[]){
    if(visited[curr])
        return;
    visited[curr]=true;
    for(auto x:adj[curr]){
        dfs2(x,visited,adj);
    }
}
//returns count of strongly connected component
int kosaraju(int V, vector<int> adj[])
{
    //code here
    stack<int> order;
    vector<int> visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i])
            dfs1(i,order,visited,adj);
    }
    vector<int> graph[V];
    for(int i=0;i<V;i++){
        for(auto x:adj[i]){
            graph[x].push_back(i);
        }
    }
    int count=0;
    visited.clear();
    visited.resize(V,false);
    while(!order.empty()){
        auto curr=order.top();
        order.pop();
        if(visited[curr])
            continue;
        count++;
        dfs2(curr,visited,graph);
    }
    return count;
}
int main(){
    return 0;
}