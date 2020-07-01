
vector<int> extractDigs(int A) {
    vector<int> dig;
    while(A) {
        dig.push_back(A%10);
        A /= 10;
    }
    int half = dig.size()/2;
    for(int i = 0; i < half; i++) {
        swap(dig[i], dig[dig.size()-i-1]);
    }
    return dig;
}

int Solution::colorful(int A) {
    map<int, int> mp;
    vector<int> dig = extractDigs(A);
    for(int i = 0; i < dig.size(); i++) {
        int prod = 1;
        for(int j = i; j < dig.size(); j++) {
            prod *= dig[j];
            mp[prod] += 1;
        }
    }
    bool flag = true;
    auto it = mp.begin();
    for(; it != mp.end(); it++) {
        if(it->second > 1) {
            flag = false;
            break;
        }
    }
    return int(flag);
}
