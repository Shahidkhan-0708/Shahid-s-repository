class Solution {
public:

        bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    
    function<bool(int, int, int)> dfs = [&](int r, int c, int idx) -> bool {
        if (idx == word.size()) return true;
        if (r < 0 || r >= m || c < 0 || c >= n) return false;
        if (board[r][c] != word[idx]) return false;
        
        char temp = board[r][c];
        board[r][c] = '#'; // mark visited
        
        bool found = dfs(r+1, c, idx+1) || dfs(r-1, c, idx+1) ||
                     dfs(r, c+1, idx+1) || dfs(r, c-1, idx+1);
        
        board[r][c] = temp; // restore
        return found;
    };
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (dfs(i, j, 0)) return true;
    
    return false;
}
    
};