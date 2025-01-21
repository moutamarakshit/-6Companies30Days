class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
       Node* temp = head;
       while (temp) {
           for (int i = 0; i < m - 1 && temp != nullptr; i++) {
               temp = temp->next;
           }
           
           if (!temp) return head;
           
           Node* t = temp->next;
           for (int i = 0; i < n && t != nullptr; i++) {
               Node* del = t;
               t = t->next;
               delete(del);
           }
           
           temp->next = t; // connecting
           temp = t; // new curr node
       }
       return head;
    }
