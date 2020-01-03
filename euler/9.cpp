// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
// a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

#include <iostream>

using namespace std;
void main()
{
    // To run, open a Developer Command Prompt for VS, cd to the current dir and run "cl /EHsc 9.cpp && 9.exe"
    // It's getting late so I'm totally brute forcing this one (exec should take around 0.5 sec)
    for (int c = 1000; c > 0; c--)
    {
        for(int b = c - 1;b>0; b--)
        {
            for (int a = b-1; a>0; a--)
            {
                if (a+b+c == 1000)
                {
                    if (a*a + b*b == c*c)
                    {
                        cout << " a= " << a << " b= " << b << " c= " << c << endl;
                        cout << " a*b*c= " << a*b*c << endl;
                        cout << " a^2 + b^2 = c^2  => " << a*a + b*b << " = " << c*c << endl;
                    }
                }
            }
        }
    }
}