#pragma once
#include<iostream>
using namespace std;
class StuInfo {
public:
	int No;
	char Name[10];
	char Sex[10];
	char Home[30];
	void setInfo(int no, char name[], char sex[], char home[]) {
		No = no;
		strcpy_s(Name, name);
		strcpy_s(Sex, sex);
		strcpy_s(Home, home);
	}
public:
	operator int&() {            //类型转换符重载
		return No;
	}
	StuInfo() {};
	StuInfo(int no, char name[], char sex[], char home[]) {
		setInfo(no, name, sex, home);
	}
	StuInfo& operator=(StuInfo& sour) {
		if (this == &sour)return *this;
		setInfo(sour.No, sour.Name, sour.Sex, sour.Home);
		return *this;
	}
	friend ostream& operator <<(ostream& out, const StuInfo &s);
};
ostream& operator <<(ostream& out, const StuInfo &s) {
	out << s.No << " " << s.Name << " " << s.Sex << " " << s.Home << endl;
	return out;
}