class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;

        for(string str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            map[s].push_back(str);
        }

        for(auto m: map){
            ans.push_back(m.second);
        }

        return ans;
    }
};