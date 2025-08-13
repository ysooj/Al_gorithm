#include <iostream>

using namespace std;

int main()
{
#pragma region 선택 정렬
	// 주어진 리스트 중에 최소값을 찾은 다음
	// 특정한 위치에서 결과를 교체하는 방시으로 정렬하는 알고리즘입니다.

	// 초기 배열
	int list[] = { 8, 5, 10, 7, 1, 3, 2, 9, 6, 4 };

	// 배열 크기 계산
	int size = sizeof(list) / sizeof(list[0]);

	// 선택 정렬 수행
	for (int i = 0; i < size - 1; i++)
	{
		// 현재 위치를 최소값 인덱스로 설정
		int min = list[i];
		int minIndex = i;

		// i 이후의 값들 중에서 가장 작은 값을 찾기 위한 반복문
		for (int j = i + 1; j < size; j++)
		{
			if (min > list[j])
			{
				min = list[j];	// 더 작은 값 발견 시 인덱스 갱신
				minIndex = j;
			}
		}

		int minValue = list[minIndex];

		// 현재 위치(i)와 최소값 위치(minIndex)를 교환
		swap(list[i], list[minIndex]);

		// 정렬 과정 출력
		cout << "정렬 과정 : ";
		for (const auto& element : list)
		{
			cout << element << " ";
		}

		cout << endl;

		cout << "현재 가장 작은 값 : " << minValue << endl;

		cout << endl;
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