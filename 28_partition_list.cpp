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

void append(ListNode **A, int x) {
    (*A)->next = new ListNode(x);
    (*A) = (*A)->next;
}

void print(ListNode *a) {
    while(a) {
        cout << a->val << " ";
        a = a->next;
    }
    cout << "\n";
}


ListNode* Solution::partition(ListNode* A, int B) {
    if(A == NULL) return A;
    ListNode *lt = new ListNode(0);
    ListNode *gt = new ListNode(0);
    ListNode *lp = lt, *gp = gt;
    int n = len(A);
    for(int i = 0; i < n; i++) {
        if(A->val < B) {
            append(&lp, A->val);
        } else {
            append(&gp, A->val);
        }
        A = A->next;
    }
    lt = lt->next;
    gt = gt->next;
    ListNode *ans = NULL, *end = NULL;
    
    // print(lt);
    // print(gt);
    
    if(lt != NULL) {
        ans = lt;
        end = lp;
    }

    if(gt != NULL) {
        if(ans && end) {
            end->next = gt;
        } else {
            ans = gt;
        }
        end = gp;
    }
    
    return ans;
}
