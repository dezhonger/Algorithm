

void dfs(int x) {
    a[++m] = x; //aÊý×é´æ´¢DFSÐò
    v[x] = 1;
    for(int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if(v[y]) continue;
        dfs(y);
    }
    a[++m] = x;
}
