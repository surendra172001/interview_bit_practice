
int countZeroSum(vector<int> &arr)
{
  int n = arr.size();
  unordered_map<int, int> mp;
  int count = 0;
  int sum = 0;
  for(int i = 0; i < n; i++)
  {
      sum += arr[i];
      if(sum==0)
      {
          count++;
      }
      if(mp.find(sum) != mp.end())
      {
          count += mp[sum];
      }
      mp[sum]++;
  }
  return count;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    if(n == 0 || m == 0) {
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        vector<int> aux(n);
        for(int j = i; j < m; j++) {
            for(int k = 0; k < n; k++) {
                aux[k] += A[k][j];
            }
            ans += countZeroSum(aux);
        }
    }
    return ans;
}
