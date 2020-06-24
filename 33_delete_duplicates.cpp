/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *curr = A;
    ListNode *ans = new ListNode(-1);
    ListNode *ansp = ans;
    while(curr) {
        ListNode *aux = curr;
        ansp->next = new ListNode(curr->val);
        ansp = ansp->next;
        while(aux && curr->val == aux->val) {
            aux = aux->next;
        }
        curr = aux;
    }
    return ans->next;
}
