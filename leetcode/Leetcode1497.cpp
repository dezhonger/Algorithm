class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int m[k];
		memset(m, 0, sizeof(m));
		for (int x : arr) {
			if (x > 0) m[x%k]++;
			else {
				int y = -x;
				int h = (y + k - 1) / k;
				x += h * k;
				m[x%k]++;
			
			}
		}
		for (int i = 0; i < k; i++) {
			if (m[i] > 0) {
				m[i]--;
				int n = (k - i) % k;
				if (m[n] > 0) m[n]--;
				else return false;
			}
		}
		return true;
		
    }
};