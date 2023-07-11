class Solution {
private:
    vector<string> ones = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    vector<string> tens = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    vector<string> thousands = {"", " Thousand", " Million", " Billion"};
    
    string N_to_W(int n) {
        if (n < 20) return ones[n];
        
        if (n < 100) return tens[n / 10] + N_to_W(n % 10);
        
        if (n < 1000) return N_to_W(n / 100) + " Hundred" + N_to_W(n % 100);
        
        for (int i = thousands.size()-1; i >= 0; i--) {  // Iterating over thousand array
            if (n >= pow(1000, i)) {
                return N_to_W(n / pow(1000, i)) + thousands[i] + N_to_W(n % (int)pow(1000, i));
            }
        }
        return "";
    }
    
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string ans = N_to_W(num);
        ans = ans.substr(1,ans.size()-1); //excluding the leading space
        return ans;
    }
};









