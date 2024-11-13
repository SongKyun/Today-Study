int binarySearch(const vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1; // 가장 오른쪽

	while (left <= right) {
		int mid = left + (rigth - left) / 2; // 중앙 값
		cout << mid << " : " << arr[mid] << '\n';
		if (arr[mid] == target) {
			return mid; // 타겟 값을 찾았을 때
		}
		else if (arr[mid] < target) {
			left = mid + 1; // 타겟이 중간 값보다 크므로 오른쪽 부분 탐색
		}
		else {
			right = mid - 1; // 타겟이 중간 값 보다 작으므로 왼쪽 부분을 탐색
		}
	}
	return -1; // 값을 찾지 못했을 경우
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