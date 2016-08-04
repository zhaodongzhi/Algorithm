class Solution {
public:
    void help(const string &s, int begin, string record, vector<string>& result, int times){
        if(times == 5 && begin == s.size()){
            record.pop_back();
            result.push_back(record);
        }
        //else if((times == 5 && begin != s.size()) || (times != 5 && begin == s.size())) return;
        if((s.size() - begin > 3*(5-times)) || (s.size()-begin < (5-times))) return;
        else{
            int num = 0;
            for(int i = begin; i < begin + 3; ++i){
                num = num*10 + (s[i] - '0');
                record.push_back(s[i]);
                if(num < 256){
                    help(s, i+1, record+".", result, times+1);
                }
                if(num == 0){
                    break;
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string record;
        vector<string> result;
        help(s, 0, record, result, 1);
        return result;
    }
};
