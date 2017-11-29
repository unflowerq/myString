#include "myString.h"
#include <cstring>
#include <cstdlib>//exit �Լ��� ����ϱ� ���� �������

myString::myString()
/*
*default constructor
*precondition : �ƹ� ���ڵ� ���� ���ƾ� �Ѵ�.
*postcondition : length�� 0�̰� cStr�� �ƹ� �͵� ����Ű�� �ʴ´�.
*/
{
	length = 0;
	cStr = NULL;
}

myString::myString(const char* s)
/*
*constructor
*precondition : ���ڰ� char�� �����Ͱ� ����Ű�� ��(���ڿ�)���� ���� �Ѵ�.  
*postcondition : length�� �ΰ��� ������ ����, cStr�� ���ڷ� ���� ���ڿ��� ����Ų��. 
*/
{
	length = strlen(s) + 1;
	cStr = new char[length];
	strcpy_s(cStr, length, s);
}

myString::myString(const myString& s)
/*
*copy constructor / deep copy
*precondition : ���ڷ� myString Ŭ������ ���۷����� ���� �Ѵ�.
*postcondition : ���۷����� ���� myString Ŭ������ length�� strcpy 
�޼ҵ带 �̿��Ͽ� �ش� ���ڿ��� �����ϰ� cStr�� ����Ų��.
*/
{
	length = s.length;
	cStr = new char[length];
	strcpy_s(cStr, length, s.cStr);
}

myString::~myString()
/*
*destructor
*precondition : �ش� ��ü�� �Ҹ��� �� ȣ��ȴ�.
*postcondition : �� ������ �޸𸮸� ��ȯ�ϰ� cStr�� �ƹ� �͵� ����Ű�� �ʴ´�.
*/
{
	if (cStr != NULL)
	{
		delete[] cStr;
		cStr = NULL;
	}
}

myString myString::operator+ (const myString& s)
/* 
*operator + //str1 + str2 
*precondition : + �����ڸ� ����Ͽ��� �� ȣ��Ǹ�, const myString�� ���۷����� ���ڷ� �޴´�.
*postcondition : ���� ��ü�� �����Ͽ� + ����� ���� �������� ���ڷ� �ְ� �� ��ü�� ���۷����� ��ȯ�Ѵ�.
*/
{
	int temp_length = length + s.length - 1;//������ length�� �ǵ帮�� �ȵȴ�.
	char* temp = new char[temp_length];

	strcpy_s(temp, temp_length, cStr);
	strcat_s(temp, temp_length, s.cStr);
	myString obj(temp);//���ο� ��ü�� �����Ͽ� ��ȯ

	delete[] temp;
	return obj;
}

myString& myString::operator= (const myString& s)
/*
*assignment operator = for deep copy / myString �Ӹ� �ƴ϶� ���ڿ��� ���� / chaining ����� �ִ�.
*precondition : const myString�� ���۷����� ���ڷ� �޴´�.
*postcondition : cStr�� ��� ���ڿ��� ����Ų�ٸ� �� �޸𸮸� ��ȯ���ְ�, ���۷����� ���� 
myString Ŭ������ length�� strcpy �޼ҵ带 �̿��Ͽ� �ش� ���ڿ��� �����ϰ� cStr�� ����Ű��
���� �� �ڽ��� ��ü ���۷����� ��ȯ�Ѵ�.
*/
{												 
	if (cStr != NULL)
		delete[] cStr;

	length = s.length;
	cStr = new char[length];
	strcpy_s(cStr, length, s.cStr);

	return *this;//chaining �� ������ �ϱ� ���� return
}

myString& myString::operator+= (const myString& s)
/*
*operator += / Append ���  
*precondition : const myString�� ���۷����� ���ڷ� �޴´�.
*postcondition : ���۷����� ���� myString Ŭ������ length�� �ڽ� ��ü�� length�� ���ϰ� 
���ο� �޸𸮿� ���� �� �ڽ��� ���ڿ��� ���ڷ� ���� myString Ŭ������ ���ڿ��� append�Ͽ� 
���� �� �ڽ��� ��ü ���۷����� ��ȯ�Ѵ�.
*/
{
	length += s.length - 1;
	char* temp = new char[length];

	strcpy_s(temp, length, cStr);
	strcat_s(temp, length, s.cStr);

	if (cStr != NULL)
		delete[] cStr;

	cStr = temp;

	return *this;//chaining �� ������ �ϱ� ���� return
}

