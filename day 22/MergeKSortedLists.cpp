/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
    /*    priority_queue<pair<int,ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>pq;
        for (auto it: lists) {
            if (it != NULL)
            pq.push({it->val, it});
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top().second;
            pq.pop();
            if (node->next) pq.push({node->next->val, node->next});
            temp->next = node;
            temp = temp->next; 
        }
        return dummy->next; */
        return mergesort(0, lists.size() - 1, lists);
    }

    ListNode* mergesort(int start, int end, vector<ListNode*>& lists) {
        if (start > end) return NULL;
        if (start == end) return lists[start];
        int mid = start + (end - start) / 2;
        ListNode* left = mergesort(start, mid, lists);
        ListNode* right = mergesort(mid + 1, end, lists);
        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (left != NULL && right != NULL) {
            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        temp->next = (left != NULL) ? left : right;
        return dummy->next;
    }
};
