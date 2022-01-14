class Solution {
public:
    string multiply(string num1, string num2) {
     if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        string result(num1.size() + num2.size(), '0');        

        for (int i = num1.size() - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--, carry /= 10) {
                carry += (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
                result[i + j + 1] = carry % 10 + '0';
            }
            
            result[i] += carry;
        }
        
        return result[0] == '0' ? result.substr(1, result.size()) : result;       
    }
};