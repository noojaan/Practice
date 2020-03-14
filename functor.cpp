#include <iostream>
#include <vector>
#include <algorithm> //for_each

template <typename T>
class PrintDouble {
	public:
	void operator()(T a) {					//Functor
		std::cout << "functor: " << 2 * a << std::endl;
	}
};

template <typename T>
void printTwice(T a)
{
	std::cout << "func: " << 2 * a << std::endl;
}

int main()
{
	std::vector<int> v{ 1,2,3,4,5 };
	PrintDouble<int> print_it;
	for_each(v.begin(), v.end(), print_it);
	for_each(v.begin(), v.end(), printTwice<int>);
	return 0;
}