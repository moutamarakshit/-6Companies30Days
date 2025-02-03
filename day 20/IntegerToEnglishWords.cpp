class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string big[] = {"Thousand", "Million", "Billion"};
        string res = helper(num % 1000);
        num /= 1000;
        for (int i = 0; i < 3; i++) {
            if (num > 0 && num % 1000 > 0)
                res = helper(num % 1000) + big[i] + " " + res;
            num /= 1000;
        }
        return res.substr(0, res.size() - 1);
    }
    string helper(int num) {
        string ones[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string elev[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
        "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res = "";
        if (num > 99) {
            res += ones[num / 100] + " Hundred ";
        }
        num %= 100;
        if (num < 20 && num > 9) {
            res += elev[num % 10] + " ";
        }
        else {
            if (num >= 20) {
            res += tens[num / 10] + " ";
            num %= 10;
            }
            if (num > 0) {
                res += ones[num] + " ";
            }
        }
        return res;
    }
};
