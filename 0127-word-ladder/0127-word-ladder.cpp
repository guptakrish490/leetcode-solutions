class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({beginWord, 1});

        while (!q.empty()) {
            string word = q.front().first;
            int dist = q.front().second;

            q.pop();

            if (word == endWord)
                return dist;

            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    pattern[i] = ch;

                    if (st.find(pattern) != st.end()) {
                        st.erase(pattern);
                        q.push({pattern, dist + 1});
                    }
                }
            }
        }

        return 0;
    }
};