class Solution {
public:
    int f(vector<int>& nums, int n, vector<int>& dp) {
        if (n < 0) return 0;
        if (n == 0) return nums[0];

        if (dp[n] != -1) return dp[n];

        int rob     = f(nums, n - 2, dp) + nums[n];
        int skip    = f(nums, n - 1, dp);

        return dp[n] = max(rob, skip);
    }

    int robRange(vector<int>& nums, int start, int end) {
        int size = end - start + 1;
        vector<int> dp(size, -1);

        // Create a subarray for the range
        vector<int> sub(nums.begin() + start, nums.begin() + end + 1);
        return f(sub, size - 1, dp);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int case1 = robRange(nums, 0, n - 2); // Exclude last
        int case2 = robRange(nums, 1, n - 1); // Exclude first

        return max(case1, case2);
    }
};