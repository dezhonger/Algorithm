

void dfs(int x) {
    v[x] = 1;
    size[x] = 1; //����x�Ĵ�С
    int max_part = 0; //ɾ��x��ֳɵ���������Ĵ�С
    for(int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if (v[y]) continue; //��y�Ѿ������ʹ���
        dfs(y);
        size[x] += size[y]; //���ӽڵ��򸸽ڵ����
        max_part = max(max_part, size[y]);
    }
    max_part = max(max_part, n - size[x]); //nΪ�������Ľڵ���Ŀ
    if (max_part < ans) {
        ans = max_part; //ȫ�ֱ���ans��¼���Ķ�Ӧ��max_partֵ
        pos = x; //ȫ�ֱ���pos��¼������
    }
}
