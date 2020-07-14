/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<set>

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    multiset<int> st;
    for(ListNode* curr : A) {
        ListNode* t = curr;
        while(t) {
            st.insert(t->val);
            t = t->next;
        }
    }
    ListNode* ans = new ListNode(0);
    ListNode* t = ans;
    for(int x : st) {
        t->next = new ListNode(x);
        t = t->next;
    }
    ans = ans->next;
    return ans;
}

// class cmp
// {
//     public:
//     bool operator()(ListNode* a, ListNode* b)
//     {
//         return a->val > b->val;
//     }
// };

// ListNode* Solution::mergeKLists(vector<ListNode*> &a) {
//     priority_queue<ListNode *,vector<ListNode *>, cmp> pq;
//     ListNode *dummy = new ListNode(-1);
//     ListNode *b = dummy;
//     for(int i=0; i<a.size(); i++)
//     {
//         if(a[i] != NULL)
//         {
//             pq.push(a[i]);
//         }
//     }
//     while(!pq.empty())
//     {
//         b->next = pq.top();
//         ListNode *temp = pq.top();
//         pq.pop();
//         if(temp->next) pq.push(temp->next);
//         b = b->next;
//         b->next = NULL;
//     }
//     return dummy->next;
// }
