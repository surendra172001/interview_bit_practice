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
 

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if(A == NULL) return B;
    if(B == NULL) return A;
    int m = len(A);
    int n = len(B);
    ListNode *t;
    int diff;
    if(m < n) {
        t = A;
        diff = n-m;
    } else {
        t = B;
        diff = m-n;
    }
    ListNode *tp = NULL;
    while(t) tp = t, t=t->next;
    for(int i = 0; i < diff; i++) {
        tp->next = new ListNode(0);
        tp = tp->next;
    }
    ListNode *t1 = A;
    ListNode *t2 = B;
    int carry = 0;
    int sum = 0;
    int dig = 0;
    
    int bg = max(m, n);
    
    ListNode *prev = NULL;
    
    while(t1 != NULL && t2 != NULL) {
        sum = t1->val+t2->val+carry;
        dig = sum%10;
        carry = sum/10;
        t1->val = dig;
        prev = t1;
        t1 = t1->next;
        t2 = t2->next;
    }
    if(carry) prev->next = new ListNode(carry);
    return A;
}
