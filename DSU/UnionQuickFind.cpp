#include<bits/stdc++.h>
using namespace std;

class UnionFind_QF{
    vector<int> head;
    public:
    UnionQuickFind(int nodes){
        head.resize(nodes);
        for(int i=0;i<nodes;i++)
            head[i]=i;
    }
    int find(int x)
    {
        return head[x];
    }
    void Union(int x, int y){
        int headX=find(x);
        int headY=find(y);
        if(headX==headY)
            return;
        for(int i=0;i<head.size();i++){
            if(head[i]==headY)
                head[i]=headX;
        }
    }

    bool connected(int x, int y){
        return find(x)==find(y);
    }
};

int main() {
    // for displaying booleans as literal strings, instead of 0 and 1
    cout << boolalpha;
    UnionFind_QF uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.Union(1, 2);
    uf.Union(2, 5);
    uf.Union(5, 6);
    uf.Union(6, 7);
    uf.Union(3, 8);
    uf.Union(8, 9);
    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.Union(9, 4);
    cout << uf.connected(4, 9) << endl;  // true

    return 0;
}