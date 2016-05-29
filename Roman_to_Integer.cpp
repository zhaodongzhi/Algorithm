class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) return 0;

        int roman[24] = {};
        roman['I' - 'A'] = 1;
        roman['V' - 'A'] = 5;
        roman['X' - 'A'] = 10;
        roman['L' - 'A'] = 50;
        roman['C' - 'A'] = 100;
        roman['D' - 'A'] = 500;
        roman['M' - 'A'] = 1000;
        
        int result = roman[s.back()-'A'];
        for(int i = s.size()-2; i >= 0; --i){
            int left = roman[s[i]-'A'];
            int right = roman[s[i+1]-'A'];
            if(left >= right){
                result += left;
            }
            else{
                result -= left;
            }
        }
        return result;
    }
};
