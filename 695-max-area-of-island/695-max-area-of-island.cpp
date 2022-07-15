class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // initialize m & n. where,m is the no.  oof rows & n is the number of coloumns
        int  m= grid.size(), n=grid[0].size(),maxi=0; 
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                // check when value of index is 1
                if(grid[i][j]==1){
                    int count = 1;
                    count_island(grid,i,j,count);
                    maxi = max(maxi,count);
                }
            }
        }
        return maxi;
    }
    int count_island(vector<vector<int>>& grid, int i, int j,int & count){
        //check if it is within bounds , return 0 if it goes out of bounds
        
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()){
            return 0;
        }
        
            //check if it is a useless neighbour, return 0 if it is useless
            if(grid[i][j]==0) return 0;
        //after backtracking make neighbour 0 so that it will not interfare in further iterations
            grid[i][j]=0;
            //call the neighbours if they are helpful or not
            if(count_island(grid,i-1,j,count)==1) count++;//above
            if(count_island(grid,i,j-1,count)==1) count++;//left
            if(count_island(grid,i+1,j,count)==1) count++;//below
            if(count_island(grid,i,j+1,count)==1) count++;//right
            
        
        return 1;
    } 
};