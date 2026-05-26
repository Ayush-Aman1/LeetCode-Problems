class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordCount;
        for (const auto& word : words) {
            wordCount[word]++;
        }
        vector<int> result;
        int stringLength = s.length();
        int wordArraySize = words.size();
        int wordLength = words[0].length();
        for (int offset = 0; offset < wordLength; ++offset) {
            int left = offset;
            int right = offset;
            unordered_map<string, int> currentWindowCount;
            while (right + wordLength <= stringLength) {
                string currentWord = s.substr(right, wordLength);
                right += wordLength;
                if (!wordCount.contains(currentWord)) {
                    currentWindowCount.clear();
                    left = right;
                    continue;
                }
                currentWindowCount[currentWord]++;
                while (currentWindowCount[currentWord] > wordCount[currentWord]) {
                    string leftWord = s.substr(left, wordLength);
                    currentWindowCount[leftWord]--;
                    if (currentWindowCount[leftWord] == 0) {
                        currentWindowCount.erase(leftWord);
                    }
                    left += wordLength;
                }
                if (right - left == wordArraySize * wordLength) {
                    result.push_back(left);
                }
            }
        }

        return result;
    }
};
