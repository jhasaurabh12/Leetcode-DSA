#include<bits/stdc++.h>
using namespace std;
struct Edge{
  int u;
  int v;
  int wt;
  
  Edge(int _u,int _v, int _wt){
      u=_u;
      v=_v;
      wt=_wt;
  }
};
vector<int> BellmanFord(int src,int n, vector<Edge> edges){
    vector<int> dist(n,1e8);
    dist[src]=0;

    for(int i=1;i<=n-1;i++){
        for(auto e:edges){
            if(dist[e.v]>dist[e.u]+e.wt)
                dist[e.v]=dist[e.u]+e.wt;
        }
    }
    return dist;

}
int main(){

    return 0;
}