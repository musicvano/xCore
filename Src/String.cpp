/*
	Unicode Strings
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#include "xCore/String.h"
#include "xCore/Memory.h"
#include <cstring>

namespace xCore
{
	// Returns minimum value
	uint Min(uint x, uint y)
	{
		return x < y ? x : y;
	}

	// Returns new allocated buffer with copied data from source
	char * New(const char *src, usize count)
	{
		auto dest = new char[count + 1];
		MemCopy(dest, src, count);
		dest[count] = '\0';
		return dest;
	}

	String::String() { }

	String::String(String &&str)
	{
		length = str.length;
		buffer = str.buffer;
		str.length = 0;
		str.buffer = nullptr;
	}

	String::String(const String &str)
	{
		if (length = str.length)
			buffer = New(str.buffer, length);
	}

	String::String(const char *str)
	{
		if (length = StrLength(str))
			buffer = New(str, length);
	}

	String::String(const String &str, uint length)
	{
		if (this->length = Min(length, str.length))
			buffer = New(str.buffer, this->length);
	}

	String::String(const char *str, uint length)
	{
		if (this->length = Min(length, StrLength(str)))
			buffer = New(str, this->length);
	}

	String::String(const String &str, uint index, uint length)
	{
		if (index < str.length)
			if (this->length = Min(length, str.length - index))
				buffer = New(str.buffer + index, this->length);
	}

	String::String(const char *str, uint index, uint length)
	{
		uint len = StrLength(str);
		if (index < len)
			if (this->length = Min(length, len - index))
				buffer = New(str + index, this->length);
	}

	String::String(const char *first, const char *last)
	{
		if (last > first)
		{
			length = last - first;
			buffer = New(first, length);
		}
	}

	String::String(char c, uint count)
	{
		if (length = count)
		{
			buffer = new char[length + 1];
			MemSet(buffer, c, length);
			buffer[length] = '\0';
		}
	}

	String::~String()
	{
		delete[] buffer;
	}

	String & String::operator=(String &&str)
	{
		if (this != &str)
		{
			this->~String();
			length = str.length;
			buffer = str.buffer;
			str.length = 0;
			str.buffer = nullptr;
		}
		return *this;
	}

	String & String::operator=(const String &str)
	{
		if (this != &str)
		{
			this->~String();
			if (length = str.length)
				buffer = New(str.buffer, length);
			else
				buffer = nullptr;
		}
		return *this;
	}

	String & String::operator=(const char *str)
	{
		return *this = String(str);
	}

	String & String::operator=(char c)
	{
		return *this = String(c, 1);
	}

	/*string string::operator+(const string &str)
	{
		if (!desc->Length)
			return str;
		if (!str.desc->Length)
			return *this;
		return string(NewStrDesc(desc->Buffer, desc->Length, str.desc->Buffer, str.desc->Length));
	}

	string string::operator+(const char *str)
	{
		uint len = StrLength(str);
		if (!len)
			return *this;
		if (!desc->Length)
			return string(NewStrDesc(str, len));
		else
			return string(NewStrDesc(desc->Buffer, desc->Length, str, len));
	}

	string operator+(const char *str1, const string &str2)
	{
		uint len = StrLength(str1);
		if (!len)
			return str2;
		if (!str2.desc->Length)
			return string(NewStrDesc(str1, len));
		else
			return  string(NewStrDesc(str1, len, str2.desc->Buffer, str2.desc->Length));
	}

	string string::operator+(char c)
	{
		if (!desc->Length)
			return string(c, 1);
		if (!c)
			return *this;
		return string(NewStrDesc(desc->Buffer, desc->Length, &c, 1));
	}

	string operator+(char c, const string & str)
	{
		if (!str.desc->Length)
			return string(c, 1);
		if (!c)
			return str;
		return string(NewStrDesc(&c, 1, str.desc->Buffer, str.desc->Length));
	}

	string& string::operator+=(const string &str)
	{
		return *this = *this + str;
	}

	string& string::operator+=(const char *str)
	{
		return *this = *this + str;
	}

	string& string::operator+=(char c)
	{
		return *this = *this + c;
	}

	char string::operator[](uint index)
	{
		return desc->Buffer[index];
	}

	uint string::Length() const
	{
		return desc->Length;
	}

	bool string::IsEmpty() const
	{
		return desc->Length == 0;
	}

	const char* string::Chars() const
	{
		return desc->Buffer;
	}

	void string::Clear()
	{
		this->~string();
		desc = GetEmptyStrDesc();
	}

	uint string::Find(const string &str) const
	{
		return StrFind(desc->Buffer, str.desc->Buffer);
	}

	uint string::Find(const string &str, uint index) const
	{
		return StrFind(desc->Buffer + index, str.desc->Buffer) + index;
	}

	uint string::Find(const char *str) const
	{
		return StrFind(desc->Buffer, str);
	}

	uint string::Find(const char *str, uint index) const
	{
		return StrFind(desc->Buffer + index, str) + index;
	}

	uint string::Find(char c) const
	{
		return StrFind(desc->Buffer, c);
	}

	uint string::Find(char c, uint index) const
	{
		return StrFind(desc->Buffer + index, c) + index;
	}

	bool string::operator==(const string &str) const
	{
		return StrCompare(desc->Buffer, str.desc->Buffer) == 0;
	}

	bool string::operator==(const char *str) const
	{
		return StrCompare(desc->Buffer, str) == 0;
	}

	bool operator==(const char *str1, const string &str2)
	{
		return StrCompare(str1, str2.desc->Buffer) == 0;
	}

	bool string::operator!=(const string &str) const
	{
		return StrCompare(desc->Buffer, str.desc->Buffer) != 0;
	}

	bool string::operator!=(const char *str) const
	{
		return StrCompare(desc->Buffer, str) != 0;
	}

	bool operator!=(const char *str1, const string &str2)
	{
		return StrCompare(str1, str2.desc->Buffer) != 0;
	}

	bool string::operator<(const string &str) const
	{
		return StrCompare(desc->Buffer, str.desc->Buffer) < 0;
	}

	bool string::operator<(const char *str) const
	{
		return StrCompare(desc->Buffer, str) < 0;
	}

	bool operator<(const char *str1, const string &str2)
	{
		return StrCompare(str1, str2.desc->Buffer) < 0;
	}

	bool string::operator<=(const string &str) const
	{
		return StrCompare(desc->Buffer, str.desc->Buffer) <= 0;
	}

	bool string::operator<=(const char *str) const
	{
		return StrCompare(desc->Buffer, str) <= 0;
	}

	bool operator<=(const char *str1, const string &str2)
	{
		return StrCompare(str1, str2.desc->Buffer) <= 0;
	}

	bool string::operator>(const string &str) const
	{
		return StrCompare(desc->Buffer, str.desc->Buffer) > 0;
	}

	bool string::operator>(const char *str) const
	{
		return StrCompare(desc->Buffer, str) > 0;
	}

	bool operator>(const char *str1, const string &str2)
	{
		return StrCompare(str1, str2.desc->Buffer) > 0;
	}

	bool string::operator>=(const string &str) const
	{
		return StrCompare(desc->Buffer, str.desc->Buffer) >= 0;
	}

	bool string::operator>=(const char *str) const
	{
		return StrCompare(desc->Buffer, str) >= 0;
	}

	bool operator>=(const char *str1, const string &str2)
	{
		return StrCompare(str1, str2.desc->Buffer) >= 0;
	}

	void string::Swap(string & str)
	{
		StringDesc *tmp = desc;
		desc = str.desc;
		str.desc = tmp;
	}

	void string::Swap(string &str1, string &str2)
	{
		str1.Swap(str2);
	}

	string string::Remove(uint index) const
	{
		return string(*this, 0, index);
	}

	string string::Remove(uint index, uint count) const
	{
		char *str1 = null, *str2 = null;
		uint len1 = 0, len2 = 0;
		uint pos = index;
		str1 = desc->Buffer;
		len1 = pos < desc->Length ? pos : desc->Length;
		pos = index + count;
		if (pos < desc->Length)
		{
			str2 = desc->Buffer + pos;
			len2 = desc->Length - pos;
		}
		if (len1 + len2 == desc->Length)
			return *this;
		if (len1 == 0 && len2 == 0)
			return string();
		return string(NewStrDesc(str1, len1, str2, len2));
	}
	*/

	const char* String::begin() const
	{
		return buffer;
	}

	const char* String::end() const
	{
		return buffer + length;
	}

	usize StrLength(const char *str)
	{
		return strlen(str);
	}

	usize StrLength(const wchar *str)
	{
		const wchar *s;
		for (s = str; *s; ++s);
		return s - str;
	}

	usize StrLength(const uchar *str)
	{
		const uchar *s;
		for (s = str; *s; ++s);
		return s - str;
	}

	int StrCompare(const char *str1, const char *str2)
	{
		return strcmp(str1, str2);
	}

	bool StrEqual(const char *str1, const char *str2)
	{
		return strcmp(str1, str2) == 0;
	}
}