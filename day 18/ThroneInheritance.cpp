class ThroneInheritance {
public:
    unordered_map<string, bool>dead;
    unordered_map<string, vector<string>>mpp;
    string king;
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        mpp[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead[name] = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        dfs(ans, king);
        return ans;
    }
    void dfs(vector<string>& ans, string root) {
        if (!dead[root]) ans.push_back(root);
        for (auto it: mpp[root]) dfs(ans, it);
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
