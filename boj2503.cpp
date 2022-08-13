// BOJ 2503: 숫자야구
// 1~9를 하나씩 사용하여 3자리 숫자 모두 생성하여 주어진 입력과 일치한지 비교

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int cand[100][3];   // {{후보 숫자, strike 개수, ball 개수} * N}
bool visited[10] = {0, };
int ret = 0;

bool check(vector<int> qn, vector<int> an, int idx) {
    int ball_cnt = 0;
    int strk_cnt = 0;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(an[i] == qn[j] && i == j)
                strk_cnt++;
            else if(an[i] == qn[j])
                ball_cnt++;
            else {}
        }
    }

    if(cand[idx][1] == strk_cnt && cand[idx][2] == ball_cnt) 
        return true;
    return false;
}

void make_num(vector<int>& num, int cnt) {
    if(cnt == 3) {
        int sum = 0;
        for(int i=0; i<N; i++) {
            vector<int> an;
            int a = cand[i][0];
            while(a != 0) {
                an.push_back(a%10);
                a /= 10;
            }
            reverse(an.begin(), an.end());
            sum += check(num, an, i);
        }

        if(sum == N) 
            ret++;
    }

    for(int i=1; i<10; i++) {
        if(!visited[i]) {
            num.push_back(i);
            visited[i] = true;
            make_num(num, cnt+1);
            visited[i] = false;
            num.pop_back();
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> cand[i][0] >> cand[i][1] >> cand[i][2];
    }

    vector<int> num;
    make_num(num, 0);
    
    cout << ret << '\n';

    return 0;
}