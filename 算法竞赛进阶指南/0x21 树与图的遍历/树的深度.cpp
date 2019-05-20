
void dfs(int x) {
    v[x] = 1;
    for (int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if (v[y]) continue;
        d[y] = d[x] + 1;
        dfs(y);
    }
}
