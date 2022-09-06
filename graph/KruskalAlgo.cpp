#include<bits/stdc++.h>
using namespace std;
class UnionFind{
    private:
    vector<int> root,rank;

    public:
    UnionFind(int n){
        root.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++)
            root[i]=i;
    }

    int findRoot(int x){
        if(root[x]==x)
            return x;
        return root[x]=findRoot(root[x]);
    }

    bool connected(int x,int y){
        return findRoot(x)==findRoot(y);
    }

    void unionNodes(int x, int y){
        int rootX=findRoot(x);
        int rootY=findRoot(y);

        if(rootX==rootY)
            return;
        
        if(rank[rootX]<rank[rootY]){
            root[rootX]=rootY;
        }
        else if(rank[rootX]>rank[rootY]){
            root[rootY]=rootX;
        }
        else{
            root[rootX]=rootY;
            rank[rootY]++;
        }
    }
};
//returns the edges present in minimum spanning tree
vector<vector<int>> kruskal(int n,vector<vector<int>> &edges){
    //each edge contains three elements, first ele is weight and remaining two are nodes
    sort(edges.begin(),edges.end());
    vector<vector<int>> MST;
    int MSTEdgesCount=0;
    UnionFind uf(n);
    for(int i=0;i<edges.size() && MSTEdgesCount<=n-1;i++)
    {
        auto e=edges[i];
        if(uf.connected(e[1],e[2]))
            continue;
        uf.unionNodes(e[1],e[2]);
        MSTEdgesCount++;
        MST.push_back(e);
    }
    return MST;
}
int main(){
    return 0;
}