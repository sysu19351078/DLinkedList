#ifndef _NODE_H_
#define _NODE_H_

template<class T>
class Node
{
public:
	Node<T>* pred;
	Node<T>* succ;
	T data;

	Node()
	{
		pred = succ = nullptr;
	}
	Node(const T& item, Node* p, Node* s)
	{
		pred = p;
		succ = s;
		data = item;
	}

};


#endif _NODE_H_
