int longestPrefixInOrder(string str) {
    if(str.empty()) return 0;
    int count = 1;
    for(int i = 1; i < str.size(); i++) {
        if(str[i] >= str[i-1]) count++;
        else break;
    }
    return count;
}

int main() {
    cout << longestPrefixInOrder("ransom") << endl;
    cout << longestPrefixInOrder("google") << endl;
    cout << longestPrefixInOrder("knotty") << endl;
}
