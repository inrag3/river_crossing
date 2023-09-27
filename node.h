#pragma once
#ifndef NODE_H
#define	NODE_H

using Position = std::tuple<int, int, int>;
using Move = std::tuple<int, int, int>;

class Node
{
	Position _position;
	Node* _parent;

public:
	//M - missionaries in left
	//C - cannibals in left
	//B = 1 boat on left
	//B = 0 boat on right
	Node(int m, int c, int b, Node* parent = nullptr) : _parent(parent)
	{
		_position = std::make_tuple(m, c, b);
	}

	Position position() const
	{
		return _position;
	}

	Node* parent()
	{
		return _parent;
	}

	friend std::ostream& operator<<(std::ostream& os, const Node& node)
	{
		auto [m, c, b] = node._position;
		return os << "[" << m << ", " << c << ", " << b << "]";
	}
};

struct NodeHash
{
public:
	size_t operator()(const Node* node) const
	{
		auto [x, y, z] = node->position();
		size_t hash = 17;

		hash *= 31 + std::hash<int>()(x);
		hash *= 31 + std::hash<int>()(y);
		hash *= 31 + std::hash<int>()(z);
		return hash;
	}
};

struct NodeEquals
{
public:
	bool operator()(const Node* node1, const Node* node2) const
	{
		return node1->position() == node2->position();
	}
};

#endif // NODE_H