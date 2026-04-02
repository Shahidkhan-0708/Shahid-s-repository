class Solution {
public:
  void solve( vector<vector<string>>&ans,int n,vector<string>&board,int col,vector<int>&upDiagonal,vector<int>&lowDiagonal,vector<int>&leftRow){
    if(col==n) {
        ans.push_back(board);
        return;}

  for(int row=0;row<n;row++){
    if(leftRow[row]==0&&lowDiagonal[col+row]==0&&upDiagonal[n-1+col-row]==0){
        board[row][col]='Q';
        leftRow[row]=1;
        lowDiagonal[row+col]=1;
        upDiagonal[n-1+col-row]=1;
        solve(ans,n,board,col+1,upDiagonal,lowDiagonal,leftRow);
        board[row][col]='.';
        leftRow[row]=0;
        lowDiagonal[row+col]=0;
        upDiagonal[n-1+col-row]=0;

    }
  }
  }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>leftRow(n,0);
        vector<int>lowDiagonal(2*n-1,0);
        vector<int>upDiagonal(2*n-1,0);
        solve(ans,n,board,0,upDiagonal,lowDiagonal,leftRow);
        return ans;
    }
};