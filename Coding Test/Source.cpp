#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
	sort(numlist.begin(), numlist.end(), [n](int a, int b) {
		int distA = abs(a - n);
		int distB = abs(b - n);
		if (distA == distB) {
			return a > b;
		}
		return distA < distB;
		});
	return numlist;
}

int num;

bool compare(int prev, int next) {
	if (abs(prev - num) == abs(next - num))
		return prev > next;
	return abs(prev - num) < abs(next - num);
}

vector<int> solution(vector<int> numlist, int n) {
	num = n;
	sort(numlist.begin(), numlist.end(), compare);
	return numlist;
}