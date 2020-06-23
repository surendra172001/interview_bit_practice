/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *h = A, *prev = NULL, *end = NULL;
    // getting at mth position
    int x = B-1;
    while(x--) prev = h, h = h->next;
    end = prev;
    
    ListNode *curr = h, *t = NULL;
    prev = NULL;
    x = C-B+1;
    while(x--) {
        t = curr->next;
        curr->next = prev;
        prev = curr;
        curr = t;
    }
    h->next = curr;
    if(end){
        end->next = prev;
    } else {
        A = prev;
    }
    return A;
}
