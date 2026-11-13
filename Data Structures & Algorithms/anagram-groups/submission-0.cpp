class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> inxs;

        for(int i = 0; i < strs.size(); i++){
            string sorted_str = strs[i];
            sort(sorted_str.begin(), sorted_str.end());
            inxs[sorted_str].push_back(i);
        }

        vector<vector<string>> output(inxs.size());
        int i = 0;
        for(auto element: inxs){
            for(int inx: element.second){
                output[i].push_back(strs[inx]);
            }
            i++;
        }

        return output;
    }
};
