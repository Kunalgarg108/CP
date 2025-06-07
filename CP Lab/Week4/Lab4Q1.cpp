#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* head,Node* tail) {
    while (head!=tail->next) {
        cout <<head->data << " ";
        head=head->next;
    }
    cout << endl;
}

Node* partition(Node* head, Node* tail) {
    Node* pivot = head;
    Node* pre = head;
    Node* curr = head;

    while (curr != tail->next) {
        if (curr->data < pivot->data) {
            pre = pre->next;
            swap(curr->data, pre->data);
        }
        curr = curr->next;
    }
    swap(pivot->data, pre->data);
    return pre;
}

Node* quickSort(Node* head,Node* tail) {
    if (head == nullptr || head == tail) {
        return head;
    }
    Node* pivot = partition(head, tail);
    quickSort(head, pivot);
    quickSort(pivot->next, tail);
    return head;
}

void insert(Node*& head,Node*& tail,int data) {
    Node* newNode=new Node(data);
    if (!head) {
        head=newNode;
        tail=head;
        return;
    }
    tail->next=newNode;
    tail=tail->next;
    return;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        Node* head=nullptr;
        Node* tail=nullptr;
        cin>>n;
        for(int i=0;i<n;i++){
            int x=0;
            cin>>x;
            insert(head,tail,x);
        }
        head = quickSort(head,tail);
        printList(head,tail);
    }
    return 0;
}


/*
Input:
5
1 2 3 4 5
6
22 13 25 18 9 3
8
11 12 11 23 34 32 11 23
9
23 23 23 35 31 21 16 16 16
*/

/*
Output:
1 2 3 4 5
3 9 13 18 22 25
11 11 11 12 23 23 32 34
16 16 16 21 23 23 23 31 35
*/