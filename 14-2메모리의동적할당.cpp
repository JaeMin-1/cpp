#include <iostream>
using namespace std;

void f(int* p) { // =f(int p[])
	p[0] = 10;   // =*(p+0)  p에다가 0을 더한 주소가 가리키는 값은 10이다 라는 뜻
	p[1] = 20;
	p[2] = 30;
}

int main() {
	int a[3] = { 0 };
	
	cout << (a == &a[0]) << endl;
	f(a);    // =f(&a[0]);
	cout << "a[0] : " << a[0] << endl;
	cout << "a[1] : " << a[1] << endl;
	cout << "a[2] : " << a[2] << endl;
	

}