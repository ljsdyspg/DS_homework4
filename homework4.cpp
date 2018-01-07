#include "hashtable.h"
#include "StuInfo.h"
#include <iostream>
#include <fstream>

void main()
{
	HashTable<StuInfo, int> stu(11);
	char file[20];
	char c;
	bool filecheck=false;
	do {
		cout << endl;
		cout << "I.��һ���ı��ļ����������¼������ɢ�б�"<<endl;
		cout << "F.��������ʾ����ѧ�ŵ�ѧ����¼"<<endl;
		cout << "A.����һ����¼"<<endl;
		cout << "D.ɾ��һ����¼"<<endl;
		cout << "P.��Ļ��ʾѧ�������¼��"<<endl;
		cout << "S.����ѧ�������¼��"<<endl;
		cout << "X.�˳�"<<endl;
		cout << "����ǰ����ĸ��ѡ���Ӧ���ܣ�";
		cin >> c;
		cout << endl;

		switch (c)
		{
		case'I':case 'i':{
			cout << "�����ı��ļ����Ե����¼(Ĭ��Ϊ�� StuInfo.txt)��";
			cin >> file;
			ifstream inFile;
			inFile.open(file);
			int numb;
			char name[30];
			char sex[30];
			char home[30];
			while (inFile >> numb >> name >> sex >> home)
			{
				StuInfo temp(numb, name, sex, home);
				stu.Insert(temp);
			}
			inFile.close();
			cout << "��ȡ���" << endl;
			filecheck = true;
			break;
		}
		case'F':case'f': {
			int numb, pos;
			cout << "�����������ѧ����ѧ�ţ�";
			cin >> numb;
			StuInfo temp;
			if (stu.Find(numb, temp, pos) == Success)
			{
				cout << "�����ɹ�" << endl;
				cout << temp;
			}
			else
				cout << "����ʧ��" << endl;
			break;

		}
		case'A':case'a': {
			int no;
			char name[10], sex[10], home[30];
			cout << "��������һ��ѧ��ѧ�ţ��������Ա�ͼ��᣺";
			cin >> no >> name >> sex >> home;
			StuInfo temp(no, name, sex, home);
			if (stu.Insert(temp) == Success)
				cout << "����ɹ�";
			else
				cout << "����ʧ��";
			break;
		}
		case'D': case'd':{
			int numb;
			StuInfo temp;
			cout << "�������ɾ��ѧ��ѧ�ţ�";
			cin >> numb;
			if (stu.Remove(numb, temp) == Success)
				cout << "ɾ���ɹ� ��ɾ��ѧ���� " << temp;
			else
				cout << "ɾ��ʧ��";
			break;
		}
		case'P': case'p':{
			if (filecheck == true) {
				cout << "ѧ�������¼��" << endl;
				stu.Print();
			}
			else cout << "���ļ����밴I�����ļ�"<<endl;
			break;
		}
		case'S': case's':{
			ofstream outFile;
			outFile.open(file);
			for (int i = 0; i < stu.M; i++)
			{
				if (stu.ht[i] != NeverUsed)
					outFile << stu.ht[i].No << " " << stu.ht[i].Name << " " << stu.ht[i].Sex << " " << stu.ht[i].Home << endl;
			}
			outFile.close();	
			cout << "�������!"<<endl;
			break;
		}
		default:
			cout << "�������" << endl; break;
		}
	} while (c != 'X'&&c!='x');
	return;
}

