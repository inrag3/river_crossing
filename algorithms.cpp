#include <vector>
#include <tuple>
#include <unordered_set>
#include <queue>
#include <stack>
#include <iostream>
#include "algorithms.h"
#include "node.h"

using Position = std::tuple<int, int, int>;
using Move = std::tuple<int, int, int>;

Node* bfs(Node* node)
{
	std::queue<Node*> queue;
	std::unordered_set<Node*, NodeHash, NodeEquals> labeled;
	queue.push(node);

	while (!queue.empty())
	{
		node = queue.front();
		labeled.insert(node);
		queue.pop();

		if (is_result(node))
			return node;

		for (auto position : get_nodes(node))
		{
			if (!labeled.contains(position) && is_valid(position))
			{
				queue.push(position);
			}

		}
	}
}

Node* dfs(Node* node)
{
	std::stack<Node*> stack;
	std::unordered_set<Node*, NodeHash, NodeEquals> labeled;
	stack.push(node);

	while (!stack.empty())
	{
		node = stack.top();
		stack.pop();
		labeled.insert(node);


		if (is_result(node))
			return node;

		for (auto position : get_nodes(node))
		{
			if (!labeled.contains(position) && is_valid(position))
			{
				stack.push(position);
			}
		}
	}
}

Node* dls(Node* node, int current, int limit)
{
	if (current > limit)
		return nullptr;

	if (is_result(node))
		return node;

	for (auto position : get_nodes(node))
	{
		if (is_valid(position))
		{
			Node* result = dls(position, current + 1, limit);
			if (result != nullptr)
				return result;
		}
	}
	return nullptr;
}

Node* ids(Node* node)
{
	for (int i = 1; i < 20; ++i)
	{
		Node* result = dls(node, 0, i);
		if (result != nullptr)
			return result;
	}
}

bool is_result(Node* node)
{
	auto [m, b, c] = node->position();
	return !(m || b || c);
}

bool is_valid(Node* node)
{
	auto [x, y, z] = node->position();
	auto x1 = 3 - x;
	auto y1 = 3 - y;
	return !(
		x > 3 or y > 3 or x < 0 or y < 0 or
		x1 > 3 or y1 > 3 or x1 < 0 or y1 < 0 or
		(y > x) and (x > 0) or (y1 > x1 > 0) and (x1 > 0)
		);
}

std::vector<Node*> get_nodes(Node* node)
{
	auto [m, c, b] = node->position();
	std::vector<Node*> nodes;

	std::vector<Move> moves = {
		Move(2, 0, 1),
		Move(0, 2, 1),
		Move(1, 0, 1),
		Move(0, 1, 1),
		Move(1, 1, 1),
	};

	for (auto move : moves)
	{
		auto [x, y, z] = move;
		if (b) // Если лодка слева
			nodes.push_back(new Node(m - x, c - y, b - z, node));
		else
			nodes.push_back(new Node(m + x, c + y, b + z, node));
	}
	return nodes;
}

void show_path(Node* node)
{
	std::cout << *node << std::endl;
	auto parent = node->parent();
	while (parent != nullptr)
	{
		std::cout << *parent << std::endl;
		parent = parent->parent();
	}
}
