bool issafe(int row,int col,int i, int j,vector<vector<bool>>&visited, vector<vector<int>>&maze){
    if ( ((i>=0 && i<row) && (j>=0 && j<col))
    && (maze[i][j]==1) && 
    (visited[i][j]==false)){
        return true;
    }
    else {
    return false;
  }
}

void findmaze(vector<vector<int>>&maze,int row,int col,int i,int j,vector<vector<bool>>&visited,vector<string>&path, 
string output){
    //base condition
    if (i==row-1 && j==col-1){
        path.push_back(output);
        return;
    }

    //movement
    //down 
    if (issafe(row,col,i+1,j,visited, maze)){
        visited[i+1][j]=true;
        //recursion
        findmaze(maze, row, col, i+1, j, visited, path, output+'D');
        //backtrack
        visited[i+1][j]=false;
    }

    //up
    if (issafe(row,col,i-1,j,visited, maze)){
        visited[i-1][j]=true;
        //recursion
        findmaze(maze, row, col, i-1, j, visited, path, output+'U');
        //backtrack
        visited[i-1][j]=false;
    }

    //left
    if (issafe(row,col,i,j-1,visited, maze)){
        visited[i][j-1]=true;
        //recursion
        findmaze(maze, row, col, i, j-1, visited, path, output+'L');
        //backtrack
        visited[i][j-1]=false;
    }

    //right
    if (issafe(row,col,i,j+1,visited, maze)){
        visited[i][j+1]=true;
        //recursion
        findmaze(maze, row, col, i, j+1, visited, path, output+'R');
        //backtrack
        visited[i][j+1]=false;
    }
    
}


class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
    int row=n;
    int col=n;
    
    vector<string> path;
    string output = "";
    
    if (m[0][0]==0){
        return path;
    }
    
    vector<vector<bool>>visited(row, vector<bool>(col,false));
    visited[0][0] = true;

    findmaze(m,row,col,0,0,visited,path, output);
    return path;
    }
};

    
