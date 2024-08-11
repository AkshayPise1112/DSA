#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // 876. Middle of the Linked List
    // https://leetcode.com/problems/middle-of-the-linked-list/submissions/1348951737/

    ListNode* middleNode(ListNode* head) {
        int n = 0;

        ListNode* ptr = head, ans;

        while(ptr != NULL){
            n++;
            ptr = ptr -> next;
        }

        int mid = n/2, i=0;
        ptr = head;

        while(i < mid){
            ptr = ptr -> next;
            i++;
        }

        return ptr;
    }

    
    // 206. Reverse Linked List
    // https://leetcode.com/problems/reverse-linked-list/submissions/1349583117/

    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }

        ListNode* next = head;
        ListNode* prev = NULL;

        while(next != NULL){
            ListNode* ptr = next -> next;
            next -> next = prev;
            prev = next;
            next = ptr;
        }

        return prev;
    }

    
    
    // 141. Linked List Cycle
    // https://leetcode.com/problems/linked-list-cycle/description/

    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }

        ListNode* ptr1 = head;
        ListNode* ptr2 = head -> next;

        while(ptr2 != NULL){
            if(ptr1 == ptr2){
                return true;
            }

            ptr1 = ptr1 -> next;
            if(ptr2 -> next != NULL){
                ptr2 = ptr2 -> next -> next;
            }
            else{
                return false;
            }
        }

        return false;
    }

};