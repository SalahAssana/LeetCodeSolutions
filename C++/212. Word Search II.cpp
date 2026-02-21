struct TrieNode
{
    string word { "" };
    array<TrieNode*, 26> chars { nullptr };
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        vector<string> output;
        
        // Build Trie
        TrieNode* root = new TrieNode();
        
        for (string word : words)
        {
            TrieNode* iter = root;
            
            for (char c : word)
            {
                int index = c - 'a';
                
                if (iter->chars[index] == nullptr)
                {
                    iter->chars[index] = new TrieNode();
                }
                
                iter = iter->chars[index];
            }
            
            iter->word = word;
        }
        
        // Loop through board and check if character is start of possible word
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                int index = board[i][j] - 'a';
                
                if (root->chars[index] != nullptr)
                {
                    search(board, output, i, j, root);
                }
            }
        }
        
        return output;
    }
    
private:
    void search(vector<vector<char>>& board, vector<string>& output, int i, int j, TrieNode* node)
    {
        if (i < 0 || j < 0 || i == board.size() || j == board[i].size() || board[i][j] == '*')
        {
            return;
        }
        
        int index = board[i][j] - 'a';
        node = node->chars[index];
        
        // If valid node continue
        if (node)
        {
            // If we found a word add it
            if (!empty(node->word))
            {
                output.emplace_back(node->word);
                node->word = "";
            }
            
            char letter = board[i][j];
            board[i][j] = '*';
            
            search(board, output, i+1, j, node);
            search(board, output, i-1, j, node);
            search(board, output, i, j+1, node);
            search(board, output, i, j-1, node);
            
            board[i][j] = letter;
        }
        
    }
};