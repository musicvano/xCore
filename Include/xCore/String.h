/*
	Unicode Strings
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once
#include "xCore/Types.h"

namespace xCore
{
	//static const uint nullpos = -1;

	// Unicode string (UTF-8)
	class String
	{
	public:
		// Constructs the empty string with a length of zero characters
		String();

		// Constructs the string by moving content from another string
		String(String &&str);

		// Constructs the string by copying characters from another string
		String(const String &str);

		// Constructs the string by copying characters from null-terminated C-string
		String(const char *str);

		// Constructs the string by copying first length characters from another string
		String(const String &str, uint length);

		// Constructs the string copying first length characters from null-terminated C-string
		String(const char *str, uint length);

		// Constructs the string by copying substring beginning from start index and spans length characters
		String(const String &str, uint index, uint length);

		// Constructs the string by copying substring beginning from start index and spans length characters
		String(const char *str, uint index, uint length);

		// Constructs the string by copying the sequence of characters in the range [first, last), in the same order
		String(const char *first, const char *last);

		// Constructs the string with count consecutive copies of character c
		String(char c, uint count);

		// Destroys the string object
		~String();

		// Assigns a new value to the string, replacing its current content
		String & operator=(String &&str);

		// Assigns a new value to the string, replacing its current content
		String & operator=(const String &str);

		//  Assigns a new value to the string, replacing its current content
		String & operator=(const char *str);

		// Assigns a char to the string
		String & operator=(char c);


		// Concatenates string and char
/*		String operator+(char c);

		// Concatenates char and string
		friend String operator+(char c, const String &str);

		// Concatenates string and C-string
		String operator+(const char *str);

		// Concatenates C-string and string
		friend String operator+(const char *str1, const String &str2);

		// Concatenates strings
		String operator+(const String &str);

		// Appends char to the string
		String& operator+=(char c);

		// Appends the C-string
		String& operator+=(const char *str);

		// Appends the string
		String& operator+=(const String &str);

		// Returns character of the string by index
		char operator[](uint index);

		// Returns the number of characters in the current string
		uint Length() const;

		// Returns true if the string is null or empty
		bool IsEmpty() const;

		// Returns the pointer to an array that contains a null-terminated string
		const char* Chars() const;

		// Erases the contents of the string, which becomes an empty string
		void Clear();

		// Returns the index of the first occurrence of the specified string
		uint Find(const String &str) const;

		// Returns the index of the first occurrence of the specified string started from index
		uint Find(const String &str, uint index) const;

		// Returns the index of the first occurrence of the specified C-string
		uint Find(const char *str) const;

		// Returns the index of the first occurrence of the specified C-string started from index
		uint Find(const char *str, uint index) const;

		// Returns the index of the first occurrence of the specified character
		uint Find(char c) const;

		// Returns the index of the first occurrence of the specified character started from index
		uint Find(char c, uint index) const;

		// Return true if strings have equal content
		bool operator==(const String &str) const;

		// Return true if strings have equal content
		bool operator==(const char *str) const;

		// Return true if strings have equal content
		friend bool operator==(const char *str1, const String &str2);

		// Return true if strings have different content
		bool operator!=(const String &str) const;

		// Return true if strings have different content
		bool operator!=(const char *str) const;

		// Return true if strings have different content
		friend bool operator!=(const char *str1, const String &str2);

		// Compares strings
		bool operator<(const String &str) const;
		bool operator<(const char *str) const;
		friend bool operator<(const char *str1, const String &str2);
		bool operator<=(const String &str) const;
		bool operator<=(const char *str) const;
		friend bool operator<=(const char *str1, const String &str2);
		bool operator>(const String &str) const;
		bool operator>(const char *str) const;
		friend bool operator>(const char *str1, const String &str2);
		bool operator>=(const String &str) const;
		bool operator>=(const char *str) const;
		friend bool operator>=(const char *str1, const String &str2);

		// Swaps the strings
		void Swap(String &str);

		// Swaps the strings
		static void Swap(String &str1, String &str2);

		// Returns a new string by removing characters from index position to the end
		String Remove(uint index) const;

		// Returns a new string by removing count characters from index position
		String Remove(uint index, uint count) const;*/

		// Returns an iterator pointing to the first character of the string
		const char* begin() const;

		// Returns an iterator pointing to the last character of the string.
		const char* end() const;

	private:
		usize length = 0;
		char *buffer = nullptr;
	};


	// Returns the length of a ASCII, UTF-8 string
	usize StrLength(const char *str);

	// Returns the length of a UTF-16 string
	usize StrLength(const wchar *str);

	// Returns the length of a UTF-32 string
	usize StrLength(const uchar *str);

	// Compares two strings
	int StrCompare(const char *str1, const char *str2);

	// Returns true if strings are equals
	bool StrEqual(const char *str1, const char *str2);
}