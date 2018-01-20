/*
	Vector
	xCore Library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once
#include "xCore/Types.h"
#include "xCore/Memory.h"
#include "xCore/Exception.h"
#include <initializer_list>

namespace xCore
{
	// Vector - sequential container representing array that can change in size
	template <typename T>
	class Vector
	{
	public:
		// Constructs an empty container with no elements
		Vector() noexcept :
			capacity(0),
			count(0),
			data(nullptr)
		{};

		// Constructs an empty list with given initial capacity
		explicit Vector(usize capacity) :
			capacity(capacity),
			count(0),
			data(nullptr)
		{
			if (capacity > 0)
				data = Alloc(capacity);
		};

		// Constructs a container with count elements, each element is a copy of value
		Vector(usize count, const T &value) :
			capacity(count),
			count(count),
			data(nullptr)
		{
			if (count > 0)
			{
				data = Alloc(count);
				Construct(data, count, value);
			}
		};

		// Constructs a container by copying elements from another container
		Vector(const Vector<T> &other) :
			capacity(other.count),
			count(other.count),
			data(nullptr)
		{
			if (other.count > 0)
			{
				data = Alloc(other.count);
				Construct(data, other.count, other.data);
			}
		};

		// Constructs a container by moving elements from another container
		Vector(Vector<T> &&other) noexcept :
			capacity(other.capacity),
			count(other.count)
			data(other.data)
		{
			other.capacity = 0;
			other.count = 0;
			other.data = nullptr;
		};

		// Constructs a container by copying count elements from an array
		Vector(const T *array, usize count) :
			capacity(count),
			count(count),
			data(nullptr)
		{
			if (count > 0)
			{
				data = Alloc(count);
				Construct(data, count, array);
			}
		};

		// Constructs a container with the contents of initializer list
		Vector(std::initializer_list<T> list) :
			capacity(list.size()),
			count(capacity),
			data(nullptr)
		{
			if (count > 0)
			{
				data = Alloc(count);
				Construct(data, count, list.begin());
			}
		};

		// Destroys the container with all its elements
		~Vector() noexcept
		{
			Destruct(data, count);
			Free(data);
		};

		// Copies all the elements from another container
		Vector & operator=(Vector other)
		{
			Swap(other);
			return *this;
		};

		// Moves all the elements from another container 
		/*Vector & operator= (Vector &&other) noexcept
		{
			if (this != &other)
			{
				Free(data, count);
				Move(other);
			}
			return *this;
		};*/

		// Copies all the elements of initializer list into the container
		Vector & operator=(std::initializer_list<T> list)
		{
			Vector temp(list);
			Swap(temp);
			return *this;
		};

		// Exchanges the contents of the container with another one
		void Swap(Vector &other) noexcept
		{
			::Swap(capacity, other.capacity);
			::Swap(count, other.count);
			::Swap(data, other.data);
		}

		// Returns the number of elements that can be held in currently allocated storage
		usize Capacity() const noexcept
		{
			return capacity;
		};

		// Returns the number of elements in the container
		usize Count() const noexcept
		{
			return count;
		};

		// Returns a reference to the element at specified location
		T & operator[](usize index)
		{
			return data[index];
		}

		// Returns a const reference to the element at specified location
		const T & operator[](usize index) const
		{
			return data[index];
		}

		// Returns a reference to the element at specified location, with bounds checking
		T & At(usize index)
		{
			if (index < count)
				return data[index];
			throw OutOfRangeException();
		}

		// Returns a const reference to the element at specified location, with bounds checking
		const T & At(usize index) const
		{
			if (index < count)
				return data[index];
			throw OutOfRangeException();
		}

		// Returns a reference to the first element in the container
		T & First()
		{
			return data[0];
		}

		// Returns a const reference to the first element in the container
		const T & First() const
		{
			return data[0];
		}

		// Returns a reference to the last element in the container
		T & Last()
		{
			return data[count - 1];
		}

		// Returns a const reference to the last element in the container
		const T & Last() const
		{
			return data[count - 1];
		}

		// Returns a pointer to the underlying array serving as element storage
		T * Data() noexcept
		{
			return data;
		}

		// Returns a const pointer to the underlying array serving as element storage
		const T * Data() const noexcept
		{
			return data;
		}

		// Returns a pointer to the underlying array serving as element storage
		explicit operator T * () noexcept
		{
			return data;
		}

		// Returns a const pointer to the underlying array serving as element storage
		explicit operator const T * () const noexcept
		{
			return data;
		}

		// Checks if the container has no elements
		bool IsEmpty() const noexcept
		{
			return count == 0;
		}

		// Removes all elements from the container
		void Clear() noexcept
		{
			Destruct(data, count);
			count = 0;
		};

		// Appends the given element value to the end of the container by copying
		void Add(const T &value)
		{
			AddHelper(value);
		};

		// Appends the given element value to the end of the container by moving
		void Add(T &&value)
		{
			AddHelper((T &&)value);
		};

		// Sorts the elements in the container
		void Sort() noexcept
		{
			for (usize i = 0; i < count; i++)
				for (usize j = i + 1; j < count; j++)
					if (data[i] > data[j])
						::Swap(data[i], data[j]);
		};

		// Reverses the sequence of the elements in the container
		void Reverse() noexcept
		{
			for (usize i = 0; i < count / 2; i++)
				::Swap(data[i], data[count - i - 1]);
		};

		// Determines whether an element is in the container
		bool Contains(const T &value) const noexcept
		{
			for (usize i = 0; i < count; i++)
				if (data[i] == value)
					return true;
			return false;
		};

		// Searches for the specified value and returns the index of the first occurrence within the container
		usize IndexOf(const T &value) const noexcept
		{
			for (usize i = 0; i < count; i++)
				if (data[i] == value)
					return i;
			return -1;
		};

		// Returns an iterator to the first element of the container
		T * Begin() noexcept
		{
			return data;
		}

		// Returns an iterator to the first element of the container
		T * begin() noexcept
		{
			return data;
		}

		// Returns a const iterator to the first element of the container
		const T * Begin() const noexcept
		{
			return data;
		}		
		
		// Returns a const iterator to the first element of the container
		const T * begin() const noexcept
		{
			return data;
		}

		// Returns an iterator to the element following the last element of the container
		T * End() noexcept
		{
			return data + count;
		}
		
		// Returns an iterator to the element following the last element of the container
		T * end() noexcept
		{
			return data + count;
		}

		// Returns a const iterator to the element following the last element of the container
		const T * End() const noexcept
		{
			return data + count;
		}		
		
		// Returns a const iterator to the element following the last element of the container
		const T * end() const noexcept
		{
			return data + count;
		}
		
		// Returns the maximum number of elements the container is able to hold
		constexpr usize MaxCount() const noexcept
		{
			return usize(~0) / sizeof(T);
		}

		// Returns true if the contents of the containers are equal
		bool operator== (const Vector &other)
		{
			if (count != other.count)
				return false;
			for (usize i = 0; i < count; i++)
				if (data[i] != other.data[i])
					return false;
			return true;
		}

		// Returns true if the contents of the containers are not equal
		bool operator!= (const Vector &other)
		{
			return !(*this == other);
		}

		// Retuns true if the contents of the container are lexicographically less than the contents of other
		bool operator< (const Vector &other)
		{
			usize i = 0, j = 0;
			for (; i < count && j < other.count; ++i, ++j)
			{
				if (data[i] < other.data[j])
					return true;
				if (other.data[j] < data[i])
					return false;
			}
			return (i == count) && (j != other.count);
		}

		// Returns true if the contents of the container are lexicographically less than or equal the contents of other
		bool operator<= (const Vector &other)
		{
			return !(other < *this);
		}

		// Returns true if the contents of the container are lexicographically greater than the contents of other
		bool operator> (const Vector &other)
		{
			return other < *this;
		}

		// Returns true if the contents of the container are lexicographically greater than or equal the contents of other
		bool operator>= (const Vector &other)
		{
			return !(*this < other);
		}

	private:
		usize capacity;
		usize count;
		T *data;

		// Allocates an array of count elements without invoking their constructors
		T * Alloc(usize count)
		{
			return (T *) operator new(count * sizeof(T));
		}

		// Deallocates an array of elements without invoking their destructors
		void Free(T *arr) noexcept
		{
			operator delete(arr);
		}

		// Constructs count elements from an array, each of the element is a copy of value
		void Construct(T *arr, usize count, const T &value)
		{
			for (usize i = 0; i < count; i++)
				new(&data[i]) T(value);
		}

		// Constructs count element from an array by coping them from a source array
		void Construct(T *arr, usize count, const T *src)
		{
			for (usize i = 0; i < count; i++)
				new(&data[i]) T(src[i]);
		}

		// Destructs count elements from an array by invoking their destructors
		void Destruct(T *arr, usize count) noexcept
		{
			for (usize i = 0; i < count; i++)
				arr[i].~T();
		}

		// Appends the given element value to the end of container by forwarding
		template <typename U>
		void AddHelper(U &&value)
		{
			if (count == capacity)
			{
				// Max possible size of the container
				const usize max = MaxCount();
				if (capacity == max)
					throw SizeLimitException();
				usize newCapacity = (capacity < max - capacity / 2) ? count + count / 2 + 1 : max;
				T *buf = Alloc(newCapacity);
				MemCopy(buf, data, count * sizeof(T));
				Free(data);
				data = buf;
				capacity = newCapacity;
			}
			new(&data[count++]) T((U &&)value);
		};
	};
}