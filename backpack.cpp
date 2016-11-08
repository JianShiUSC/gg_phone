int backpack(vector<int> coins, int val) {
    //dp[i] 表示和为i时的 数量
    vector<int> dp(val + 1, 0);

    for(int i = 0; i < coins.size(); i++) {
        for(int j = coins[i]; j <= val; j++) {
//            dp[j] = max(dp[j], dp[j - coins[i]] + 1);
            dp[j] += dp[j-coins[i]] + 1;
        }
    }
    return dp[val];
}

int main() {
    vector<int> coins = {2,3};
    cout << backpack(coins, 10) << endl;
}
