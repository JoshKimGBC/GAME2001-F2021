#pragma once
#include "OrderedArray.h"
#include <cassert>

template <class T>
class UnorderedArray : public OrderedArray<T>
{
public:
	// Constructor
	UnorderedArray(int size, int growBy = 2) :
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
	~UnorderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	// Insertion
	// Fast Insertion for Unordered Array -- Big O is O(1)
	void push(T val)
	{
		assert(m_array != nullptr); // Debugging purposes

		if (m_numElements >= m_maxSize) // Check if the array has to expand to accommodate the new data
		{
			Expand();
		}

		// The array has space for a new value so it can be added to the array
		m_array[m_numElements] = val;
		m_numElements++;
	}
	// Linear searching
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

	// Inherited Functions
	virtual void remove() const;
	virtual void pop() const;
	virtual void clear() const;
	virtual int GetSize() const;
	virtual int GetMaxSize() const;
	virtual int GetGrowSize() const;
	virtual int SetGrowSize() const;

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
