int binarySearch(const vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1; // ���� ������

	while (left <= right) {
		int mid = left + (rigth - left) / 2; // �߾� ��
		cout << mid << " : " << arr[mid] << '\n';
		if (arr[mid] == target) {
			return mid; // Ÿ�� ���� ã���� ��
		}
		else if (arr[mid] < target) {
			left = mid + 1; // Ÿ���� �߰� ������ ũ�Ƿ� ������ �κ� Ž��
		}
		else {
			right = mid - 1; // Ÿ���� �߰� �� ���� �����Ƿ� ���� �κ��� Ž��
		}
	}
	return -1; // ���� ã�� ������ ���
}

int main() {
	vector<int> arr = { 1, 3, 6, 9, 10, 21, 22, 30 };
	int target = 6;
	int ret = binarySearch(arr, target);

	if (result != -1) {
		cout << " Target found at index : " << result << "\n";
	}
	else {
		cout << "Target not found in the array \n";
	}
	return 0;
}