#pragma once
#include<iostream>
using namespace std;
class animal
{
public:
	virtual void eat()const { cout << " animal"; };
	virtual void drink()const { cout << " animal"; };;
	virtual void run()const { cout << " animal"; };;
};
class pig :public animal
{
public:
	void eat();
	void drink();
	void run();
};
void pig::eat()
{
	cout << "I'm pig.I can eat" << endl;
}
void pig::drink()
{
	cout << "I'm pig.I can drink" << endl;
}
void pig::run()
{
	cout << "I'm pig.I can run" << endl;
}