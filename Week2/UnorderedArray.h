#pragma once
#include "BaseArray.h"
#include <cassert>

template <class T>
class UnorderedArray : public BaseArray<T>
{
public:
	// Constructor
	UnorderedArray(int size, int growBy = 2) : BaseArray<T>(size, growBy) {}

	// Destructor
	~UnorderedArray() {}

	// Insertion
	// Fast Insertion for Unordered Array -- Big O is O(1)
	void push(T val)
	{
		assert(this->m_array != nullptr); // Debugging purposes

		if (this->m_numElements >= this->m_maxSize) // Check if the array has to expand to accommodate the new data
		{
			this->Expand();
		}

		// The array has space for a new value so it can be added to the array
		this->m_array[this->m_numElements] = val;
		this->m_numElements++;
	}
	// Linear searching
	int search(T val)
	{
		assert(this->m_array != nullptr);

		// Brute Force search
		for (int i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == val)
			{
				return i; // Return the index of where the item is located in the array
			}
		}

		return -1;
	}
};
