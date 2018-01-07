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
		cout << "I.从一个文本文件中输入各记录来建立散列表"<<endl;
		cout << "F.搜索并显示给定学号的学生记录"<<endl;
		cout << "A.插入一个记录"<<endl;
		cout << "D.删除一个记录"<<endl;
		cout << "P.屏幕显示学生情况记录表"<<endl;
		cout << "S.保存学生情况记录表"<<endl;
		cout << "X.退出"<<endl;
		cout << "输入前置字母，选择对应功能：";
		cin >> c;
		cout << endl;

		switch (c)
		{
		case'I':case 'i':{
			cout << "输入文本文件名以导入记录(默认为： StuInfo.txt)：";
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
			cout << "读取完成" << endl;
			filecheck = true;
			break;
		}
		case'F':case'f': {
			int numb, pos;
			cout << "请输入待搜索学生的学号：";
			cin >> numb;
			StuInfo temp;
			if (stu.Find(numb, temp, pos) == Success)
			{
				cout << "搜索成功" << endl;
				cout << temp;
			}
			else
				cout << "搜索失败" << endl;
			break;

		}
		case'A':case'a': {
			int no;
			char name[10], sex[10], home[30];
			cout << "依次输入一个学生学号，姓名，性别和籍贯：";
			cin >> no >> name >> sex >> home;
			StuInfo temp(no, name, sex, home);
			if (stu.Insert(temp) == Success)
				cout << "插入成功";
			else
				cout << "插入失败";
			break;
		}
		case'D': case'd':{
			int numb;
			StuInfo temp;
			cout << "请输入待删除学生学号：";
			cin >> numb;
			if (stu.Remove(numb, temp) == Success)
				cout << "删除成功 被删除学生是 " << temp;
			else
				cout << "删除失败";
			break;
		}
		case'P': case'p':{
			if (filecheck == true) {
				cout << "学生情况记录表：" << endl;
				stu.Print();
			}
			else cout << "无文件，请按I读入文件"<<endl;
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
			cout << "保存完成!"<<endl;
			break;
		}
		default:
			cout << "输入错误" << endl; break;
		}
	} while (c != 'X'&&c!='x');
	return;
}

