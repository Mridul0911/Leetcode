class Solution {
public:
    int maximum69Number (int num) {
        string numm = to_string(num);
        for (auto &c : numm) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return stoi(numm);
    }
};