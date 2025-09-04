#include <iostream>

int main()
{
	constexpr int answer = 42;

	std::cout << "The answer to the question of\n"
		      << "Life, the Universe, and Everything is "
		      << answer << ".\n";

	return 0;
}