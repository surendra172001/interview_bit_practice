
struct Node {
    int x = 0;
    Node* child[2] = {NULL, NULL};
};

void insert(Node *head, int p) {
    Node *curr = head;
    for(int i = 31; i >= 0; i--) {
        int x = (p >> i) & 1;
        if(!curr->child[x]) curr->child[x] = new Node();
        curr = curr->child[x];
    }
    curr->x = p;
}

int query(Node *head, int v) {
    Node *curr = head;
    for(int i = 31; i >= 0; i--) {
        int c = (v >> i) & 1;
        if(curr->child[c]) curr = curr->child[c];
        else if(curr->child[1-c]) curr = curr->child[1-c];
    }
    return v^(curr->x);
}

int Solution::findMinXor(vector<int> &A) {
    int n = A.size();
    int minXor = INT_MAX;
    sort(A.begin(), A.end()); 
    int val = 0; 
    for (int i = 0; i < n - 1; i++) { 
        val = A[i] ^ A[i + 1]; 
        minXor = min(minXor, val); 
    } 
    return minXor; 
}

