#include "MyString.h"

int getLength(const char* string)
{
	int count = 0;
	if (string)
	{
		while (string[count] != '\0')
		{
			count++;
		}
	}
	return count;
}

MyString::MyString()
{
	string = nullptr;
	allocated = 0;
}

MyString::MyString(const char* input)
{
	if (!input)
	{
		string = nullptr;
		allocated = 0;
	}
	else
	{
		int count = getLength(input);
		string = new char[count + 1];
		for (int i = 0; i < count; i++)
		{
			string[i] = input[i];
		}
		string[count] = '\0';
		allocated = count + 1;
	}
}

MyString::MyString(const MyString& input)
{
	if (input.isNull())
	{
		string = nullptr;
	}
	else
	{
		int count = input.length();
		string = new char[count + 1];
		for (int i = 0; i < count; i++)
		{
			string[i] = input[i];
		}
		string[count] = '\0';
		allocated = count + 1;
	}
}

void MyString::allocate(const int size)
{
	if (allocated == size)
	{
		return;
	}
	allocated = size;
	if (string)
	{
		char* oldString = string;
		string = new char[size];
		int i = 0;
		while ((oldString[i] != '\0') && (i + 1 < size))
		{
			string[i] = oldString[i];
		}
		string[i] = '\0';
		delete[] oldString;
		return;
	}
	string = new char[size];
	string[0] = '\0';
	return;
}

MyString::~MyString()
{
	if (string)
	{
		delete[] string;
	}
}

char*const MyString::cpyStr()const
{
	char* newString = new char[length() + 1];
	int i = 0;
	while (string[i] != '\0')
	{
		newString[i] = string[i];
		i++;
	}
	newString[i] = '\0';
	return newString;
}

MyString& MyString::operator=(const char* input)
{	
	if (!input)
	{
		if (string)
		{
			delete[] string;
			string = nullptr;
		}		
		return *this;
	}
	int count = getLength(input);
	if (string && (count + 1 > allocated))
	{
		delete[] string;
	}
	if (!string || (count + 1 > allocated))
	{
		allocated = count + 1;
		string = new char[allocated];
	}
	for (int i = 0; i < count; i++)
	{
		string[i] = input[i];
	}
	string[count] = '\0';
	return *this;
}

MyString& MyString::operator=(const MyString& input)
{
	if (this == &input)
	{
		return *this;
	}
	if (!input.string)
	{
		if (string)
		{
			delete[] string;
			string = nullptr;
		}
		return *this;
	}
	int length = input.length();
	if (string && (length + 1 > allocated))
	{
		delete[] string;
	}
	if (!string || (length + 1 > allocated))
	{
		allocated = length + 1;
		string = new char[allocated];
	}
	for (int i = 0; i < length; i++)
	{
		string[i] = input[i];
	}
	string[length] = '\0';
	return *this;
}

inline char& MyString::operator[](const int& index) const
{
	return  string[index];
}

MyString operator+(const MyString& string1, const MyString& string2)
{
	int length1 = string1.length();
	int length2 = string2.length();	
	char* newString = new char[length1 + length2 + 1];
	for (int i = 0; i < length1; i++)
	{
		newString[i] = string1[i];
	}
	for (int i = length1; i < length1 + length2; i++)
	{
		newString[i] = string2[i - length1];
	}
	newString[length1 + length2] = '\0';
	MyString temp = newString;
	delete[] newString;
	return temp;
}

MyString operator+(const MyString& string1, const char* string2)
{
	int length1 = string1.length();
	int length2 = getLength(string2);
	char* newString = new char[length1 + length2 + 1];
	for (int i = 0; i < length1; i++)
	{
		newString[i] = string1[i];
	}
	for (int i = length1; i < length1 + length2; i++)
	{
		newString[i] = string2[i - length1];
	}
	newString[length1 + length2] = '\0';
	MyString temp = newString;
	delete[] newString;
	return temp;
}

int MyString::length()const
{
	int count = 0;
	if (string)
	{
		while (string[count] != '\0')
		{
			count++;
		}
	}
	return count;
}

