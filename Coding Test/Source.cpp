#include<iostream>
#include<vector>
using namespace std;

int K;
vector<int> inorder;
vector<vector<int>> levels;

void buildTree(int start, int end, int depth) {
	if (start > end) return;

	int mid = (start + end) / 2;
	levels[depth].push_back(inorder[mid]);

	buildTree(start, mid - 1, depth + 1);
	buildTree(mid + 1, end, depth + 1);
}

int main() {
	cin >> K;
	int numNodes = (1 << K) - 1;
	inorder.resize(numNodes);
	levels.resize(K);

	for (int i = 0; i < numNodes; i++) {
		cin >> inorder[i];
	}

	buildTree(0, numNodes - 1, 0);

	for (int i = 0; i < K; i++) {
		for (int val : levels[i]) {
			cout << val << " ";
		}
		cout << "\n";
	}

	return 0;
}