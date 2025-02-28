#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
char board[21][21];
int ans = 0;

// DFS �Լ�: (r, c) ��ġ, ������� ��� ���� cnt, ���� ���ĺ� ���� (��Ʈ����ũ)
// ��Ʈ����ũ���� i��° ��Ʈ�� 1�̸� 'A'+i ���ڰ� �̹� ������ �ǹ�.
void dfs(int r, int c, int cnt, int used) {
    ans = max(ans, cnt);
    
    // �����¿� �̵�
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    for (int d = 0; d < 4; d++){
        int nr = r + dr[d];
        int nc = c + dc[d];
        // ���� üũ
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        // ���� ĭ�� ���ĺ�
        int idx = board[nr][nc] - 'A';
        // ���� �ش� ���ĺ��� �̹� ���Ǿ��ٸ� �ǳʶٱ�
        if (used & (1 << idx)) continue;
        // ��� ���� ����: �ش� ���ĺ��� ��� ǥ���ϰ� DFS ����
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
    
    // ���� ��ġ (0,0): ���� ���ĺ� ���´� board[0][0]�� �ش��ϴ� ��Ʈ ����
    int startUsed = 1 << (board[0][0] - 'A');
    dfs(0, 0, 1, startUsed);
    
    cout << ans << "\n";
    
    return 0;
}

