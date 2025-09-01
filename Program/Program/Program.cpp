#include <iostream>
#include <vector>

#define INFINITY 10000000

using namespace std;

class Dijkstra
{
private:
	vector <vector <int>> adjacencyMatrix;
	vector <int> visited;
	vector <int> distance;

	int size = 0;
	int newSize;
public:
	void insert(int i, int j, int weight)
	{
		newSize = max(i, j) + 1;
		
		if (newSize > size)
		{
			resize(newSize);
		}

		adjacencyMatrix[i][j] = weight;
	}

	void resize(int node)
	{
		newSize = node + 1;

		// stl 함수인 resize 함수 이용하기. 재귀 함수 아님 주의!
	}
};

int main()
{
#pragma region 다익스트라 알고리즘
	// 길찾기 알고리즘
	
	// 시작점으로부터 모든 노드까지의 최소 거리를 구해주는 알고리즘입니다.

	// 1. 거리 배열에서 weight[시작 노드]의 값들로 초기화합니다.
	// 2. 시작점을 방문 처리합니다.
	// 3. 거리 배열에서 최소 비용 노드를 찾고 방문 처리합니다.
	// 4. 최소 비용 노드를 거쳐갈 지 고민해서 거리 배열을 갱신합니다.
	//	  단, 이미 방문한 노드는 제외합니다.
	// 5. 모든 노드를 방문할 때까지 3~4번 반복합니다.

	// 방문하지 않은 노드 중에서 가장 작은 거리를 가진 노드를 방문하고
	// 그 노드와 연결된 다른 노드까지의 거리를 계산합니다.
	
	// 시간복잡도 : v²(vertex의 제곱)
#pragma endregion

	return 0;
}