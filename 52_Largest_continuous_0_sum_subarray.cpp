
typedef pair<int, int> pii;

vector<int> Solution::lszero(vector<int> &A) {
    int n =  A.size();
    vector<pii> v(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += A[i];
        v[i] = {sum, i};
    }
    sort(v.begin(), v.end());
    int s = 0, e = 0, size = 0;
    
    for(int i = 0; i < n; i++) {
        if(v[i].first == 0) {
            int j = i+1;
            while(j < n && v[j].first == 0) {
                j += 1;
            }
            j--;
            if(size < v[j].second+1) {
                s = 0;
                e = v[j].second;
                size = v[j].second+1;
            }
            break;
        }
    }
    
    for(int i = 0; i < n; i++) {
        int j = i+1;
        while(j < n && v[j].first == v[i].first) {
            j += 1;
        }
        j--;
        int currSize = v[j].second-v[i].second;
        if(size < currSize) {
            s = v[i].second+1;
            e = v[j].second;
            size = currSize;
        } else if(size == currSize && s > v[i].second+1) {
            s = v[i].second+1;
            e = v[j].second;
        }
        i = j;
    }
    // for(pii x : v) {
    //     cout << x.first << " " << x.second << endl;
    // }
    vector<int> ans(size);
    for(int i = 0; i < size; i++) {
        ans[i] = A[s+i];
    }
    return ans;
}


