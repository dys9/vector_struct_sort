#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <algorithm>
#define SIZE 20

using namespace std;

typedef struct 구조체
{
	string name;
	int seq;
}Data;

class Vector
{
public:
	vector<Data> m_vector_data;
	Vector(string _str)
	{
		srand(time(NULL));
		for (int i = 0; i < SIZE; i++)
		{
			m_vector_data.push_back(Data{ _str, rand() % 100 });
		}
	}

	void PrintAll()
	{
		for (auto iter : m_vector_data)
		{
			cout << iter.name << ", " << iter.seq << endl;
		}
	}

	static bool cmp(Data const& a, Data const& b) {
		if (a.seq != b.seq)
		{
			return a.seq < b.seq;
		}
		return a.name < b.name;
	}
};



int main()
{
	Vector vvector("Name");

	sort(vvector.m_vector_data.begin(), vvector.m_vector_data.end(), vvector.cmp);
	vvector.PrintAll();

	return 0;
}