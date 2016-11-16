// in one pass
char findNonRepeating(string s) {
    set<char> repeating;
    vector<char> nonRepeating;

    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(repeating.find(c) != repeating.end()) continue;
        if(find(nonRepeating.begin(), nonRepeating.end(), c) != nonRepeating.end()) {
            nonRepeating.erase(remove(nonRepeating.begin(), nonRepeating.end(), c), nonRepeating.end());
            repeating.insert(c);
        } else {
            nonRepeating.push_back(c);
        }
    }
    return nonRepeating.empty() ? ' ' : nonRepeating[0];
}


int main() {
    cout << findNonRepeating("geeg") << endl;
}
