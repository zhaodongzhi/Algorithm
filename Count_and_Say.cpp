class Solution {
public:
    string countAndSay(int n) {
        string result = "";
        if(n == 0) return result;
        result.push_back('1');
        for(int i = 0; i < n-1; ++i){
            string temp = "";
            char c = result[0];
            int count = 0;
            for(int j = 0; j < result.size(); ++j){
                if(result[j] == c){
                    ++count;
                }
                else{
                    temp.push_back('0'+count);
                    temp.push_back(c);
                    count = 1;
                    c = result[j];
                }
            }
            temp.push_back('0'+count);
            temp.push_back(c);
            result = temp;
        }
        return result;
    }
};
