#include <iostream>
#include <iomanip>

int main()
{
	constexpr double one = 1.000,
					 two = 1.414,
					 three = 1.732,
					 four = 2.000,
					 five = 2.236;


	std::cout << std::fixed << std::setprecision(3);
	std::cout << "N\tSquare Root" << "\n1\t"
			  << one << "\n2\t"
		 	  << two << "\n3\t"
			  << three << "\n4\t"
			  << four << "\n5\t"
			  << five << '\n';

	return 0;
}