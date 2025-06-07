#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout <<  source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1,source,destination,auxiliary);
    cout << source << " to " << destination << endl;
    towerOfHanoi(n - 1,auxiliary,source,destination);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        towerOfHanoi(n, 'A', 'B', 'C');
    }
    return 0;
}
