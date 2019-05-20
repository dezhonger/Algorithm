//��ս������� p378 4.7.3 ��׺����
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


const int MAX_N = 100010;
int n, k;
int rak[MAX_N + 1];//rank
int tmp[MAX_N + 1];
int sa[MAX_N + 1];
int lcp[MAX_N + 1];

//�Ƚ� (rank[i], rank[i+k]) �� (rank[j], rank[j+k])
bool compare_sa(int i, int j) {
    if(rak[i] != rak[j]) return rak[i] < rak[j];
    else {
        int ri = i + k <= n ? rak[i + k]  : -1;
        int rj = j + k <= n ? rak[j + k]  : -1;
        return ri < rj;
    }
}

//�����ַ���S�ĺ�׺����
void construct_sa(string S) {
    n = S.length();
    //��ʼ����Ϊ1, rankֱ��ȡ�ַ��ı���
    for(int i = 0; i <= n; i++) {
        sa[i] = i;
        rak[i] = i < n ? S[i] : -1;
    }
    //���öԳ���Ϊk���������Գ���Ϊ2k������
    for(k = 1; k <= n; k <<= 1) {
        sort(sa, sa + n + 1, compare_sa);
        //����tmp����ʱ�洢�¼����rank����ת���rank��
        tmp[sa[0]] = 0;
        for(int i = 1; i <= n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for(int i = 0; i <= n; i++) {
            rak[i] = tmp[i];
        }
    }
}

void construct_lcp(string S) {
    n = S.length();
    for(int i = 0; i < n ; i++) rak[sa[i]] = i;
    int h = 0;
    //lcp[i] = S[sa[i]]��S[sa[i+1]]�������ǰ׺
    lcp[0] = 0;
    for(int i = 0; i < n; i++) {
        //�����ַ����д�λ��i��ʼ�ĺ�׺�����ں�׺�����е�ǰһ����׺��lco
        int j = sa[rak[i] - 1];
        //��h�ȼ�ȥ����ĸ��1���ȣ��ڱ���ǰ׺��ͬ��ǰ���²�������
        if(h > 0) h--;
        for(; j + h < n && i + h < n; h++) {
            if(S[j + h] != S[i + h]) break;
        }
        lcp[rak[i] - 1] = h;
    }
}

string longestDupSubstring(string S) {
    construct_sa(S);
    construct_lcp(S);
    cout << "s.length = " << S.length() << endl;
    int res = -1;
    int pos;
    //for(int i = 0; i <= n; i++) cout << i << ", " << "sa[" << i << "]:" << sa[i] << " " << lcp[i] << " " << S.substr(sa[i]) << endl;
    for(int i = 0; i < n; i++) {
        if(lcp[i] > res) {
            res = lcp[i];
            pos = sa[i];
        }
    }
    cout << S.substr(pos, res);
    return S.substr(pos, res);
}

int main() {
    string s = "abracadabra";
    //string s = "banana";
    longestDupSubstring(s);
    return 0;
}
