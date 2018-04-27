#include<iostream>
#include "MyString.h"

using namespace std;

int main() {
	char* pt = new char[4];
	pt[0] = 'A';
	pt[1] = 'B';
	pt[2] = 'C';
	pt[3] = '\0';

	MyString ob1(pt);

	pt[0] = 'D';
	pt[1] = 'E';
	pt[2] = 'F';
	pt[3] = '\0';
	MyString ob2(pt);

	ob1.print_str();
	ob2.print_str();

	MyString ob3 = ob1 + ob2 + ob1;
	ob3.print_str();
	ob1.print_str();
	ob2.print_str();

	///if <'void' operator=(MyString ob)> then, ob2 cannot assign values to ob3. Since, <operator=(MyString ob)> returns a value, thus it is further assigned to ob3
	ob3 = ob2 = ob1 = pt;
	ob2.print_str();

	///The following is an Object Assignment. This is not a = operator overloading;
	MyString ob4 = ob3;
	ob4 = ob4 + " executed";
	ob4.print_str();


	ob4 += ob3 + "ABC";
	ob4.print_str();

	ob1 = "ABC";
	ob2 = "ABC";
	ob3 = "DEF";

	if (ob1 == ob2) {
		cout << "ob1 == ob2 [ ABC == ABC ]\n";
	}
	if (ob2 < ob3) {
		cout << "ob2 < ob3 [ ABC < DEF ]\n";
	}
	else if (ob2 > ob3) {
		cout << "ob2 > ob3 [ ABC > DEF ]\n";
	}

	ob2=++ob1;
	ob1.print_str();
	ob2.print_str();


	ob3 = ob1++;
	ob1.print_str();
	ob3.print_str();

	getchar();

	return 0;
}