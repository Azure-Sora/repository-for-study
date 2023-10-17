#include<iostream>
using namespace std;

template<typename T> 
T bigger(T num1, T num2)
{
	return num1 > num2 ? num1 : num2;
}

template<class T>
T max(T arr[], int n)
{

}

int main()
{

	cout << bigger(1, 2) << endl << bigger(0.5, 2.3);

	return 0;
}