bool operator==(const MyString& string1,const MyString& string2)
{
	if (string1.isNull() && string2.isNull())
	{
		return true;
	}
	if (string1.isNull() || string2.isNull())
	{
		return false;
	}
	bool checking = true;
	int i = 0;
	while (checking)
	{
		if (string1[i] != string2[i])
		{			
			return false;
		}
		if (string1[i] == '\0')
		{
			checking = false;
		}
		i++;
	}
	return true;
}

bool operator==(const MyString& string1, const char* string2)
{
	if (string1.isNull() && (!string2))
	{
		return true;
	}
	if (string1.isNull() || (!string2))
	{
		return false;
	}
	bool checking = true;
	int i = 0;
	while (checking)
	{
		if (string1[i] != string2[i])
		{
			return false;
		}
		if (string1[i] == '\0')
		{
			checking = false;
		}
		i++;
	}
	return true;
}

inline bool MyString::isNull()const
{
	return string ? false : true;
}

void MyString::insert(const int index, const char* insertion)
{
	if (index > length() || !insertion)
	{
		return;
	}
	int newLength = length() + getLength(insertion) + 1;
	if (newLength > allocated)
	{
		allocated = newLength;
		char* temp = string;
		string = new char[newLength];
		int i = 0;
		for (i = 0; i < index; i++)
		{
			string[i] = temp[i];
		}
		int j = 0;
		while (insertion[j] != '\0') 
		{
			string[i++] = insertion[j++];						
		}
		j = index;
		for (i; i < newLength - 1; i++, j++)
		{
			string[i] = temp[j];
		}
		string[newLength - 1] = '\0';
		delete[] temp;
		return;
	}
	int stringLength = length();
	int moveLength = stringLength - index + 1;
	int moveStep = getLength(insertion);
	for (int i = 0; i < moveLength; i++)
	{
		string[stringLength - i + moveStep] = string[stringLength - i];
	}
	int j = 0;
	while (insertion[j] != '\0')
	{
		string[index + j] = insertion[j];
		j++;
	}
	return;
}

void MyString::insert(const int index, const MyString& insertion)
{
	if (index > length() || insertion.isNull())
	{
		return;
	}
	int newLength = length() + insertion.length() + 1;
	if (newLength > allocated)
	{
		allocated = newLength;
		char* temp = string;
		string = new char[newLength];
		int i = 0;
		for (i = 0; i < index; i++)
		{
			string[i] = temp[i];
		}
		int j = 0;
		while (insertion[j] != '\0')
		{
			string[i++] = insertion[j++];
		}
		j = index;
		for (i; i < newLength - 1; i++, j++)
		{
			string[i] = temp[j];
		}
		string[newLength - 1] = '\0';
		delete[] temp;
		return;
	}
	int stringLength = length();
	int moveLength = stringLength - index + 1;
	int moveStep = insertion.length();
	for (int i = 0; i < moveLength; i++)
	{
		string[stringLength - i + moveStep] = string[stringLength - i];
	}
	int j = 0;
	while (insertion[j] != '\0')
	{
		string[index + j] = insertion[j];
		j++;
	}
	return;
}

void MyString::remove(const int index, const int amount)
{
	int stringLength = length();
	if ((index >= stringLength) || (amount <= 0))
	{
		return;
	}
	if (index + amount >= stringLength)
	{
		string[index] = '\0';
		return;
	}
	int moves = stringLength - index - amount + 1;
	for (int i = 0; i < moves; i++)
	{
		string[index + i] = string[index + i + amount];
	}
	return;
}

void MyString::reverse(const int index1, const int index2)
{
	int strLength = length();
	if (index1 < 0 || index1 > strLength - 1 || index2 > strLength - 1)
	{
		return;
	}
	int endIndex = index2;
	if (index2 == -1)
	{		
		endIndex = length() - 1;
	}
	else if (index2 < 0)
	{
		return;
	}
	int iterations = (endIndex + 1 - index1) / 2;
	if (iterations < 0)
	{
		iterations = -iterations;
	}
	for (int i = 0; i < iterations; i++)
	{
		char temp = string[index1 + i];
		string[index1 + i] = string[endIndex - i];
		string[endIndex - i] = temp;
	}
	return;
}