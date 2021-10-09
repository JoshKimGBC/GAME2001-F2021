#pragma once
#include "BaseArray.h"
#include <cassert>

template <class T>
class OrderedArray : public BaseArray<T>
{
public:
	// Constructor
	// Default Constructor

	OrderedArray(int size, int growBy = 2) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size) // Is this a legal size fo an array?
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; // Dynamically allocating array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize); // Explicitly set 0 to all elements in the array;

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	// Destructor
	~OrderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	// Insertion -- Big-O = O(N)
	void push(T val)
	{
		assert(m_array != nullptr);

		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		int i, k; // i - Index to be inserted. k - Used for shifting purposes
		// Step 1: Find the index to insert val	
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}

		// If there is an index value that is at a location in the array already, we break.
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] = val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index(i) forward by one. Work backwards
		for (k = m_numElements; k > i; k--)
		{
			m_array[k] = m_array[k - 1];
		}

		// Step 3: Insert val into the array at index(i)
		m_array[i] = val;

		m_numElements++;

		// return i;
	}

	int search(T searchKey)
	{
		assert(m_array != nullptr);

		// Helper variables.
		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;

		while (1) // <-- Replaced with recursion
		{
			current = (lowerBound + upperBound) >> 1; // Preview of bitwise operation. Divides by 2

			// Binary search steps:
			// Step 1: Check if the middle is the value we are looking for.
			if (m_array[current] == searchKey)
			{
				// Found the item in the middle of the Array. Return the index
				return current;
			}
			// Step 2: Check that we've exhausted all options. Can't find the item
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			// Step 3: Check which half of the array the value is in.
			else
			{
				if (m_array[current] < searchKey)
				{
					lowerBound = current + 1; // Represents that the value may be in the upper half of the index
				}
				else
				{
					upperBound = current - 1; // Represents that the value may be in the lower half of the index
				}
			}
		}

		return -1; // Catch all return from danger because this is an infinite loop.
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

protected:
	//  Protected Variables

	T* m_array;			// Pointer to the beginning of the array

	int m_maxSize;			 // Max size of the array
	int m_growSize;		   	// Max size the array can grow through expansion
	int m_numElements;		// Number of items currently in the array


};
