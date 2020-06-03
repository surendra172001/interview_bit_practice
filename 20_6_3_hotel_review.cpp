
#include<bits/stdc++.h>
using namespace std;
#define pii     pair<int, int>
#define F       first
#define S       second

struct Node {
    bool end;
    Node *children[26];
    Node() {
        end = false;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};


void insert(Node *head, string &word) {
    Node *temp = head;
    for(char ch : word) {
        int pos = (int)ch - 97;
        if(temp->children[pos] == NULL) {
            temp->children[pos] = new Node();
        }
        temp = temp->children[pos];
    }
    temp->end = true;
}

bool isGoodWord(string &word, Node *head) {
    Node *temp = head;
    for(char ch : word) {
        int pos = (int)ch - 97;
        if(temp->children[pos] == NULL) {
            return false;
        }
        temp = temp->children[pos];
    }
    if(temp->end)
        return true;
    else
        return false;
}


bool cmp(pii &a, pii &b) {
    if(a.F != b.F) return a.F > b.F;
    else return a.S < b.S;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    Node *head = new Node();
    stringstream s(A);
    string word;
    while (getline(s, word, '_')) {
        insert(head, word);
    }
    vector<pii> aux(B.size());
    int p = 0;
    for(string x : B) {
        int cnt = 0;
        stringstream ss(x);
        while (getline(ss, word, '_')) {
            if(isGoodWord(word, head)) cnt += 1;
        }
        aux[p] = {cnt, p};
        p += 1;
    }
    
    sort(aux.begin(), aux.end(), cmp);
    vector<int> ans(B.size());
    p = 0;
    for(pii y : aux) {
        ans[p] = y.S;
        p++;
    }
    return ans;
}

