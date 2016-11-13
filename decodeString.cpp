// leetcode 394
class Solution {
public:
    string decodeString(string s) {
        pair<int, string> pp;
        stack<pair<int, string>> stk;
        int size = s.size();
        int count = 0;
        string res = "";

        for(int i = 0; i < size; i++) {
            if(isdigit(s[i])) {
                count = count * 10 + (s[i] - '0');
            } else if(s[i] == '[') {
                stk.push(make_pair(count, ""));
                count = 0;
            } else if(s[i] == ']') {
                pair<int, string> temp = stk.top();
                stk.pop();
                while(temp.first) {
                    if(!stk.empty()) {
                        stk.top().second += temp.second;
                    } else {
                        res += temp.second;
                    }
                    temp.first--;
                }
            } else {
                if(!stk.empty()) {
                    stk.top().second += s[i];
                } else {
                    res += s[i];
                }
            }
        }

        return res;
    }
};

// follow up encode string
// https://github.com/Changtx/gg_pdf/blob/master/p054_compressString.java
