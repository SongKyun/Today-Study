#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 문자열 S
string S;

int main()
{
	// cin >> S; // 공백을 기준으로 한 단어 입력 , cin 은 공백을 만나면 입력이 끝남

	// 문자열 입력
	getline(cin, S); // 공백 포함 입력 받기 getline

	string word; // 뒤집을 단어 저장 string 타입 변수
	string result; // 최종 출력 결과 저장 string 타입 변수
	bool inTag = false;

	for (size_t i = 0; i < S.size(); i++)
	{
		// 태그 시작 만약 < 일 때
		if (S[i] == '<')
		{
			if (!word.empty()) // 워드가 비어있지 않을 때?? : < 전에 현재까지 단어가 쌓여 있다면
			{
				reverse(word.begin(), word.end());	// 단어 뒤집기
				result += word;						// 결과 문자열에 추가
				word.clear();						// 단어 버퍼 초기화
			}

			// 태그 안에 있는지 체크할 bool 변수 필요
			inTag = true;

			// 결과에 추가
			result += S[i];
		}
		// 태그 종료 > 시
		else if (S[i] == '>')
		{
			inTag = false;
			result += S[i];
		}
		// 태그 내부이면 그대로 추가
		else if (inTag)
		{
			result += S[i];
		}
		// 태그 바깥 (단어, 공백 처리)
		else
		{
			// 공백을 만났을 경우
			if (S[i] == ' ')
			{
				reverse(word.begin(), word.end()); // 단어 뒤집기
				result += word + " "; // 공백 추가
				word.clear();
			}
			// 단어에 속하는 문자
			else
			{
				word += S[i];
			}
		}
	}
	// 공백 , < 태그를 만나야 뒤집혀서 결과에 추가됨
	// 하지만 문자열의 끝에서는 공백이나 태그가 없어 자동으로 뒤집어 추가되지 않음
	// 따라서 반복문 종료 후 마지막 문자만 추가 처리 해야함
	if (!word.empty())
	{
		reverse(word.begin(), word.end());
		result += word;
	}

	cout << result << endl;

	return 0;
}