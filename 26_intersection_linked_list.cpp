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

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int m = len(A);
    int n = len(B);
    int diff = abs(m-n);
    ListNode* h1 = A;
    ListNode* h2 = B;
    if(m > n) {
        while(diff) {
            h1 = h1->next;
            diff--;
        }
    } else {
        while(diff) {
            h2 = h2->next;
            diff--;
        }
    }
    
    while(h1 != NULL && h2 != NULL) {
        if(h1 == h2) return h1;
        h1 = h1->next;
        h2 = h2->next;
    }
    return NULL;
}
