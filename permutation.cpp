void helper(vector<vector<string>>& res, vector<string>& sol, vector<vector<string>> list, int pos) {
    if(sol.size() == list.size()) {
        res.push_back(sol);
        return;
    }
    for(int i = 0; i < list[pos].size(); i++) {
        sol.push_back(list[pos][i]);
        helper(res, sol, list, pos+1);
        sol.pop_back();
    }
}

vector<vector<string>> permutation(vector<vector<string>> list) {
    vector<vector<string>> res;
    vector<string> sol;
    helper(res, sol, list, 0);
    return res;
}

int main() {
    vector<vector<string>> list = {{"a","b"}, {"1"}, {"x","y"}};
    permutation(list);
}
