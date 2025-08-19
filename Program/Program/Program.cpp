#include <iostream>

using namespace std;

int find(int list[], int left, int right)
{
	// left, right, middle은 인덱스 값을 의미한다.

	int middle = (left + right) / 2;

	if (left == right)
	{
		return list[left];
	}

	int leftValue = find(list, left, middle);
	int rightValue = find(list, middle + 1, right);

	if (leftValue > rightValue)
	{
		return leftValue;
	}

	else
	{
		return rightValue;
	}
}

int main()
{
#pragma region 분할 정복
	// 주어진 2개 이상의 부분으로 문제를 나눈 뒤, 각 부분 문제에 대한 답을 재귀로 호출하여 계산한 다음
	// 그 답으로부터 전체 문제의 답을 계산해내는 알고리즘입니다.

	// 분할 (Divide) : 주어진 문제를 두 개 혹은 그 이상의 형식으로 나눕니다.
	
	// 정복 (Conquer) : 나누어진 문제를 재귀적으로 해결해서 나누어진 문제를
	//					더 이상 나누어서 문제가 필요없을 때까지 계속 분할합니다.

	// 통합 (Combine) : 나누어서 해결한 문제들을 통합해서 원래 문제의 해답을 생성합니다.

	int list[] = { 20, 15, 99, 1, 101 };

	int size = sizeof(list) / sizeof(list[0]);

	cout << find(list, 0, size - 1);
#pragma endregion

	return 0;
}