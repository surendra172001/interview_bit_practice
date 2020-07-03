
int Solution::solve(string A) {
    int cnt[26] = {0};
    for(char ch : A) {
        cnt[(int)(ch-'a')] += 1;
    }
    int n = A.length();
    int oddCnt = 0;
    int evenCnt = 0;
    for(int i = 0; i < 26; i++) {
        evenCnt += (cnt[i]%2 == 0);
        oddCnt += (cnt[i]%2);
    }
    // for(int i = 0; i < 26; i++) {
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;
    // cout << evenCnt << " " << oddCnt << endl;
    if(n%2 == 0) {
        return (oddCnt == 0);
    } else {
        return (oddCnt == 1);
    }
}
