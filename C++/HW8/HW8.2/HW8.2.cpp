#include <cstdio>
#include "String.h"

int main()
{
	//test
	String a, b, c, d, e;
	allocate(c, 256);
	a = "aaa";
	b = "bbbbb" + a;
	c = a + b;
	c = c + "cccccccccc";
	c = d + c;
	c = c + c;
	d = getSubstring(c, 4, 7);
	e = clone(d);
	fputs(("bbbbbaaa" == b) ? "true\n" : "false\n", stdout);
	char* temp = convertToCString(a);
	if (temp)
	{
		fputs(temp, stdout);
		fputs("\n", stdout);
		delete[] temp;
	}
	temp = convertToCString(b);
	if (temp)
	{
		fputs(temp, stdout);
		fputs("\n", stdout);
		delete[] temp;
	}
	temp = convertToCString(c);
	if (temp)
	{
		fputs(temp, stdout);
		fputs("\n", stdout);
		delete[] temp;
	}
	temp = convertToCString(d);
	if (temp)
	{
		fputs(temp, stdout);
		fputs("\n", stdout);
		delete[] temp;
	}
	temp = convertToCString(e);
	if (temp)
	{
		fputs(temp, stdout);
		fputs("\n", stdout);
		delete[] temp;
	}
	deleteString(a);
	deleteString(b);
	deleteString(c);
	deleteString(d);
	deleteString(e);
	return 0;
}