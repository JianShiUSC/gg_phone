vector<string> removeDuplicates(vector<string> arr) {
    vector<string> res;
    unordered_set<string> ss;
    for(int i = 0; i < arr.size(); i++) {
        ss.insert(arr[i]);
    }
    for(auto str : ss) {
        res.push_back(str);
    }
    return res;
}

vector<string> removeDuplicates(vector<string> arr) {
    vector<string> res;
    sort(arr.begin(), arr.end());
    string preStr = arr[0];
    res.push_back(preStr);
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] == preStr) continue;
        else {
            preStr = arr[i];
            res.push_back(preStr);
        }
    }
    return res;
}

int main() {
    vector<string> arr = {"1","1","2","2","3"};
    removeDuplicates(arr);
}
