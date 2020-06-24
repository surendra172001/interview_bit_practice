/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
void print(ListNode *head, int n) {
    ListNode *t2 = head;
    for(int i = 0; i < n; i++) {
        cout << (t2->val) << " ";
        t2 = t2->next;
    }
    cout << "\n";
}


ListNode* getFirstNode(ListNode *A, ListNode *B) {
    int cnt = 1;
    ListNode *t = B->next;
    while(t != B) cnt++, t = t->next;
    ListNode *p1 = A, *p2 = A;
    for(int i = 0; i < cnt; i++) {
        p2 = p2->next;
    }
    while(p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}


ListNode* detectCycle(ListNode* A) {
    //detectCycle
    ListNode *sp = A, *fp = A->next;
    while(sp && fp && fp->next) {
        if(sp == fp) {
            break;
        }
        sp = sp->next;
        fp = fp->next->next;
    }
    //end
    
    if(sp == fp) {
        return getFirstNode(A, sp);
    } else {
        return NULL;
    }
}



int main()
{
    int n;
    cin >> n;
    ListNode *head = new ListNode(-1);
    
    ListNode *t1 = head;
    
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        t1->next = new ListNode(x);
        t1 = t1->next;
    }
    
    head = head->next;
    
    int b;
    
    cin >> b;
    
    if(b != -1) {
        ListNode *t2 = head;
        for(int i = 0; i < b-1; i++) {
            t2 = t2->next;
        }
        t1->next = t2;
    }

    
    ListNode* ans = detectCycle(head, n);
    
    cout << ans->val << "\n";

    return 0;
}


