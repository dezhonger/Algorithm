

void dfs(int x) {
    a[++m] = x; //a����洢DFS��
    v[x] = 1;
    for(int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if(v[y]) continue;
        dfs(y);
    }
    a[++m] = x;
}
