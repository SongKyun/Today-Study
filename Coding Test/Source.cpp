//#include <iostream>
//
//using namespace std;
//
//struct Node
//{
//	char data;
//	Node* left;
//	Node* right;
//
//	Node(char parent)
//	{
//		data = parent;
//		left = right = nullptr;
//	}
//};
//
//void insert(Node*& root, char parent, char left, char right) {
//	if (root == nullptr) root = new Node(parent);
//
//	if (root->data == parent) {
//		if (left != '.') root->left = new Node(left);
//		if (right != '.') root->right = new Node(right);
//	}
//	else {
//		if (root->left) insert(root->left, parent, left, right);
//		if (root->right) insert(root->right, parent, left, right);
//	}
//}
//
//void preorder(Node* root)
//{
//	if (root)
//	{
//		cout << root->data;
//		preorder(root->left);
//		preorder(root->right);
//	}
//}
//
//void inorder(Node* root)
//{
//	if (root)
//	{
//		inorder(root->left);
//		cout << root->data;
//		inorder(root->right);
//	}
//}
//
//void postorder(Node* root)
//{
//	if (root)
//	{
//		postorder(root->left);
//		postorder(root->right);
//		cout << root->data;
//	}
//}
//
//int main()
//{
//	Node* root = nullptr;
//
//	int N;
//	cin >> N;
//
//	char parent, left, right;
//
//	for (int i = 0; i < N; i++) {
//		cin >> parent >> left >> right;
//		insert(root, parent, left, right);
//	}
//
//	preorder(root);
//	cout << endl;
//	inorder(root);
//	cout << endl;
//	postorder(root);
//
//	return 0;
//}

// 트리의 부모 찾기

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> tree[100001]; // 트리(인접 리스트)
int parent[100001]; // 부모 노드 저장 배열

// BFS
void bfs(int root) {
	queue<int> q;
	q.push(root);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : tree[cur]) {
			if (parent[next] == 0) { // next에 없다면(방문 안 한 노드라면)
				parent[next] = cur; // 부모 설정
				q.push(next);
			}
		}
	}
}

// DFS
void dfs(int cur) {
	for (int next : tree[cur]) {
		if (parent[next] == 0) {
			parent[next] = cur;
			dfs(next);
		}
	}
}

int main()
{
	cin >> N;

	// 입력 받은 a, b 값을 트리에 넣는다
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a); // 양방향 연결
	}

	parent[1] = -1; // 루트 노드(1)의 부모는 없음
	bfs(1); // BFS 탐색 시작

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}