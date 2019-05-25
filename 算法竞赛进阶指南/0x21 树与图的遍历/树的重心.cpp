

void dfs(int x) {
    v[x] = 1;
    size[x] = 1; //子树x的大小
    int max_part = 0; //删掉x后分成的最大子树的大小
    for(int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if (v[y]) continue; //点y已经被访问过了
        dfs(y);
        size[x] += size[y]; //从子节点向父节点递推
        max_part = max(max_part, size[y]);
    }
    max_part = max(max_part, n - size[x]); //n为整棵树的节点数目
    if (max_part < ans) {
        ans = max_part; //全局变量ans记录重心对应的max_part值
        pos = x; //全局变量pos记录了重心
    }
}
