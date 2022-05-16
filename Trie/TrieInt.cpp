#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* links[2];
    Node(){
        links[0]=NULL;
        links[1]=NULL;
    }
};

class TrieInt{
    Node* root;
    
    public:
    TrieInt(){
        root= new Node();
    }

    void insert(int x){
        Node* curr=root;
        for(int i=31;i>=0;i--){
            int ind=(x>>i)&1;
            if(curr->links[ind]==NULL)
                curr->links[ind]=new Node();
            curr=curr->links[ind];
        }
    }

    int maxXor(int x){
        Node* curr=root;
        int reqNum=0;
        for(int i=31;i>=0;i--){
            int currBit=(x>>i)&1;
            int reqBit=currBit==1 ? 0:1;
            if(curr->links[reqBit]){
                
                curr=curr->links[reqBit];
                reqNum=reqNum|(reqBit<<i);
            }
            else{
                curr=curr->links[currBit];
                reqNum=reqNum|(currBit<<i);
            }
        }
        return reqNum^x;
    }
};
int main(){

    TrieInt* trie=new TrieInt();
    vector<int> arr={9,8,6,7,5};
    int x=8;
    for(auto &n:arr)
        trie->insert(n);
    cout<<trie->maxXor(x)<<endl;
    return 0;
}