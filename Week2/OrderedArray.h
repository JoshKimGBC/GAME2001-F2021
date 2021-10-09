#pragma once
#include "BaseArray.h"
#include <cassert>

template <class T>
class OrderedArray : public BaseArray<T>
{
public:
	// Constructor
	OrderedArray(int size, int growBy = 2) : BaseArray<T>(size, growBy) {}


	// Destructor
	~OrderedArray() {}


	// Insertion -- Big-O = O(N)
	void push(T val)
	{
		
		assert(this->m_array != nullptr);

		if (this->m_numElements >= this->m_maxSize)
		{
			this->Expand();
		}

		int i, k; // i - Index to be inserted. k - Used for shifting purposes
		// Step 1: Find the index to insert val	
		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] > val)
			{
				break;
			}
		}

		// If there is an index value that is at a location in the array already, we break.
		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] = val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index(i) forward by one. Work backwards
		for (k = this->m_numElements; k > i; k--)
		{
			this->m_array[k] = this->m_array[k - 1];
		}

		// Step 3: Insert val into the array at index(i)
		this->m_array[i] = val;

		this->m_numElements++;

		// return i;
	}

	int search(T searchKey)
	{
		assert(this->m_array != nullptr);

		// Helper variables.
		int lowerBound = 0;
		int upperBound = this->m_numElements - 1;
		int current = 0;

		while (1) // <-- Replaced with recursion
		{
			current = (lowerBound + upperBound) >> 1; // Preview of bitwise operation. Divides by 2

			// Binary search steps:
			// Step 1: Check if the middle is the value we are looking for.
			if (this->m_array[current] == searchKey)
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
				if (this->m_array[current] < searchKey)
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
};
