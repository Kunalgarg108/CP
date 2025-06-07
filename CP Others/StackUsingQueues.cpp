#include<bits/stdc++.h>
using namespace std;

// 1. Push
// 2. Pop
// 3. Top
// 4. Is Empty
// 5. Exit
class Stack {
    queue<int> q1, q2;

public:
    void push(int x){
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop(){
        if(q1.empty()) {
            cout <<"Stack Underflow"<<endl;
            return;
        }
        q1.pop();
    }
    int top(){
        if(q1.empty()) {
            cout <<"Stack is empty"<<endl;
            return -1;
        }
        return q1.front();
    }
    bool empty(){
        return q1.empty();
    }
};

int main() {
    Stack st;
    int choice, value;
    while(true) {
        cin >> choice;
        switch(choice) {
            case 1:
                cin >> value;
                st.push(value);
                break;

            case 2:
                st.pop();
                break;

            case 3:
                value = st.top();
                if(value != -1)
                    cout << value << endl;
                break;

            case 4:
                cout <<(st.empty() ? "Stack is empty." : "Stack is not empty.")<<endl;
                break;

            case 5:
                return 0;
        }
    }
    return 0;
}
