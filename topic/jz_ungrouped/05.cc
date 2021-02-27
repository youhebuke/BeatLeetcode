class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(auto i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                res += "%20";
            } else{
                res += s[i];
            }
        }
        return res;
    }
};