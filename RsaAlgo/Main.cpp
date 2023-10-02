#include <iostream>
#include "RsaUtil.h"

using std::cout;
using std::cin;

int main()
{
	unsigned int p, q, e, isPrime, n, lambda, d, numberToEncrypt, encryptResult, decryptResult;

	cout << "Enter the first prime number: ";
	cin >> p;
	isPrime = prime(p);
	if (isPrime == 0)
	{
		cout << "\nWrong Input, you must enter a prime number" << std::endl;
		cin.get();
		return 0;
	}

	cout << "\nEnter the second prime number: ";
	cin >> q;
	isPrime = prime(q);
	if (isPrime == 0)
	{
		cout << "\nWrong Input, you must enter a prime number";
		cin.get();
		return 0;
	}

	n = p * q;
	cout << "\nThe compute of n is: " << n << std::endl;

	lambda = lcm(p - 1, q - 1);
	cout << "The lambda value is: " << lambda << std::endl;

	cout << "Choose a coprime number < " << lambda << ": ";
	cin >> e;

	if (e > lambda) {
		cout << "\nWrong Input, you must choose a prime number < " << lambda << std::endl;
		cin.get();
		return 0;
	}

	isPrime = prime(e);
	if (isPrime == 0)
	{
		cout << "\nWRONG INPUT\n";
		cin.get();
		return 0;
	}

	d = modInverse(e, lambda);
	cout << "The compute of d is: " << d << std::endl;

	cout << "Enter a number to encrypt: ";
	cin >> numberToEncrypt;

	encryptResult = moduloPow(numberToEncrypt, e, n);
	cout << "\nThe encrypt number is: " << encryptResult << std::endl;

	decryptResult = moduloPow(encryptResult, d, n);
	cout << "The decrypt number is: " << decryptResult << std::endl;

	cin.get();
	return 0;
}