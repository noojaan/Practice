#include <iostream>

int getValueFromUser() 
{
	int num{};
	std::cout << "Enter a integer value: ";
	std::cin >> num;
	return num;
}

void printDouble(int num) 
{
	std::cout << "Double of "<< num << " is: " << num*2 << '\n';
}


int main()
{
	int a{};
	a= getValueFromUser();
	printDouble(a);

	return 0;
}