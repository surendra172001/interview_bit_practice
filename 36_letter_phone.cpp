map<int, string> mp;

void initialize() {
    mp.insert({1 , "1"});
    mp.insert({2 , "abc"});
    mp.insert({3 , "def"});
    mp.insert({4 , "ghi"});
    mp.insert({5 , "jkl"});
    mp.insert({6 , "mno"});
    mp.insert({7 , "pqrs"});
    mp.insert({8 , "tuv"});
    mp.insert({9 , "wxyz"});
    mp.insert({0 , "0"});
}

vector<string> letterCombinationsUtil(string &A, int idx) {
    if(idx == A.length()) {
        return vector<string>(1, "");
    }
    vector<string> smallOutput = letterCombinationsUtil(A, idx+1);
    string str = mp[A[idx]-'0'];
    vector<string> output(str.size()*smallOutput.size());
    int i = 0;
    for(char x : str) {
        for(string s : smallOutput) {
            output[i] += x;
            output[i] += s;
            i++;
        }
    }
    return output;
}

vector<string> Solution::letterCombinations(string A) {
    initialize();
    vector<string> ans = letterCombinationsUtil(A, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
