#include <iostream>

using namespace std;

int fibonacci(int n)
{
	if (n <= 0)
	{
		// cout << "n이 0보다 작습니다." << endl;
		return 0;
	}
	else if (n <= 2)
	{
		return 1;
	}

	return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci(int n, int list[])
{
	if (n <= 0)
	{
		return 0;
	}
	else if (n <= 2)
	{
		return 1;
	}

	if (list[n] != 0)
	{
		return list[n];
	}

	return list[n] = fibonacci(n - 1, list) + fibonacci(n - 2, list);
}

int main()
{
#pragma region 동적 계획법
	// 하나의 큰 문제를 여러 개의 작은 문제로 나누어서
	// 그 결과를 저장하여 다시 큰 문제를 해결할 때 사용하는 알고리즘입니다.

	// 겹치는 부분 문제 (Overlapping Subproblems)
	// 동일한 작은 문제들이 반복하여 나타나는 경우를 의미합니다.

	// 최적 부분 구조 (Optimal Substructure)
	// 부분 문제의 최적 결과 값을 사용하여, 전체 문제의 최적의 결과를 낼 수 있는 경우를 의미합니다.

	// 메모이제이션 (Memoization)
	// 프로그램이 동일한 계산을 반복해야할 때, 이전에 계산한 값을 메모리에 저장함으로써
	// 동일한 계산을 반복 수행하는 작업을 제거하여 프로그램의 실행 속도를 향상시키는 방법입니다.

	int n = 45;

	int * list = new int[n + 1] {0};	// 배열을 0으로 초기화

	// 메모이제이션에서 list[n] != 0이면 이미 계산된 값으로 판단합니다.
	// 초기값이 0이므로, 아직 계산되지 않은 상태를 구분할 수 있습니다.
	// 피보나치 수열 0번째 항이 0이므로 이 방식이 맞습니다.

	cout << "피보나치 수열 (" << n << ") : " << fibonacci(n, list) << endl;

	delete [] list;
#pragma endregion

	return 0;
}