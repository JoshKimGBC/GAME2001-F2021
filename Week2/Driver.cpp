#include <iostream>
#include "UnorderedArray.h"
#include "OrderedArray.h"
#include "BaseArray.h"

int main()
{
	OrderedArray<int> OrderedArray(3);

	OrderedArray.push(3);
	OrderedArray.push(3);
	OrderedArray.push(4); // Should be removed here
	OrderedArray.push(5); // Should expand here	
	OrderedArray.push(6); // Should also expand here and then get popped

	OrderedArray.remove(2);
	OrderedArray.pop();



	std::cout << "Ordered array contents: ";

	for (int i = 0; i < OrderedArray.GetSize(); i++)
	{
		std::cout << OrderedArray[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "Search for 3 was found at index: " << std::endl;
	std::cout << OrderedArray.search(3) + 1; // Added one to show the user the first index but not in a way that shows 0 as the first

	std::cout << std::endl;

	UnorderedArray<int> UnorderedArray(3);

	UnorderedArray.push(3);
	UnorderedArray.push(4);
	UnorderedArray.push(33); // Should be removed here
 	UnorderedArray.push(1); 
	UnorderedArray.push(7); // Should expand here and then get popped

	UnorderedArray.remove(2);
	UnorderedArray.pop();



	std::cout << "Unordered array contents: ";

	for (int i = 0; i < UnorderedArray.GetSize(); i++)
	{
		std::cout << UnorderedArray[i] << " ";
	}

	std::cout << std::endl;

	std::cout << "Search for 1 was found at index: " << std::endl;
	std::cout << UnorderedArray.search(1) + 1; // Added one to show the user the first index but not in a way that shows 0 as the first

	std::cout << std::endl;
	return 0;
}