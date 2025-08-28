#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

template <typename T>

class Graph
{
private:
	// 그래프를 인접 리스트 형태로 저장
	// 각 정점 T에 대해 연결된 정점들의 벡터를 저장
	unordered_map<T, vector<T>> adjacencyList;
public:
	// 두 정점 i와 j를 연결하는 간선을 삽입 (무방향 그래프)
	void insert(const T& i, const T& j)
	{
		adjacencyList[i].push_back(j);	// i에 j 추가
		adjacencyList[j].push_back(i);	// j에 i 추가 (무방향)
	}

	// BFS 탐색 함수: 시작 정점 start부터 탐색
	void search(const T& start)
	{
		queue<T> queue;				// BFS에 사용할 큐: 방문 예정인 노드들 저장
		unordered_set<T> visited;	// 방문한 노드를 기록: 중복 방문 방지

		queue.push(start);			// 시작 노드를 큐에 넣음
		visited.insert(start);		// 시작 노드를 방문 처리

		// 큐가 빌 때까지 반복 (탐색할 노드가 없을 때까지)
		while (queue.empty() == false)
		{
			T x = queue.front();	// 큐 맨 앞 노드를 꺼냄 (현재 탐색 중인 노드)
			queue.pop();			// 큐에서 제거

			cout << x << " ";	// 현재 노드 출력 (방문 순서 기록)

			// 현재 노드에 인접한 모든 노드들을 검사
			for (const T& element : adjacencyList[x])
			{
				// 아직 방문하지 않은 노드만 처리
				if (visited.count(element) == false)
				{
					visited.insert(element);	// 방문 처리
					queue.push(element);		// 다음 탐색을 위해 큐에 추가
				}
			}
		}
	}
};

int main()
{
#pragma region 너비 우선 탐색 (Breadth First Search)
	// 하나의 시작 정점을 방문한 후, 시작 정점에 인접한 모든 정점들을 우선적으로 방문하는 탐색입니다.

	// 그래프 생성 및 간선 삽입
	Graph <char> graph;

	graph.insert('A', 'B');
	graph.insert('A', 'C');
	graph.insert('B', 'D');
	graph.insert('B', 'E');
	graph.insert('C', 'F');
	graph.insert('C', 'G');

	// 'A' 정점부터 BFS 탐색 시작
	graph.search('A');
#pragma endregion

	return 0;
}