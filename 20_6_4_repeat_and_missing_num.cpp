#define ll long long
vector<int> Solution::repeatedNumber(const vector<int> &a) {
    int n = a.size();
    int A, B;
    ll nSum = 0, nSqSum = 0, acSum = 0, acSqSum = 0;
    for(int i = 0; i < n; i++) {
        nSum += i+1;
        nSqSum += ((ll)(i+1)) * ((ll)(i+1));
        acSum += a[i];
        acSqSum += ((ll)(a[i])) * ((ll)(a[i]));
    }
    int abSum = (acSqSum - nSqSum)/(acSum - nSum);
    int abDiff = (acSqSum - nSqSum)/abSum;
    A = abs(abDiff+abSum)/2;
    B = abs(abSum - abDiff)/2;
    vector<int> ans = {A, B};
    return ans;
}
