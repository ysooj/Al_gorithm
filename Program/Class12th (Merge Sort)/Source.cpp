#include <iostream>

using namespace std;

// 공간 복잡도는 O(n)
// 시간 복잡도는 O(n log n)

// 두 개의 정렬된 부분 배열을 병합하는 함수
void combine(int list[], int start, int middle, int end)
{
	int left = start;		// 왼쪽 부분 배열의 시작 인덱스
	int right = middle + 1;	// 오른쪽 부분 배열의 시작 인덱스 (중요: middle 바로 다음이 시작)
	int count = 0;			// combineList 배열에서 현재 저장할 위치


	// 병합 결과를 임시로 저장할 동적 배열 생성
	// [start ~ end] 범위를 커버해야 하므로, 총 개수는 end - start + 1
	int* container = new int[end - start + 1];

	// 두 부분의 배열을 병합합니다.
	// 두 부분 배열이 모두 남아 있을 때까지 비교하며 작은 값을 먼저 저장
	while (left <= middle && right <= end)
	{
		if (list[left] <= list[right])	// 왼쪽 값이 작거나 같으면
		{
			container[count++] = list[left++];	// 작은 값을 병합 배열에 저장
		}
		else	// 오른쪽 값이 더 작으면
		{
			container[count++] = list[right++];
		}
	}

	// 왼쪽 배열에 남은 요소들을 전부 복사
	while (left <= middle)
	{
		container[count++] = list[left++];
	}

	// 오른쪽 배열에 남은 요소들을 전부 복사
	while (right <= end)
	{
		container[count++] = list[right++];
	}

	// 병합 결과를 원래 배열의 정렬 대상 범위에 덮어쓰기
	// 원래 배열의 인덱스는 start부터 시작해야 하므로 start + i 사용
	for (int i = 0; i < end - start + 1; i++)
	{
		list[start + i] = container[i];	// 꼭 start + i로 해야 함!
		// 병합 결과를 원래 배열의 정확한 위치에 덮어쓰기 위해 필요
	}

	delete[] container;	// 동적 할당 해제 (메모리 누수 방지)
}

// 배열을 재귀적으로 반으로 나누고, 다시 병합 정렬하는 함수
void merge_sort(int list[], int start, int end)
{
	// 정렬할 구간의 크기가 2개 이상일 때만 진행
	if (start < end)
	{
		int middle = (start + end) / 2;	// 중간 지점 계산

		// 왼쪽 절반 정렬
		merge_sort(list, start, middle);
		// 오른쪽 절반 정렬
		merge_sort(list, middle + 1, end);

		// 정렬된 두 부분 배열 병합
		combine(list, start, middle, end);
	}
}

int main()
{
#pragma region 합병 정렬
	// 하나의 리스트를 두 개의 균일한 크기로 분할하고, 분할된 부분 리스트를 정렬한 다음
	// 두 개의 정렬된 부분 리스트를 합하여 전체가 정렬된 리스트가 되게 하는 방법입니다.

	// 1. 리스트의 길이가 0 또는 1이 되면, 이미 정렬된 것으로 봅니다.

	// 2. 그렇지 않은 경우

	// 2-1. 정렬되지 않은 리스트를 절반으로 잘라, 비슷한 크기의 두 부분 리스트로 나눕니다.

	// 2-2. 각 부분 리스트를 재귀적으로 합병 정렬을 이용하여 정렬합니다.

	// 2-3. 두 부분 리스트를 다시 하나의 정렬된 리스트로 병합합니다.

	int list[] = { 3, 5, 2, 7, 4, 1, 8, 6 };

	int size = sizeof(list) / sizeof(list[0]);

	merge_sort(list, 0, size - 1);

	for (const auto& element : list)
	{
		cout << element << " ";
	}
#pragma endregion

	return 0;
}