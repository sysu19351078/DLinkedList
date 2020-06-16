#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"node.h"
#include"DLinkedList.h"
using namespace std;

int main()
{
	DLinkedList<int> list1, list2;			//创建两空双向链表
	
	ifstream myfile;
	myfile.open("IntegerData.txt");//传入“IntegerData.txt”
	if (myfile.fail())
	{
		cout << "传入文件失败！" << endl;
		return -1;
	}
	else
	{
		cout << "传入文件成功！" << endl;
	}
	string str, text;
	while (getline(myfile, str))			//提取数据
	{
		text += str;
	}
	auto start = text.find("number");
	start = text.find_first_of(":", start+1);
	while (start != string::npos)
	{
		string tnum(text, start + 1, 2);
		int num = stod(tnum);
		list1.insertAtLast(num);			//将数据插入进list1
		start = text.find_first_of(":", start + 1);
	}

	ifstream myfile2;
	myfile2.open("Merge.txt");				//打开第二个文件
	if (myfile2.fail())
	{
		cerr << "传入文件失败！" << endl;
		return -1;
	}
	else
	{
		cout << "传入文件成功!" << endl;
	}

	string test;
	while (getline(myfile2, str))			//提取数据
	{
		test += str;
	}
	start = test.find("number");
	start = test.find_first_of(":", start + 1);
	while (start != string::npos)
	{
		string tnum(test, start + 1, 2);
		int num = stod(tnum);
		list2.insertAtLast(num);			//将数据插入进list
		start = test.find_first_of(":", start + 1);
	}

	cout << "\n对双向链表list1进行操作：" << endl;
	if (!list1.empty())
	{
		cout << "list1 不为空链表" << endl;
	}
	cout << "list1 的节点数为:" << list1.size() << endl;
	cout << "\n打印list1的节点内容" << endl;
	list1.show();
	cout << "\n翻转list1并打印其内容" << endl;
	list1.reverse();
	list1.show();
	
	cout <<"\n删除list1第1个节点，并打印其数据"<< endl;
	Node<int>p=list1.remove(1);
	cout << "被删除节点的数据为：" << p.data << endl << "\n此时list1的数据为：" << endl;
	list1.show();
	
	cout << "\n在链表list1头和尾插入数据32" << endl << "\n此时list1的数据为：" << endl;
	list1.insertAtFirst(32);
	list1.insertAtLast(32);
	list1.show();
	
	cout << "\n对双向链表list2进行操作：" << endl;
	list2.sort();//使链表list2有序
	if (!list2.empty())
	{
		cout << "list2 不为空链表" << endl;
	}
	cout << "list2 的节点数为:" << list2.size() << endl;
	cout << "\n打印list2的节点内容" << endl;
	list2.show();

	cout << "\n拼接list1和list2" << endl;

	cout << "合并链表list1和list2，排序后打印数据：" << endl;
	list1.merge(list2);
	list1.sort();
	list1.show();

	return 0;
}
