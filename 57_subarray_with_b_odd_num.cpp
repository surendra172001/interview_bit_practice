int Solution::solve(vector<int>& a, int m)
{
    int n = a.size();

    if(m == 0) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(a[i]%2 == 1) {
                continue;
            }
            int j = i+1;
            while(j < n && (a[j]%2 == 0)) {
                j += 1;
            }
            j -= 1;
            int r = j-i+1;
            ans += r*(r+1)/2;
            i = j;
        }
        return ans;
    }

    int count = 0;
    int prefix[n] = { 0 };
    int odd = 0;

    // traverse in the array
    for (int i = 0; i < n; i++) {

        prefix[odd]++;

        // if array element is odd
        if (a[i] & 1)
            odd++;

        // when number of odd elements>=M
        if (odd >= m)
            count += prefix[odd - m];
    }

    return count;
}

