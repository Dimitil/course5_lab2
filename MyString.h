#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdarg.h>
#include <string.h>
#include <iostream>

class MyString
{
    size_t   m_len;
	char* m_pStr;	//ñòðîêà-÷ëåí êëàññà
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& MyStr);
	~MyString();
	const char* GetString() const { if (this) return m_pStr; else return ""; }
	void SetNewString(const char* NewString);

	MyString& operator=(const MyString& other);
	MyString& operator=(const char* str);
	MyString& operator=(MyString&& other);

	friend std::ostream& operator<<(std::ostream& os, const MyString& str);

	MyString operator+(const MyString& other) const;
	MyString& operator+=(const MyString& other);
};

MyString* MyStringCat(const char* str, ...);
