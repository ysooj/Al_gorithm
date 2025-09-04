#include <iostream>

using namespace std;

int main()
{
#pragma region 쉘 정렬
	// 리스트를 일정한 간격에 따라 나누고, 각 부분 리스트를 삽입 정렬을 통해 정렬하는 방법입니다.

	// 1. 초기 시작 간격을 설정합니다.

	// 2. 간격 단위로 그룹을 묶어서 리스트를 나눕니다.

	// 3. 각 그룹의 n번째 원소들끼리 삽입정렬을 수행합니다.

	// 4. 간격의 크기를 반으로 줄입니다.

	// 5. 간격이 1이 될 때까지 2번부터 반복합니다.

	int list[] = { 14, 57, 21, 8, 36, 25, 32, 19 };

	int size = sizeof(list) / sizeof(list[0]);

	// 초기 간격(gap)은 배열 크기의 절반부터 시작
	int k = size / 2;

	// k가 0보다 클 동안 반복
	// k가 1이 되면 일반적인 삽입 정렬과 동일한 작업을 수행하며,
	// 이 과정을 통해 배열이 점진적으로 정렬됨
	while (k > 0)
	{
		// k 간격만큼 떨어진 요소들을 대상으로 삽입 정렬 수행
		for (int i = k; i < size; i++)
		{
			int key = list[i];	// 삽입할 값을 임시 저장
			int j = i;

			// 현재 값(key)보다 큰 값을 만날 때까지,
			// k 간격으로 앞의 값을 뒤로 밀어서 삽입할 위치를 찾는다.
			// 
			// 'list[j - k] > key' → 앞의 값이 더 크면 뒤로 밀기
			// 'j >= k' → 배열 범위를 벗어나지 않도록 조건 추가
			while (j >= k && list[j - k] > key)
			{
				list[j] = list[j - k];	// 큰 값을 뒤로 밀기

				j -= k;					// 비교 대상을 k만큼 앞으로 이동
			}

			list[j] = key;	// 빈 공간에 key 삽입
		}

		k /= 2;	// k값을 점점 줄여가며 점진적으로 정렬 정확도를 높임
	}

	cout << "정렬된 배열 : ";
	for (const auto& element : list)
	{
		cout << element << " ";
	}
#pragma endregion

	return 0;
}