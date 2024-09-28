class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int prefix[n];
        prefix[0] = arr[0];

        for(int i=1; i<n; i++)
            prefix[i] = arr[i] + prefix[i-1];

        unordered_map<int,int> map;

        int ans = 0;

        for(int i=0; i<n; i++) {
            if(prefix[i] == k)
                ans++;

            if(map.find(prefix[i] - k) != map.end())
                ans += map[prefix[i] - k];

            map[prefix[i]]++;
        }
        return ans;
    }
};