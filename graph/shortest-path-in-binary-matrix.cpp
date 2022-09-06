/*
The first approach that came to my mind was bruteforce. In bruteforce, we explore all the paths from (0,0) to (n-1,m-1). This can be done using dfs. The bruteforce implementation is also coded below and commented.


Then while thinking about the optimization, tried with the dp approach but dp won't be possible because the subproblems in dp have interpendency on each other which enters in deadlock. Let's say dp[i][j] is the length of shortest path to go from (i,j) to (n-1,m-1).
Suppose we want to find answer of dp[1][1], then it depends on 8 other states. for e.g it depends on dp[0][0] and also on dp[2][2]. For dp[1][1], if we go bottom up we will have 
dp[0][0] already calculated but dp[2][2] won't be pre-calculated. Similarly if we go top down vice versa will happen. thus dp won't be applicable here.


The most efficient approach will be BFS. whenever we need to find the shortest path in unit weight edge, bfs is most efficient. BFS will always give shortest path because in BFS we start from source node and explore it's nearest neighbours all at once. similarly for next level node we explore their nearest neighbours all at once. this way whenver we will reach the destination node, it will be reached via the shortest path possible.

BFS is applicable whenever the distance between each level of neighbours is always same, In this case distance between each level of neighbours is 1.
TC:O(nm), SC:O(nm)

*/





class Solution {
//     void dfs(vector<vector<int>> &grid, int i, int j, int &ans, int currDist){
//         if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || grid[i][j]==1)
//             return;
//         // cout<<i<<" "<<j<<endl;
//         if(i==grid.size()-1 && j==grid[0].size()-1)
//             ans=min(ans,currDist);
        
//         int x[]={-1,0,1};
//         grid[i][j]=1;
//         for(int p=0;p<3;p++){
//             for(int q=0;q<3;q++){
                
//                 dfs(grid,i+x[p],j+x[q],ans,currDist+1);
//             }
//         }
//         grid[i][j]=0;
//     }

    
    int bfs(vector<vector<int>> &grid){
        
        int n=grid.size();
        int m=grid[0].size();
        
        if(grid[0][0]==1 || grid[n-1][m-1]==1)
            return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        int dir[]={-1,0,1};
        

        // cout<<n<<m<<endl;
        int currDist=0;
        
        while(!q.empty()){
            
            int qsize=q.size();
            currDist++;
            
          
            
            while(qsize--){
                
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i==n-1 && j==m-1)
                    return currDist; 
                
                for(int x=0;x<3;x++){
                    for(int y=0;y<3;y++){
                        


                        int ni=i+dir[x];
                        int nj=j+dir[y];
                        
                        if(ni>=n || nj>=m || ni<0 || nj<0 || grid[ni][nj]==1)
                            continue;
                        
                        grid[ni][nj]=1;
                        
                        q.push({ni,nj});

                    }
                }
            }
        }
        return -1;
        
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        return bfs(grid);
    }
};