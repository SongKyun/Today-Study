#include <iostream>
using namespace std;

int n, m, result = 987654321; // 친구, 색상, 최소 질투심 초기값
int arr[300000]; // 각 색상의 형광펜 개수를 저장하는 배열

// 특정 질투심으로 형광펜을 분배할 수 있는지 확인하는 함수
bool search(int estimate_val)
{
	int ret = 0; // 필요한 친구 수
	for (int i = 0; i < m; i++)
	{
		ret += arr[i] / estimate_val; // 나눈 몫을 추가함
		if (arr[i] % estimate_val) ret++; // 나머지가 있다면 1명이 더 필요
	}
	return ret <= n; // n 이하인 경우 True 반환
}

int main()
{
	cin >> n >> m;

	int left = 1, right = 0, mid;

	for (int i = 0; i < m; ++i)
	{
		cin >> arr[i]; // 각 색상의 형광펜 개수 입력
		right = max(right, arr[i]);
	}

	// 이진 탐색을 통해 최소 질투심 구하기
	while (left <= right)
	{
		mid = (left + right) / 2; // 중간값

		if (search(mid)) // mid 값으로 분배가 가능한 경우
		{
			result = min(result, mid); // 최소 질투심 갱신
			right = mid - 1; // 더 작은 질투심 탐색
		}
		else
		{
			left = mid + 1; // 더 큰 질투심 탐색
		}
	}
	cout << result << '\n';
	return 0;
}