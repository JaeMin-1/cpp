#include <iostream>
using namespace std;

void sub1(int a[]) {
	a += 1;
	*a = 1;
}
void sub2(int* a) {
	a += 1;
	*a = 2;
}

int main() {
	int a[] = { 10,20,30,40,50 };

	cout << "&a[0] = " << &a[0] << endl;  //a[0]의 4바이트 메모리중 가장 앞의 1바이트 메모리 주소 출력(4칸중 가장 첫번째칸 주소)
	cout << "&a[1] = " << &a[1] << endl;  //a[1]의 ~동일
	cout << "&a[2] = " << &a[2] << endl;  //a[2]의 ~동일
	//int는 4바이트이기때문에 a[0] a[1] a[2] 의 각 주소의 차이는 4씩차이난다

	cout << "a = " << a << endl;          //전체 배열 a = a[0]의 주소 출력 즉 시작주소 출력
	cout << "a + 1 = " << a + 1 << endl;  //a+1은 a의 다음 주소이기때문에 1차이가 나지만 실제 주소값은 int형이기때문에 4차이가 난다.
	cout << "*a = " << *a << endl;        //a[0]의 주소가 가리키는 곳, 즉 a[0]의 값 10을 출력

	int iarr[20], *ip = iarr;             //ip는 iarr의 주소, 즉 ip = &iarr
	cout << "ip : " << ip << endl;        //iarr[0]의 주소값이 출력됨

	char carr[20] = "characters", * cp = carr;
	cout << "cp : " << cp << endl;        //이때  char형의 경우는 주소값이 출력되지 않고 그 주소부터의 문자열을 출력해서 보여줌
	cout << "(void *)cp: " << (void*)cp << endl; //char형은 이렇게 입력해야 주소값이 출력된다.
	cout << *(cp + 1) << endl << endl;                   //두번째 문자열인 h가 출력된다. cp+1이라는 주소값이 가리키는 곳이 h이다.

	int b[10];
	sub1(b);
	cout << b[1] << endl;
	sub2(b);
	cout << b[1] << endl;

	//동적메모리는 new와 delete 키워드 사용
	int* p;                //동적 메모리를 가리키는 포인터

	p = new int;           //1.동적메모리 할당  

	*p = 100;              //2.동적메모리 사용   //p는 100의 주소값을 저장함(즉 *p = p에 저장된 주소가 가리키는 곳 = 100)

	delete p;              //3.동적메모리 반납

	int* q = new int;      //반납된 메모리를 재사용할 수 있음
	return 0;
}

int get_sum1(int a[], int n) {
	int i;
	int sum = 0;

	for (i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

//위와 같은 인덱스 표기법 사용보단 밑과 같이 포인터를 사용한 for문이 더 빠르다. p값이 자동적으로 주소를 갖고있기 때문이다. a[i]는 매번 그때그때 주소찾아야댐.
int get_sum2(int a[], int n) {
	int i;
	int* p;
	int sum = 0;

	p = a;
	for (i = 0; i < n; i++)
		sum += *p++;
	return sum;
}