#include <iostream>
#include <cmath>
#include <time.h>
#include <thread>

bool isPrime(int num)
{
	if (num == 2) return true;
	else if (num <= 1 || num % 2 == 0) return false;
	double sqrt_num = sqrt(double(num));
	for (int div = 3; div <= sqrt_num; div += 2) {
		if (num % div == 0) return false;
	}
	return true;
}

void start_multithreading1(int n, int x) {
	for (; x < n; x ++) isPrime(x);
}
void start_multithreading2(int n, int x) {
	for (; x < n; x++) isPrime(x);
}
void start_multithreading3(int n, int x) {
	for (; x < n; x++) isPrime(x);
}
void start_multithreading4(int n, int x) {
	for (; x < n; x++) isPrime(x);
}

int main() {
	const int PROCESSOR_COUNT = std::thread::hardware_concurrency();
	int n1 = 2500000;
	int n2 = 5000000;
	int n3 = 7500000;
	int n4 = 10000000;


	std::thread threads[4]{
	std::thread(start_multithreading1, n1, 0),
	std::thread(start_multithreading2, n2, 2500000),
	std::thread(start_multithreading3, n3, 5000000),
	std::thread(start_multithreading4, n4, 7500000)
	};



	clock_t start, end;
	start = clock();

	threads[0].join();
	threads[1].join();
	threads[2].join();
	threads[3].join();

	end = clock();
	printf("time: %f", (end - start) / ((double)CLOCKS_PER_SEC));
	// scanf_s("%i", &n);
	return 0;
}