#include <bits/stdc++.h>
using namespace std;

int insertBits(int n, int k, int i, int j) {
    int left = 1 << (j + 1);  
    int right = (1 << i) - 1;   
    int mask = left | right;    
    cout<<mask<<endl;    
    n = n & mask;
    k = k << i;
    return (n | k);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k, start, end;
        cin >> n >> k >> start >> end;
        int result = insertBits(n, k, start, end);
        cout << result << endl;
    }
    
    return 0;
}






/*Input
16 7
0 2
37 19
2 4
41 40
0 5
47 21
0 31
32 6
2 3 

*/

/*
Output:
16
41
53
40
55
61
62
56
*/

