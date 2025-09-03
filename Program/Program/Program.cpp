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
	int gap = size / 2;

	// gap이 1 이상일 때까지 반복
	// gap == 1일 때 삽입 정렬과 동일한 작업을 하며, 
	// 이 과정을 통해 최종적으로 완전한 정렬 상태를 만듦
	while(gap >= 1)
	{
		// gap 간격만큼 떨어진 요소들을 대상으로 삽입 정렬 수행
		for (int i = gap; i < size; i++)
		{
			int temp = list[i];	// 삽입할 값을 임시 저장
			int j = i;

			// while문의 역할:
			// 'temp'보다, 앞에 있는 값(list[j - gap])이 크면
			// 그 값을 한 칸 뒤로 밀어내어 빈 공간을 만든다.
			// 
			// 'list[j - gap] > temp' 조건은 '앞 값이 크다'는 뜻으로,
			// 이 조건을 통해 정렬 기준을 유지할 수 있다.
			//
			// 'j >= gap' 조건은 배열 범위 초과 방지용.
			while (j >= gap && list[j - gap] > temp)
			{
				list[j] = list[j - gap];	// 큰 값을 뒤로 밀기
				j -= gap;					// 비교 대상을 gap만큼 앞으로 이동
			}

			list[j] = temp;	// 빈 공간에 temp 삽입
		}

		gap /= 2;	// gap을 점점 줄여가며 점진적으로 정렬 정확도를 높임
	}

	cout << endl;
	cout << "정렬된 배열 : ";
	for (const auto & element : list)
	{
		cout << element << " ";
	}
#pragma endregion

	return 0;
}

// 금요일 : 유니티 설치 방법 알려줄 예정