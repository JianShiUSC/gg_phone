bool subsequenceAndSubstring(string s, string t, int N) {
    int t_start = 0;
    while(t_start < t.size()) {
        int cursor_s = 0;
        int deleteCount = 0;
        while(deleteCount <= N) {
            if(cursor_s == s.size()) {
                return true;
            }
            if(s[cursor_s] == t[t_start]) {
                t_start++;
                cursor_s++;
            } else {
                cursor_s++;
                deleteCount++;
            }
        }
        t_start++;
    }
    return false;
}

int main() {
    cout << subsequenceAndSubstring("abcbookd", "book", 4) << endl;
}
