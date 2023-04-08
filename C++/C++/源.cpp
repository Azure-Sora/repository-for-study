#include<iostream>
using namespace std;

class Circle
{
private:
	double r;
public:
	void setR(double r)
	{
		this->r = r;
	}
	double getR() 
	{
		return this->r;
	}
};

int main()
{
	Circle yuan{};
	yuan.setR(10);
	cout << yuan.getR();

	return 0;
}

