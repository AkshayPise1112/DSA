#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    

    // 234. Palindrome Linked List
    // https://leetcode.com/problems/palindrome-linked-list/

    bool isPalindrome(ListNode* head) {
        vector<int> ans;
        ListNode* ptr = head;

        while(ptr != NULL){
            ans.push_back(ptr -> val);
            ptr = ptr -> next;
        }

        for(int i=0, j=ans.size()-1; i <= j; i++, j--){
            if(ans[i] == ans[j]){
                continue;
            }
            else{
                return false;
            }
        }
        
        return true;
    }

    // 328. Odd Even Linked List
    // https://leetcode.com/problems/odd-even-linked-list/

    
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head; 

        ListNode* odd = head; 
        ListNode* even = head->next;
        ListNode* temp = even; 

        while (even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = temp;

        return head;
    }


    // 61. Rotate List
    // https://leetcode.com/problems/rotate-list/


    ListNode* solve(ListNode* head){
        ListNode* prev;
        ListNode* next = head;

        while(next -> next != NULL){
            prev = next;
            next = next -> next;
        }

        next -> next = head;
        prev -> next = NULL;

        return next;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* ptr = head;
        int count = 0;

        while(ptr != NULL){
            ptr = ptr -> next;
            count ++;
        }

        k = k % count;

        for(int i=0; i<k; i++){
            head = solve(head);
        }

        return head;
    }
};
