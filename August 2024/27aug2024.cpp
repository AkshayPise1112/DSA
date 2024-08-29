#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // 2. Add Two Numbers
    // https://leetcode.com/problems/add-two-numbers/

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* ans = new ListNode(-1);
        ListNode* ansPtr = ans;
        int borrow = 0;

        while(ptr1 != NULL || ptr2 != NULL){
            if(ptr1 != NULL && ptr2 != NULL){

                int temp = ptr1 -> val + ptr2 -> val + borrow;
                int og = temp % 10;
                borrow = temp / 10;

                ListNode* node = new ListNode(og);
                ansPtr -> next = node;

                ansPtr = ansPtr -> next;
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }

            if(ptr1 != NULL && ptr2 == NULL){
                int temp = ptr1 -> val + borrow;
                int og = temp % 10;
                borrow = temp / 10;

                ListNode* node = new ListNode(og);
                ansPtr -> next = node;

                ansPtr = ansPtr -> next;
                ptr1 = ptr1 -> next;
            }

            if(ptr2 != NULL && ptr1 == NULL){
                int temp = ptr2 -> val + borrow;
                int og = temp % 10;
                borrow = temp / 10;

                ListNode* node = new ListNode(og);
                ansPtr -> next = node;

                ansPtr = ansPtr -> next;
                ptr2 = ptr2 -> next;
            }
        }

        if(borrow != 0){
            ListNode* node = new ListNode(borrow);
            ansPtr -> next = node;
        }

        return ans -> next;
    }

    // Add 1 to a Linked List Number
    // https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

    int add(Node * head){
        if(head == nullptr)
            return 1;
          
        int carry = add(head->next);
        head->data += carry;
        carry = head->data/10;
        head->data = head->data%10;
        return carry;
    }
  
    Node* addOne(Node* head) {
        
        if(add(head)){
            Node *temp = new Node(1);
            temp->next = head;
            return temp;
        }
        
        return head;
    }

    // Flattening a Linked List
    // https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

    Node *flatten(Node *root) {
        vector<int> num;
        Node* ptr = root;
        
        while(ptr != NULL){
            num.push_back(ptr -> data);
            Node* btmPtr = ptr -> bottom;
            while(btmPtr != NULL){
                num.push_back(btmPtr -> data);
                btmPtr = btmPtr -> bottom;
            }
            ptr = ptr -> next;
        }
        
        sort(num.begin(), num.end());
        
        Node* ans = new Node(-1);
        Node* ansPtr = ans;
        
        for(auto i: num){
            Node* temp = new Node(i);
            ansPtr -> bottom = temp;
            ansPtr = ansPtr -> bottom;
        }
        
        return ans -> bottom;
        
    }
};