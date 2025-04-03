//#include<iostream>
//#include<vector>
//using namespace std;
//
//int K;						// 트리 깊이
//vector<int> inorder;		// 중위 순회 결과 저장 벡터
//vector<vector<int>> levels;	// 각 레벨의 노드 저장
//
//// 트리 복원 함수
//void buildTree(int start, int end, int depth) {
//	// 기저 사례 범위 제한
//	if (start > end) return;
//	// 중간값 = 루트
//	int mid = (start + end) / 2;
//	// 해당 레벨 깊이에 노드 추가
//	levels[depth].push_back(inorder[mid]);
//
//	// 왼쪽 서브트리 재귀
//	buildTree(start, mid - 1, depth + 1);
//	// 오른쪽 서브트리 재귀
//	buildTree(mid + 1, end, depth + 1);
//}
//
//int main() {
//	// K 입력
//	cin >> K;
//	// 총 노드 크기
//	int numNodes = (1 << K) - 1; // 2^K - 1 개의 노드 (총 노드)
//	// 중위 순회에 총 노드 크기 적용
//	inorder.resize(numNodes);
//	// 각 레벨 노드 K 크기 적용
//	levels.resize(K);
//
//	// 중위 순회 결과 입력
//	for (int i = 0; i < numNodes; i++) {
//		cin >> inorder[i];
//	}
//
//	// 트리 구축
//	buildTree(0, numNodes - 1, 0);
//
//	// 출력
//	for (int i = 0; i < K; i++) {
//		for (int val : levels[i]) {
//			cout << val << " ";
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n, r, parent, root;			// 노드 개수, 삭제 노드, 부모 정보, 루트 표시
//vector<int> tree[54];	// 트리 표현 인접 리스트
//
//int dfs(int here) {
//	int leaf = 0;	// 리프 노드 개수 변수
//	int child = 0;	// 자식 노드 개수 변수
//
//	for (int there : tree[here]) {	// 현재 노드 here 순회
//		if (there == r) continue;	// 만약 순회 중인 노드가 삭제 노드면 패스
//		leaf += dfs(there);			// 자식 노드가 있다면, 해당 자식에 리프 노드 개수를 더함
//		child++;					// 자식 노드 기록
//	}
//
//	if(child == 0) return 1;		// 자식이 없으면 리프노드로 1 반환
//	return leaf;					// 자식 있으면 리프 노드 개수를 반환
//}
//
//int main() {
//	
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		cin >> parent;
//
//		if (parent == -1) root = i;		// -1인 경우 루트 노드
//		else tree[parent].push_back(i);	// 루트가 아니면 그 부모의 자식 리스트에 추가
//	}
//
//	cin >> r;
//
//	if (r == root) {		// 삭제 노드가 루트 노드라면
//		cout << 0 << "\n";	// 모든 트리 삭제되므로 리프 노드 0개
//		return 0;			// 프로그램 종료
//	}
//
//	cout << dfs(root) << "\n";	// 루트 노드부터 DFS 탐색 시작, 리프 노드 개수 출력
//
//	return 0;
//}

//return (childCount == 0) ? 1 : leafCount; // 자식이 없으면 리프 노드

###  * *참조자(Reference)와 포인터(Pointer)의 차이점 * *

🔹** 면접 질문 예시**

👉** 참조자(Reference)란 무엇이며, 어떤 특징이 있나요 ? **

💡 참조자는 기존 변수의 별칭(Alias)으로, 해당 변수와 같은 메모리 주소를 공유합니다.

- 선언과 동시에 초기화해야 하며, `NULL` 또는 `nullptr`로 설정할 수 없습니다.
- Modern C++ 초기화 리스트와는 다름 생성자의 초기화 리스트를 의미함
- 생성자 내부에서 null로 초기화를 하고 난 뒤 값을 넣는 방식이기 때문에 한 번 초기화되면 다른 변수에 재할당할 수 없습니다.

👉 * *포인터(Pointer)와 참조자의 차이점은 무엇인가요 ? **

