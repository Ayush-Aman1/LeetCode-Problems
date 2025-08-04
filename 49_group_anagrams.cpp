class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> mp;
        for(string word:strs){
            string sorted_str = word;
            sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(word);
        }

        vector<vector<string>> res;
        for(auto& wd:mp){
            res.push_back(wd.second);
        }
        return res;
    }
};