class Solution {
public:
    string intToRoman(int num) {
        string roman;
        vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        for (int i = 0; num > 0; i++) {
            while (num >= val[i]) {
                roman += symbol[i];
                num -= val[i];
            }
        }
        return roman;
    }
};




