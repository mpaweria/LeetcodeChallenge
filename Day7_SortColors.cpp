class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = -1, mid = 0, end = nums.size()-1;

        while(mid <= end) {
            if(nums[mid] == 0) {
                start++;
                swap(nums[start], nums[mid]);
                mid++;
            } else if(nums[mid] == 1)
                mid++;
            else {
                swap(nums[mid], nums[end]);
                end--;
            }
        }
    }
};