bool myString::operator== (const myString& s)
/*
*precondition : const myString�� ���۷����� ���ڷ� �޴´�.
*postcondition : 0�� �ƴ� ���� ������ false , 0�̸� true�� �����Ѵ�.
*/
{
	return strcmp(cStr, s.cStr) ? false : true;
}
bool myString::operator!= (const myString& s)
/*
*precondition : const myString�� ���۷����� ���ڷ� �޴´�.
*postcondition : 0�� �ƴ� ���� ������ true , 0�̸� false�� �����Ѵ�.
*/
{
	return strcmp(cStr, s.cStr) ? true : false;
}
bool myString::operator< (const myString& s)
/*
*precondition : const myString�� ���۷����� ���ڷ� �޴´�.
*postcondition : -1�̸� true , �ƴϸ� false �����Ѵ�.
*/
{
	return strcmp(cStr, s.cStr) == -1 ? true : false;
}
bool myString::operator> (const myString& s)
/*
*precondition : const myString�� ���۷����� ���ڷ� �޴´�.
*postcondition : 1�̸� true , �ƴϸ� false �����Ѵ�.
*/
{
	return strcmp(cStr, s.cStr) == 1 ? true : false;
}
bool myString::operator<= (const myString& s)
/*
*precondition : const myString�� ���۷����� ���ڷ� �޴´�.
*postcondition : -1�̰ų� 0�̸� true �ƴϸ� false �����Ѵ�.
*/
{
	return strcmp(cStr, s.cStr) == -1 || strcmp(cStr, s.cStr) == 0 ? true : false;
}
bool myString::operator>= (const myString& s)
/*
*precondition : const myString�� ���۷����� ���ڷ� �޴´�.
*postcondition : 1�̰ų� 0�̸� true �ƴϸ� false �����Ѵ�.
*/
{
	return strcmp(cStr, s.cStr) == 1 || strcmp(cStr, s.cStr) == 0 ? true : false;
}

const char& myString::operator[] (int index)
/*
*operator [] /return a reference to the element at index position
*precondition : 0���� length -1 ������ index�� ���ڷ� �޾ƾ� ���ϴ� ���� �����Ѵ�.
*postcondition : �ش� �ε��� ��°�� �迭�� �����Ѵ�.
*/
{
	if (index > length - 1)
	{
		cout << "out of range!!" << endl;
		exit(1);
	}
	return cStr[index];
}

const char& myString::at(int index)
/*
*return a reference to the element at index position
*precondition : 0���� length -1 ������ index�� ���ڷ� �޾ƾ� ���ϴ� ���� �����Ѵ�.
*postcondition : �ش� �ε��� ��°�� �迭�� �����Ѵ�.
*/
{
	if (index > length - 1)
	{
		cout << "out of range!!" << endl;
		exit(1);
	}
	return cStr[index];
}

int myString::length_method()
/*
*length()
*precondition : X
*postcondition : '\0'�� ���� �ڸ��� ������ ���̸� ��ȯ�Ѵ�.
*/
{
	if (length == 0)
		return 0;

	return length - 1; //null�� ������ ���� ��ȯ
}

char* myString::c_str()
/*
*c_str() return a pointer to an array that contains a null-terminated sequence of charactters
*precondition : �� ��ȯ���� �����ϴ� ������ ������ ���������Ѵ�.
*postcondition : ������ ���� cStr�� ��ȯ�Ѵ�.
*/
{
	return cStr;
}

myString myString::substr(int position, int length)
/*
*substr return substring object
*precondition : position�� length�� myString ��ü�� ���� ���� ���̾�� �Ѵ�.
*postcondition : ���ϴ� myString class�� ���纻�� ��ȯ�Ѵ�.
*/
{
	int split_length = length;
	char* temp = new char[split_length];

	for (int i = 0; i < split_length; i++)
	{
		temp[i] = cStr[position + i];
	}
	temp[split_length] = '\0';

	myString tempstr(temp);
	return tempstr;
}

bool myString::empty()
/*
*precondition : X
*postcondition : cStr�� ����Ŵ ������ ��ȯ�Ѵ�.
*/
{
	return (cStr == NULL) ? true : false;
}

