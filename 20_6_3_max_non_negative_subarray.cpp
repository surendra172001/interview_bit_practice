vector<int> Solution::maxset(vector<int> &a) {
    int n = a.size();
    long maxTillNow = 0, maxLen = 0, maxEndingHere = 0, currLen = 0, globalStart = -1, currStart = -1;
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(a[i] < 0) {
            flag = true;
            if(maxTillNow < maxEndingHere) {
                maxTillNow = maxEndingHere;
                maxLen = currLen;
                globalStart = currStart;
            } else if(maxTillNow == maxEndingHere && maxLen < currLen) {
                maxLen = currLen;
                globalStart = currStart;
            }
            maxEndingHere = 0;
            currStart = -1;
            currLen = 0;
        } else {
            if(flag) {
                currStart = i;
                flag = false;
            }
            currLen += 1;
            maxEndingHere += a[i];
        }
    }

    if(maxTillNow < maxEndingHere) {
        maxTillNow = maxEndingHere;
        maxLen = currLen;
        globalStart = currStart;
    } else if(maxTillNow == maxEndingHere && maxLen < currLen) {
        maxLen = currLen;
        globalStart = currStart;
    }
    

    if(maxLen <= 0) {
        return vector<int>();
    }
    
    vector<int> ans(maxLen);
    for(int i = 0; i < maxLen; i++) {
        ans[i] = a[i+globalStart];
    }
    
    return ans;
}



