#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // 142. Linked List Cycle II
    // https://leetcode.com/problems/linked-list-cycle-ii/

    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }

        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        bool first = false;

        while(ptr2 != NULL){

            cout << ptr2 -> val << " ";
            if(ptr1 == ptr2 && first){
                ptr2 = head;
                break;
            }
            else{
                first = true;
                ptr1 = ptr1 -> next;
                if(ptr2 -> next != NULL){
                    ptr2 = ptr2 -> next -> next;
                }
                else{
                    return NULL;
                }
            }

        }

        while(ptr2 != NULL){
            if(ptr1 == ptr2){
                return ptr1;
            }

            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }

        return NULL;
    }

    
    // 25. Reverse Nodes in k-Group
    // https://leetcode.com/problems/reverse-nodes-in-k-group/

    ListNode* reverse(ListNode* head, int k, ListNode* &last){
        int count = 0;
        ListNode* nextPtr = head;
        ListNode* prevPtr = NULL;
        last = head;

        while(count < k){
            ListNode* temp = nextPtr -> next;
            nextPtr -> next = prevPtr;
            prevPtr = nextPtr;
            nextPtr = temp;
            count ++;
        }

        return prevPtr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head -> next == NULL || head == NULL){
            return head;
        }
        
        ListNode* ptr = head;
        ListNode* first = head;
        ListNode* ans = new ListNode(0);
        ListNode* currAns = ans;
        int count = 0;

        while(ptr != NULL){
            ptr = ptr -> next;
            count ++;
            if(count == k){
                ListNode* last = NULL;
                ListNode* temp = reverse(first, k, last);
                first = ptr;
                count = 0;
                currAns -> next = temp;
                currAns = last;
            }
        }

        if(first != NULL){
            currAns -> next = first;
        }

        return ans -> next;
    }


    
    // Find length of Loop
    // https://www.geeksforgeeks.org/problems/find-length-of-loop/1

    int countNodesinLoop(struct Node *head) {
        if(head == NULL || head -> next == NULL){
            return 0;
        }

        struct Node* ptr1 = head;
        struct Node* ptr2 = head;
        struct Node* firstNode = NULL;
        bool first = false;

        while(ptr2 != NULL){

            if(ptr1 == ptr2 && first){
                ptr2 = head;
                break;
            }
            else{
                first = true;
                ptr1 = ptr1 -> next;
                if(ptr2 -> next != NULL){
                    ptr2 = ptr2 -> next -> next;
                }
                else{
                    return 0;
                }
            }

        }

        while(ptr2 != NULL){
            if(ptr1 == ptr2){
                firstNode = ptr1;
                break;
            }

            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }

        if(firstNode != NULL) ptr1 = firstNode -> next;
        int count = 1;

        while(ptr1 != NULL && ptr2 != NULL){
            count ++;
            ptr1 = ptr1 -> next;
            if(ptr1 == firstNode){
                return count;
            }
            
        }
        return 0;
    }
};