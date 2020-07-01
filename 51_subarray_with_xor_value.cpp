
// struct TrieNode {
//     TrieNode *child[2] = {NULL, NULL};
//     int cnt = 0;
// };

// void insert(TrieNode *root, int val) {
//     TrieNode *curr = root;
//     for(int i = 31; i >= 0; i--) {
//         int b = (val>>i)&1;
//         if(curr->child[b] == NULL) {
//             curr->child[b] = new TrieNode();
//         }
//         curr = curr->child[b];
//     }
//     curr->cnt += 1;
// }

// int query(TrieNode *root, int preXor, int b) {
//     TrieNode *curr = root;
//     for(int i = 31; i >= 0; i--) {
//         if(curr) {
//             int x = (b>>i)&1;
//             int y = (preXor>>i)&1;
//             if(x == 1) {
//                 curr = curr->child[1-y];
//             } else {
//                 curr = curr->child[y];
//             }
//         }
//     }
//     return (curr == NULL ? 0 : curr->cnt);
// }

int Solution::solve(vector<int> &arr, int m) {
    int n = arr.size();

    long long ans = 0; // Initialize answer to be returned 
  
    int* xorArr = new int[n]; 
    unordered_map<int, int> mp; 
    xorArr[0] = arr[0]; 
  
    for (int i = 1; i < n; i++) 
        xorArr[i] = xorArr[i - 1] ^ arr[i]; 
  
    for (int i = 0; i < n; i++) { 
        int tmp = m ^ xorArr[i]; 
        ans = ans + ((long long)mp[tmp]); 
        if (xorArr[i] == m) 
            ans++; 
        mp[xorArr[i]]++; 
    } 
    return ans; 
}
