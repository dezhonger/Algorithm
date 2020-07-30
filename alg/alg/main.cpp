#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
using namespace std;

string makeLargestSpecial (string S) {
    int count = 0, i = 0;
    vector<string> res;
    for (int j = 0; j < S.size(); ++j) {
        if (S[j] == '1') count++;
        else count--;
        if (count == 0) {
            res.push_back ('1' + makeLargestSpecial (S.substr (i + 1, j - i - 1)) + '0');
            i = j + 1;
        }
    }
    sort (res.begin(), res.end(), greater<string>());
    string res2 = "";
    for (int i = 0; i < res.size(); ++i) res2 += res[i];
    return res2;
}

int main() {
    cout << makeLargestSpecial ("11011000") << endl;
}
