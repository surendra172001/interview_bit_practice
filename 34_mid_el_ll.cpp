int len(ListNode* A) {
    ListNode* t = A;
    int l = 0;
    while(t != NULL) {
        l++;
        t = t->next;
    }
    return l;
}
 
int Solution::solve(ListNode* A) {
    int n = len(A);
    int half = n/2;
    ListNode *f = A;
    
    for(int i = 0; i < half; i++) {
        f = f->next;
    }
    return f->val;
}
