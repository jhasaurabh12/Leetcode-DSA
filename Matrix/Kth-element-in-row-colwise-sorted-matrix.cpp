#define piii pair<int,pair<int,int>>
#define minheap priority_queue<piii,vector<piii>,greater<piii>>
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
    minheap pq;
    for(int i=0;i<n;i++)
        pq.push({mat[0][i],{0,i}});
    piii curr;
    for(int i=0;i<k;i++){
        curr=pq.top();
        pq.pop();
        int col=curr.second.second;
        int row=curr.second.first;
        if(row<n-1)
            pq.push({mat[row+1][col],{row+1,col}});
    }
    return curr.first;
}