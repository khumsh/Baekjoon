#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
char board[21][21];
int ans = 0;

// DFS 함수: (r, c) 위치, 현재까지 경로 길이 cnt, 사용된 알파벳 상태 (비트마스크)
// 비트마스크에서 i번째 비트가 1이면 'A'+i 문자가 이미 사용됨을 의미.
void dfs(int r, int c, int cnt, int used) {
    ans = max(ans, cnt);
    
    // 상하좌우 이동
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    for (int d = 0; d < 4; d++){
        int nr = r + dr[d];
        int nc = c + dc[d];
        // 범위 체크
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        // 현재 칸의 알파벳
        int idx = board[nr][nc] - 'A';
        // 만약 해당 알파벳이 이미 사용되었다면 건너뛰기
        if (used & (1 << idx)) continue;
        // 사용 상태 갱신: 해당 알파벳을 사용 표시하고 DFS 진행
        dfs(nr, nc, cnt + 1, used | (1 << idx));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> board[i][j];
        }
    }
    
    // 시작 위치 (0,0): 사용된 알파벳 상태는 board[0][0]에 해당하는 비트 설정
    int startUsed = 1 << (board[0][0] - 'A');
    dfs(0, 0, 1, startUsed);
    
    cout << ans << "\n";
    
    return 0;
}

