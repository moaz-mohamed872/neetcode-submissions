class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int,int>> rank;
        vector<int> output;

        for(int num: nums)
            freq[num]++;

        for(auto elment: freq)
            rank.push({elment.second, elment.first});
        
        while(output.size() < k && !rank.empty()){
            output.push_back(rank.top().second);
            rank.pop();
        }

        return output;
    }
};
