// BOJ18808: 스티커 붙이기
// https://www.acmicpc.net/problem/18808

#include <iostream>
using namespace std;

int N, M, K;
int notebook[40][40];
int rc[100][2];
int sticker[100][10][10];    // 1=스티커 O, 0=스티커 X

void rotate(int idx) {  // 스티커 회전  
    int origin[10][10];
    for(int i=0; i<rc[idx][0]; i++)      // 원본 복사
        for(int j=0; j<rc[idx][1]; j++)
            origin[i][j] = sticker[idx][i][j];

    for(int i=0; i<rc[idx][0]; i++) 
        for(int j=0; j<rc[idx][1]; j++)
            sticker[idx][j][rc[idx][0]-1-i] = origin[i][j];

    int tmp;
    tmp = rc[idx][0];
    rc[idx][0] = rc[idx][1];
    rc[idx][1] = tmp;
}

void paste() {
    bool is_success;
    int fail_cnt = 0;

    for(int idx=0; idx<K; ) {   // K개의 스티커를 붙인다.
        if(rc[idx][0] > N || rc[idx][1] > M) {    // 스티커 크기가 노트북보다 크다면 바로 실패 처리
            if(fail_cnt == 3) {
                fail_cnt = 0;
                idx++;
            } else {
                fail_cnt++;
                rotate(idx);
            }
            continue;
        }

        for(int i=0; i<N-rc[idx][0]+1; i++) {  // 노트북 전체에 좌측상단부터 스티커를 붙이기 적절한 위치를 탐색
            // 노트북 세로
            for(int j=0; j<M-rc[idx][1]+1; j++) {
                // 노트북 가로
                is_success = true;  // 붙이는 매 시도마다 초기화
                for(int k=0; k<rc[idx][0]; k++) {
                    // 스티커 세로
                    for(int l=0; l<rc[idx][1]; l++) {
                        // 스티커 가로
                        if(sticker[idx][k][l] && notebook[i+k][j+l]) { // 적절하지 않다면
                            is_success = false;     // 실패 처리
                            break;
                        }
                    }
                    if(!is_success) 
                        break;
                }

                if(is_success) {    // 적절한 위치라면
                    for(int k=0; k<rc[idx][0]; k++) {    // 붙인다.
                        for(int l=0; l<rc[idx][1]; l++) {
                            if(sticker[idx][k][l])
                                notebook[i+k][j+l] = sticker[idx][k][l];
                        }
                    }
                    break;
                }
            }
            if(is_success) 
                break;
        }
        
        if(is_success) {    // 성공했다면
            idx++;  // 다음 스티커로 넘어간다.
            fail_cnt = 0;
        } else {    // 실패했다면
            if(fail_cnt == 3) {     // 이미 3번 실패했다면 불가능하기에 다음 스티커로 넘어간다.
                idx++;
                fail_cnt = 0;
            } else {
                rotate(idx);    // 회전 시킨다.
                fail_cnt++;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for(int i=0; i<K; i++) {
        cin >> rc[i][0] >> rc[i][1];
        for(int j=0; j<rc[i][0]; j++)
            for(int k=0; k<rc[i][1]; k++)
                cin >> sticker[i][j][k];
    }

    paste();

    int cnt = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cnt += notebook[i][j];

    cout << cnt << '\n';
    
    return 0;
}