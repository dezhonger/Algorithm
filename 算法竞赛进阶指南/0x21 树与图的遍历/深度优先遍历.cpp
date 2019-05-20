

//采用下面的代码，调用dfs(1)，完成一张图的深度优先遍历


void dfs(int x) {
    v[x] = 1; //记录点x被访问过，v是visit的缩写
    for (int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if (v[y]) continue; //点y已经被访问过了
        dfs(y);
    }

}
