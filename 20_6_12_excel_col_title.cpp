
bool invalidChar (char c) 
{  
    return !(c>=0 && c <128);   
} 
void stripUnicode(string & str) 
{ 
    str.erase(remove_if(str.begin(),str.end(), invalidChar), str.end());  
}

string Solution::convertToTitle(int A) {
    string ans, aux, mp = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
    int t = A;
    while(A) {
        aux += mp[A%26];
        if(A%26 == 0) A -= 26;
        A /= 26;
    }
    for(int i = aux.length(); i >= 0; i--) {
        ans += aux[i];
    }
    // stripUnicode(ans);
    // if(t == 980089) {
    //     for(char x : ans) cout << x << " ";
    //     cout << ans.size() << "\n";
    // }
    return ans.substr(1, ans.size()-1);
}
