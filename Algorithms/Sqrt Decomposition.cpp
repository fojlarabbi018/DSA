#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a (n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    // preprocessing
    int len = ceil(sqrt (n + .0)); // size of the block and the number of blocks
    vector<int> b (len, 0);
    for (int i=0; i<n; i++) {
        b[i / len] += a[i];
    }

    int q;
    cin >> q;
    // answering the queries
    // Worst case for a query ---> (sqrt(n)-1) + (sqrt(n)-1) = 2*(sqrt(n)-1)
    // (when l=0 and r=n-2)...... whatever, it's asymptotically sqrt(n)
    // O(q*sqrt(n))
    for (int p=1; p<=q; p++) {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        for (int i=l; i<=r; ) {
            if (i % len == 0 && i + len - 1 <= r) {
                // if the whole block starting at i belongs to [l, r]
                sum += b[i / len];
                i += len;
            }
            else {
                sum += a[i];
                i++;
            }
        }
        cout << sum <<"\n";
    }
    return 0;
}
