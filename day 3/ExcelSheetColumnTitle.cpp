class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str;
        while (columnNumber) {
            columnNumber--;
            int curr = columnNumber % 26;
            columnNumber /= 26;
            str.push_back(curr + 'A');
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
