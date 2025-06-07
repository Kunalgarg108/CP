#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void insertNode(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next) return head; 

    ListNode* dummy = new ListNode(0); 
    ListNode* curr = head; 

    while (curr!=NULL) {
        ListNode* prev = dummy; 
        ListNode* nextNode = curr->next; 
        while (prev->next && prev->next->val < curr->val) {
            prev = prev->next;
        }
        curr->next = prev->next;
        prev->next = curr;
        curr = nextNode;
    }

    return dummy->next; 
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val <<" ";
        head = head->next;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        ListNode* head = nullptr;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            insertNode(head, x);
        }
        head = insertionSortList(head);
        printList(head);
    }

    return 0;
}


/*
Input:6
4
3 2 1 4
5
1 2 3 4 5
5
5 4 3 2 1
5
3 3 3 3 3
1 
7
2
4 1
*/

/*
Output:
1 2 3 4
1 2 3 4 5
1 2 3 4 5
3 3 3 3 3 
7
1 4
*/