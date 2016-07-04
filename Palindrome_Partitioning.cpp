class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if(s.size() == 0){
            return result;
        }
        vector<string> temp_result;
        help(s, 0, temp_result, result);
        return result;
    }
    
    void help(const string& s, int start, vector<string>& temp_result, vector<vector<string>>& result){
        if(start == s.size()){
            result.push_back(temp_result);
        }
        for(int i = start; i < s.size(); ++i){
            if(is_palindrome(s, start, i)){
                temp_result.push_back(s.substr(start, i-start+1));
                help(s, i+1, temp_result, result);
                temp_result.pop_back();
            }
        }
    }
    
    bool is_palindrome(const string& s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
};
