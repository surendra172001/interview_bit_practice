int Solution::isPalindrome(string A) {
    string b;
    for(char ch : A) {
        int x = ch;
        if((65 <= x && x  <= 90) || (97 <= x && x <= 122) || (48 <= x && x <= 57)) b += ch;
    }
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    int n = b.length();
    for(int i = 0; i < n/2; i++) {
        if(b[i] != b[n-i-1]) return 0;
    }
    return 1;
}
