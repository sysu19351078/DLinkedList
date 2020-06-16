#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"node.h"
#include"DLinkedList.h"
using namespace std;

int main()
{
	DLinkedList<int> list1, list2;			//��������˫������
	
	ifstream myfile;
	myfile.open("IntegerData.txt");//���롰IntegerData.txt��
	if (myfile.fail())
	{
		cout << "�����ļ�ʧ�ܣ�" << endl;
		return -1;
	}
	else
	{
		cout << "�����ļ��ɹ���" << endl;
	}
	string str, text;
	while (getline(myfile, str))			//��ȡ����
	{
		text += str;
	}
	auto start = text.find("number");
	start = text.find_first_of(":", start+1);
	while (start != string::npos)
	{
		string tnum(text, start + 1, 2);
		int num = stod(tnum);
		list1.insertAtLast(num);			//�����ݲ����list1
		start = text.find_first_of(":", start + 1);
	}

	ifstream myfile2;
	myfile2.open("Merge.txt");				//�򿪵ڶ����ļ�
	if (myfile2.fail())
	{
		cerr << "�����ļ�ʧ�ܣ�" << endl;
		return -1;
	}
	else
	{
		cout << "�����ļ��ɹ�!" << endl;
	}

	string test;
	while (getline(myfile2, str))			//��ȡ����
	{
		test += str;
	}
	start = test.find("number");
	start = test.find_first_of(":", start + 1);
	while (start != string::npos)
	{
		string tnum(test, start + 1, 2);
		int num = stod(tnum);
		list2.insertAtLast(num);			//�����ݲ����list
		start = test.find_first_of(":", start + 1);
	}

	cout << "\n��˫������list1���в�����" << endl;
	if (!list1.empty())
	{
		cout << "list1 ��Ϊ������" << endl;
	}
	cout << "list1 �Ľڵ���Ϊ:" << list1.size() << endl;
	cout << "\n��ӡlist1�Ľڵ�����" << endl;
	list1.show();
	cout << "\n��תlist1����ӡ������" << endl;
	list1.reverse();
	list1.show();
	
	cout <<"\nɾ��list1��1���ڵ㣬����ӡ������"<< endl;
	Node<int>p=list1.remove(1);
	cout << "��ɾ���ڵ������Ϊ��" << p.data << endl << "\n��ʱlist1������Ϊ��" << endl;
	list1.show();
	
	cout << "\n������list1ͷ��β��������32" << endl << "\n��ʱlist1������Ϊ��" << endl;
	list1.insertAtFirst(32);
	list1.insertAtLast(32);
	list1.show();
	
	cout << "\n��˫������list2���в�����" << endl;
	list2.sort();//ʹ����list2����
	if (!list2.empty())
	{
		cout << "list2 ��Ϊ������" << endl;
	}
	cout << "list2 �Ľڵ���Ϊ:" << list2.size() << endl;
	cout << "\n��ӡlist2�Ľڵ�����" << endl;
	list2.show();

	cout << "\nƴ��list1��list2" << endl;

	cout << "�ϲ�����list1��list2��������ӡ���ݣ�" << endl;
	list1.merge(list2);
	list1.sort();
	list1.show();

	return 0;
}
