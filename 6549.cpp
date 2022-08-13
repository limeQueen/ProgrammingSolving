#include <iostream>
#include <algorithm>
using namespace std;

long long h[100'001];

long long solve(int left, int right) {
    if(left == right)
        return h[left];

    int mid = (left + right) / 2;
		// 가장 큰 직사각형이 왼쪽 또는 오른쪽 부분 문제에 존재하는 경우
    long long ret = max(solve(left, mid), solve(mid + 1, right)); 

		// 가장 큰 직사각형이 왼쪽 부분 문제와 오른쪽 부분 문제에 걸쳐 존재하는 경우
    int lo = mid, hi = mid + 1;
    long long height = min(h[lo], h[hi]);
    ret = max(ret, height * 2);

		// 가로로 한 칸씩 확장해 나간다.
    while(left < lo || right > hi) {
        if(right > hi && (left == lo || h[lo-1] < h[hi+1])) {
            hi++;
            height = min(height, h[hi]);
        } else {
            lo--;
            height = min(height, h[lo]);
        }

        ret = max(ret, (hi-lo+1)*height);
    }

    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    while(1) {
        cin >> n;

        if(!n)
            break;

        for(int i=0; i<n; i++) {
            cin >> h[i];
        }

        cout << solve(0, n-1) << '\n';
    }

    return 0;
}