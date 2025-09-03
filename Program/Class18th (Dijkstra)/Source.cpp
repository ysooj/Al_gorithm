#include <iostream>
#include <vector>

using namespace std;

#define INFINITY 10000000

class Dijkstra
{
private:
	vector<int> distance;
	vector<bool> visited;
	vector<vector<int>> graph;
public:
	void Resize(int node)
	{
		int newSize = node + 1;

		if (graph.size() < newSize)
		{
			int previousSize = graph.size();

			graph.resize(newSize);

			for (int i = previousSize; i < newSize; i++)
			{
				graph[i].resize(newSize, INFINITY);
			}

			for (int i = 0; i < previousSize; i++)
			{
				graph[i].resize(newSize, INFINITY);
			}

			for (int i = previousSize; i < newSize; i++)
			{
				graph[i][i] = 0;
			}
		}

		if (visited.size() < newSize)
		{
			visited.resize(newSize, false);
			distance.resize(newSize, INFINITY);
		}
	}

	void insert(int i, int j, int weight)
	{
		Resize(max(i, j));

		graph[i][j] = weight;
		graph[j][i] = weight;
	}

	const int& find()
	{
		int index = 0;
		int min = INFINITY;

		for (int i = 0; i < distance.size(); i++)
		{
			if (distance[i] < min && visited[i] == false)
			{
				min = distance[i];
				index = i;
			}
		}

		return index;
	}

	void update(int start)
	{
		for (int i = 0; i < graph.size(); i++)
		{
			distance[i] = graph[start][i];
		}

		visited[start] = true;

		for (int i = 0; i < graph.size() - 1; i++)
		{
			int minNode = find();

			visited[minNode] = true;

			for (int j = 0; j < graph.size(); j++)
			{
				if (visited[j] == false && distance[minNode] + graph[minNode][j] < distance[j])
				{
					distance[j] = distance[minNode] + graph[minNode][j];
				}
			}
		}

		cout << "[" << start << "번 노드에서 시작했을 때 최단 거리]" << endl;

		for (int i = 0; i < graph.size(); i++)
		{
			cout << "  -> " << i << "번 노드까지의 거리 : ";
			cout << distance[i] << endl;
		}

		cout << endl;
	}

	// 내 버전 - update함수의 'visited[start] = true;' 부분까지만 있을 경우
	//	void dijkstra(int start)
	//	{
	//		// 시작 노드에서 거리 배열 초기화
	//		for (int i = 0; i < graph.size(); i++)
	//		{
	//			distance[i] = graph[start][i];
	//		}
	//		visited[start] = true;
	//		distance[start] = 0;
	//	
	//		// 모든 노드를 방문할 때까지 반복
	//		for (int count = 0; count < distance.size() - 1; count++)
	//		{
	//			int minIndex = find();
	//			if (minIndex == -1) break; // 방문할 노드가 더 이상 없으면 종료
	//			visited[minIndex] = true;
	//	
	//			// 거리 갱신
	//			for (int i = 0; i < graph.size(); i++)
	//			{
	//				if (!visited[i] && distance[minIndex] + graph[minIndex][i] < distance[i])
	//				{
	//					distance[i] = distance[minIndex] + graph[minIndex][i];
	//				}
	//			}
	//		}
	//	
	//		// 결과 출력
	//		cout << start << "번 노드에서 시작했을 때 최단 거리:" << endl;
	//		for (int i = 1; i < distance.size(); i++) // 0번은 더미 노드라서 제외
	//		{
	//			cout << " → " << i << "번 노드까지: ";
	//			if (distance[i] == INFINITY)
	//				cout << "도달 불가" << endl;
	//			else
	//				cout << distance[i] << endl;
	//		}
	//		cout << endl;
	//	}
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

	Dijkstra dijkstra;

	// 간선 추가: graph.insert(시작노드, 도착노드, 가중치);
	dijkstra.insert(1, 2, 2);
	dijkstra.insert(1, 3, 5);
	dijkstra.insert(1, 4, 1);

	dijkstra.insert(2, 3, 3);
	dijkstra.insert(2, 4, 2);

	dijkstra.insert(3, 4, 3);
	dijkstra.insert(3, 5, 1);
	dijkstra.insert(3, 6, 5);

	dijkstra.insert(4, 5, 1);

	dijkstra.insert(5, 6, 2);

	// 다익스트라 실행 (1번 노드 시작)
	dijkstra.update(1);
#pragma endregion

	return 0;
}