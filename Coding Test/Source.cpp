#include <iostream>
using namespace std;

int n, m, result = 987654321; // ģ��, ����, �ּ� ������ �ʱⰪ
int arr[300000]; // �� ������ ������ ������ �����ϴ� �迭

// Ư�� ���������� �������� �й��� �� �ִ��� Ȯ���ϴ� �Լ�
bool search(int estimate_val)
{
	int ret = 0; // �ʿ��� ģ�� ��
	for (int i = 0; i < m; i++)
	{
		ret += arr[i] / estimate_val; // ���� ���� �߰���
		if (arr[i] % estimate_val) ret++; // �������� �ִٸ� 1���� �� �ʿ�
	}
	return ret <= n; // n ������ ��� True ��ȯ
}

int main()
{
	cin >> n >> m;

	int left = 1, right = 0, mid;

	for (int i = 0; i < m; ++i)
	{
		cin >> arr[i]; // �� ������ ������ ���� �Է�
		right = max(right, arr[i]);
	}

	// ���� Ž���� ���� �ּ� ������ ���ϱ�
	while (left <= right)
	{
		mid = (left + right) / 2; // �߰���

		if (search(mid)) // mid ������ �й谡 ������ ���
		{
			result = min(result, mid); // �ּ� ������ ����
			right = mid - 1; // �� ���� ������ Ž��
		}
		else
		{
			left = mid + 1; // �� ū ������ Ž��
		}
	}
	cout << result << '\n';
	return 0;
}