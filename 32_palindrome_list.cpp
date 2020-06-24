/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 

int len(ListNode* A) {
    ListNode* t = A;
    int l = 0;
    while(t != NULL) {
        l++;
        t = t->next;
    }
    return l;
}

ListNode* reverse(ListNode *A, ListNode **endP, int B) {
    ListNode *h = A;
    ListNode *curr = A;
    ListNode *prev = NULL;
    for(int i = 0; i < B; i++) {
        ListNode* t = curr->next;
        curr->next = prev;
        prev = curr;
        curr = t;
    }
    *endP = h;
    return prev;
}

int Solution::lPalin(ListNode* A) {
    int n = len(A);
    int half = n/2;
    ListNode *f1 = A, *f2 = A;
    
    for(int i = 0; i < half; i++) {
        f2 = f2->next;
    }
    
    if(n%2) {
        f2 = f2->next;
    }
    
    ListNode *prev = NULL, *end = f2;
    while(end) {
        prev = end;
        end = end->next;
    }
    end = prev;
    
    f2 = reverse(f2, &end, half);
    
    bool flag = true;
    for(int i = 0; i < half; i++) {
        if(f1->val != f2->val) {
            flag = false;
            break;
        }
        f1 = f1->next;
        f2 = f2->next;
    }
    
    return flag;
}
