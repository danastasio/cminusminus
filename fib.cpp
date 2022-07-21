#include<iostream>

void fib(int iter, int sum = 0)
{
	int last = sum;
	sum = iter + sum;
	if (sum > 50000) {
		return;
	}
	std::cout << sum << std::endl;
	fib(last, sum);
}

int main()
{
	fib(1);
}

