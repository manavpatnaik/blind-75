#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getMid(ListNode* head) {
    ListNode *slow, *fast, *prev = NULL;
    slow = fast = head;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) prev->next = NULL;
    return slow;
}

ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL, *curr = head, *temp = NULL;
    while (curr) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}