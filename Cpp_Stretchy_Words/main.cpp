class Solution {
public:
    string minLength(string s) {
        int l = 0, r = 0, n = s.size();
        string res;
        while (l < n) {
            if (s[l] != s[r] or r == n) {
                res += s[l];
                res += '0' + (r - l);
                l = r;
            } else {
                r++;
            }
        }
        
        return res;
    }
    
    int expressiveWords(string S, vector<string>& words) {
        S = minLength(S);
        int ans = 0, n = S.size();
        cout << S << endl;
        
        for (auto &word : words) {
            word = minLength(word);
            if (word.size() == S.size()) {
                int flag = 0;
                for (int i = 1; i < n; i += 2) {
                    if (word[i-1] != S[i-1] or !(word[i] == S[i] or (S[i] >= '3' and word[i] < S[i]))) {
                        flag = 1;
                        break;
                    }
                }
                if (!flag) ans++;
            }
        }
        
        return ans;
    }
};


Given a string S we are changing it to show how many consecutive letters are there.
Example - heeellooo is changed to h1e3l2o3, hello to h1e1l2o1

This way we know how many consecutive letters there are.
 After that we are just comparing first the characters and then how many 
 times they are appearing and comparing according to the conditions. The logic is clear in the if statement.