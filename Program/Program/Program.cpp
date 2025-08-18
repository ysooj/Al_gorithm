#include <iostream>

using namespace std;

void Prime(int n)
{
	for (int i = 2; i <= n; i++)
	{
		bool isPrime = true;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				isPrime = false;

				break;
			}
		}

		if (isPrime == true)
		{
			cout << i << " ";
		}
	}
}

void sieve(int n)
{
	int * array = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		array[i] = i;
	}

	array[0] = 0;
	array[1] = 0;

	for (int i = 2; i * i <= n; i++)
	{
		for (int j = i * i; j <= n; j += i)
		{
			array[j] = 0;
		}
	}

	for (int i = 2; i < n; i++)
	{
		if (array[i] != 0)
		{
			cout << array[i] << " ";
		}
	}
}

int main()
{
#pragma region 에라토스테네스의 체
	// 소수 : 1과 자기 자신 이외에 나누어 떨어지지 않는 수
	// ex) 2, 3, 5, 7, 11, 13, 17, 19

	// 2 ~ n까지 소수를 출력하는 알고리즘 만들기

	//	Prime(20);

	//	// 선생님 버전
	//	int j = 0;
	//	int n = 0;
	//	
	//	std::cin >> n;
	//	
	//	for (int i = 2; i <= n; i++)
	//	{
	//		for (j = 2; j < n; j++)
	//		{
	//			if (i % j == 0)
	//			{
	//				break;
	//			}
	//		}
	//	
	//		if (i == j)
	//		{
	//			cout << i << " ";
	//		}
	//	}
	//	// 현재는 시간 복잡도가 0(n²).
	//	// 이걸 에라토스테네스의 채를 통해 0(n log log n)까지 줄일 것이다.
	//	// 0(n * log(log n))은 0(log n)보다는 느리지만(log n은 진짜 빠르다고 한다.) 비슷하게 빠르다고 한다.

	sieve(100);
#pragma endregion

	return 0;
}