#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // 138. Copy List with Random Pointer
    // https://leetcode.com/problems/copy-list-with-random-pointer/

    Node* copyRandomList(Node* head) {
        
        Node* ptr = head;

        while(ptr != NULL){
            Node* temp = new Node(ptr -> val);
            temp -> next = ptr -> next;
            ptr -> next = temp;
            ptr = ptr -> next -> next;
        }

        ptr = head;

        while(ptr != NULL){
            if(ptr -> random == NULL){
                ptr = ptr -> next -> next;
                continue;
            }
            ptr -> next -> random = ptr -> random -> next;
            ptr = ptr -> next -> next;
        }

        ptr = head;

        Node* newList = new Node(-1);
        Node* newPtr = newList;

        while(ptr != NULL){
           newPtr -> next = ptr -> next;
           ptr -> next = ptr -> next -> next;
           ptr = ptr -> next;
           newPtr = newPtr -> next;
        }

        return newList -> next;
    }

    
    // 160. Intersection of Two Linked Lists
    // https://leetcode.com/problems/intersection-of-two-linked-lists/

    ListNode* solve(ListNode* headA, ListNode* headB){
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        // if(ptr1 == ptr2){
        //     return ptr1;
        // }


        while(1){
            if(ptr1 == NULL && ptr2 == NULL){
                return NULL;
            }
            if(ptr1 == NULL){
                ptr1 = headB;
            }
            if(ptr2 == NULL){
                ptr2 = headA;
            }

            if(ptr1 == ptr2){
                return ptr1;
            }

            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }

        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        return solve(headA, headB);

        // ------------------------------------------------------------------------------------------------

        // unordered_map<ListNode*, int> mp;

        // ListNode* ptr = headA;

        // while(ptr != NULL){
        //     mp[ptr] = 1;
        //     ptr = ptr -> next;
        // }

        // ptr = headB;

        // while(ptr != NULL){
        //     if(mp[ptr] == 1){
        //         return ptr;
        //     }
        //     ptr = ptr -> next;
        // }

        // return NULL;


        // ------------------------------------------------------------------------------------------------

        // ListNode* ptr = headA;
        // ListNode* ans = NULL;

        // while(ptr != NULL){
        //     ListNode* temp = headB;
        //     while(temp != NULL){
        //         if(temp == ptr){
        //             ans = temp;
        //             break;
        //         }
        //         temp = temp -> next;
        //     }
        //     if(ans != NULL){
        //         break;
        //     }
        //     ptr = ptr -> next;
        // }

        // return ans;
    }

    // Sort a linked list of 0s, 1s and 2s
    // https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

    Node* segregate(Node* head) {
        
        int zero = 0;
        int one = 0;
        int two = 0;
        
        Node* ptr = head;
        
        while(ptr != NULL){
            if(ptr -> data == 0) zero++;
            if(ptr -> data == 1) one++;
            if(ptr -> data == 2) two++;
            
            ptr = ptr -> next;
        }
        
        ptr = head;
        
        while(zero > 0){
            ptr -> data = 0;
            ptr = ptr -> next;
            zero--;
        }
        while(one > 0){
            ptr -> data = 1;
            ptr = ptr -> next;
            one--;
        }
        while(two > 0){
            ptr -> data = 2;
            ptr = ptr -> next;
            two--;
        }
        
        return head;
    }
};