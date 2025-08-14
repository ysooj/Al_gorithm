#include <iostream>

using namespace std;

// ========================================================
// 
// !!!!!!!!!!!!!!!!!!!!!다시 보기 필수!!!!!!!!!!!!!!!!!!!!!
// 
//              코드 똑같은 지 다시 확인하기
// 
// ========================================================

int main()
{
#pragma region 삽입 정렬
	// 데이터를 하나씩 확인하면서 이미 정렬된 부분과 비교하여
	// 자신의 위치를 찾아 삽입하는 방식으로 정렬하는 알고리즘입니다.

	int list[] = { 7, 6, 8, 4, 1, 3, 10, 5, 2, 9 };

	int size = sizeof(list) / sizeof(list[0]);

	int key = 0;
	int j = 0;

	for (int i = 1; i < size; i++)
	{
		key = list[i];

		for (int j = i - 1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j];
		}

		list[j + 1] = key;
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