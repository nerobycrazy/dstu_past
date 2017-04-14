// nas.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
class B1{
	B1();
	~B1();
};
class B2{
	B2();
	~B2();
};
class D1 : public B1, public B2{
public:
	D1();
	~D1();
};


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

