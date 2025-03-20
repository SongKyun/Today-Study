//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	string S;
//	getline(cin, S);
//
//	string word;
//	string result;
//	bool inTag = false;
//
//	for (size_t i = 0; i < S.size(); i++)
//	{
//		if (S[i] == '<')
//		{
//			if (!word.empty())
//			{
//				reverse(word.begin(), word.end());
//				result += word;
//				word.clear();
//			}
//
//			inTag = true;
//			result += S[i];
//		}
//		else if(S[i] == '>')
//		{
//			inTag = false;
//			result += S[i];
//		}
//		else if (inTag)
//		{
//			result += S[i];
//		}
//		else
//		{
//			if (S[i] == ' ')
//			{
//				reverse(word.begin(), word.end());
//				result += word;
//				word.clear();
//			}
//			else
//			{
//				word += S[i];
//			}
//		}
//	}
//
//	if (!word.empty())
//	{
//		reverse(word.begin(), word.end());
//		result += word;
//	}
//
//	cout << result << endl;
//
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;


int binaryCheck(int N)
{
	const int MOD = 15746;

	vector<int> dp(N + 1, 0); // dp 배열 0으로 초기화
	// 왜 N + 1 이지??
	// N = 4 일 경우, dp 배열은 길이가 5인 배열로, 인덱스 0부터 4까지 존재해서

	// 초기값 설정
	dp[0] = 1; // 길이가 0인 수열 1가지 (빈 수열)
	dp[1] = 1; // 길이가 1인 수열 1가지 (1)

	if (N >= 2)
	{
		dp[2] = 2; // 길이가 2인 수열은 2가지 (00, 11)
	}

	// 점화식에 따라 dp 배열을 채워나감
	// 초깃값은 dp[3]을 구하려고 dp[2]와 dp[1]을 사용해야 하므로 3부터 시작함
	for (int i = 3; i <= N; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD; // 이전 두 길이의 경우를 더함 (피보나치)
	}
	
	return dp[N];
}

int main()
{
	int N;
	cin >> N;

	int result = binaryCheck(N);
	cout << result << endl;

	return 0;

}