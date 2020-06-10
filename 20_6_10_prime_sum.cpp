
vector<int> Solution::primesum(int A) {
    const int MAX = A+1;
    bool prime[A+1] = {};
    vector<int> p;
	prime[2] = true;
	for(int i = 3; i < MAX; i += 2) prime[i] = true;
    for (int p=3; p*p<MAX; p += 2) { 
        if (prime[p]) { 
            for (int i=p*p; i < MAX; i += p) 
                prime[i] = false; 
        }
    }
    for(int i = 2; i < MAX; i++) {
        if(prime[i]) p.push_back(i);
    }
    for(int i = 0; i < p.size(); i++) {
        int x = A-p[i];
        if(prime[x]) {
            return vector<int>({p[i], x});
        }
    }
}
