/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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

int len(ListNode* A) {
    ListNode* t = A;
    int l = 0;
    while(t != NULL) {
        l++;
        t = t->next;
    }
    return l;
}

ListNode* Solution::reverseList(ListNode* A, int B) {
    int n = len(A);
    int f = n/B;
    ListNode *h = A;
    ListNode *prev = NULL;
    for(int i = 0; i < f; i++) {
        ListNode *nextSt = h;
        for(int j = 0; j < B; j++) nextSt = nextSt->next;
        ListNode *end = NULL;
        h = reverse(h, &end, B);
        if(prev) prev->next = h;
        else A = h;
        end->next = nextSt;
        prev = end;
        h = nextSt;
    }
    return A;
}
