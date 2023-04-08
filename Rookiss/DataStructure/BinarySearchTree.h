#pragma once

template<typename T>
struct Node
{
	Node*	parent = nullptr;
	Node*	left = nullptr;
	Node*	right = nullptr;
	T		key = {};
};

template<typename T>
class BinarySearchTree
{
public:
	inline void	Print() { Print(_root, 10, 0); };
	inline void	Print(Node<T>* node, int x, int y);
	inline void	Print_Inorder() { Print_Inorder(_root); }
	inline void	Print_Inorder(Node<T>* node);

	inline void	Insert(T key);
	inline void	Delete(T key);
	inline void	Delete(Node<T>* node);
	inline void	Replace(Node<T>* U, Node<T>* v);

	inline Node<T>* Search(Node<T>* node, T key);
	inline Node<T>* Min(Node<T>* node);
	inline Node<T>* Max(Node<T>* node);
	inline Node<T>* Next(Node<T>* node);
	
private:
	Node<T>*		_root = nullptr;
};

#include "BinarySearchTree.inl"