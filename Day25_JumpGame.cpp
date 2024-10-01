class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJumps = nums[0];
        for(int i=0; i<nums.size(); i++) {
            if(maxJumps >= nums.size()-1)
                return true;
            if(nums[i] == 0 && maxJumps == i)
                return false;
            if(i + nums[i] > maxJumps)
                maxJumps = i + nums[i];
        }
        return true;
    }
};