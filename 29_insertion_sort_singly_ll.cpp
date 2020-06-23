/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *result = new ListNode(A->val);
    ListNode *prev = NULL, *curr = NULL;
    ListNode *t = A->next;
    while(t != NULL) {
        prev = NULL;
        curr = result;
        while(curr && (curr->val) < (t->val)) {
            prev = curr;
            curr = curr->next;
        }
        ListNode *nN = new ListNode(t->val);
        if(prev == NULL) {
            nN->next = result;
            result = nN;
        } else if(curr == NULL) {
            prev->next = nN;
        } else {
            nN->next = prev->next;
            prev->next = nN;
        }
        t = t->next;
    }
    return result;
}
