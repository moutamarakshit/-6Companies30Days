class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream s(preorder);
        int nodes = 1;
        string str;
        while(getline(s, str, ',')) {
            nodes--;
            if (nodes < 0) return false;
            if (str != "#") nodes += 2; // for every not null node, there must be two children nodes in the preorder
        }
        return nodes == 0;  
    }
};
