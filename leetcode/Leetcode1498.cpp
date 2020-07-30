#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	const int mod = int (1e9) + 7;
	typedef long long LL;
	LL powmod(LL a,LL b) {LL res=1;a%=mod;  for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
		int ans = 0;
		int sz = nums.size();
		int r = sz - 1;
		for (int i = 0; i < sz; i++) {
			while (r >= i && nums[i] + nums[r] > target) r--;
			cout << i << " " << r << endl;
			if (r >= i) ans += powmod(2, (r - i ));
			ans %= 1000000007;
		}
		return ans;
    }
};

int main() {
	Solution sol;
	vector<int> a = {3, 5, 6, 7};
	vector<int> b = {3, 3, 6, 8};
	vector<int> c = {2,3,3,4,6,7};
	cout << sol.numSubseq(a, 9) << endl;
	cout << sol.numSubseq(b, 10)<< endl;
	cout << sol.numSubseq(c, 12)<< endl;
	return 0;
}