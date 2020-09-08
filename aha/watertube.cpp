#include<iostream>
#include<algorithm>
using namespace std;

int a[51][51];
int book[51][51];
int n, m, flag = 0;
struct note {
    int x;
    int y;
}s[100];
int top = 0;

void dfs(int x, int y, int front) {
    if(x == n && y == m + 1) {
        flag = 1;
        for(int i = 1; i <= top; ++i) 
            cout << "(" << s[i].x << "," << s[i].y << ")" << " "; 
        return ;
    }
    if(x < 1 || x > n || y < 1 || y > m) return ;
    if(book[x][y] == 1)  return ;
    book[x][y] = 1;

    top++;
    s[top].x = x;
    s[top].y = y;

    // 当前是直管
    if(a[x][y] >= 5 && a[x][y] <= 6) {
        if(front == 1) dfs(x, y + 1, 1);
        if(front == 2) dfs(x + 1, y, 2);
        if(front == 3) dfs(x, y - 1, 3);
        if(front == 4) dfs(x - 1, y, 4);
    } 
    // 当前是弯管
    if(a[x][y] >= 1 && a[x][y] <= 4) {
        if(front == 1) {
            dfs(x + 1, y, 2);
            dfs(x - 1, y, 4);
        }
        if(front == 2) {
            dfs(x, y + 1, 1);
            dfs(x, y - 1, 3);
        }
        if(front == 3) {
            dfs(x - 1, y, 4);
            dfs(x + 1, y, 2);
        }
        if(front == 4) {
            dfs(x, y + 1, 1);
            dfs(x, y - 1, 3);
        }
    }

    book[x][y] = 0;
    top--;
    return ;
}

int main() {
    int num = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    dfs(1, 1, 1);
    if(flag == 0) cout << "impossible" << endl;
    //else cout << "find solution" << endl;
    return 0;
}