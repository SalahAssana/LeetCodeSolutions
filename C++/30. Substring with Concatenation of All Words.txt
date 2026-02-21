class Solution
{
    public:
        vector<int> findSubstring(string s, vector<string>& words)
        {
            // Indexes of start and end of Substring with Concatenation of All Words
            vector<int> indexes;
            
            if (words.empty()) return indexes;
            
            // Map to hold the counts of every word
            unordered_map<string, int> counts;

            // Build the map of word counts
            for (string word : words)
                counts[word]++;

            int n = s.length();          // Length of the string
            int num = words.size();      // Number of words
            int len = words[0].length(); // Length of individual words

            // Loop through every possible window in the substring
            for (int i = 0; i < n - num * len + 1; i++)
            {
                // Map to hold all word seen in the window
                unordered_map<string, int> seen;
                int j;

                // Loop through every word in the dictionary
                for (j = 0; j < num; j++)
                {
                    // Generate substring of appropriate size
                    string word = s.substr(i + j * len, len);

                    // If the word is in the counts dictionary
                    if (counts.find(word) != counts.end())
                    {
                        // Increment the number of times it has been seen
                        seen[word]++;

                        // If we have seen the word too many times exit the loop
                        if (seen[word] > counts[word])
                            break;
                    }
                    // If word is not in the dictionary exit the loop
                    else break;
                }

                // If we reach the end without breaking add the index
                if (j == num) indexes.push_back(i);
            }

            return indexes;
        }
};