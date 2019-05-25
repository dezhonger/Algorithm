


void dfs(int x) {
    v[x] = cnt;
    for(int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if(v[y]) continue;
        dfs(y);
    }
}

int main() {
    for(int i = 1; i <= n; i++) {
        if(!v[i]) {
            cnt++;
            dfs(i);
        }
    }
}


