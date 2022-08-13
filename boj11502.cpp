#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

#define MAX 987654321

int card[1'001];
int cache[1'001];
int N;

int choice(int cnt) {
    if(cnt > N) return MAX;
    if(cnt == N) {
        return 0;
    }
    
    int& ret = cache[cnt];
    if(ret != MAX)   
        return ret;

    for(int i=1; i<=N; i++) {
        ret = min(ret, choice(cnt + i) + card[i]);
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<=1000; i++)
        cache[i] = MAX;

    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> card[i];
    }

    cout << choice(0) << '\n';

    return 0;
}