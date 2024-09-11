class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mapP, mapS;
        vector<int> ans;

        for(int i=0; i<p.size(); i++)
            mapP[p[i]]++;

        for(int i=0; i<p.size(); i++)
            mapS[s[i]]++;

        int i = 0, j = p.size()-1;

        while(j < s.size()) {
            if(mapP == mapS)
                ans.push_back(i);
            mapS[s[i]] > 1 ? mapS[s[i]]-- : mapS.erase(s[i]);
            i++;
            j++;

            if(j < s.size())
                mapS[s[j]]++;
        }
        return ans;
    }
};