#include "String.h"

char& String::operator[](int index)const
{
	return this->cString[index];
}

int getLength(const char* string)
{
	if (!string)
	{
		return 0;
	}
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}

int getLength(const String& string)
{
	if (!string.cString)
	{
		return 0;
	}
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}

String& String::operator=(const String& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	if (!rhs.cString)
	{
		if (this->cString)
		{
			delete[] this->cString;
			this->cString = nullptr;
			this->allocated = 0;
		}
		return *this;
	}
	int size = getLength(rhs);
	if (this->cString && size + 1 > allocated)
	{
		delete[] this->cString;
	}
	if (!this->cString)
	{
		this->cString = new char[size + 1];
		allocated = size + 1;
	}
	for (int i = 0; i < size; i++)
	{
		this->cString[i] = rhs[i];
	}
	this->cString[size] = '\0';
	return *this;
}

String& String::operator=(String* rhs)
{
	if (this == rhs)
	{
		return *this;
	}
	if (!rhs->cString)
	{
		if (this->cString)
		{
			delete[] this->cString;
			this->cString = nullptr;
			this->allocated = 0;
		}
		delete rhs;
		return *this;
	}
	int size = getLength(*rhs);
	if (this->cString && size + 1 > allocated)
	{
		delete[] this->cString;
	}
	if (!this->cString)
	{
		this->cString = new char[size + 1];
		allocated = size + 1;
	}
	for (int i = 0; i < size; i++)
	{
		this->cString[i] = (*rhs)[i];
	}
	this->cString[size] = '\0';
	deleteString(*rhs);
	delete rhs;
	return *this;
}

String& String::operator=(const char* rhs)
{
	if (!rhs)
	{
		if (this->cString)
		{
			delete[] this->cString;
			this->cString = nullptr;
			this->allocated = 0;
		}
		return *this;
	}
	int size = getLength(rhs);
	if (this->cString && size + 1 > allocated)
	{
		delete[] this->cString;
	}
	if (!this->cString)
	{
		this->cString = new char[size + 1];
		allocated = size + 1;
	}
	for (int i = 0; i < size; i++)
	{
		this->cString[i] = rhs[i];
	}
	this->cString[size] = '\0';
	return *this;
}

String* operator+(const String& lhs, const String& rhs)
{
	int size1 = getLength(lhs);
	int size2 = getLength(rhs);
	char* newString = new char[size1 + size2 + 1];
	if (lhs.cString)
	{
		for (int i = 0; i < size1; i++)
		{
			newString[i] = lhs[i];
		}
	}
	if (rhs.cString)
	{
		for (int i = size1; i < size1 + size2; i++)
		{
			newString[i] = rhs[i - size1];
		}
	}
	newString[size1 + size2] = '\0';
	String* result = new String;
	*result = newString;
	delete[] newString;
	return result;
}

String* operator+(const String& lhs, const char* rhs)
{
	String temp;
	temp = rhs;
	String* result = lhs + temp;
	deleteString(temp);
	return result;
}

String* operator+(const char* lhs, const String& rhs)
{
	String temp;
	temp = lhs;
	String* result = temp + rhs;
	deleteString(temp);
	return result;
}

bool operator==(const String& lhs, const String& rhs)
{
	int size = getLength(lhs);
	if (size != getLength(rhs))
	{
		return false;
	}
	if (!lhs.cString && !rhs.cString)
	{
		return true;
	}
	if (!lhs.cString && rhs.cString || lhs.cString && !rhs.cString)
	{
		return false;
	}
	for (int i = 0; i <= size; i++)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}
	return true;
}

bool operator==(const char* lhs, const String& rhs)
{
	String temp;
	temp = lhs;
	bool result = temp == rhs;
	deleteString(temp);
	return result;
}

bool operator==(const String& lhs, const char* rhs)
{
	String temp;
	temp = rhs;
	bool result = lhs == temp;
	deleteString(temp);
	return result;
}

void allocate(String& string, int size)
{
	if (size < 1)
	{
		if (string.cString)
		{
			delete[] string.cString;
			string.cString = nullptr;
			string.allocated = 0;
		}
		return;
	}
	if (size != string.allocated)
	{
		char* temp = new char[size];
		if (string.cString)
		{
			for (int i = 0; i < size - 1; i++)
			{
				temp[i] = string[i];
			}
			temp[size - 1] = '\0';
			delete[] string.cString;
		}
		string.cString = temp;
		string.allocated = size;
	}
	return;
}

bool isEmpty(const String& string)
{
	return !string.cString;
}

void deleteString(String& string)
{
	if (!isEmpty(string))
	{
		delete[] string.cString;
		string.allocated = 0;
	}
	return;
}

char* convertToCString(const String& string)
{
	if (!string.cString)
	{
		return nullptr;
	}
	int size = getLength(string) + 1;
	char* result = new char[size];
	for (int i = 0; i < size; i++)
	{
		result[i] = string[i];
	}
	return result;
}

String* clone(const String& string)
{
	String* copy = new String;
	*copy = string;
	return copy;
}

String* getSubstring(const String& string, int index, int length)
{
	if (!string.cString || index + length > getLength(string))
	{
		return nullptr;
	}
	String* subString = new String;
	subString->cString = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		(*subString)[i] = string[index + i];
	}
	(*subString)[length] = '\0';
	return subString;
}