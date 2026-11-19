class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size()), sufix(nums.size());

        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            prefix[i] = nums[i] * prefix[i-1];
        }

        sufix[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; --i) {
            sufix[i] = nums[i] * sufix[i+1];
        }

        vector<int> output(nums.size());
        output[0] = sufix[1];
        output[nums.size() - 1] = prefix[nums.size() - 2];
        for (int i = 1; i < nums.size() - 1; ++i) {
            output[i] = prefix[i - 1] * sufix[i + 1];
        }
        
        return output;
    }
};