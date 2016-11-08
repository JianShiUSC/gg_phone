char findFirstUnique(string str) {
    int size = str.size();
    unordered_map<char, int> mm;

    for(auto c : str) {
        mm[c]++;
    }

    for(int i = 0; i < str.size(); i++) {
        if(mm[str[i]] == 1) return str[i];
    }
    return ' ';
}

int main() {
    cout << findFirstUnique("ijiji") << endl;
}
