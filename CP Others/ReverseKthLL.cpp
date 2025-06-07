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

Node* reverseKGroup(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* curr = head;
    Node* prevTail = nullptr;
    Node* newHead = nullptr;

    while (curr) {
        stack<Node*> st;
        Node* temp = curr;
        int count = 0;

        while (temp && count < k) {
            st.push(temp);
            temp = temp->next;
            count++;
        }

        if (count < k) {
            if (prevTail)
                prevTail->next = curr;
            break;
        }

        while (!st.empty()) {
            if (!newHead) {
                newHead = st.top();
                prevTail = newHead;
                st.pop();
            } else {
                prevTail->next = st.top();
                prevTail = prevTail->next;
                st.pop();
            }
        }

        prevTail->next = temp;
        curr = temp;
    }

    return newHead ? newHead : head;
}

int main() {
    Node* head = nullptr;
    int n, val, k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        insert(head, val);
    }
    cin >> k;
    head = reverseKGroup(head, k);
    printList(head);
    return 0;
}
