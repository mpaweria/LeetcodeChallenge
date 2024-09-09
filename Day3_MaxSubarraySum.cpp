class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], maxSum = nums[0];

        for(int i=1; i<nums.size(); i++) {
            int temp = sum + nums[i];
            sum = max(temp, nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};