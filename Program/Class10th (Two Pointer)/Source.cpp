#include <iostream>

using namespace std;

void search(int list[], int key, int size)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int pivot = (left + right) / 2;

		if (list[pivot] == key)
		{
			cout << "Key found : " << list[pivot] << endl;
			cout << "Index : " << pivot << endl;

			return;	// key를 찾으면 바로 함수 종료
			// break는 반복문만 종료하고, 함수의 나머지 부분은 계속 실행됨 → 아래 "Not key found" 메시지까지 출력됨

			// ────────────────────────────────
			//    return / break / continue   
			// ────────────────────────────────
			//   return    │ 함수 자체를 종료   
			//   break     │ 반복문만 종료      
			//   continue  │ 이번 반복만 건너뜀 
			// ────────────────────────────────
		}

		else if (list[pivot] < key)
		{
			left = pivot + 1;
		}

		else
		{
			right = pivot - 1;
		}
	}

	cout << "Not key found" << endl;	// 반복문 종료 후에도 key를 못 찾았을 때 출력하는 문구
}

int main()
{
#pragma region 이분 탐색
	// 탐색 범위를 반으로 나누어, 찾는 값을 포함하는 범위를 좁혀나가는 방식으로 동작하는 알고리즘입니다.

	// two pointer 알고리즘
	// 메모리 주소를 가리키는 포인터가 아니라, 배열의 양 끝에서 이동하는 두 개의 인덱스를 의미한다.

	int list[] = { 1, 2, 15, 19, 33, 45, 60 };
	int size = sizeof(list) / sizeof(list[0]);

	search(list, 11, size);
#pragma endregion

	return 0;
}