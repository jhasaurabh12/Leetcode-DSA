#include<bits/stdc++.h>
uisng namespace std;
//adjList has pair<int,int> where first ele is weight, second ele is vertex
vector<int> dijkstra(int source, vector<vector<pair<int,int>>> &adjList){
    int n=adjList.size();
    vector<int> dist(n,INT_MAX);
    vector<int> finalized(n,false);
    dist[source]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    int final=0;
    while(final<n && !pq.empty()){
        auto curr=pq.top();
        pq.pop();
        if(finalized[curr.second])
            continue;

        int v=curr.second;
        final++;
        finalized[v]=true;
        for(auto u:adjList[v]){
            if(dist[u.second]>dist[v]+u.first){
                pq.push({dist[v]+u.first,u.second});
                dist[u.second]=dist[v]+u.first;
            }
        }
    }
    return dist;
    
}