void myString::insert(int position, myString insert_str)
/*
*precondition : += operator�� �����Ǿ� �־�� �Ѵ�.
*postcondition : ���� �ڽ��� ��ü�� ���ϴ� ���ڿ��� ���ϴ� ��ġ�� �����Ѵ�.
*/
{
	myString temp = substr(position, length - position);
	*this = substr(0, position);
	*this += insert_str += temp;
}

void myString::remove(int position, int delete_length)
/*
*precondition : += operator�� substr �Լ��� �����Ǿ� �־�� �Ѵ�.
*postcondition : ���� �ڽ��� ��ü�� ���ϴ� ���ڿ��� ���ϴ� ��ġ���� �����Ѵ�.
*/
{
	myString temp = substr(position + delete_length, length - (position + delete_length));
	*this = substr(0, position);
	*this += temp;
}

int myString::find(myString s)
/*
*precondition : ���ڿ��� ���ڷ� �޾ƾ� �Ѵ�.
*postcondition : ���ϴ� ���ڿ��� �ִ��� ã�Ƽ� �ش� ��°�� �ε����� ��ȯ�Ѵ�.
*/
{
	int sum = 0;

	for (int i = 0; i < length_method(); i++)
	{
		if (cStr[i] == s[0])
		{
			for (int j = 1; j < s.length_method(); j++)
			{
				if (cStr[i + j] == s[j])
					sum++;
				else
				{
					sum = 0;
					break;
				}
			}
			if (sum == s.length_method() - 1)
				return i;
		}
	}
	return -1;
}
int myString::find(myString s, int position)
/*
*precondition : ���ڿ��� ������ ����� �ʴ� ��ġ�� ���ڷ� �޾ƾ� �Ѵ�.
*postcondition : ���ϴ� ���ڿ��� �ִ��� ã�Ƽ� �ش� ��°�� �ε����� ��ȯ�Ѵ�.
*/
{
	int sum = 0;

	for (int i = position; i < length_method(); i++)
	{
		if (cStr[i] == s[0])
		{
			for (int j = 1; j < s.length_method(); j++)
			{
				if (cStr[i + j] == s[j])
					sum++;
				else
				{
					sum = 0;
					break;
				}
			}
			if (sum == s.length_method() - 1)
				return i;
		}
	}
	return -1;
}

int myString::find_first_of(myString s, int position)
/*
*precondition : ���ڿ��� ������ ����� �ʴ� ��ġ�� ���ڷ� �޾ƾ� �Ѵ�.
*postcondition : ���ϴ� ���ڿ��� �ִ��� ã�Ƽ� �ش� ��°�� �ε����� ��ȯ�Ѵ�.
*/
{
	for (int i = position; i < length_method(); i++)
	{
		for (int j = 0; j < s.length_method(); j++)
			if (cStr[i] == s[j])
				return i;
	}
	return -1;
}

int myString::find_first_not_of(myString s, int position)
/*
*precondition : ���ڿ��� ������ ����� �ʴ� ��ġ�� ���ڷ� �޾ƾ� �Ѵ�.
*postcondition : ���ϴ� ���ڿ��� �ִ��� ã�Ƽ� �ش� ��°�� �ε����� ��ȯ�Ѵ�.
*/
{
	int sum = 0;
	for (int i = position; i < length_method(); i++)
	{
		for (int j = 0; j < s.length_method(); j++)
			if (cStr[i] == s[j])
				sum++;
		if (sum == 0)
			return i;
		else
			sum = 0;
	}
	return -1;
}

ostream& operator<< (ostream& os, const myString& s)
/*
*precondition : ostream ���۷��� ��ü�� const myString ���۷��� ��ü�� ���ڷ� �޴´�.
*postcondition : ostream ���۷��� ��ü�� ��ȯ�Ѵ�.
*/
{
	os << s.cStr;
	return os;
}

istream& operator>> (istream& is, myString& s)
/*
*precondition : istream ���۷��� ��ü�� const myString ���۷��� ��ü�� ���ڷ� �޴´�.
*postcondition : istream ���۷��� ��ü�� ��ȯ�Ѵ�.
*/
{
	char str[50];
	is >> str;
	s = myString(str);
	return is;
}