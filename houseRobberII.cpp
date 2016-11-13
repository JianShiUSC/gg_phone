/*
dp[n] = max{dp[n-1], dp[n-2] + nums[n]}
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        return max(getMoney(nums, 0, size - 2), getMoney(nums, 1, size - 1));
    }

    int getMoney(vector<int>& nums, int begin, int end) {
        if(begin == end) return nums[begin];
        int dp1 = nums[begin];
        int dp2 = max(nums[begin], nums[begin + 1]);

        for(int i = begin + 2; i <= end; i++) {
            int temp = dp2;
            dp2 = max(dp2, dp1 + nums[i]);
            dp1 = temp;
        }
        return dp2;
    }
};



// house robber 1 : 一个int[] A, 输出不相邻的elements组成的最大的sum
// follow up negative number

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        int dp1 = nums[0];
        if(size == 1)  return dp1;
        int dp2 = max(nums[0], nums[1]);

        for(int i = 2; i < size; i++) {
            int temp = dp2;
            dp2 = max(dp1 + nums[i], dp2);
            dp1 = temp;
        }
        return dp2;
    }
};



class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        int dp1 = max(nums[0], 0);
        if(size == 1)  return dp1;
        int dp2 = max(dp1, nums[1]);

        for(int i = 2; i < size; i++) {
            int temp = dp2;
            dp2 = max(dp1 + nums[i], dp2);
            dp1 = temp;
        }
        return dp2;
    }
};
