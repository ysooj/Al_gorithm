#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

template <typename T>

class Graph
{
private:
	unordered_map <T, vector<T>> adjacencyList;
	unordered_map <T, int> degree;
	unordered_set <T> vertices;
public:

	void insert(const T & i, const T & j)
	{
		adjacencyList[i].push_back(j);
		degree[j]++;

		vertices.insert(i);
		vertices.insert(j);

		if (degree.count(i) == false)
		{
			degree[i] = 0;
		}
	}

	void search()
	{
		queue <T> queue;
		vector <T> forPrint;

		for (const auto& element : vertices)
		{
			if (degree[element] == 0)
			{
				queue.push(element);
			}
		}

		while (queue.empty() == false)
		{
			T x = queue.front();

			queue.pop();

			forPrint.push_back(x);

			for (const T & element : adjacencyList[x])
			{
				degree[element]--;

				if (degree[element] == 0)
				{
					queue.push(element);
				}
			}
		}

		for (const T & element : forPrint)
		{
			cout << element << " ";
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

	graph.insert(1, 2);
	graph.insert(1, 5);

	graph.insert(2, 3);

	graph.insert(3, 4);

	graph.insert(4, 6);

	graph.insert(5, 6);

	graph.insert(6, 7);

	graph.search();
#pragma endregion

	return 0;
}