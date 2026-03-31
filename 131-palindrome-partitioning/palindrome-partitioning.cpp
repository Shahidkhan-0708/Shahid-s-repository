class Solution {
public:
    bool isPalin(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void bt(string& s, int start, vector<string>& curr,
             vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(curr); // found a valid partition
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPalin(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));
                bt(s, end + 1, curr, res); // recurse
                curr.pop_back();          // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        bt(s, 0, curr, res);
        return res;
    }
};