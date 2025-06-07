#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v){
        val=v;
        next=NULL;
    } 
};

Node* Input(int n,int p){
    Node* head=NULL;
    Node* temp=NULL;
    Node* store=NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* nn=new Node(x);
        if(head==NULL){
            head=nn;
            temp=head;
        }
        else{
            temp->next=nn;
            temp=temp->next;
        }
        if(i==p){
            store=temp;
        }
    }
    if(p==-1){
        temp->next=NULL;
    }
    else{
        temp->next=store;
    }
    return head;
}

bool isCycle(Node* head){
    if(head==NULL && head->next==NULL){
        return false;
    }
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,p;
        cin>>n>>p;
        Node* head=NULL;
        head=Input(n,p);
        cout<<isCycle(head)<<endl;
    }
    return 0;
}


/*Input:11
7 -1
1 3 2 4 5 6 7
6 4
1 2 3 4 5 6
7 3
1 3 2 5 6 7 9
8 4
1 3 2 5 4 7 6 8
7 2
1 2 3 4 5 6 7
7 4
3 4 5 6 2 1 8
6 0
1 2 4 3 6 5
0 -1
1 -1
4
2 -1
1 3
2 0
2 4
*/

/*Output
0
1
1
1
1
1
1
0
0
0
1
*/