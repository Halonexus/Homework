#pragma once

class MyString
{	
	int allocated;
	char* string;
public:		
	MyString();
	MyString(const char*);
	MyString(const MyString& input);
	void allocate(const int);
	~MyString();
	int length()const;
	char*const cpyStr()const;
	friend MyString operator +(const MyString&, const char*);
	friend MyString operator +(const MyString&, const MyString&);
	friend bool operator ==(const MyString&, const MyString&);
	friend bool operator ==(const MyString&, const char*);
	bool isNull()const;
	char& operator [](const int&)const;
	MyString& operator =(const MyString&);
	MyString& operator =(const char*);
	void insert(const int index, const char*);
	void insert(const int index, const MyString&);
	void remove(const int index, const int amount = 1);
	void reverse(const int = 0, const int = -1);
};