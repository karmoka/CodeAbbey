#include <iostream>


// The sum of the squares of the first ten natural numbers is,
// 1^2 + 2^2 + ... + 10^2 = 385

// The square of the sum of the first ten natural numbers is,
// (1 + 2 + ... + 10)^2 = 552 = 3025

// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.


using namespace std;
void main()
{
    int sum = 0;
    int sumOfSquares = 0;
    for (int i = 0; i < 100; ++i)
    {   
        sum += i;
        sumOfSquares += i*i;
    }
    int squareOfSum = sum * sum;
    cout << "diff " << squareOfSum - sumOfSquares << endl;
}