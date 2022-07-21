#include<iostream>

void fibb(int iter, int last = 1)
{
	int sum = iter+last;
	if (sum > 50000) {
		return;
	} else {
		std::cout << sum << std::endl;
		fibb(last, sum);
	}
}

int main()
{
	fibb(1);
}
