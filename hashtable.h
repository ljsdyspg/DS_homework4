#pragma once
#include<iomanip>
#include"StuInfo.h"
using namespace std;
enum ResultCode {Underflow, Overflow,	Success, Duplicate, NotPresent};

int h1(int key) {
	return(key % 11);
}
int h2(int key) {
	return(key % 9 + 1);
}

StuInfo NeverUsed(-1, "null", "null", "null");

template<class T, class K>
class HashTable
{
public:
	HashTable(int divisor);
	~HashTable() { delete[]ht; delete[] empty; }
	ResultCode Insert(T &x);
	ResultCode Remove(K key, T &x);
	void Print();
	ResultCode Find(K key, T &x, int& pos);
	int M;
	T *ht;
	bool* empty;
};

template <class T, class K>
HashTable<T, K>::HashTable(int divitor)
{
	int i;
	M = divitor;
	ht = new T[M]; empty = new bool[M];
	for (i = 0; i < M; i++) empty[i] = true;
	for (i = 0; i < M; i++) ht[i] = NeverUsed;
}

template <class T, class K>
ResultCode HashTable<T, K>::Find(K key, T &x, int& pos)
{
	int k1, k2;
	k1 = h1(key);
	k2 = h2(key);
	int j = 0;
	do {
		if (empty[k1] || ht[k1] == key)break;
		k1 = k1 + k2;
		k2 = k2%M;
		j++;
	} while (j < M);
	if (ht[k1] == key) {
		x = ht[k1];
		pos = k1;
		return Success;
	}
	return NotPresent;
}

template <class T, class K>
ResultCode HashTable<T, K>::Insert(T &x)
{
	int key = x;
	int k1 = h1(key);
	int k2 = h2(key);
	int j = 0;
	do {
		if (ht[k1] == key)
			return Duplicate;
		if (ht[k1] == NeverUsed) {
			ht[k1] = x;
			empty[k1] = false;
			return Success;
		}
		k1 += k2;
		k1 %= M;
		j++;
	} while (j <= M);
	return Overflow;
}

template <class T, class K>
ResultCode HashTable<T, K>::Remove(K key, T& x)
{
	int pos;
	if (Find(key, x, pos) == Success) {
		ht[pos] = NeverUsed;
		return Success;
	}
	return NotPresent;
}

template <class T, class K>
void  HashTable<T, K>::Print()
{
	for (int i = 0; i < M; i++)
		if (ht[i] != NeverUsed)
			cout << ht[i];

}