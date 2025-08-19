#include <iostream>

using namespace std;

int main()
{
#pragma region 계수 정렬
	// 데이터의 값을 비교하지 않고, 각 원소에 데이터가 몇 개 있는 지
	// 개수를 세어 저장한 다음 정렬하는 알고리즘입니다.

	// 시간 복잡도는 0(n + k).
	// n : 정렬한 요소의 개수
	// k : 정수 데이터 중에서 최댓값

	int list[] = { 1, 1, 3, 1, 2, 3, 4, 4, 2, 5 };

	int size = sizeof(list) / sizeof(list[0]);

	int countList[5] = { 0 };

	for (int i = 0; i < size; i++)
	{
		countList[list[i] - 1]++;
	}

	for (int i = 0; i < 5; i++)
	{
		if (list[i] != 0)
		{
			for (int j = 0; j < countList[i]; j++)
			{
				cout << i + 1 << " ";
			}
		}
	}

	// 인벤토리 정리할 때 쓸 수 있다.
#pragma endregion

	return 0;
}