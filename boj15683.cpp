#include <iostream>
#include <vector>
#include <algorithm>

#define UP      0
#define RIGHT   1
#define DOWN    2
#define LEFT    3

#define WALL    6

using namespace std;

typedef struct _CCTV {
    int num;
    int y_;
    int x_;
    bool pos[4];    
} CCTV;

int N, M;
int ret = 987654321;
int map[8][8];
vector<CCTV> c;

void rotate(int idx) {
    int tmp = c[idx].pos[3];
    for(int i=3; i>=0; i--)
        c[idx].pos[i+1] = c[idx].pos[i];
    c[idx].pos[0] = tmp;
}

void activate_cctv(int idx, int plus) {   
    int y, x;
    for(int i=0; i<4; i++) {
        y = c[idx].y_;
        x = c[idx].x_;
        if(c[idx].pos[i]) {
            if(i == UP) {
                while(y >= 0 && map[y][x] != WALL) {
                    if(map[y][x] <= 0)
                        map[y--][x] += plus;
                    else 
                        y--;
                }
            } else if(i == RIGHT) {
                while(x < M && map[y][x] != WALL) {
                    if(map[y][x] <= 0) 
                        map[y][x++] += plus;
                    else 
                        x++;
                }
            } else if(i == DOWN) {
                while(y < N && map[y][x] != WALL) {
                    if(map[y][x] <= 0)
                        map[y++][x] += plus;
                    else 
                        y++;
                }
            } else {
                while(x >= 0 && map[y][x] != WALL) {
                    if(map[y][x] <= 0)
                        map[y][x--] += plus;
                    else 
                        x--;
                }
            }
        }
    }
}

void solve(int idx, int n) {
    if(idx == n) {
        int count = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                if(!map[i][j])
                    count++;
        
        ret = min(ret, count);
        return;
    }

    for(int i=0; i<4; i++) {        
        activate_cctv(idx, -1);     
        solve(idx+1, n);
        activate_cctv(idx, 1);      
        rotate(idx);
    }
}

int main(void) {
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            cin >> map[i][j];

            if(map[i][j] >= 1 && map[i][j] <= 5) {  
                CCTV unit;
                unit.num = map[i][j];
                unit.y_ = i;
                unit.x_ = j;
                for(int i=0; i<4; i++)
                    unit.pos[i] = 0;
                if(unit.num == 1) 
                    unit.pos[RIGHT] = true;
                else if(unit.num == 2) 
                    unit.pos[RIGHT] = unit.pos[LEFT] = true;
                else if(unit.num == 3)
                    unit.pos[UP] = unit.pos[RIGHT] = true;
                else if(unit.num == 4)
                    unit.pos[UP] = unit.pos[RIGHT] = unit.pos[LEFT] = true;
                else
                    unit.pos[UP] = unit.pos[RIGHT] = unit.pos[LEFT] = unit.pos[DOWN] = true;

                c.push_back(unit);
            }
        }

        solve(0, c.size());
        cout << ret << '\n';

    return 0;
}