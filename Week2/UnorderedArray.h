#pragma once
#include <cassert>

template <class T>
class UnorderedArray
{
public:
	// Constructor
	UnorderedArray(int size, int growBy = 1) :
		m_pArray(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size) // Is this a legal size fo an array?
		{
			m_maxSize = size;
			m_pArray = new T[m_maxSize]; // Dynamically allocating array to m_maxSize
			memset(m_pArray, 0, sizeof(T) * m_maxSize); // Explicitly set 0 to all elements in the array;

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	// Destructor
	~UnorderedArray()
	{
		if (m_pArray != nullptr)
		{
			delete[] m_pArray;
			m_pArray = nullptr;
		}
	}
	// Insertion
	// Fast Insertion for Unordered Array -- Big O is O(1)
	void push(T val)
	{
		assert(m_pArray != nullptr); // Debugging purposes

		if (m_numElements >= m_maxSize) // Check if the array has to expand to accommodate the new data
		{
			Expand();
		}

		// The array has space for a new value so it can be added to the array
		m_pArray[m_numElements] = val;
		m_numElements++;
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
		assert(m_pArray != nullptr);

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
				m_pArray[i] = m_pArray[i + 1];
			}
		}
		m_numElements--;
	}
	// Linear Searching
	int search(T val)
	{
		assert(m_pArray != nullptr);

		// Brute Force search
			for (int i = 0; i < m_numElements; i++)
			{
				if (m_pArray[i] == val)
				{
					return i; // Return the index of where the item is located in the array
				}
			}

		return -1;
	}

	// Overloaded [](array notation) operator
	T& operator[](int index)
	{
		assert(m_pArray != nullptr && index < m_numElements);
		return m_pArray[index];
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

private:
// Private functions

	// Expansion
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			// LEAVE
			return false;
		}
	}

	// Create the new array if grow size is > 0
	T* temp = new T[m_maxSize + m_growSize];
	assert(temp != nullptr);

	// Copy the contents of the original array into the new array
	memcpy(temp, m_pArray, sizeof(T) * m_maxSize);

	// After copy the contents in the new array, delete the old array
	delete[] m_pArray;

	// Clean up variable assignments
	m_pArray = temp;
	temp = nullptr;

	m_maxSize += m_growSize;

	return true;

private:
//  Private Variables

	T* m_pArray;			// Pointer to the beginning of the array

	int m_maxSize;			 // Max size of the array
	int m_growSize;		   	// Max size the array can grow through expansion
	int m_numElements;		// Number of items currently in the array
};
