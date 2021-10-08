#include <iostream>
#include "UnorderedArray.h"
#include "OrderedArray.h"

int main()
{
	OrderedArray<int> array(3);

	array.push(3);
	array.push(53);
	array.push(83);
	array.push(23); // Should expand here		// 3 23 82
	array.push(82); // Should also expand here

	array[2] = 112;

	array.pop();
	array.remove(2);

	std::cout << "Ordered array contents: ";
		
	for (int i = 0; i < array.GetSize(); i++)
	{
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "Search for 53 was found at index: " << std::endl;
	std::cout << array.search(53);

	std::cout << std::endl;

	return 0;
}