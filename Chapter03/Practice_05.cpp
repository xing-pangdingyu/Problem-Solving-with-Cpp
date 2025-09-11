#include <iostream>
#include <cmath>

bool is_prime(int n) {
    int sqrt_n = static_cast<int>(std::sqrt(n));

    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false; // Exclude evens (except 2)
    
    for (int m = 3; m <= sqrt_n; m += 2) { // Check odd factors only
        if (n % m == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
	for (int n = 2; n <= 100; n++)
	{
		if (is_prime(n)) {
            std::cout << n << ' ';
        }
	}

    std::cout << '\n';
	return 0;
}
