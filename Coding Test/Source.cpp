//#include <iostream>
//#include <vector>
//using namespace std;
//
//int binaryCheck(int N)
//{
//	const int MOD = 15746;
//
//	vector<int> dp(N + 1, 0);
//
//	dp[0] = 1;
//	dp[1] = 1;
//
//	if (N >= 2)
//	{
//		dp[2] = 2;
//	}
//
//	for (int i = 3; i <= N; ++i)
//	{
//		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
//	}
//	return dp[N];
//}
//
//int main()
//{
//	int N;
//	cin >> N;
//
//	int result = binaryCheck(N);
//	cout << result << endl;
//
//	return 0;
//}

#include <iostream>

using namespace std;

// 노드 구조체
struct Node
{
	char data;		// 노드에 저장되는 문자
	Node* left;		// 왼쪽 자식 노드 포인터
	Node* right;	// 오른쪽 자식 노드 포인터

	// 생성자 : 값을 받아서 새로운 노드를 생성
	Node(char parent)
	{
		data = parent;
		left = right = nullptr;
	}
};

// 삽입 함수
Node* insert(Node* root, char parent, char left, char right)
{
	// 트리가 비어 있다면 새로운 노드를 생성하여 반환
	if (root == nullptr)
	{
		return new Node(parent);
	}

	// 부모 노드를 찾고 자식 연결
	if (root->data == parent)
	{
		// 왼쪽 자식 연결
		if (left != '.')
		{
			root->left = new Node(left);
		}

		if (right != '.')
		{
			root->right = new Node(right);
		}
	}
	// 위에서부터 부모 노드를 찾을 때까지 왼쪽, 오른쪽 자식 노드를 재귀적으로 탐색
	else
	{
		if (root->left) insert(root->left, parent, left, right);
		if (root->right) insert(root->right, parent, left, right);
	}

	return root;
}

// xx 순회 xxorder traversal

// 전위 순회 Pre
// 루트 -> 왼쪽 -> 오른쪽
void preorder(Node* root)
{
	if (root)
	{
		cout << root->data;		// 현재 노드 출력
		preorder(root->left);	// 왼쪽
		preorder(root->right);	// 오른쪽
	}
}

// 중위 순회 In
// 왼쪽 -> 루트 -> 오른쪽
void inorder(Node* root)
{
	if (root) // 재귀의 기저사례 root == nullptr이면 종료
	{
		// 함수 재호출(재귀(스택) : 쌓였다가 기저 조건 만나면 하나씩 복귀) 
		inorder(root->left);	// 왼쪽
		cout << root->data;		// 현재 노드 출력
		inorder(root->right);	// 오른쪽
	}
}

// 후위 순회 Post
// 왼쪽 -> 오른쪽 -> 루트
void postorder(Node* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data;
	}
}

int main()
{
	Node* root = nullptr; // 루트 노드 초기화

	int N;
	cin >> N;

	char parent, left, right;

	for (int i = 0; i < N; i++)
	{
		cin >> parent >> left >> right;
		if (root == nullptr)
		{
			root = new Node(parent); // 루트 노드 생성
		}
		root = insert(root, parent, left, right);
	}

	// 순회 결과 출력
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);

	return 0;
}