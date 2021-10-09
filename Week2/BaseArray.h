#pragma once
#include <cassert>

template <class T>
class BaseArray
{
public:
	// Constructor
	BaseArray() = default;

	BaseArray(int size, int growBy = 2) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size) // Is this a legal size for an array? 
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; // Dynamically allocating array to m_maxSize 
			memset(m_array, 0, sizeof(T) * m_maxSize); // Explicitly set 0 to all elements in the array; 

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	// Destructor
	~BaseArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	// Deletion (2 ways)
	// First way, removes the last item inserted into the array
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--; // Reduce the total number of elements by 1. Ignoring the last element.
		}
	}
	// Second way, remove the item given an index - almost brute-force execution -- Big O = O(N)
	void remove(int index)
	{
		assert(m_array != nullptr);

		if (index >= m_numElements)
		{
			// Trying to remove something outside of the bounds of the array
			return; // Maybe do some form of exception handling usually
		}

		for (int i = index; i < m_numElements; i++)
		{
			// Start at the index we want to remove. 

			// Shift everything after index back by one.
			if (i + 1 < m_numElements) // Confines the loop into the array
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	// Linear Searching
	int search(T val)
	{
		assert(m_array != nullptr);

		// Brute Force search
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
			{
				return i; // Return the index of where the item is located in the array
			}
		}

		return -1;
	}

	// Overloaded [](array notation) operator
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}

	// Clear
	void clear()
	{
		m_numElements = 0; // Ignore/forgets all current items in the array
	}
	// Getters
	int GetSize()
	{
		return m_numElements;
	}
	int GetMaxSize()
	{
		return m_maxSize;
	}
	int GetGrowSize()
	{
		return m_growSize;
	}

	// Setters

	int SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}
	public:
	// Yo this function is public straight up
	// Expansion
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			// LEAVE
			return false;
		}


		// Create the new array if grow size is > 0
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != nullptr);

		// Copy the contents of the original array into the new array
		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		// After copy the contents in the new array, delete the old array
		delete[] m_array;

		// Clean up variable assignments
		m_array = temp;
		temp = nullptr;

		m_maxSize += m_growSize;

		return true;
	}

	T* m_array;			// Pointer to the beginning of the array

	int m_maxSize;			 // Max size of the array
	int m_growSize;		   	// Max size the array can grow through expansion
	int m_numElements;		// Number of items currently in the array

};
