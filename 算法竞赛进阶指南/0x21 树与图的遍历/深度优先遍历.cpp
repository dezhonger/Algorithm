

//��������Ĵ��룬����dfs(1)�����һ��ͼ��������ȱ���


void dfs(int x) {
    v[x] = 1; //��¼��x�����ʹ���v��visit����д
    for (int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if (v[y]) continue; //��y�Ѿ������ʹ���
        dfs(y);
    }

}
