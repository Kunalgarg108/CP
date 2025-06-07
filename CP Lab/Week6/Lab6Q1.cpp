#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node* random;

    Node(int v) {
        val = v;
        next = NULL;
        random = NULL;
    }
};

void printList(Node* head) {
    Node* start=head;
    while (head!=NULL) {
       cout<<head->val<<" ";
       head=head->next;
    }
    cout<<endl;
    while(start!=NULL){
        if(start->random!=NULL){
            cout<<start->val<<" "<<start->random->val<<endl;
        }
        start=start->next;
    }
    return;
}

Node* cloneList(Node* head) {
    if (!head) return NULL;
    unordered_map<Node*, Node*> mp;
    Node* temp = head;
    while (temp) {
        mp[temp] = new Node(temp->val);
        temp = temp->next;
    }

    temp = head;
    while (temp) {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    return mp[head];
}
Node* createList() {
    int n;
    cin >> n;
    if (n == 0) return NULL;
    vector<Node*> nodes;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        nodes.push_back(new Node(val));
        if (i > 0)
            nodes[i - 1]->next = nodes[i];
    }
    for (int i = 0; i < n; i++) {
        int randIndex;
        cin >> randIndex;
        if ((randIndex>=0 && randIndex<n)){
            nodes[i]->random = nodes[randIndex];
        } 
        else{
            nodes[i]->random = NULL;
        }   
    }

    return nodes[0];  
}

int main() {
    int t;
    cin>>t;
    while(t--){
        Node* head = NULL;
        head=createList();
        Node* clonedHead = cloneList(head);
        printList(clonedHead);
    }

    return 0;
}



/*Input
6
1 2 3 4 5 6
2 3 4 5 1 0
5
10 20 30 40 50
0 1 2 3 4 
5
10 20 30 40 50
4 3 2 1 0
5
10 20 30 40 50
3 3 3 3 3
1
30
0
2
20 40
1 0
*/

/*
Output:
1 2 3 4 5 6
1 3
2 4
3 5
4 6
5 2
6 1

10 20 30 40 50
10 10
20 20
30 30
40 40
50 50

10 20 30 40 50
10 50
20 40
30 30
40 20
50 10

10 20 30 40 50
10 40
20 40
30 40
40 40
50 40

30
30 30

20 40
20 40
40 20

*/