#include <bits/stdc++.h>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> visited;
        for(int num: nums){
            if(visited[num])
                return true;
            
            visited[num] = true;
        }
        return false;
    }
};