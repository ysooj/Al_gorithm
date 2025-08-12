#include <iostream>

using namespace std;

int main()
{
#pragma region 완전 탐색
    // 가능한 모든 경우의 수를 탐색하면서 결과를 찾아내는 알고리즘입니다.

    // 브루트 포스(Brute Force)" : 직역하면 "무식한 힘" 또는 "무대포 방식"
    // 즉, 최적화나 효율적인 방법 없이 모든 가능한 경우를 전부 시도해서 문제를 푸는 방식

    int password[3] = { 5, 1, 7 };

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (password[0] == i && password[1] == j && password[2] == k)
                {
                    cout << "비밀번호가 해제되었습니다." << endl;
                    cout << "release : " << i << " " << j << " " << k << endl;

                    return 0;   // 찾았으니 더 이상 탐색하지 않음
                    // for문은 명시적으로 멈추라고 지시하지 않는 한 끝까지 돈다는 특징이 있기 때문에
                    // 비밀번호를 찾았고 나서 더 이상 탐색하지 않으려면 return을 바로 해줘야 한다.
                }
            }
        }
    }

    // 시간 복잡도가 세제곱 시간 0(n³)으로 보일 수 있다.
    // 그러나 이론상으로는 고정돼있는 범위기 때문에 상수 0(n)라고 한다.
#pragma endregion

    return 0;
}