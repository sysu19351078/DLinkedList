#ifndef _DLINKEDLIST_H
#define _DLINKEDLIST_H
#include"Node.h"
#include<iostream>
using namespace std;

template<class T>
class DLinkedList
{
public:
	DLinkedList();						//���캯��
	DLinkedList(const DLinkedList& l);	//���ƹ��캯��
	~DLinkedList();						//��������

	
	int size();		//����ڵ���
	bool empty();	//�����Ƿ�Ϊ��
	
	Node<T>* find(int index);		//����
	Node<T> remove(int index);	//ɾ�������ڵ�
	Node<T>* first();			//�����׽ڵ�
	Node<T>* last();				//����β�ڵ�

	void insertAtFirst(const T& data);	//ǰ����
	void insertAtLast(const T& data);	//�����
	
	void sort();		//��data��С����
	void reverse();		//����ת
	void merge(const DLinkedList&l);		//�ϲ���һ����
	void show();		//������ӡ

protected:
	void init();	//��ʼ��

private:
	Node<T>* head;
	Node<T>* tail;
	int count = 0;
};



//DLinkedList��ľ���ʵ��

template<class T>
void DLinkedList<T>::init()
{
	Node<T>* node = new Node<T>();	//�����ձ�ͷ
	head = node;
	tail = nullptr;
}

template<class T>				//���캯��
DLinkedList<T>::DLinkedList()
{
	init();
}

template<class T>				//���ƹ��캯��
DLinkedList<T>::DLinkedList(const DLinkedList<T>& l)
{
	init();
	Node<T>* pnode;
	for (pnode = l.head->succ; pnode != l.tail; pnode = pnode->succ)
	{
		insertAtLast(pnode->data);
	}
}

template<class T>				//��������
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
	//���ɾ����ͷ
	delete head;
	head = tail = nullptr;
}

template<class T>				//��ǰ����
void DLinkedList<T>::insertAtFirst(const T& data)	
{
	
	Node<T>* node = new Node<T>(data, head, head->succ);
	head->succ->pred = node;
	head->succ = node;
	
	count++;
}

template<class T>				//������
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

template<class T>			//���ؽڵ���
int DLinkedList<T>::size()
{
	return count;
}

template<class T>			//�ж��Ƿ�Ϊ��
bool DLinkedList<T>::empty()
{
	return count == 0;
}

template<class T>			//�����ض�λ�ýڵ�
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


template<class T>			//ɾ���ض�λ�ýڵ�
Node<T> DLinkedList<T>::remove(int index)
{
	Node<T>* pnode = find(index);
	pnode->succ->pred = pnode->succ;
	pnode->pred->succ = pnode->succ;
	return *pnode;

	delete pnode;
	count--;
}

template<class T>			//�����׽ڵ�
Node<T>* DLinkedList<T>::first()
{
	if (empty())
	{
		cout << "����Ϊ��" << endl;
		return nullptr;
	}
	else
		return head->succ;
}

template<class T>			//����β�ڵ�
Node<T>* DLinkedList<T>::last()
{
	if (empty())
	{
		cout << "����Ϊ��" << endl;
		return nullptr;
	}
	else
		return tail;
}

template<class T>			//����
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

template<class T>			//��ת����
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

template<class T>				//ƴ������
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

template<class T>				//��ӡ����
void DLinkedList<T>::show()
{
	int i = 1;
	for (Node<T>* p = head->succ; p != tail->succ; p = p->succ)
	{
		cout <<"�ڵ�"<<i<<"��"<< p->data << endl;
		i++;
	}
}


#endif
