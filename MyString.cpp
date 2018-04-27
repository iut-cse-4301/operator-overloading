#include "MyString.h"

void MyString::str_cpy(char * temp_str, int size) {
	this->str = new char[this->size];
	for (int i = 0; i < this->size; i++) {
		this->str[i] = temp_str[i];
	}
	this->str[this->size - 1] = '\0';
}

void MyString::str_cat(char * temp_str, int size) {
	MyString ob(this->str);
	this->str = new char[this->size + size - 1];
	this->size += size - 1;
	for (int i = 0; i < ob.size - 1; i++) {
		this->str[i] = ob.str[i];
	}
	int i, j;
	for (i = ob.size - 1, j = 0; i < this->size - 1, j < size - 1; i++, j++) {
		this->str[i] = temp_str[j];
	}
	this->str[this->size - 1] = '\0';
}


MyString::MyString()
{
	this->str = new char[1];
	this->str[0] = '\0';
	this->size = 1;
}

MyString::MyString(char* temp_str) {
	int len = strlen(temp_str);
	this->size = len + 1;
	this->str_cpy(temp_str, this->size);
}

MyString::MyString(const MyString &ob) {
	this->size = ob.size;
	this->str_cpy(ob.str, this->size);
}

MyString MyString::operator+(MyString ob) {
	MyString ob2(this->str);
	ob2.str_cat(ob.str, ob.size);
	return ob2;
}

MyString MyString::operator+(char* temp_str) {
	MyString ob2(this->str);
	ob2.str_cat(temp_str, strlen(temp_str) + 1);
	return ob2;
}

MyString MyString::operator+(const char* temp_str) {
	MyString ob2(this->str);
	ob2.str_cat((char*)temp_str, strlen(temp_str) + 1);
	return ob2;
}

MyString MyString::operator+=(MyString ob) {
	this->str_cat(ob.str, ob.size);
	return *this;
}

MyString MyString::operator+=(char* temp_str) {
	this->str_cat(temp_str, strlen(temp_str) + 1);
	return *this;
}

MyString MyString::operator+=(const char* temp_str) {
	this->str_cat((char*)temp_str, strlen(temp_str) + 1);
	return *this;
}


MyString MyString::operator=(MyString ob) {
	this->size = ob.size;
	this->str_cpy(ob.str, this->size);
	return *this;
}

MyString MyString::operator=(char* temp_str) {
	this->size = strlen(temp_str) + 1;
	this->str_cpy(temp_str, this->size);
	return *this;
}

MyString MyString::operator=(const char* temp_str) {
	this->size = strlen(temp_str) + 1;
	this->str_cpy((char*)temp_str, this->size);
	return *this;
}

bool MyString::operator==(MyString ob) {
	return strcmp(this->str,ob.str)==0?true:false;
}

bool MyString::operator==(char* temp_str) {
	return strcmp(this->str, temp_str) == 0 ? true : false;
}

bool MyString::operator==(const char* temp_str) {
	return strcmp(this->str, temp_str) == 0 ? true : false;
}

bool MyString::operator<(MyString ob) {
	return strcmp(this->str, ob.str) < 0 ? true : false;
}

bool MyString::operator<(char* temp_str) {
	return strcmp(this->str, temp_str) < 0 ? true : false;
}

bool MyString::operator<(const char* temp_str) {
	return strcmp(this->str, temp_str) < 0 ? true : false;
}


bool MyString::operator>(MyString ob) {
	return strcmp(this->str, ob.str) > 0 ? true : false;
}

bool MyString::operator>(char* temp_str) {
	return strcmp(this->str, temp_str) > 0 ? true : false;
}

bool MyString::operator>(const char* temp_str) {
	return strcmp(this->str, temp_str) > 0 ? true : false;
}


//for ++ operator, we are demonstrating it by repeatig the last character in the string once

//increment then assignment [ ob = ++ob1; ]
MyString MyString::operator++() {
	MyString ob = *this;
	char *c = new char[2];
	c[0] = ob.str[ob.size - 2];
	c[1] = '\0';
	this->str_cat(c, 2);
	return *this;
}

//assignment then increment  [ ob = ob1++; ]
MyString MyString::operator++(int notused) {
	MyString ob = *this;
	char *c = new char[2];
	c[0] = ob.str[ob.size - 2];
	c[1] = '\0';
	this->str_cat(c, 2);

	return ob;
}




void MyString::print_str() {
	cout << this->str << endl;
}
MyString::~MyString()
{
	delete[] str;
}
