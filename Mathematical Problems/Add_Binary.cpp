// Solution 1 --------->>>>>>>>
class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string str="";

        int i=a.size()-1;
        int j=b.size()-1;

        while(i>=0 && j>=0) {
            if(a[i]=='0' && b[j]=='0') {
                str.push_back(carry+'0');
                if(carry==1) carry=0; 
            }
            else if((a[i]=='0' && b[j]=='1') || (a[i]=='1' && b[j]=='0')) {
                if(carry==0) 
                    str.push_back('1');
                else 
                    str.push_back('0');
            }
            else if(a[i]=='1' && b[j]=='1') {
                str.push_back(carry+'0');
                carry=1;
            }
            i--;
            j--;
        }


        while(i>=0 || j>=0) {
            if(i>=0) {
                if(a[i] == '1') {
                    if(carry == 1) {
                        str.push_back('0');
                    }
                    else {
                        str.push_back('1');
                    }
                }
                else {
                    str.push_back(carry+'0');
                    if(carry == 1) carry = 0;
                }
                i--;
            }
            if(j>=0) {
                if(b[j] == '1') {
                    if(carry == 1) {
                        str.push_back('0');
                    }
                    else {
                        str.push_back('1');
                    }
                }
                else {
                    str.push_back(carry+'0');
                    if(carry == 1) carry = 0;
                }
                j--;
            }
        }


        if(carry==1) str.push_back('1');
        reverse(begin(str),end(str));
        return str;
    }
};




// Solution 2 -------->>>>>>>

class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry=0;
        int i = a.size()-1;
        int j = b.size()-1;

        while (i>=0 || j>=0 || carry) {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};






