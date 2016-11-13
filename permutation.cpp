// 给n个集合比如{a, b}, {1}, {x, y}. 从每个集合里面去一个数组成新的集合，输出所有这种集合，比如例子就是：{{a, 1, x}, {a,1,y}, {b,1,x}, {b,1,y}}.
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
