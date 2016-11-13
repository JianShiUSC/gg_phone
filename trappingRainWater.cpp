class Solution {
public:
    int trap(vector<int>& height) {
        int begin = 0;
        int end = height.size() - 1;
        int res = 0;
        int level = 0;
        while(begin < end) {
            int lower = height[begin] < height[end] ? height[begin++] : height[end--];
            level = max(level, lower);
            res += (level - lower);
        }
        return res;
    }
};
