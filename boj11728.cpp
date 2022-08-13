// BOJ 11728
// https://www.acmicpc.net/problem/11728

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<m; i++) 
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> c(n+m);
    int p = 0, q = 0, idx = 0;
    while(p < n && q < m) {
        if(a[p] > b[q]) {
            c[idx] = b[q];
            q++;
        } else {
            c[idx] = a[p];
            p++;
        }
        idx++;
    }

    if(q >= m) {
        for(int i=p; i<n; i++, idx++)
            c[idx] = a[i];
    } else {
        for(int i=q; i<m; i++, idx++)
            c[idx] = b[i];
    }

    for(int i=0; i<idx; i++)
        cout << c[i] << ' ';

    return 0;
}