#include "BinarySearchTree.h"
#include <iostream>
#include <windows.h>

inline void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

template<typename T>
inline void BinarySearchTree<T>::Print(Node<T>* node, int x, int y)
{
	if (node == nullptr)
	{
		return;
	}

	SetCursorPosition(x, y);

	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}

template<typename T>
inline void BinarySearchTree<T>::Print_Inorder(Node<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	std::cout << node->key << std::endl;
	Print_Inorder(node->left);
	Print_Inorder(node->right);
}

template<typename T>
inline void BinarySearchTree<T>::Insert(T key)
{
	Node<T>* newNode = new Node<T>();
	newNode->key = key;

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node<T>* node = _root;
	Node<T>* parent = nullptr;

	while (node)
	{
		parent = node;

		if (key < node->key)
		{
			node = node->left;
		}

		else
		{
			node = node->right;
		}
	}

	newNode->parent = parent;

	if (key < parent->key)
	{
		parent->left = newNode;
	}

	else
	{
		parent->right = newNode;
	}
}

template<typename T>
inline void BinarySearchTree<T>::Delete(T key)
{
	Node<T>* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

template<typename T>
inline void BinarySearchTree<T>::Delete(Node<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	{
		if (node->left == nullptr)
		{
			Replace(node, node->right);
		}

		else if (node->right == nullptr)
		{
			Replace(node, node->left);
		}

		else
		{
			Node<T>* next = Next(node);
			node->key = next->key;
			Delete(next);
		}
	}
}

// u 서브트리를 v 서브트리로 교체
// u 메모리 삭제
template<typename T>
inline void BinarySearchTree<T>::Replace(Node<T>* u, Node<T>* v)
{
	{
		if (u->parent == nullptr)
		{
			_root = v;
		}

		else if (u == u->parent->left)
		{
			u->parent->left = v;
		}

		else
		{
			u->parent->right = v;
		}
	}

	if (v)
	{
		v->parent = u->parent;
	}

	if (u)
	{
		delete u;
	}
}

template<typename T>
inline Node<T>* BinarySearchTree<T>::Search(Node<T>* node, T key)
{
	while (node && key != node->key)
	{
		if (key < node->key)
		{
			node = node->left;
		}

		else
		{
			node = node->right;
		}
	}

	return node;
}

template<typename T>
inline Node<T>* BinarySearchTree<T>::Min(Node<T>* node)
{
	while (node->left)
	{
		node = node->left;
	}

	return node;
}

template<typename T>
inline Node<T>* BinarySearchTree<T>::Max(Node<T>* node)
{
	while (node->right)
	{
		node = node->right;
	}

	return node;
}

template<typename T>
inline Node<T>* BinarySearchTree<T>::Next(Node<T>* node)
{
	if (node->right)
	{
		return Min(node->right);
	}

	Node<T>* parent = node->parent;

	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}

	return parent;
}

