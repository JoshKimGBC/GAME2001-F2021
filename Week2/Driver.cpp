#include <iostream>
#include "UnorderedArray.h"
#include "OrderedArray.h"
#include "BaseArray.h"

int main()
{
	UnorderedArray<int> OrderedArray(4);

	OrderedArray[0] = 1;
	OrderedArray.push(3);
	OrderedArray.push(53);
	OrderedArray.push(83);
	// OrderedArray.push(23); // Should expand here		// 3 23 82
	// OrderedArray.push(82); // Should also expand here

	
	// OrderedArray.remove(2);

	// OrderedArray.pop();



	std::cout << "Ordered array contents: ";

	for (int i = 0; i < OrderedArray.GetSize(); i++)
	{
		std::cout << OrderedArray[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "Search for 53 was found at index: " << std::endl;
	std::cout << OrderedArray.search(53);

	std::cout << std::endl;

	return 0;
}