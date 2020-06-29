
#include<set>
#include<string>
#define SIZE 21
typedef long long ll;
ll fact[SIZE] = {1, 1};

void fillFact() {
    for(ll i = 2; i < SIZE; i++) {
        fact[i] = i*fact[i-1];
    }
}

string Solution::getPermutation(int A, int B) {
    fillFact();
    string ans;
    set<int> s;
    for(int i = 1; i <= A; i++) {
        s.insert(i);
    }
    B -= 1;
    int r = B;
    for(ll i = A; i > 1; i--) {
        int digPos = r/fact[i-1]+1;
        set<int>::iterator it = s.begin();
        for(int r = 0; r < digPos-1; r++) {
            it++;
        }
        ans += to_string(*it);
        s.erase(it);
    }
    ans += to_string(*s.begin());
    return ans;
}
