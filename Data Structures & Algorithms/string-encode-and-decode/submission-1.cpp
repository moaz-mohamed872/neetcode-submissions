class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";
        for(string str: strs){
            for(char c: str){
                output += to_string((int)c);
                output += ',';
            }
            output += '/';
        }
        return output;
    }

    vector<string> decode(string s) {
        vector<string> output;

        string current_str = "", current_char = "";
        for(char c: s){
            if (c == ','){
                current_str += (char)stoi(current_char);
                current_char = "";
            }
            else if (c == '/'){
                output.push_back(current_str);
                current_str = "";
            }
            else{
                current_char += c;
            }
        }
        return output;
    }
};
