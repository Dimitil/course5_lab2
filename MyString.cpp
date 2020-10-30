#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "MyString.h"
#include <iostream>


// Îïðåäåëåíèå êîíñòðóêòîðà.

MyString::MyString()
{
	m_len = 0;
	m_pStr = nullptr;
}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--

MyString::MyString(const char* str)
{
	m_len = strlen(str);
	m_pStr = new char[m_len + 1];
	strcpy(m_pStr, str);
}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--

MyString::~MyString()
{
    if(m_pStr)
    {
        delete[] m_pStr;
    }
	m_len = 0;
}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--

MyString::MyString(const MyString& MyStr)
{
	m_len = strlen(MyStr.m_pStr);
	m_pStr = new char[m_len + 1];
	strcpy(m_pStr, MyStr.m_pStr);
}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--

void MyString::SetNewString(const char* NewString)
{

	if (m_len < strlen(NewString))
	{
		delete[] m_pStr;
		m_len = strlen(NewString);
		m_pStr = new char[m_len + 1];
	}

	strcpy(m_pStr, NewString);
}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--

MyString* MyStringCat(const char* str, ...)
{
	va_list  argptr;
	va_start(argptr, str);

	char buf1[80];
	char buf2[80];

	strcpy(buf1, str);
	strcpy(buf2, va_arg(argptr, char* const));

	while (strcmp(buf2, "end$"))			//êàê ñäåëàòü 0 - êîíåö ââîäà?
	{
		strcat(buf1, buf2);
		strcpy(buf2, va_arg(argptr, char* const));
	}

	MyString* Res = new MyString(buf1);

	va_end(argptr);

	return Res;
}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		if (m_len < other.m_len)
		{
			delete[] m_pStr;
			m_pStr = new char[other.m_len + 1];
		}
		m_len = other.m_len;
        strcpy(m_pStr, other.m_pStr);
	}
	return *this;
}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--

MyString& MyString::operator=(const char* str)
{
	if (m_pStr != str)//èñïðàâèòü!íåàäåêâàòíî!!!!!!!!!!!!!!!!!!
	{
		if (m_len < strlen(str))
		{
			delete[] m_pStr;
			m_pStr = new char[strlen(str) + 1];
		}
		m_len = strlen(str);
		strcpy(m_pStr, str);
	}

	return *this;
}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--

MyString& MyString::operator=(MyString&& other)
{
	//ïðîâåðêà íà ñàìîïðèñâàåâàíèå!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	delete[] m_pStr;
	m_len = other.m_len;
	m_pStr = other.m_pStr;

	other.m_len = 0;
	other.m_pStr = nullptr;
	return *this;
}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	os << str.m_pStr;
	return os;
}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--

MyString MyString::operator+(const MyString& other) const
{
	MyString res;

	res.m_len = this->m_len + other.m_len;
	res.m_pStr = new char[res.m_len + 1];
	strcpy(res.m_pStr, this->m_pStr);
	strcat(res.m_pStr, other.m_pStr);


	return res;
}

//--//--//--//--//--//--//-//--//--//--//--//--//--//--//--//--//--//--//--//--

MyString& MyString::operator+=(const MyString& other)
{
	m_len += other.m_len;
	char* newptr = new char[m_len + 1];
	strcpy(newptr, m_pStr);
	strcat(newptr, other.m_pStr);
	delete[] m_pStr;
	m_pStr = newptr;

	return *this;
}
