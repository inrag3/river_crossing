#pragma once
#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "node.h"
#include <vector>

Node* bfs(Node* node);
Node* dfs(Node* node);
Node* ids(Node* node);
bool is_result(Node* node);
bool is_valid(Node* node);
std::vector<Node*> get_nodes(Node* node);
void show_path(Node* node);

#endif // ALGORITHMS_H