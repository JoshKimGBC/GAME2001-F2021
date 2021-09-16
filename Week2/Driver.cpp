#include <iostream>
#include "UnorderedArray.h"

int main()
{
	UnorderedArray<int> array(3);

	array.push(3);
	array.push(53);
	array.push(83);
	array.push(23); // Should expand here
	array.push(82); // Should also expand here

	array[2] = 112;

	array.pop();
	array.remove(2);

	std::cout << "Unordered array contents: ";
		
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