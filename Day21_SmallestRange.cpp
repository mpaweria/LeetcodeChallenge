class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = nums.size(), mini = INT_MAX, maxi = INT_MIN;

        for(int i=0; i<n; i++) {
            int val = nums[i][0];
            mini = min(mini, val);
            maxi = max(maxi, val);
            pq.push({val, i, 0});
        }

        int left = mini, right = maxi;

        while(!pq.empty()) {
            vector<int> top = pq.top();
            int val = top[0];
            int r = top[1];
            int c = top[2];
            pq.pop();

            if(maxi-val < right - left) {
                right = maxi;
                left = val;
            }

            if(c+1 < nums[r].size()) {
                int temp = nums[r][c+1];
                maxi = max(maxi, temp);

                pq.push({temp, r, c+1});
            } else {
                break;
            }
        }
        return {left, right};
    }
};