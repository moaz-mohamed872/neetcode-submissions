class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> char_appear;

        for(char c: s)
            char_appear[c]++;

        for(char c: t){
            if(char_appear[c] == 0)
                return false;
            
            char_appear[c]--;

            if(char_appear[c] == 0)
                char_appear.erase(c);
        }

        if(char_appear.empty())
            return true;
        
        return false;
    }
};
