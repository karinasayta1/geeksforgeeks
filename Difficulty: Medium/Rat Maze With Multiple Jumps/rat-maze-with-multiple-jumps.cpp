class Solution {
  public:
    bool isSafe(int x, int y, vector<vector<int>>& matrix){
        int n = matrix.size();
        return (x >= 0 && x < n && y >= 0 && y < n && matrix[x][y] != 0);
            
    }
    bool helper(int x, int y,vector<vector<int>>& matrix, vector<vector<int>>& sol){
        int n = matrix.size();
        if(x == n-1 && y == n-1){
            sol[x][y]=1;
            return true;
        }
        
        if(isSafe(x,y,matrix)){
            sol[x][y]=1;
            
            //try all possible paths
            for(int steps = 1; steps<=matrix[x][y]; steps++){
                //move right
                if(helper(x,y+steps,matrix,sol))
                    return true;
                //move down
                if(helper(x+steps,y,matrix,sol))
                    return true;
            }
            sol[x][y]=0;
            return false;
        }
        
        return false;
    }
    vector<vector<int>> ShortestDistance(vector<vector<int>>& matrix) {
        // Code here
        int n = matrix.size();
        vector<vector<int>> sol(n, vector<int>(n,0));
        if(helper(0, 0, matrix, sol))
            return sol;

        return {{-1}}; // no path found
    }
};