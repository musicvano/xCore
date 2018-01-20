#include "stdafx.h"

#include <Windows.h>
#include <vector>
#include "xCore/Vector.h"
using namespace std;
using namespace xCore;

class Obj
{
public:
	Obj()
	{
		cout << "Constructor" << endl;
	};

	Obj(Obj &&obj)
	{
		cout << "Move Constructor" << endl;
	};

	Obj(const Obj &obj)
	{
		cout << "Copy Constructor" << endl;
	};

	~Obj()
	{
		cout << "Destructor" << endl;
	};

	Obj & operator=(Obj &&obj)
	{
		cout << "Assign &&obj" << endl;
		if (this != &obj)
			a = obj.a;
		return *this;
	};

	Obj & operator=(const Obj &obj)
	{
		cout << "Assign &obj" << endl;
		if (this != &obj)
			a = obj.a;
		return *this;
	};

	int a = 100;
	int b = 100;
};

int main()
{
	const usize COUNT = 5;
	DWORD t0 = GetTickCount();

	Vector<int> v1;
	for (usize i = 0; i < COUNT; i++)
	{
		v1.Add(rand());
	}
	
	DWORD t1 = GetTickCount();

	vector<int> v2;
	for (usize i = 0; i < COUNT; i++)
	{
		v2.push_back(rand());
	}

	DWORD t2 = GetTickCount();

	cout << v1.Last() << endl;
	cout << v2.back() << endl;

	cout << "xCore Vector time: " << t1 - t0 << " ms\n";
	cout << "Std vector time: " << t2 - t1 << " ms\n";

	return 0;
}