#pragma once
#include<cstring>
#include<iostream>
using namespace std;
class MyString
{
	char * str;
	int size;
	void str_cpy(char* temp_str,int size);
	void str_cat(char* temp_str, int size);
public:
	MyString();
	MyString(char* temp_str);
	MyString(const MyString &ob);
	
	MyString operator+(MyString ob);
	MyString operator+(char* temp_str);
	MyString operator+(const char* temp_str);

	MyString operator+=(MyString ob);
	MyString operator+=(char* temp_str);
	MyString operator+=(const char* temp_str);

	MyString operator=(MyString ob);
	MyString operator=(char* temp_str);
	MyString operator=(const char* temp_str);

	bool operator==(MyString ob);
	bool operator==(char* temp_str);
	bool operator==(const char* temp_str);

	bool operator<(MyString ob);
	bool operator<(char* temp_str);
	bool operator<(const char* temp_str);

	bool operator>(MyString ob);
	bool operator>(char* temp_str);
	bool operator>(const char* temp_str);

	MyString operator++();
	MyString operator++(int notused);
	
	void print_str();
	~MyString();
};

