// 给一个String和一个字典，找字典里面长度最长的能由String里面删去某些字符后组成的单词
// 比如S = abpcplea， Dict = {ale, apple, monkey, plea}, 就返回apple

// bfs 复杂度极高
vector<string> findNeighbors(string s, unordered_set<string>& dict) {
    vector<string> res;
    for(int i = 0; i < s.size(); i++) {
        string temp = s.substr(0, i) + s.substr(i+1);
        res.push_back(temp);
    }
    return res;
}

string longestWordInDict(string s, unordered_set<string> dict) {
    queue<string> qu;
    qu.push(s);

    while(!qu.empty()) {
        string word = qu.front();
        if(dict.find(word) != dict.end()) return word;
        qu.pop();
        vector<string> neighbors = findNeighbors(word, dict);
        for(auto nei : neighbors) {
            qu.push(nei);
        }
    }
    return "";
}


int main() {
    unordered_set<string> dict = {"ale", "apple", "monkey", "plea"};
    cout << longestWordInDict("abpcplea", dict) << endl;
}


// Trie
