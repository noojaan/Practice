#include <iostream>


class CharPair
{
	char first;
	char second;
public:
	CharPair(char ch1 = NULL, char ch2 = NULL) :first(ch1), second(ch2) {}
	void set(char ch1, char ch2) { first = ch1; second = ch2; }
	void print() { std::cout << "Pair(" << first << ", " << second << ")" << std::endl; }
	char getFirst() const { return first; }
	char getSecond() const { return second; }
	/* if we don't make these get function const we get error in line 25 when using const CharPair& */
};

class IntPair
{
	int first;
	int second;
public:
	IntPair(int i = 0, int j = 0) :first(i), second(j) {}
	void set(int i, int j) { first = i; second = j; }
	void print() { std::cout << "Pair(" << first << ", " << second << ")" << std::endl; }
	void copyFrom(const CharPair& cp1)
	{
		first = static_cast<int>(cp1.getFirst());
		/* can't directly use cp1.first because function copyFrom
		   doesn't have access to private members of CharPair
		   access control works on a per-class basis, not a per-object basis */
		second = static_cast<int>(cp1.getSecond());
	}

};


int main()
{
	IntPair p1{ 1,1 };
	p1.print();

	CharPair p2{ 'a','b' };
	p2.print();

	IntPair p3;
	p3.copyFrom(p2);
	p3.print();

	return 0;
}