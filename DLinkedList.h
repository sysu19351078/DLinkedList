#ifndef _DLINKEDLIST_H
#define _DLINKEDLIST_H
#include"Node.h"
#include<iostream>
using namespace std;

template<class T>
class DLinkedList
{
public:
	DLinkedList();						//构造函数
	DLinkedList(const DLinkedList& l);	//复制构造函数
	~DLinkedList();						//析构函数

	
	int size();		//报告节点数
	bool empty();	//报告是否为空
	
	Node<T>* find(int index);		//查找
	Node<T> remove(int index);	//删除单个节点
	Node<T>* first();			//返回首节点
	Node<T>* last();				//返回尾节点

	void insertAtFirst(const T& data);	//前插入
	void insertAtLast(const T& data);	//后插入
	
	void sort();		//按data大小排序
	void reverse();		//链表反转
	void merge(const DLinkedList&l);		//合并另一链表
	void show();		//遍历打印

protected:
	void init();	//初始化

private:
	Node<T>* head;
	Node<T>* tail;
	int count = 0;
};



//DLinkedList类的具体实现

template<class T>
void DLinkedList<T>::init()
{
	Node<T>* node = new Node<T>();	//创建空表头
	head = node;
	tail = nullptr;
}

template<class T>				//构造函数
DLinkedList<T>::DLinkedList()
{
	init();
}

template<class T>				//复制构造函数
DLinkedList<T>::DLinkedList(const DLinkedList<T>& l)
{
	init();
	Node<T>* pnode;
	for (pnode = l.head->succ; pnode != l.tail; pnode = pnode->succ)
	{
		insertAtLast(pnode->data);
	}
}

template<class T>				//析构函数
DLinkedList<T>::~DLinkedList()
{
	Node<T>* ptemp;
	Node<T>* pnode = head->succ;
	while (pnode != head)
	{
		ptemp = pnode;
		pnode = pnode->succ;
		delete ptemp;
		count--;
	}
	//最后删除表头
	delete head;
	head = tail = nullptr;
}

template<class T>				//向前插入
void DLinkedList<T>::insertAtFirst(const T& data)	
{
	
	Node<T>* node = new Node<T>(data, head, head->succ);
	head->succ->pred = node;
	head->succ = node;
	
	count++;
}

template<class T>				//向后插入
void DLinkedList<T>::insertAtLast(const T& data)
{
	if (tail == nullptr)
	{
		Node<T>* node = new Node<T>(data, head, nullptr);
		tail = node;
		head->succ = tail;
		tail->pred = head;
	}
	else
	{
		Node<T>* node = new Node<T>(data, tail, nullptr);
		tail->succ = node;
		tail = node;
	}
	count++;
}

template<class T>			//返回节点数
int DLinkedList<T>::size()
{
	return count;
}

template<class T>			//判断是否为空
bool DLinkedList<T>::empty()
{
	return count == 0;
}

template<class T>			//查找特定位置节点
Node<T>* DLinkedList<T>::find(int index)
{
	Node<T>* pnode = head->succ;
	if (index < 0 || index >= count)
	{
		cout << "get node failed! the index is out of bound!" << endl;
		return nullptr;
	}
	else
	{

		for (int i = 1; i < index - 1; i++)
		{
			pnode = pnode->succ;
		}
		return pnode;
	}

}


template<class T>			//删除特定位置节点
Node<T> DLinkedList<T>::remove(int index)
{
	Node<T>* pnode = find(index);
	pnode->succ->pred = pnode->succ;
	pnode->pred->succ = pnode->succ;
	return *pnode;

	delete pnode;
	count--;
}

template<class T>			//返回首节点
Node<T>* DLinkedList<T>::first()
{
	if (empty())
	{
		cout << "链表为空" << endl;
		return nullptr;
	}
	else
		return head->succ;
}

template<class T>			//返回尾节点
Node<T>* DLinkedList<T>::last()
{
	if (empty())
	{
		cout << "链表为空" << endl;
		return nullptr;
	}
	else
		return tail;
}

template<class T>			//排序
void DLinkedList<T>::sort()
{
	for (Node<T>* p1 = head->succ; p1 != tail; p1 = p1->succ)
	{
		T temp;
		for (Node<T>* p2 = p1->succ; p2 != tail->succ; p2 = p2->succ)
		{
			if (p1->data > p2->data)
			{
				temp = p1->data;
				p1->data = p2->data;
				p2->data = temp;
			}
		}
	}
}

template<class T>			//反转链表
void DLinkedList<T>::reverse()
{
	if (count >= 2)
	{
		T temp;
		Node<T>* p1;
		Node<T>* p2;
		int i;
		for (p1 = head->succ, p2 = tail, i = 1; i <= (count / 2); i++, p1 = p1->succ, p2 = p2->pred)
		{
			temp = p1->data;
			p1->data = p2->data;
			p2->data = temp;
		}
	}
}

template<class T>				//拼接链表
void DLinkedList<T>::merge(const DLinkedList& l)
{
	if (l.count != 0)
	{
		Node<T>* p;
		for (p = l.head->succ; p != l.tail->succ; p = p->succ)
		{
			insertAtLast(p->data);
		}
	}
}

template<class T>				//打印数据
void DLinkedList<T>::show()
{
	int i = 1;
	for (Node<T>* p = head->succ; p != tail->succ; p = p->succ)
	{
		cout <<"节点"<<i<<"："<< p->data << endl;
		i++;
	}
}


#endif
