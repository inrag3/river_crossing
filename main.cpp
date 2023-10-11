#include <iostream>
#include <chrono>
#include "node.h"
#include "algorithms.h"

/*
Алгоритм BFS
Время: 40 us
[0, 0, 0]
[1, 1, 1]
[0, 1, 0]
[0, 3, 1]
[0, 2, 0]
[2, 2, 1]
[1, 1, 0]
[3, 1, 1]
[3, 0, 0]
[3, 2, 1]
[3, 1, 0]
[3, 3, 1]

Алгоритм DFS
Время: 23 us
[0, 0, 0]
[0, 2, 1]
[0, 1, 0]
[0, 3, 1]
[0, 2, 0]
[2, 2, 1]
[1, 1, 0]
[3, 1, 1]
[3, 0, 0]
[3, 2, 1]
[2, 2, 0]
[3, 3, 1]

Алгоритм IDS
Время: 16 ms
[0, 0, 0]
[1, 1, 1]
[0, 1, 0]
[0, 3, 1]
[0, 2, 0]
[2, 2, 1]
[1, 1, 0]
[3, 1, 1]
[3, 0, 0]
[3, 2, 1]
[3, 1, 0]
[3, 3, 1]
*/

int main()
{
	setlocale(LC_ALL, "");
	Node* initial = new Node(MISSIONARIES, CANNIBALS, 1);

	auto s = std::chrono::steady_clock::now();
	Node* result = bfs(initial);
	auto e = std::chrono::steady_clock::now();
	printf("Алгоритм BFS\n");
	printf("Время: %I64d ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(e - s).count());
	show_path(result);
	std::cout << std::endl;

	s = std::chrono::steady_clock::now();
	result = dfs(initial);
	e = std::chrono::steady_clock::now();
	printf("Алгоритм DFS\n");
	printf("Время: %I64d ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(e - s).count());
	show_path(result);
	std::cout << std::endl;

	s = std::chrono::steady_clock::now();
	result = ids(initial);
	e = std::chrono::steady_clock::now();
	printf("Алгоритм IDS\n");
	printf("Время: %I64d ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(e - s).count());
	show_path(result);
}