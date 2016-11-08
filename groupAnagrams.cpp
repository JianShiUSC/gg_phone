vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    vector<string> sol;
    for(auto ss : strs) {
        sort(ss.begin(), ss.end());
        sol.push_back(ss);
    }
    unordered_map<string, vector<int>> mm;
    for(int i = 0; i < sol.size(); i++) {
        mm[sol[i]].push_back(i);
    }

    for(auto it = mm.begin(); it != mm.end(); it++) {
        vector<string> temp;
        for(int i = 0; i < it->second.size(); i++) {
            temp.push_back(strs[it->second[i]]);
        }
        sort(temp.begin(), temp.end());
        res.push_back(temp);
    }
    return res;
}
