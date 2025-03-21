// TC : O(m * n * 4^k) where k = word length && SC : O(m * n)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1},{0, -1}};
    bool find(int i, int j, int idx, string word, vector<vector<char>>& board)
    {
        if(idx == word.length())
           return true;
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '*')
           return false;

        if(word[idx] != board[i][j])
           return false; 
        char temp = board[i][j];
        board[i][j] = '*';
        for(auto& dir : directions)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(find(new_i, new_j, idx + 1, word, board))
               return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(word[0] == board[i][j] && find(i, j, 0, word, board))
                 return true;
            }
        }
        return false;
    }
};
