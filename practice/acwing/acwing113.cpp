// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
   public:
	vector<int> specialSort(int N) {
		vector<int> out;
		out.push_back(1);
		for (int i = 2; i <= N; i++) {
			int l = 0, r = out.size();
			while (l < r) {
				int mid = (l + r) >> 1;
				if (compare(out[mid], i)) {
					l = mid + 1;
				} else {
					r = mid;
				}
			}
			out.insert(out.begin() + l, i);
		}
		return out;
	}
};