💡 포인터는 변수의 주소를 저장할 수 있는 변수이며, 동적 메모리 할당에도 사용됩니다.

- 포인터는 `NULL`이 가능하고, 할당 및 재할당이 자유롭습니다.
- 참조자는 한 번 초기화되면 바꿀 수 없지만, 포인터는 다른 변수를 가리킬 수 있습니다.

👉** 포인터를 사용할 때 발생할 수 있는 문제는 무엇인가요 ? **

💡 * *댕글링 포인터(Dangling Pointer) * *문제가 발생할 수 있습니다.

- 포인터 변수를 delete나 free로 해제 시 메모리 할당 해제가 되어도 변수가 가리키는 주소 값이 사라지는 것이 아니기 때문에, 그 포인터 변수를 다시 참조하려고 하면 미정의 동작을 수행한다.
- 이를 방지하기 위해 해제 후 포인터를 `nullptr`로 설정하는 것이 일반적인 해결 방법입니다.
- 사용할 때 마다 nullptr인지 체크하는 테크닉이 있으면 더 좋다.
- 비주얼 스튜디오의 경우, 메모리 해제 시 임의의 메모리로 치환하여 강제 크래시를 유발함(의도적인 크래시가 미정의 동작보다 차라리 안전해서)

[](https://lh7-us.googleusercontent.com/ypL9S5WHXjJgGSdto3HMPPFYu6oul_mYb5HEPkKhbIGzUdwukj6CX2ILMmsGx_3CnCN3V-JBdVIlBceADXb4oBVi4cWUb4VY4GaQfP60sSbBSePH6rHARF3HsdULhEGv-zYv5-w0rc7aGFahGwPIcw)

-단, 아무리 할당 해제 후 nullptr로 치환하였다고 해도, 그것을 참조하는 포인터 변수가 있었다면 이는 추적하기 힘든 메모리 누수 / 버그를 발생시킬 수 있다.→ 스마트 포인터로 어느정도 해소 가능

-- -

###  * *동적 메모리 할당(Malloc vs New의 차이점) * *

🔹 * *면접 질문 예시 * *

👉 * *`malloc`과 `new`의 차이점은 무엇인가요 ? **

💡 `malloc`과 `new`는 모두 동적 메모리 할당을 위한 기능이지만, 차이점이 있습니다.

| 구분 | `malloc` | `new` |
| -- - | -- - | -- - |
| 언어 | C 스타일 | C++ 스타일 |
| 기능 | 단순한 메모리 할당 | 할당과 동시에 객체 초기화 |
| 반환 타입 | `void*` (캐스팅 필요) | 객체 타입 그대로 반환 |
| 생성자 호출 | ❌ | ✅ |
| 연산자 오버로딩 | ❌ | ✅ |

👉 * *C++에서 `malloc`보다 `new`를 사용하는 것이 더 적합한 이유는 ? **

💡 `new`는 객체를 생성할 때 * *생성자(Constructor) * *를 호출하므로, 객체 초기화가 가능합니다.

- `malloc`은 단순한 메모리 할당만 수행하기 때문에, 생성자가 필요한 C++ 객체에는 적합하지 않습니다.

-- -

###  * *스마트 포인터(Smart Pointer) * *

-C#이나 Java처럼 Garbage Collector를 사용하는 것은 아니고 레퍼런스 카운트를 통하여 제거 시점을 결정한다
- <memory> 헤더 안에 정의되어 있다.

🔹 * *면접 질문 예시 * *

👉 * *스마트 포인터란 무엇이며, 원시 포인터(Raw Pointer)와의 차이점은 무엇인가요 ? **

💡 스마트 포인터는 * *C++11 * *에서 도입된 자동 메모리 관리 기능을 가진 포인터입니다.

- 스마트 포인터는 자유 공간(new / delete로 할당한 공간, malloc / free로 할당한 공간은 힙 공간)에 할당한 메모리 주소만 저장할 수 있다.
- 원시 포인터에서 하던 증가, 감소 같은 산술 연산은 스마트 포인터에서 할 수 없다.
- 원시 포인터(`new`/`delete`)는 프로그래머가 직접 메모리를 해제해야 하지만,

    스마트 포인터는 * *자동으로 메모리를 관리 * *하여 메모리 누수를 방지합니다.


    -- -

    -unique_ptr<T>

    ### unique_ptr<T>

    -unique_ptr<T>는 타입 T에 대한 포인터처럼 사용되며, 언제나 유일해야 한다.즉 둘 이상의 unique_ptr이 같은 주소를 가질 수 없으며, **unique_ptr은 복사될 수 없다 * *. (유일성을 손상시켜서는 안 된다)
    - unique_ptr을 옮기려면 오직 소유권을 * *이동 * *시키는 행위만이 허용된다.
    - utility헤더에 정의된 std::move()를 사용하면 unique_ptr객체에 저장된 주소를 다른 unique_ptr객체로 이동시킬 수 있으며, 소유권을 이전하면 기존의 unique_ptr 객체는 * *무효화(Invalidate) * *된다.
    - 그러므로, **객체에 대한 단일 소유권만 허용하고 싶을 때 * *는(반드시 하나만 가지고 사용하고 싶을 때는) unique_ptr<T>를 이용하는 것이 좋다.

    * *unique_ptr의 사용방법 * *

    ```cpp
    std::unique_ptr<type> name{ new type() };

ex)

std::unique_ptr<std::string> pname{ new std::string {"Algernon"} };

auto pname = std::make_unique<std::string>("Algernon");

auto pstr = std::make_unique<std::string>(6, '*');
```

- 스마트 포인터는 원시 포인터와 마찬가지로 역참조를 통해 객체에 접근할 수 있다.

```cpp
std::cout < *pname << std::endl;
```

- 임의의 크기로 스마트 포인터 배열을 생성할 수도 있다.

```cpp
int len = 10;

std::unique_ptr<int[]> pnumbers{ new int[len }};

std::unique_ptr<int[]> pnumbers = std::make_unique<int[]>(len);
```

- unique_ptr 객체는 복제가 불가능 하므로, 함수에 값으로 전달할 수 없다.만약 unique_ptr객체를 함수의 인수로 쓰고 싶다면 인수를 ** 참조 매개변수** 로 받아야 한다.
- unique - ptr 객체는 복제될 수 없지만 암묵적 이동 연산(implicit move operation)에 의해 반환이 가능하므로 함수에서 반환될 수 있다.
- **reset() * *->스마트 포인터가 가리키는 원본 객체를 소멸, unique_ptr은 해제된다.
- ptr.reset(new std::string{ "Fred" })와 가이, reset의 인자에 새 객체를 넣으면 스마트포인터와 새 객체를 연결해준다.
- **release() * *->스마트 포인터가 가리키는 원본 객체의 소유권을 해제하고, 원본 객체를 리턴
- unique_ptr 객체끼리 비교하고 싶을 때는 두 객체의 get()을 호출하여 반환된 주소값을 비교한다.

-- -

-shared_ptr<T>

### shared_ptr<T>

-shared_ptr<T>객체는 타입 T에 대한 포인터처럼 행동한다.
- unique_ptr과는 반대로 shared_ptr<T>는 객체를 여러 shared_ptr<T>와 공유할 수 있다.shared_ptr<T>는 레퍼런스 카운팅 방식을 사용하여 메모리를 관리하는데 새로운 shared_ptr<T>객체가 주소를 공유받을 때 마다 레퍼런스 카운트가 증가하며, 공유를 받았던 shared_ptr 객체가 소멸되거나, 다른 주소를 할당받거나, nullptr을 할당받으면 해당 객체의 레퍼런스 카운트가 감소한다.만약 레퍼런스 카운터가 0이 되면(해당 주소를 가리키는 shared_ptr<T>객체가 없으면) 해당 주소를 위한 힙 메모리가 자동으로 해제된다.
- 새로운 shared_ptr을 정의하면 두 가지 할당을 받게 된다.
- **첫 번째는 * *shared_ptr이 가리키는 원본 객체를 위한 힙 메모리를 할당하게 된다.
- **두 번째는 * *스마트 포인터의 레퍼런스 카운트를 위한 컨트롤 블록을 위해 스마트 포인터 객체와 관련된 힙 메모리를 할당받게 된다.

* *shared_ptr의 사용방법 * *

1. 일반적인 할당 방법

```cpp
* *std::shared_ptr<double> pdata{ new double(999.0) }; **
```

1. 일반적인 할당보다 효율적으로 동작(추천)

```cpp
* *std::shared_ptr<double> pdata = std::make_shared<double>(999.0); **
```

1. 다른 shared_ptr로 초기화하는 스마트 포인터 : 레퍼런스 카운트가 증가함

```cpp
* *std::shared_ptr<double> pdata2{ pdata }; **
```

1. 스마트 포인터의 원시 포인터 객체를 반환한다.
- 반드시 사용해야 할 경우가 있을 때만 사용하며, get()을 통해 반환한 원시 포인터를 이용해서 shared_ptr<T>를 생성하는 올바르지 않고 위험을 초래할 수 있다.

```cpp
** double* pvalue = pdata.get() * *
```

1. reset()을 인수없이 호출하면 레퍼런스 카운트가 1 감소하며, 해당 shared_ptr 객체가 아무것도 가리키지 않게 된다.(unique_ptr의 동작과는 좀 다르다, 물론 레퍼런스 카운트가 1이라면, 해당 shared_ptr객체를 reset하는 순간 스마트 포인터가 해제된다)

```cpp
** pname.reset(new std::String{ "Jane Austen" }); **
```

1. reset()의 인수로 원시 포인터를 전달하면 shared_ptr이 가리키는 주소를 바꿀 수 있다.
2. shared_ptr끼리의 비교는 == 연산자를 사용해 비교할 수 있다.단 두 객체가 모두 nullptr일 수 있으므로, 같은 객체를 가리키는지만 체크하면 된다.
3. 스마트 포인터는 암묵적으로 bool로 변형될 수 있으므로(객체 존재 true, nullptr false)

if ((pA  == pB  && (pA  != nullptr)) 혹은 if((pA  == pB  && pA))로 비교할 수 있다.

    4. pname.use_count() -> * *use_count() * *는 해당 shared_ptr이 가리키는 객체의 레퍼런스 카운트를 반환한다.
    5. shared_ptr이 nullptr을 가리키고 있다면 0을 반환한다.
    6. * *.unique() * *함수는 shared_ptr이 유일한지(true), 복제본이 있는지(false) 확인할 수 있다.

    -- -

    -weak_ptr<T>

    ### weak_ptr<T>

    -weak_ptr는 shared_ptr의  * *상호참조 문제 * *를 해결할 수 있다.
    - weak_ptr은 shared_ptr객체에서 생성하여 연결하며, 같은 주소를 가리킨다.
    - 단 weak_ptr은 연결된 shared_ptr객체의 레퍼런스 카운트를 증가시키지 않으므로, 객체의 소멸에 관여하지 않는다.
    - shared_ptr의 메모리가 레퍼런스 카운트가 0이되어 해제되더라도 연관된 weak_ptr 객체는 남아있게 된다.

    -- -

    👉 * *스마트 포인터의 종류와 차이점은 ? **

    💡 C++에는 * *`unique_ptr`, `shared_ptr`, `weak_ptr`* * 세 가지 주요 스마트 포인터가 있습니다.

    | 스마트 포인터 | 특징 |
    | -- - | -- - |
    | `unique_ptr` | **단독 소유 * *.하나의 객체에 하나의 `unique_ptr`만 존재 가능 |
    | `shared_ptr` | **참조 카운트 기반 공유 * *.여러 개의 `shared_ptr`가 동일한 객체를 가리킬 수 있음 |
    | `weak_ptr` | **순환 참조 방지 * *. `shared_ptr`가 가리키는 객체를 참조하지만, 참조 카운트 증가 X |

    👉 * *`unique_ptr`과 `shared_ptr`의 차이점은 ? **

    💡 `unique_ptr`은 * *소유권을 단독으로 유지 * *하므로, 복사할 수 없고 이동(`std::move()`)만 가능합니다.

        - `shared_ptr`은 * *참조 카운트를 사용하여 메모리를 공유 * *하므로, 여러 개가 동일한 객체를 가리킬 수 있습니다.

        👉 * *`weak_ptr`은 언제 사용하나요 ? **

        💡 `shared_ptr`을 사용할 때 * *순환 참조(Circular Reference) * *가 발생하면, 메모리가 해제되지 않는 문제가 생길 수 있습니다.

        - 이를 방지하기 위해 `weak_ptr`을 사용하면, 참조 카운트를 증가시키지 않으면서 객체를 참조할 수 있습니다.

        -- -

        ###  * *초기화 리스트(Initialization List)와 생성자 내부 초기화의 차이점 * *

        🔹 * *면접 질문 예시 * *

        👉 * *초기화 리스트란 무엇이며, 생성자 내부에서 초기화하는 것과의 차이점은 무엇인가요 ? **

        💡 * *초기화 리스트(Initialization List) * *는 C++에서 * *생성자의 매개변수를 이용하여 멤버 변수를 초기화하는 방법 * *입니다.

        - `Modern C++`에서 사용하는 `{}` 초기화 방식과는 다르며, ** 생성자의 초기화 리스트** 를 의미합니다.
        - 생성자 내부에서 대입 연산을 사용하는 방식보다 * *효율적 * *입니다.

        👉 * *초기화 리스트를 반드시 사용해야 하는 경우는 ? **

        💡 다음과 같은 경우에는 * *초기화 리스트를 반드시 사용해야 합니다.* *

        1. * *상수(Constant) 멤버 변수 * *
        -`const` 변수는 선언과 동시에 초기화해야 하므로, 생성자 내부에서 대입할 수 없습니다.
        2. * *참조자(Reference) 멤버 변수 * *
        -참조자는 생성 후 다른 변수를 가리킬 수 없으므로, 초기화 리스트에서 설정해야 합니다.
        3. * *클래스 포함(Has - a 관계) 멤버 변수 * *
        -다른 클래스의 객체를 멤버 변수로 포함하는 경우, 초기화 리스트를 사용해야 해당 클래스의 생성자가 정상적으로 호출됩니다.


        👉** 초기화 리스트를 사용하지 않고 생성자 내부에서 초기화하면 어떤 문제가 생기나요 ? **

        💡 초기화 리스트를 사용하지 않고 생성자 내부에서 멤버 변수를 초기화하면,

        -**초기값 없이 먼저 객체가 생성된 후, 다시 값을 대입하는 과정이 추가** 됩니다.
        - 불필요한 연산이 발생하여 * *성능이 저하될 수 있습니다.* *

        📌 * *예제 코드 * *

        ```cpp
        class Example {
    const int x;
    int& ref;
        public:
            // 초기화 리스트 사용 (권장)
            Example(int value) : x(value), ref(value) {}

            // 생성자 내부에서 초기화 (오류 발생)
            Example(int value) {
                x = value;  // ❌ const 변수는 대입 불가능 (컴파일 오류)
                ref = value;  // ❌ 참조자는 생성 후 변경 불가능 (컴파일 오류)
            }
};
```

-- -

###  * *레퍼런스 카운트(Reference Count)란 ? **

🔹 * *면접 질문 예시 * *

👉 * *레퍼런스 카운트(Reference Count)란 무엇인가요 ? **

💡 * *레퍼런스 카운트 * *는 객체가 몇 개의 포인터에 의해 참조되고 있는지를 추적하는 기법입니다.

- `shared_ptr`과 같은 스마트 포인터에서 * *객체가 몇 개의 `shared_ptr`에 의해 공유되고 있는지 * *관리하는 방식입니다.
- 레퍼런스 카운트가 `0`이 되면, 해당 객체는 자동으로 메모리에서 해제됩니다.

👉** 레퍼런스 카운트가 증가하고 감소하는 경우는 ? **

💡 * *레퍼런스 카운트 증가 * *

-새로운 `shared_ptr`이 같은 객체를 가리킬 때

💡 * *레퍼런스 카운트 감소 * *

-`shared_ptr`이 소멸되거나, 새로운 객체를 가리키거나, `reset()`을 호출할 때

📌** 예제 코드**

```cpp
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sp1 = std::make_shared<int>(10);
    std::shared_ptr<int> sp2 = sp1; // sp2도 같은 객체를 참조
    std::cout << "Reference Count: " << sp1.use_count() << std::endl; // 2

    sp2.reset();  // sp2가 해제되면서 레퍼런스 카운트 감소
    std::cout << "Reference Count: " << sp1.use_count() << std::endl; // 1
}
```

-- -

###  * *자유 공간(Free Space) vs 힙(Heap) vs 스택(Stack) * *

🔹 * *면접 질문 예시 * *

👉 * *자유 공간(Free Space)과 힙(Heap), 스택(Stack)의 차이점은 무엇인가요 ? **

💡 * *자유 공간(Free Space) * *은 동적으로 할당된 메모리가 저장되는 영역을 의미합니다.

- 대부분의 경우 * *힙(Heap) 영역 * *을 의미하지만, 일부 구현에서는 다르게 관리될 수도 있습니다.

💡** 힙(Heap)과 스택(Stack)의 차이점**

| 구분 | 힙(Heap) | 스택(Stack) |
| -- - | -- - | -- - |
| 할당 방식 | `new`, `malloc` | 지역 변수 및 함수 호출 시 자동 할당 |
| 해제 방식 | `delete`, `free` (명시적 해제 필요) | 함수 종료 시 자동 해제 |
| 속도 | 상대적으로 느림 | 빠름 |
| 크기 제한 | OS 및 가용 메모리에 따라 결정 | 일반적으로 작음(수 MB) |
| 데이터 유지 | 명시적으로 해제할 때까지 유지 | 함수가 끝나면 자동 해제 |

👉 * *힙(Heap) 메모리는 언제 사용해야 하나요 ? **

💡 * *크기가 큰 데이터 * *또는 * *수명이 긴 객체 * *를 사용할 때 힙을 사용해야 합니다.

- 예를 들어, 프로그램이 실행되는 동안 유지해야 하는** 게임 객체, 대형 배열, 동적 구조체** 등에 적합합니다.

-- -

###  * *Getter & Setter란 ? **

🔹 * *면접 질문 예시 * *

👉 * *Getter와 Setter란 무엇이며, 왜 사용하는가 ? **

💡 * *Getter(접근자) * *와 * *Setter(설정자) * *는 객체의 * *캡슐화(Encapsulation) * *를 유지하면서

멤버 변수에 접근하거나 변경할 수 있도록 도와주는 메서드입니다.

👉 * *직접 변수를 public으로 선언하면 안 되는 이유는 ? **

💡 직접 변수에 접근할 경우, 데이터 보호가 어렵고 불필요한 변경이 발생할 수 있습니다.

- Getter와 Setter를 사용하면 * *값을 검증하거나, 변경 시 추가적인 로직을 수행** 할 수 있습니다.

📌** 예제 코드**

```cpp
class Person {
private:
    int age;
public:
    // Getter (변수 값을 반환)
    int getAge() {
        return age;
    }

    // Setter (값을 변경하면서 검증 로직 추가 가능)
    void setAge(int a) {
        if (a >= 0) age = a;  // 나이는 음수가 될 수 없음
    }
};
```

👉** Getter와 Setter를 사용하면 어떤 장점이 있나요 ? **

💡 * *장점 * *

1. * *캡슐화 유지 * *: 객체의 내부 구현을 숨기고, 변경이 필요할 때 유연하게 대처 가능
2. * *데이터 보호 * *: 값이 올바른지 검증 가능(예 : 나이는 음수가 될 수 없음)
3. * *유지보수성 향상 * *: 내부 구현이 변경되더라도 인터페이스를 유지할 수 있음