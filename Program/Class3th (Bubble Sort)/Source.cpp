#include <iostream>

using namespace std;

int main()
{
#pragma region 거품 정렬
	// 서로 인접한 두 원소를 비교하여 정렬하는 알고리즘입니다.

	// 배열 초기화
	int list[] = { 3, 1, 2, 4, 5 };

	// 배열의 전체 원소 개수 계산
	int size = sizeof(list) / sizeof(list[0]);

	// 버블 정렬의 한 단계 수행
	// 인접한 두 원소를 비교하여 큰 값을 오른쪽으로 이동시킴
	for (int i = 0; i < size - 1; i++)
	{
		// 현재 원소가 다음 원소보다 크면 두 값을 교환 (오름차순 정렬)
		for (int j = 0; j < size - 1 - i; j++)
		{
			// i < size - 1인 이유:
			// 우리는 list[i]와 list[i + 1]을 비교하므로
			// i가 마지막 인덱스(size - 1)가 되면 list[i + 1]은 범위를 벗어남
			// 따라서 i는 최대 size - 2까지만 허용되어야 안전함
			if (list[j] > list[j + 1])
			{
				// 스왑
				std::swap(list[j], list[j + 1]);
			}

			// 정렬 과정 출력
			cout << "정렬 과정 : ";
			for (const auto& element : list)
			{
				cout << element << " ";
			}

			cout << endl;
		}
	}

	// 정렬 결과 출력
	cout << endl;
	cout << "정렬 결과 : ";
	for (const auto& element : list)
	{
		cout << element << " ";
	}

	cout << endl;
#pragma endregion

	return 0;
}