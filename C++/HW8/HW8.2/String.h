#pragma once

struct String
{
	char* cString = nullptr;
	int allocated = 0;
	String& operator=(const String&);
	String& operator=(String*);
	String& operator=(const char*);
	char& operator[](int)const;
};

String* operator+(const String&, const String&);
String* operator+(const String&, const char*);
String* operator+(const char*, const String&);
bool operator==(const String&, const String&);
bool operator==(const char*, const String&);
bool operator==(const String&, const char*);
void allocate(String&, int);
char* convertToCString(const String&);
void deleteString(String&);
String* clone(const String&);
int getLength(const String&);
bool isEmpty(const String&);
String* getSubstring(const String&, int index, int length);