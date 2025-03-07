#include <>
using namespace std;

int dp[104][2][34], n, m, b[104];

int go(int idx, int tree, int cnt)
{
	if (cnt < 0) return -1e9;
	if (idx == n) return 0;
	int& ret = dp[idx][tree][cnt];
	if (ret != -1) return ret;

	return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
}

main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> b[i];

	cout << max(go(0, 1, m - 1), go(0, 0, m)) << '\n';
	return 0;
}

#include <>
using namespace std;
typedef long long ll;
ll t, n, dp[10001];

int main()
{
	cin >> t;
	dp[0] = 1; // 아무 숫자도 선택하지 않는 경우
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 10000; j++)
		{
			if (j - i >= 0) dp[j] += dp[j - i];
			// j를 만드는 방법의 수에 j-i를 만드는 방법의 수를 더해서
			// i를 사용해서 j를 만들 수 있는 경우의 수를 누적하는 방식
		}
	}
	while (t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
}

