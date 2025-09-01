#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// 템플릿을 사용하여 다양한 타입의 그래프를 만들 수 있도록 정의
template <typename T>

class Graph
{
private:
	// 인접 리스트: 각 노드에 연결된 노드들을 저장
	unordered_map <T, vector<T>> adjacencyList;

	// 각 노드의 진입 차수 (in-degree)를 저장
	unordered_map <T, int> degree;

	// 그래프에 존재하는 모든 노드들을 저장
	unordered_set <T> vertices;
public:
	// 간선 삽입 함수: i -> j 형태의 방향 간선을 추가
	void insert(const T& i, const T& j)
	{
		// i에서 j로 가는 간선 추가
		adjacencyList[i].push_back(j);

		// j의 진입 차수 증가
		degree[j]++;

		// i와 j를 정점 집합에 추가
		vertices.insert(i);
		vertices.insert(j);

		// i의 진입 차수가 없을 경우 0으로 초기화
		if (degree.count(i) == false)
		{
			degree[i] = 0;
		}
	}

	// 위상 정렬 수행 함수 (Kahn’s Algorithm 사용)
	void sort()
	{
		queue <int> queue;	// 진입 차수가 0인 노드를 저장할 큐
		int count = 0;		// 정렬된 노드의 개수를 카운트

		// 모든 정점 중 진입 차수가 0인 노드를 큐에 삽입
		for (const T& element : vertices)
		{
			if (degree[element] == 0)
			{
				queue.push(element);
			}
		}

		// 큐가 빌 때까지 반복
		while (queue.empty() == false)
		{
			// 큐에서 노드 하나 꺼내기
			T x = queue.front();
			queue.pop();

			// 현재 노드 출력 (위상 정렬 결과)
			cout << x << " ";

			count++;	// 정렬된 노드 수 증가

			// 현재 노드와 연결된 모든 노드들의 진입 차수를 감소
			for (const T& element : adjacencyList[x])
			{
				degree[element]--;

				// 진입 차수가 0이 된 노드를 큐에 추가
				if (degree[element] == 0)
				{
					queue.push(element);
				}
			}
		}

		cout << endl;

		// 모든 노드를 정렬하지 못했으면 사이클 존재
		if (count != vertices.size())
		{
			cout << "A cycle has occurred." << endl;
		}
	}
};

int main()
{
#pragma region 위상 정렬
	// Topological Sort
	// 병합 그래프에 존재하는 각 정점들의 선행 순서를 지키며,
	// 모든 정점을 차례대로 진행하는 방식의 정렬입니다.

	// 사이클이 발생하는 경우, 위상 정렬을 수행할 수 없습니다.

	// DAG (Directed Acyclic Graph) : 사이클이 존재하지 않는 그래프

	// 시간 복잡도 : 0(V + E) ; 정점(Vertex), 간선(Edge)

	// 위상 정렬하는 방법
	// 1. 진입 차수가 0인 정점을 Queue에 삽입합니다.
	// 2. Queue에서 원소를 꺼내 연결된 모든 간선을 제거합니다.
	// 3. 간선 제거 이후에 진입 차수가 0이 된 정점을 Queue에 삽입합니다.
	// 4. Queue가 비어있을 때까지 2번 ~ 3번 작업을 반복적으로 수행합니다.

	// 진입 차수 : in-degree. 한 정점으로 들어오는 간선의 개수 → 해당 노드를 의존하는 노드 수
	// 진출 차수 : out-degree. 한 정점에서 나가는 간선의 개수 → 해당 노드가 의존하는 다른 노드 수

	Graph <int> graph;

	// 그래프 간선 추가 (방향: 앞 → 뒤)
	graph.insert(1, 2);
	graph.insert(1, 5);

	graph.insert(2, 3);

	graph.insert(3, 4);

	graph.insert(4, 6);

	graph.insert(5, 6);

	graph.insert(6, 7);

	// 위상 정렬 실행
	graph.sort();
#pragma endregion

	return 0;
}