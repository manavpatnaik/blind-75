#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *a, *b;
    a = b = head;
    for (int i = 0; b && i < n; i++) {
        b = b->next;
    }
    // Checking if b is null, only happens when n == length of list
    // i.e we need to delete head
    if (!b) return head->next;
    while (b->next) {
        a = a->next;
        b = b->next;
    }
    a->next = a->next->next;
    return head;
}
