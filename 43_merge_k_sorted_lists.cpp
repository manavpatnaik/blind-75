#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare {
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = NULL, *curr = NULL;
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    
    for (ListNode *list : lists) {
        if (list)
            pq.push(list);
    }
    
    while (!pq.empty()) {
        ListNode *node = pq.top();
        pq.pop();
        if (!head) {
            head = node;
            curr = head;
        } else {
            curr->next = node;
            curr = curr->next;
        }
        if (node->next) pq.push(node->next);
    }
    return head;
}