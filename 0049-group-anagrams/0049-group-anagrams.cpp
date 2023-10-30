class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagram;
        unordered_map<string, vector<string>> mp;

        for (const string& word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            mp[sortedWord].push_back(word);
        }

        for (const auto& entry : mp) {
            anagram.push_back(entry.second);
        }

        return anagram;
    }
};
