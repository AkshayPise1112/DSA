#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    // 19. Remove Nth Node From End of List
    // https://leetcode.com/problems/remove-nth-node-from-end-of-list/

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 0){
            return head;
        }

        ListNode* next = head;
        int cnt = 0;

        while(next != NULL){
            next = next -> next;
            cnt ++;
        }

        ListNode* prev = NULL;
        next = head;

        cnt = cnt - n;
        int count = 0;

        if(cnt == 0){
            return head -> next;
        }

        while(count < cnt){
            prev = next;
            next = next -> next;
            count++;
        }

        prev -> next = next -> next;
        delete next;

        return head;
    }


    // 2095. Delete the Middle Node of a Linked List
    // https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == NULL){
            delete head;
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* temp = slow -> next;
        slow -> next = slow -> next -> next;
        delete temp;

        return head;
    }
    

    // 148. Sort List
    // https://leetcode.com/problems/sort-list/

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

    void merge(vector<int> &arr, int l, int s, int mid, int e){
        vector<int> first;
        vector<int> second;

        for(int i=s; i<=mid; i++){
            first.push_back(arr[i]);
        }
        for(int i=mid+1; i<=e; i++){
            second.push_back(arr[i]);
        }

        int n = first.size();
        int m = second.size();

        int i = 0, j = 0;
        int k = s;

        while(i < n && j < m){
            if(first[i] < second[j]){
                arr[k++] = first[i++];
            }
            else{
                arr[k++] = second[j++];
            }
        }

        while(i < n){
            arr[k++] = first[i++];
        }
        while(j < m){
            arr[k++] = second[j++];
        }
    }

    void solve(vector<int> &arr, int n, int s, int e){
        if(s >= e){
            return;
        }

        int mid = s + (e - s) / 2;

        solve(arr, n, s, mid);
        solve(arr, n, mid+1, e);

        merge(arr, n, s, mid, e);
    }

    ListNode* findMid(ListNode* head){
        if(head -> next -> next == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    ListNode* mergeLL(ListNode* left, ListNode* right){
        ListNode* ans = new ListNode(-1);

        ListNode* ptr1 = left;
        ListNode* ptr2 = right;
        ListNode* ansPtr = ans;


        while(ptr1 != NULL && ptr2 != NULL){
            ListNode* temp = NULL;

            if(ptr1 -> val < ptr2 -> val){
                temp = ptr1;
                ptr1 = ptr1-> next;
            }
            else{
                temp = ptr2;
                ptr2 = ptr2 -> next;
            }

            ansPtr -> next = temp;
            ansPtr = ansPtr -> next;
            temp -> next = NULL;
        }

        if(ptr1 != NULL){
            ansPtr -> next = ptr1;
        }

        if(ptr2 != NULL){
            ansPtr -> next = ptr2;
        }

        return ans -> next;
    }


    ListNode* MergeSort(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* mid = findMid(head);
        ListNode* Middle = mid -> next;
        mid -> next = NULL;
        
        ListNode* left = MergeSort(head);
        ListNode* right = MergeSort(Middle);


        ListNode* newList = mergeLL(left, right);


        return newList;
    }

    ListNode* sortList(ListNode* head) {
        return MergeSort(head);
        
        // ListNode* ptr = head;
        // vector<int> arr;

        // while(ptr != NULL){
        //     arr.push_back(ptr -> val);
        //     ptr = ptr -> next;
        // }

        // solve(arr, arr.size(), 0, arr.size() - 1);

        // ptr = head;
        // int i = 0;

        // while(ptr != NULL){
        //     ptr -> val = arr[i++];
        //     ptr = ptr -> next;
        // }

        // return head;
    }
};