
int Solution::lengthOfLastWord(const string A) {
    if(A.length() == 0) return 0;
    int cnt = 0;
    int i = A.length()-1;
    while(i >= 0 && A[i] == ' ') i--;
    if(i < 0) return 0;
    while(i >= 0 && A[i] != ' ') cnt += 1, i--;
    return cnt;
}
