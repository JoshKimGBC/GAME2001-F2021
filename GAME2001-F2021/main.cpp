// "Generic" classes or function
// Compare 2 things. Return smallst. Return the largest.

#include <iostream>
#include<string>

// Template function 
// Check 2 "things". Return the smallest
template <class T>
T min_func(T lVal, T rVal) {

	if (lVal > rVal)
	{
		return rVal;
	}
	return lVal;
}

// Template function
// Check 2 "things". Return the largest
template <class T>
T max_func(T lVal, T rVal) {

	if (lVal < rVal)
	{
		return rVal;
	}

	return lVal;
}

// Implement a template class 
template <class T>
class TemplateClass
{
public:
	// Constructor
	TemplateClass(T val)
	{
		m_val = val;
	}
	// Getter
	T GetVal()
	{
		return m_val;
	}

	bool operator<(TemplateClass& rVal)
	{
		return m_val < rVal.GetVal();
	}

	bool operator>(TemplateClass& rVal)
	{
		return m_val > rVal.GetVal();
	}

private:
	T m_val;
};

// Main function
int main() {
	std::cout << "Template Example" << std::endl;
	std::cout << "Min = " << min_func(56.1, 43.6) << std::endl;
	std::cout << "Max = " << max_func('c', 'd') << std::endl;

	// Create 2 "TemplateClass" objects and compare them.
	std::cout << "Max (objects) = " << max_func(TemplateClass<int>(7), TemplateClass<int>(4)).GetVal();
	std::cout << "Min (objects) = " << min_func(TemplateClass<std::string>("word"), TemplateClass<std::string>("otherword")).GetVal();

	return 0;
}