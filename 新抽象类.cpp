#include "pch.h"
#include <iostream>
using namespace std;
class qqq {
	public:
		qqq() = default;
		qqq(const int a) :b(a) {}
		virtual int p() const = 0;
	private:
		int b = 0;
};
class www:public qqq {
public:
	www() = default;
	www(const int c) :d(c) {}
	int p() const override;
private:
	int d = 0;
};
int main()
{
	www s;
	return 0;
}