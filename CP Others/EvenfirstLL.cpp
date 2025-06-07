#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* rearrangeEvenOdd(Node* head) {
    if (!head || !head->next) return head;

    Node* evenStart = nullptr;
    Node* evenEnd = nullptr;
    Node* oddStart = nullptr;
    Node* oddEnd = nullptr;

    Node* curr = head;
    while (curr) {
        int val = curr->data;
        if (val % 2 == 0) {
            if (!evenStart) {
                evenStart = evenEnd = curr;
            } else {
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        } else {
            if (!oddStart) {
                oddStart = oddEnd = curr;
            } else {
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
        curr = curr->next;
    }

    if (!evenStart) return oddStart;
    evenEnd->next = oddStart;
    if (oddEnd)
        oddEnd->next = nullptr;
    return evenStart;
}

int main() {
    Node* head = nullptr;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        insert(head, val);
    }
    head = rearrangeEvenOdd(head);
    printList(head);
    return 0;
}
