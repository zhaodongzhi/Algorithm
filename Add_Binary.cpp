class Solution {
public:
    void help(string& long_s, string &short_s, string& result){
        int carry = 0;
        int i;
        for(i = 0; i < long_s.size(); ++i){
            int temp;
            if(i < short_s.size()) temp = long_s[long_s.size()-i-1]-'0' + short_s[short_s.size()-i-1]-'0' + carry;
            else temp = long_s[long_s.size()-i-1]-'0' + carry;
            char c = (char)(temp%2)+'0';
            carry = temp >> 1;
            result.push_back(c);
        }
        if(carry == 1){
            result.push_back('1');
        }
        reverse(result.begin(), result.end());
    }
    string addBinary(string a, string b) {
        string result;
        if(a.size() > b.size()){
            help(a, b, result);
        }
        else{
            help(b, a, result);
        }
        return result;
    }
};
