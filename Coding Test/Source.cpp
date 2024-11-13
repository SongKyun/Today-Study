#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m, temp;

string check(int temp, vector<int> &v) {
	int l = 0;
	int r = v.size() - 1;
	int mid;
	while (l <= r) {
		mid = l + (r - 1) / 2;
		if (v[mid] > temp) r = mid - 1;
		else if (v[mid] == temp) return "큰돌이는 기억해!";
		else l = mid + 1;
	}
	return "큰돌이는 까먹었어!";
}

int main() {
	cin >> t;
	while (t--) {
		vector<int> v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> temp;
			cout << check(temp, v) << "\n";
		}
	}
	return 0;
}